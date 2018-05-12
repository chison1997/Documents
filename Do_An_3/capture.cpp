#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
// # include <opencv2/core/core.hpp>
 #include <opencv2/videoio.hpp>
 #include <opencv2/highgui/highgui.hpp>
// # include <opencv2/imgproc/imgproc.hpp> 
//#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp> 
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    
    VideoCapture capture(argv[1]);


    if (!capture.isOpened())
    {
        cout<< "Error" << endl;
        return -1;
    }
    cout<< "Open" << endl;

    Size S = Size((int) capture.get(CAP_PROP_FRAME_WIDTH),
                    (int) capture.get(CAP_PROP_FRAME_HEIGHT));
    VideoWriter file;
    int ex = static_cast<int>(capture.get(CAP_PROP_FOURCC));
    //int codec = CV_FOURCC('M','P','E','G');
    file.open("video.mp4", ex,capture.get(CAP_PROP_FPS), S, true);

    Mat frame;
    int i = 1;
    while(capture.read(frame))
    {
        cout<< i++ << endl;
        file<<frame;
        imwrite("cap.jpg", frame);
    }

    return 0;
}