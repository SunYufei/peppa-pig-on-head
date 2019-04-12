#ifndef FACE_H_
#define FACE_H_

#include <opencv2/face.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <vector>
using namespace std;
using namespace cv;
using namespace cv::face;

class Face {
  public:
    explicit Face(const string faceModel);

    void locations(const Mat &image, vector<Rect> &faces);

  private:
    CascadeClassifier faceDetector;
};

#endif