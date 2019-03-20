#ifndef WRITER_H_
#define WRITER_H_

#include <opencv2/videoio.hpp>
#include <string>
using namespace cv;
using namespace std;

class Writer {
  private:
    VideoWriter writer;

  public:
    explicit Writer(const string &filename, double fps, Size frameSize);

    ~Writer();

    bool write(const Mat &image);
};

#endif