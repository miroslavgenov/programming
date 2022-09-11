/*
	Need to clear this code
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;

struct  point
{
	int x;
	int y;
};

int radius = 4;

bool isPointInCircle(int pointDistanceResult, int circleSquareRootRange){
	return pointDistanceResult <= circleSquareRootRange;
}


int main(){
	srand(time(nullptr));
	
	int circleCenterCoordinatesXAndY = 0;
	int x,y;
	point *p = nullptr;
	int maxDistance = radius+1;
	int pointDistanceResult;
	int circleSquareRootRange;

	int totalNumberOfPointsThatAreInTheCircle=0;
	int totalNumberOfUsedPoints = 0;
	for(int i=0;i<10000000;i++){
		x = rand() % maxDistance;
		y = rand() % maxDistance;
		// cout<<"x= "<<x<<" y= "<<y<<endl;
		p = new point{x,y};
	
		// cout<<"is point: "<<p->x<<","<<p->y <<" in circle"<<endl;
		pointDistanceResult = pow((circleCenterCoordinatesXAndY - p->x),2) + pow((circleCenterCoordinatesXAndY - p->y),2);
		// cout<<"pointDistanceResult: "<<pointDistanceResult<<endl;

		circleSquareRootRange = pow(radius,2);
		// cout<<"circleSquareRootRange: "<<circleSquareRootRange<<endl;
		// cout<<"is point in circle: "<<isPointInCircle(pointDistanceResult, circleSquareRootRange)<<endl;
		
		if(isPointInCircle(pointDistanceResult, circleSquareRootRange)){
			totalNumberOfPointsThatAreInTheCircle++;
		}
		totalNumberOfUsedPoints++;
	}

	// cout<<totalNumberOfPointsThatAreInTheCircle<<" "<<totalNumberOfUsedPoints<<endl;
	
	cout<<
	(((double)(4*totalNumberOfPointsThatAreInTheCircle)/(double)totalNumberOfUsedPoints))
	<<endl;
}
