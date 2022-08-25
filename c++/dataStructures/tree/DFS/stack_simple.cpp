#include <iostream>
#include <cstring>
using namespace std;

struct stack{
    string name;
    stack *next,*prev;
    
};

void show(stack * root){
    stack* point=root;
while(point){
    cout<<point->name<<" ";
    point=point->next;
}cout<<endl;
}
bool isNodeNull(stack * source){
    return source==nullptr;
}
stack * getLast(stack * root){
    stack* point=root;
    if(isNodeNull(point->next)){
        while(!isNodeNull(point->next)){
            point=point->next;
        }
    }
    
    return point;
}

void clearPrevNext(stack * node){
	node->prev->next=nullptr;
    
}

void clearPrev(stack * node){
    node->prev=nullptr;
}

void clearPointers(stack * node){
    clearPrevNext(node);
    clearPrev(node);
}

stack * pop_back(stack * root){
    
    stack* last = getLast(root);
    clearPointers(last);
    
    return last;
}
void append(stack * root,stack* source){
    stack * last = getLast(root);
    last->next=source;
    source->prev=last;
    source->next=nullptr;
    
}

void initStack(stack * root,string name){
    root->name=name;
    root->next=nullptr;
    root->prev=nullptr;
};

int main(){


stack *root = new stack;

stack *r1 = new stack;
stack *r2 = new stack;
stack *r3 = new stack;
stack *r4 = new stack;
stack *r5= new stack;

initStack(root,"ivan");
initStack(r1,"jojo");
initStack(r2,"dio");
initStack(r3,"jotaro");
initStack(r4,"jack");
initStack(r5,"hanma");

append(root,r1);
append(root,r2);
append(root,r3);
append(root,r4);
append(root,r5);
pop_back(root);


stack *r6= new stack;
initStack(r6,"wow");
append(root,r6);
pop_back(root);
pop_back(root);
show(root);





}










