#include "piggy.h"

Piggy::Piggy(const string file) { piggy = imread(file, IMREAD_UNCHANGED); }

void Piggy::putOnHead(Mat &image, const Rect &location) {
    Mat_<Vec3b> image_ = image;
    int x = location.x;
    int y = location.y;
    int w = location.width;
    int h = location.height;
    double ratio = double(h) / piggy.rows;
    resize(piggy, small, Size(), ratio, ratio);
    small_ = small;
    int r = small.rows;
    int c = small.cols;
    int start = (w - c) / 2;
    int i, j, k;
    for (i = 0; i < c; ++i)
        for (j = 0; j < r; ++j)
            if ((y - r + j >= 0) && ((int)small_(j, i)[3] != 0))
                for (k = 0; k < 3; ++k)
                    image_(y - r + j, x + start + i)[k] = small_(j, i)[k];
}