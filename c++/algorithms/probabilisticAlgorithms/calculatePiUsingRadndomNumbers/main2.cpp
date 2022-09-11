#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;


int main(){
	int squareSide = 200;
	int radius = squareSide/2;
	
	srand(time(0));
	
	int x;
	int y;
	
	int total=0;
	int size=10000000;
	for(int i=0;i<size;i++){
		x = (rand() % squareSide) - radius;
		y = (rand() % squareSide) - radius;
//		cout<<x<<" "<<y<<" ";
//		cout<<(x*x + y*y) <<" "<<pow(radius,2)<<endl;
		if(sqrt(x*x+y*y) < radius) total++;
	}
	cout<<(double)(4.0*(double)total)/(double)size<<endl;
	

}

































































