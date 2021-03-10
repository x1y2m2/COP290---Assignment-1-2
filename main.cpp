#include<iostream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

struct coordinate{
	int xs;
	int ys;
};

coordinate c;
c.xs=-1;
c.ys=-1;

bool newClick = false;

void MouseClick(int event,int x,int y,int flags, void*){
  if (event = EVENT_LBUTTONDOWN){
    c.xs = x;
    c.ys = y;
    newClick = true;
   }
}

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
  namedWindow("My Window",1);
  imshow("My Window",img1);
  int coordinates[4][2];                       
  for (int i=0;i<4;i++){
    waitkey(0);
    setMouseCallback("My Window",MouseClick,NULL);
    if (newClick){
      coordinates[i][0] = c.xs;
      coordinates[i][1] = c.ys;
      newClick = false;
    }
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

  imshow("modified_image",img2);

  waitkey(0);

}
