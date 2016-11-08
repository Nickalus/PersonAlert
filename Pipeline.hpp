#ifndef PIPELINE_HPP
#define PIPELINE_HPP

class Pipeline : public QObject
{
  Q_OBJECT
  
  public:
    Pipeline();
    
  private:
    GstElement * mPipeline;
};

#endif
