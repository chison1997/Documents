#include <iostream>
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;

int main()
{
    String url;
    VideoCapture* capture;
    url = "rtsp://192.168.1.2:554";
    capture = new VideoCapture(url);

    if (capture->isOpened())
    {
        Mat image;
        cout<< "Opened";
        capture->read(image);
        imshow("Capture", image);
    }
    else 
    {
        cout<< "Closed";
    }

    return 0;
}