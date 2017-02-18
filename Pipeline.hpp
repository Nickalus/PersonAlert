#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include <gst/gst.h>

#include <QObject>

class Pipeline : public QObject
{
  Q_OBJECT
  
  public:
    Pipeline();
    ~Pipeline();

    void CreatePipeline();

    //QVariant GetGLContext();

  public slots:
    void Start();

  private:
    static void Handoff(GstElement *, GstBuffer *, GstPad *, Pipeline *);

    //static void ClientDraw(GstElement *, GstGLContext *, GstSample *, Pipeline *);
    //gboolean ClientDraw(GstGLImageSink *, GstGLContext *, GstSample *, gpointer);

  private:
    GstElement * mPipeline;
    GstBus * mBus;
    //GstGLDisplay * mDisplay;
    //GstContext * mContext;
};

#endif
