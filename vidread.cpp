#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

	VideoCapture cap(0); // 1 for external webcam
	//VideoCapture cap("---PATH OF THE VIDEO TO BE PLAYED-----");
	
	if(!cap.isOpened()){
		cout<<"could not load video";
		return -1;
	}
	//to get fps of video
	/*double fps= cap.get(CV_CAP_PROP_FPS);
	cout<<"FPS: "<<fps<<endl;*/ 
	
	namedWindow("Display",CV_WINDOW_AUTOSIZE);
	
	while(1){
		Mat frame;
		bool isopen=cap.read(frame);
		if(!isopen){
			cout<<"cannot read video";
			break;
		}
		
		imshow("Display",frame);
		char key=cvWaitKey(30);
		if((key) == 27){
			break;
		}
		
	}
    destroyWindow("Display"); //Destroy Window
//  destroyAllWindows();

	return 0;
	
	
}
