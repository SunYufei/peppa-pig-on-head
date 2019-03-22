#include "face/face.h"
#include "piggy/piggy.h"
#include "video/capture.h"
// #include "video/writer.h"

#include <opencv2/highgui.hpp>
using namespace cv;

int main() {
    // Capture
    Capture capture(0);

    // Writer
    // Writer writer("output.avi", 30.0, Size(capture.width, capture.height));

    // Face
    Face face("model.xml");

    // Piggy
    Piggy piggy("piggy.png");

    // Raw data
    Mat frame;

    // Face locations
    vector<Rect> faces;

    // Monitor Windows
    namedWindow("Peppa Pig", WINDOW_AUTOSIZE);

    while (true) {
        if (capture.getFrame(frame)) {
            face.locations(frame, faces);

            if (faces.size() > 0)
                piggy.drawPiggy(frame, faces[0], true, true);

            // 辅助线
            // rectangle(frame, faces[0], Scalar(0, 255, 0));

            // 写入视频文件
            // writer.write(frame);

            // 在窗口上显示
            imshow("Peppa Pig", frame);

            // 按ESC键退出
            if (waitKey(33) == 27)
                break;
        }
    }

    return 0;
}