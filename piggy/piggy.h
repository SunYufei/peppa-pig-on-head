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

    void drawPiggy(Mat &image, const Rect &location, bool top = true,
                   bool side = false);

  private:
    Mat piggy;
    Mat small;
    Mat_<Vec4b> _small;
    Mat_<Vec3b> _image;

    int x, y, w, h;
    double ratio;
    int r, c, start;
};

#endif