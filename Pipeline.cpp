#include "Pipeline.hpp"
#include <iostream>

Pipeline::Pipeline()
  : mPipeline(gst_pipeline_new("pipeline"))
{
}

Pipeline::~Pipeline()
{

}

void Pipeline::Start()
{
  gst_element_set_state(GST_ELEMENT(mPipeline), GST_STATE_PLAYING);
}

void Pipeline::CreatePipeline()
{
  GstElement * src = gst_element_factory_make("videotestsrc", NULL);
  GstElement * sink = gst_element_factory_make("fakesink", NULL);
  GstCaps *caps = gst_caps_new_simple("video/x-raw", "format", G_TYPE_STRING, "RGB", "width", G_TYPE_INT, 320, "height", G_TYPE_INT, 240, "framerate", GST_TYPE_FRACTION, 25, 1, NULL);

  g_object_set(G_OBJECT(sink), "signal-handoffs", TRUE, NULL);
  g_signal_connect(G_OBJECT(sink), "handoff", G_CALLBACK(Handoff), this);
  //Set the context
  //gst_element_set_context(mPipeline, mContext);

  gst_bin_add_many(GST_BIN (mPipeline), src, sink, NULL);
  gst_element_link_filtered(src, sink, caps);
}

void Pipeline::Handoff(GstElement * fakesink, GstBuffer * buffer, GstPad * pad, Pipeline * pipeline)
{
  std::cout << "Handoff" << std::endl;
}
