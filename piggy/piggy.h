#ifndef PIGGY_H_
#define PIGGY_H_

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
using namespace cv;
using namespace std;

class Piggy {
  public:
    explicit Piggy(const string file);

    void putOnHead(Mat &image, const Rect &location);

  private:
    Mat piggy;
    Mat small;
    Mat_<Vec4b> small_;
};

#endif