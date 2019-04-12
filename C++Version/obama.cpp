#include "face/face.h"
#include "piggy/piggy.h"

#include <opencv2/highgui.hpp>
using namespace cv;

int main() {
    Mat obama = imread("obama.jpg");
    resize(obama, obama, Size(), 0.75, 0.75);
    Face face("model.xml");
    Piggy piggy("piggy.png");
    vector<Rect> faces;
    namedWindow("Obama", WINDOW_AUTOSIZE);
    face.locations(obama, faces);
    if (faces.size() > 0)
        piggy.drawPiggy(obama, faces[0], false, true);
    imshow("Obama", obama);
    while (true)
        if (waitKey(1) == 27)
            break;

    return 0;
}