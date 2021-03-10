#include<iostream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
  img_setup("empty.jpg");
  img_setup("traffic.jpg");
  return 0;
}

void img_setup(string s){
  Mat img1 = imread(s);
  if (img1.empty()){
    cout<<"Error loading the image"<<endl;
    return -1;
  }
  vector<Point2f> pts1;
  pts1.push_back(Point2f(coordinates[0][0],coordinates[0][1]));
  pts1.push_back(Point2f(coordinates[1][0],coordinates[1][1]));
  pts1.push_back(Point2f(coordinates[2][0],coordinates[2][1]));
  pts1.push_back(Point2f(coordinates[3][0],coordinates[3][1]));

  vector<Point2f> pts2;
  pts2.push_back(Point2f(0,0));
  pts2.push_back(Point2f(0,1075));
  pts2.push_back(Point2f(1075,1075));
  pts2.push_back(Point2f(1075,0));

  hm = getPerspectiveTransform(pts1,pts2);
  warpPerspective(img1,img2,hm,Points(1075,1075));


  waitkey(0);

}
