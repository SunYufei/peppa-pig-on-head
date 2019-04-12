#include "face.h"

Face::Face(const string faceModel) { faceDetector.load(faceModel); }

// Face Detection
void Face::locations(const Mat &image, vector<Rect> &faces) {
    Mat gray = image.clone();
    if (gray.channels() > 1)
        cvtColor(gray, gray, COLOR_BGR2GRAY);
    equalizeHist(gray, gray);
    faceDetector.detectMultiScale(gray, faces, 1.1, 3, 0, Size(32, 32));
}
