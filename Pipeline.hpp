#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include <gst/gst.h>
#define GST_USE_UNSTABLE_API
#include <gst/gl/gl.h>
#include <gst/gl/gstglconfig.h>
#include <gst/gl/egl/gstgldisplay_egl.h>
#include <gst/video/video.h>

#include <QOpenGLContext>

class Pipeline : public QObject
{
  Q_OBJECT
  
  public:
    Pipeline(QOpenGLContext *);

  private:
    void CreatePipeline();

    static void ClientDraw(GstElement *, GstGLContext *, GstSample *, Pipeline *);
    static gboolean BusMessage(GstBus *, GstMessage *);
    static gboolean SyncBusMessage(GstBus *, GstMessage *, Pipeline *);

  private:
    GstElement * mPipeline;
    GstBus * mBus;
    GstGLDisplay * mDisplay;
    GstGLContext * mContext;
};

#endif
