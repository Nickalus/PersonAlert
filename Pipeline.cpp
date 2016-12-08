#include "Pipeline.hpp"

Pipeline::Pipeline(QOpenGLContext * context)
{
  //
}

void Pipeline::CreatePipeline()
{
  //gst-launch -v v4l2src ! "video/x-raw-yuv, format=(fourcc)I420" ! glimagesink
  GstElement * glimagesink = nullptr;
  GstElement * v4l2src = nullptr;

  mPipeline = gst_pipeline_new ("pipeline");
  mBus = gst_pipeline_get_bus(GST_PIPELINE(mPipeline));


}

void Pipeline::ClientDraw(GstElement * sink, GstGLContext * context, GstSample * sample, Pipeline * p)
{
  Q_UNUSED(sink);
  Q_UNUSED(context);

  GstVideoFrame v_frame;
  GstVideoInfo v_info;
  guint texture = 0;
  GstBuffer * buffer = gst_sample_get_buffer(sample);
  GstCaps * caps = gst_sample_get_caps(sample);

  gst_video_info_from_caps(&v_info, caps);

  if(!gst_video_frame_map(&v_frame, &v_info, buffer, (GstMapFlags)(GST_MAP_READ|GST_MAP_GL)))
  {
    qDebug() << "Failed to map the video buffer";
    return;
  }

  texture = *(guint *)v_frame.data[0];

  p->NewFrameReady(texture);

  gst_video_frame_unmap(&v_frame);
}

gboolean Pipeline::BusMessage(GstBus * bus, GstMessage * message, Pipeline * p)
{
  Q_UNUSED(bus);

  switch(GST_MESSAGE_TYPE(message))
  {
    case GST_MESSAGE_EOS:
    break;
    case GST_MESSAGE_ERROR:
    break;
    default:
    break;
  }

  return TRUE;
}

gboolean Pipeline::SyncBusMessage(GstBus * bus, GstMessage * msg, Pipeline * p)
{
  Q_UNUSED(bus);

  switch(GST_MESSAGE_TYPE(msg))
  {
    case GST_MESSAGE_NEED_CONTEXT:
      const gchar *context_type;
      gst_message_parse_context_type(msg, &context_type);

      if(g_strcmp0(context_type, "gst.gl.app_context") == 0)
      {
        GstContext * app_context = gst_context_new("gst.gl.app_context", TRUE);
        GstStructure * s = gst_context_writable_structure(app_context);
        gst_structure_set(s, "context", GST_GL_TYPE_CONTEXT, p->mContext, NULL);
        gst_element_set_context(GST_ELEMENT(msg->src), app_context);
      }
    break;
    default:
    break;
  }

  return FALSE;
}
