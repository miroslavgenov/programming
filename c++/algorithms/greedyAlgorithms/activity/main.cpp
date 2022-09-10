#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct stack{
	int startAt;
	int endAt;
	stack* next;
	stack* prev;
};
vector<stack*> activityHistory;
stack* stackRoot=nullptr;

bool isStackEmpty(){
	return ::stackRoot==nullptr;
}

void appendStack(stack* stackRoot,stack* value){
	stack* point = nullptr;
	if(isStackEmpty()){
		
		::stackRoot = new stack{value->startAt, value->endAt, nullptr, nullptr};
		
	}else{
		point = stackRoot;
	while(point->next){
		point=point->next;
	}
	point->next = value;
	value->prev = point;	
	}
	
}

void printStack(stack* root){
	if(!isStackEmpty()){
		stack* point = root;
		while(point){
			cout<<point->startAt<<" "<<point->endAt<<endl;
			point=point->next;
		}	
	}
	else
	{
		cout<<"STACK IS EMPTY"<<endl;	
	}
}

stack* popStack(stack* root){

	int startAt;
	int endAt;

	if(!root){
		return stackRoot;
	}
	else if(!root->prev && !root->next){
		startAt = stackRoot->startAt;
		endAt = stackRoot->endAt;
		
		stackRoot=nullptr;
		return new stack{startAt, endAt, nullptr, nullptr};
	}else{
		stack* stackPoint = root;
		while(stackPoint->next){
			stackPoint=stackPoint->next;
		}
		
		startAt= stackPoint->startAt;
		endAt = stackRoot->endAt;
		
		stackPoint->prev->next=nullptr;
		stackPoint=nullptr;
		return new stack{startAt, endAt, nullptr, nullptr};
	}
	return stackRoot;
}

int* getTheGreaterStartAtNumberFromStack(stack* stackRoot){
	int *greater = nullptr;
	stack* point = nullptr;
	if(stackRoot){
		point = stackRoot;
		greater = new int{point->startAt};
		while(point){
			if(*greater < point->startAt){
				greater = new int{point->startAt};
			}
			point = point->next;
		}

		return greater;
	}
	return greater;
}


stack* getTheNextActivityThatFits(stack* stackRoot){
	stack* point = nullptr;
	int startAt;
	int endAt;
	stack* nullstack=nullptr;

	if(stackRoot){
		point = stackRoot;
		
		
		if(activityHistory.size() == 0){
			startAt = point->startAt;
			endAt = point->endAt;	

			while(point){
				if(endAt >= point->endAt){
					startAt = point->startAt;
					endAt = point->endAt;
				}
				point = point->next;
			}
			return new stack{startAt, endAt,nullptr,nullptr};

		}else{
			// cout<<"activityHistory is not null get the next activity which is acceptable"<<endl;
			startAt = activityHistory[activityHistory.size()-1]->startAt;
			endAt = std::numeric_limits<int>::max();
			int tempStartAt;
			while(point){
				if(point->startAt > startAt && endAt > point->endAt ){
					tempStartAt = point->startAt;
					// startAt = point->startAt;
					endAt = point->endAt;
					// break;
				}
				
				if(point->next == nullptr){
					break;

				}else{
					point=point->next;
				}

			}
			
			startAt  = tempStartAt;
			// cout<<startAt<<" "<<endAt<<endl;
			return new stack{startAt, endAt, nullptr, nullptr};
		}
	}
	return nullptr;
}

void removeFromStack(int startAt, int endAt){
	stack* point = nullptr;
	if(stackRoot){

		point = stackRoot;
		while(point){
			if(point->startAt == startAt && point->endAt == endAt){
			

				break;
			}else{
				point= point->next;	
			}
			
		}

		if(point){

			if(!point->prev && !point->next){

				stackRoot = nullptr;
			}else{

				if(point->prev && point->next){

					point->prev->next = point->next;
					point->next->prev = point->prev;
				}else if(point->prev && !point->next){

					point->prev->next=nullptr;
				}else if(!point->prev && point->next){

					stackRoot = stackRoot->next;
					stackRoot->prev=nullptr;

				}
			}
		}else{
//			cout<<" don't found"<<endl;
		}
		
		
		
	}else{
		cout<<"stackRoot is empty"<<endl;
	}
}




int main(){
	stack* s1 = new stack{0,6,nullptr,nullptr};
	stack* s2 = new stack{1,2,nullptr,nullptr};
	stack* s3 = new stack{3,4,nullptr,nullptr};
	stack* s4 = new stack{5,9,nullptr,nullptr};
	stack* s5 = new stack{1,1,nullptr,nullptr};
	stack* s6 = new stack{8,9,nullptr,nullptr};
	stack* s7 = new stack{3,2,nullptr,nullptr};
	stack* s8 = new stack{5,7,nullptr,nullptr};

	appendStack(stackRoot, s1);
	appendStack(stackRoot, s2);
	appendStack(stackRoot, s3);
	appendStack(stackRoot, s4);
	appendStack(stackRoot, s5);
	appendStack(stackRoot, s6);
	appendStack(stackRoot, s7);
	appendStack(stackRoot, s8);


	stack* f = getTheNextActivityThatFits(stackRoot);
	removeFromStack(f->startAt,f->endAt);
	activityHistory.push_back(new stack{f->startAt,f->endAt, nullptr, nullptr});
	// printStack(stackRoot);
	
	// f = getTheNextActivityThatFits(stackRoot);
	// removeFromStack(f->startAt,f->endAt);
			
	// printStack(stackRoot);
	f = getTheNextActivityThatFits(stackRoot);
	removeFromStack(f->startAt,f->endAt);
	activityHistory.push_back(new stack{f->startAt, f->endAt, nullptr, nullptr});


	f = getTheNextActivityThatFits(stackRoot);
	removeFromStack(f->startAt,f->endAt);
	activityHistory.push_back(new stack{f->startAt, f->endAt, nullptr, nullptr});

	f = getTheNextActivityThatFits(stackRoot);
	if(f!=nullptr){
		removeFromStack(f->startAt,f->endAt);
		activityHistory.push_back(new stack{f->startAt, f->endAt, nullptr, nullptr});		
	}else{
		cout<<"activityHistory done"<<endl;
	}
	
	int lastActivityStart = activityHistory[activityHistory.size()-1]->startAt;
	int greaterRemainingActivityThatStartAt =*getTheGreaterStartAtNumberFromStack(stackRoot);
	
	if(lastActivityStart > greaterRemainingActivityThatStartAt)	{
		cout<<"Activity History is done"<<endl;
		
		cout<<endl;
		for(int i=0;i<activityHistory.size();i++){
			cout<<activityHistory[i]->startAt<<" "<<activityHistory[i]->endAt<<endl;
		}

	}else{
		removeFromStack(f->startAt,f->endAt);
		activityHistory.push_back(new stack{f->startAt, f->endAt, nullptr, nullptr});		
	}
	

	
}

