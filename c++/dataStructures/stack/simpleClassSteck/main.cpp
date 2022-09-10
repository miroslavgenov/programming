#include <iostream>
#include "student.cpp"
using namespace std;

void show(Student *[],const int);
void show(Student *);

Student *root_student=nullptr;

class MyException{
	public:
		int val;
		std::string orgin;
		
		MyException(int _v,std::string org):val(_v),orgin(org){	}
		
		std::string what(){
			return std::to_string(val)+" "+orgin; 
		}
		
};

void append_before_root(Student *root,Student *src){
	
		try{
		
	if(root->get_prev_student()==nullptr && src->get_next_student()==nullptr && src->get_prev_student()==nullptr){
		root->set_prev_student(src);
		src->set_next_student(root);
		src->set_prev_student(nullptr);	
	}else{
		throw MyException(0,"Not emprty student or prev is not empty");
	}
	}catch(MyException e){
		cout<<e.what()<<endl;
	}

}

void push(Student *src){
	Student *p=root_student;
	while(p->get_next_student()!=nullptr){
		p=p->get_next_student();
	}
	p->set_next_student(src);
	src->set_prev_student(p);
}

void append_before(Student *current,Student *src){
	Student *before_current=current->get_prev_student();
    before_current->set_next_student(src);
    src->set_prev_student(before_current);
    src->set_next_student(current);
    current->set_prev_student(src);
}

void init(){
	root_student = new Student("Ivan");
}

bool is_empty(){
	if(root_student==nullptr)
		return true;
	return false;
}

void append_after(Student*current , Student *src){
    if(current->get_next_student()==nullptr){
        current->set_next_student(src);
        src->set_prev_student(current);
        
    }else{
        Student* current_next = current->get_next_student();
    current->set_next_student(src);
    src->set_prev_student(current);
    src->set_next_student(current_next);
    current_next->set_prev_student(src);
    }
}

Student* pop(){
    Student *student_last=root_student;
    while(student_last!=nullptr){
    	if(student_last->get_next_student()==nullptr){
    		break;
		}
		student_last=student_last->get_next_student();
	}
	Student *student_before_last = student_last->get_prev_student();
	student_before_last->set_next_student(nullptr);
	student_last->set_prev_student(nullptr);
	return student_last;
	
    
}

Student * pop_first(){
	Student *p = new Student(root_student->get_name());
	root_student=root_student->get_next_student();
	root_student->set_prev_student(nullptr);
	return p;
	
}

int main(){
	::init();
	Student *s2=new Student("Alex");
	push(s2);
	Student *s3=new Student("jojo");
	Student *s4=new Student("ccccc");
	Student *s5=new Student("bbb");
	Student *s6=new Student("Jotaro");
	
	push(s3);push(s4);push(s5);push(s6);
	Student *s7=new Student("hhhh");
	Student *s8=new Student("Jjjj");
	append_after(s6,s7);
	push(s8);
    Student *poped = pop();
    Student* popf=pop_first();
    show(root_student);
	cout<<endl;cout<<poped->get_name()<<endl;
	cout<<popf->get_name()<<endl;
	
	
	
	
	
//	constexpr int SIZE=5;
//    Student *list[SIZE] = {
//		new Student("Ivan"),
//		new Student("Alex"),
//		new Student("Jotaro"),
//		new Student("Dio"),
//		new Student("Jiorno")
//	}; 
//	
//	for(int i=0;i<5;i++){
//		if(i==0) {
//			list[i]->set_prev_student(nullptr);
//			list[i]->set_next_student(list[i+1]);
//			continue;
//		}
//		else if(i==4){
//			list[i]->set_next_student(nullptr);
//			list[i]->set_prev_student(list[i-1]);
//			break;
//		}
//		list[i]->set_next_student(list[i+1]);
//		list[i]->set_prev_student(list[i-1]);
//	}
	
	//show(list,SIZE);
//	show(list[0]);
	
	
	
	
	
//	Student *s1=new Student("Ivan");
//	Student *s2= new Student("Alex");
//	Student *s3 = new Student("Jotaro");
//	Student *s4 = new Student("Dio");
//	Student *s5 = new Student("Jiorno");
    
    
	
}

void show(Student *list[],const int SIZE){
	for(int i=0;i<SIZE;i++){
		std::cout<<"Current student: "<<list[i]->get_name()<<std::endl;
		
		if(list[i]->get_prev_student()==nullptr)std::cout<<"prev null"<<std::endl;
		else std::cout<<"Prev: "<<list[i]->get_prev_student()->get_name()<<std::endl;
		
		if(list[i]->get_next_student()==nullptr) std::cout<<"next null"<<std::endl;
		else std::cout<<"Next: "<<list[i]->get_next_student()->get_name()<<std::endl;
	}
}

void show(Student * root){
    Student *p=root;
    while(p!=nullptr){
        std::cout<<p->get_name()<<std::endl;
        p=p->get_next_student();
    }
}














