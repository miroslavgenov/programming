#include <iostream>
#include <vector>

using namespace std;

int coins[] = {5,4,2};
vector<int> coinsUsed;

void greedy(int num){
	if(num == 0)	{
		return;
	}else{
		for(int i=0;i<3;i++){
			if(num - coins[i] >= 0){
				num-=coins[i];
				coinsUsed.push_back(coins[i]);
				break;
			}
			if(i == 2){
				return;
			}
		}

		greedy(num);	
	}

}

void printUsedCoins(){
	cout<<endl;
	for(auto it = begin(coinsUsed) ; it < end(coinsUsed); it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main(){
	int coin = 18;
	
	greedy(coin);
	printUsedCoins();
	

	
	
	

}
