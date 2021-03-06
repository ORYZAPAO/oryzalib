// opCV_proto002.cpp : アプリケーションのエントリ ポイントを定義します。
//
#include "stdafx.h"

//
// Visual Studio Comunity 2017+
// OpenCV 3.41 + opencv_contrib-3.4.1
//

#pragma comment(lib,"opencv_world341d.lib")

#include<iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

using namespace std;
using namespace cv;


int main(){
  //cout << "Hello" << endl;
  cv::Ptr<cv::Tracker> tracker = TrackerKCF::create();  // トラッキングオブジェクト作成

  VideoCapture capture(0);
  if(!(capture.isOpened())){
    cout << "Error" << endl;
  }


  //
  // 最初のフレームで，トラッキング対象のオブジェクトを指定
  //

  // Read first frame
  Mat frame;
  bool ok = capture.read(frame);

  // Define initial boundibg box
  Rect2d bbox(287, 23, 86, 320);

  // Uncomment the line below to select a different bounding box
  bbox = selectROI(frame, false);

  // Display bounding box.
  rectangle(frame, bbox, Scalar(255, 0, 0), 2, 1);
  imshow("Tracking", frame);

  tracker->init(frame, bbox);
  
  //
  // スタート
  //
  while(1){
    capture >> frame;

    // Update the tracking result
    bool ok = tracker->update(frame, bbox);
    if(ok){
      // Tracking success : Draw the tracked object
      rectangle(frame, bbox, Scalar(255, 0, 0), 2, 1);
    } else{
      // Tracking failure detected.
      putText(frame, "Tracking failure detected", Point(100, 80), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 255), 2);
    }

    imshow("Tracking", frame);

    if(waitKey(1) == 'q') break;
  }


  cv::destroyAllWindows();

  return 0;
}
