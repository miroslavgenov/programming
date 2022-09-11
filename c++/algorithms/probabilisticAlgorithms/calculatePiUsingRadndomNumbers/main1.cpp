#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	srand(time(nullptr));

	double circleRadius = 1;
	int x,y;

	double pointDistance;
	double totalNumberOfPointsInCircle=0;
	double maxPoints = 10000000;
	
	for(int i=0;i<maxPoints;i++){
		x = rand() % 2;
		y = rand() % 2;
		pointDistance = (x*x + y*y) * 0.5;
		if(pointDistance<circleRadius){
			totalNumberOfPointsInCircle++;
		}
	}
	
	cout<<(totalNumberOfPointsInCircle*4) /maxPoints <<endl;
}
