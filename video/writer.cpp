#include "writer.h"

Writer::Writer(const string &filename, double fps, Size frameSize) {
    writer.open(filename, CAP_OPENCV_MJPEG, fps, frameSize);
}

Writer::~Writer() { writer.release(); }

bool Writer::write(const Mat &image) {
    if (writer.isOpened() && !image.empty()) {
        writer << image;
    } else {
        return false;
    }
}