#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include <gst/gst.h>


class Pipeline : public QObject
{
  Q_OBJECT
  
  public:
    Pipeline();
    
  private:
    GstElement * mPipeline;
};

#endif
