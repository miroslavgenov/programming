#include <iostream>
using namespace std;

class NextStudentNotNull{
	public:
		string msg;
		NextStudentNotNull(){
			msg="not null next";
		}
		string what(){return msg;
		}
};

class Student{
	private:
		
		
	public:
		Student* next;
		string name;
		static int index;
		
		
		
		Student(string name,Student *_next):name(name),next(_next){
			index++;
			
		}
		Student(string name):Student(name,nullptr){}
		
		void setNext(Student *student){		
			if(isNextNullptr()){
				this->next=student;
				
			}else{
				throw NextStudentNotNull();
			}
		}
		bool isNextNullptr(){
			return next==nullptr;
		}
		
		static int getSize(){
			return index;
		}
		
		bool isSizeZero(){
			return index==0;
		}
		
		void printStudent(){
			cout<<this->name<<" "<<endl;
		}
		
};

int Student::index=0;



struct node{
    int number;
    node *next;
};
int index=0;

void appendNode(node *root,node *v){
    index++;
    root->next=v;
}

int main(){
//    node *r = new node{1,nullptr};
//    node *ivan = new node{33,nullptr};
//    
//    appendNode(r,ivan);
//    appendNode(ivan,new node{5,nullptr});
//    node *point=r;
//	
//	while(point){
//		cout<<point->number<<" ";
//		point=point->next;
//	}
	Student *root = new Student("Ivan",nullptr);
	
	root->setNext(new Student("Alex",nullptr));
	cout<<Student::getSize()<<endl;
	try{
	
	
		root->setNext(new Student("Alex",nullptr));
	}
	catch(NextStudentNotNull e){
		cout<<e.what()<<endl;
	}
	//root->next->setNext(new Student("Jojo",nullptr));
	//root->printStudent();
	
//    cout<<point->number<<" "<<endl;
//    cout<<point->next->number<<" "<<endl;
    
    
}






















































