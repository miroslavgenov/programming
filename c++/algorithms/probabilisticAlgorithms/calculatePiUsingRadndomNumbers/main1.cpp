#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(){
	srand(time(nullptr));

	double circleRadius = 300;
	int x,y;

	double pointDistance;
	double totalNumberOfPointsInCircle=0;
	double maxPoints = 100000000;
	
	for(int i=0;i<maxPoints;i++){
		x = rand() % 301;
		y = rand() % 301;
		if(sqrt(x*x + y*y) < circleRadius){
			totalNumberOfPointsInCircle++;
		}
		
	}
	
	cout<<(totalNumberOfPointsInCircle*4) /maxPoints <<endl;
}














































