#include "face/face.h"
#include "video/capture.h"

#include <opencv2/highgui.hpp>
using namespace cv;

int main() {
    // Capture
    Capture capture(0);

    // Face
    Face face("model.xml");

    // Piggy
    Mat piggy = imread("piggy.png", IMREAD_UNCHANGED);
    int rows = piggy.rows;
    double ratio;

    Mat small;
    Mat_<Vec4b> small_;
    int r, c, start, x, y, w, h;

    int i, j, k;

    // Raw data
    Mat frame;
    Mat_<Vec3b> frame_;

    // Face locations
    vector<Rect> faces;

    // Monitor
    namedWindow("Monitor", WINDOW_AUTOSIZE);

    while (true) {
        if (capture.getFrame(frame)) {
            frame_ = frame;
            face.locations(frame, faces);

            if (faces.size() > 0) {
                x = faces[0].x;
                y = faces[0].y;
                w = faces[0].width;
                h = faces[0].height;
                ratio = double(h) / rows;

                /* Put piggy on head */
                resize(piggy, small, Size(), ratio, ratio);
                small_ = small;
                r = small.rows;
                c = small.cols;
                start = (w - c) / 2;

                // draw piggy 注意 Mat_(i, j) 中 i, j 代表 row, col
                for (i = 0; i < c; ++i)
                    for (j = 0; j < r; ++j)
                        if (y - r + j >= 0)
                            if ((int)small_(j, i)[3] != 0)
                                for (k = 0; k < 3; ++k)
                                    frame_(y - r + j, x + start + i)[k] =
                                        small_(j, i)[k];
            }

            imshow("Monitor", frame);

            if (waitKey(33) == 27)
                break;
        }
    }

    return 0;
}