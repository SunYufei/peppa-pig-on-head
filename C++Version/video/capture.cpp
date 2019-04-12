#include "capture.h"

void Capture::initCaptureParams() {
    width = capture.get(CAP_PROP_FRAME_WIDTH);
    height = capture.get(CAP_PROP_FRAME_HEIGHT);
    count = capture.get(CAP_PROP_FRAME_COUNT);
}

double Capture::fps() { return capture.get(CAP_PROP_FPS); }

Capture::Capture(const int id) {
    capture.open(id);
    initCaptureParams();
}

Capture::Capture(const string &filename) {
    if (!filename.empty()) {
        capture.open(filename);
        initCaptureParams();
    } else
        Capture();
}

Capture::~Capture() { capture.release(); }

bool Capture::getFrame(Mat &frame, double ratio) {
    if (capture.isOpened()) {
        capture >> frame;
        if (ratio - 1.0 > 1e-8 || 1.0 - ratio > 1e-8)
            resize(frame, frame, Size(), ratio, ratio);
        return true;
    } else {
        return false;
    }
}