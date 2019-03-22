#include "writer.h"

Writer::Writer(const string &filename, double fps, Size frameSize) {
    writer.open(filename, -1, fps, frameSize);
}

Writer::~Writer() { writer.release(); }

bool Writer::write(const Mat &image) {
    if (writer.isOpened() && !image.empty()) {
        writer.write(image);
        return true;
    } else {
        return false;
    }
}