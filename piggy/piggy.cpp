#include "piggy.h"

Piggy::Piggy(const string file) { piggy = imread(file, IMREAD_UNCHANGED); }

void Piggy::drawPiggy(Mat &image, const Rect &location, bool top, bool side) {
    _image = image;
    x = location.x;
    y = location.y;
    w = location.width;
    h = location.height;
    ratio = double(h) / piggy.rows;
    resize(piggy, small, Size(), ratio, ratio);
    _small = small;
    r = small.rows;
    c = small.cols;
    start = (w - c) / 2;
    int i, j, k;
    if (top) {
        for (i = 0; i < c; ++i)
            for (j = 0; j < r; ++j)
                if ((y - r + j >= 0) && (_small(j, i)[3] != 0))
                    for (k = 0; k < 3; ++k)
                        _image(y - r + j, x + start + i)[k] = _small(j, i)[k];
    }
    if (side) {
        for (i = 0; i < c; ++i)
            for (j = 0; j < r; ++j)
                if (_small(j, i)[3] != 0) {
                    // right side
                    if (x + 0.9 * w + i < image.cols)
                        for (k = 0; k < 3; ++k)
                            _image(y + j, x + 0.9 * w + i)[k] = _small(j, i)[k];
                    // left side
                    if (x + 0.1 * w - i > 0)
                        for (k = 0; k < 3; ++k)
                            _image(y + j, x + 0.1 * w - i)[k] = _small(j, i)[k];
                }
    }
}