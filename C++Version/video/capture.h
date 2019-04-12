#ifndef CAPTURE_H_
#define CAPTURE_H_

#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <string>
using namespace cv;
using namespace std;

class Capture {
  private:
    VideoCapture capture;
    void initCaptureParams();

  public:
    explicit Capture(const int id = 0);
    explicit Capture(const string &filename);

    ~Capture();

    double fps();
    double width = 0.0;
    double height = 0.0;
    double count = 0.0;

    bool getFrame(Mat &frame, double ratio = 1.0);
};

#endif