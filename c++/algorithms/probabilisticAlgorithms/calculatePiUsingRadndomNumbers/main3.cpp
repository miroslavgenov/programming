#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(){
	srand(time(0));
	
	int circleRadius = 100;
	int squareSideSize = 200;
	long long int totalPointsInCircle = 0;
	int x,y;
	long long int maximumPoints = 1000;
	while(1){


		for(long long int i = 0 ;i< maximumPoints; i++)	{
			// rand()% 201 will generate 0 to 200 ; then - 100 the numbers will be betwee -100 to 100
			x = (rand() % 201 ) - 100; 
			y = (rand() % 201 ) - 100;
			if(sqrt(x*x + y*y) <= circleRadius){
				totalPointsInCircle++;
			}
		}
		cout<<(4.0*totalPointsInCircle)/maximumPoints<<endl;
		totalPointsInCircle = 0;
	}
}
