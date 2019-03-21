#include "face/face.h"
#include "video/capture.h"
#include "video/writer.h"

#include <iostream>
#include <opencv2/highgui.hpp>
#include <string>
using namespace cv;
using namespace std;

int main(int argc, char **argv) {
    // 检查参数
    if (argc != 3)
        cout << "recorder.exe [input.mp4] [output.mp4]\n";
    else {
        // Capture
        Capture capture(string(argv[1]));
        // Writer
        Writer writer(string(argv[2]));
        // Face
        Face face("model.xml");
        
        
    }

    return 0;
}