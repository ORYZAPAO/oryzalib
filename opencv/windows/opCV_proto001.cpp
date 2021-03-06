// opCV_proto001.cpp : アプリケーションのエントリ ポイントを定義します。
//

//
// Visual Studio Comunity 2017+
// OpenCV 3.41 + opencv_contrib-3.4.1
//

#include "stdafx.h"

#pragma comment(lib,"opencv_world341d.lib")

#include<iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(){
  cv::Mat frame;
  //cout << "Hello" << endl;

  VideoCapture capture(0);
  if(!(capture.isOpened())){
    cout << "Error" << endl;
  }

  namedWindow("SrcWin", WINDOW_AUTOSIZE);

  while(1){
    capture >> frame;
    imshow("SrcWin", frame);

    if(waitKey(1) == 'q') break;
  }


  cv::destroyAllWindows();

  return 0;
}
