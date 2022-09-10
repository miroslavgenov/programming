#include <iostream>
using namespace std;

void b(int a[],int l,int r,int v){

	if(l<=r){
		int m=(l+r)/2;

		if(a[m]==v) {
			cout<<a[m]<<" "<<"found"<<endl;
			return;
		}
		else if(a[m]<v){
			b(a,m+1,r,v);
		}
		else if(a[m]>v){
			b(a,l,m-1,v);
		}
	}
	else{
		return;
	} 
	
	
}

void bs1(int a[],int l,int r,int v){
	cout<<"left= "<<l<<" right= "<<r<<endl;
	if(l<=r){
		cout<<"l<=r "<<l<<" <="<<r<<endl;
		int mid=(l+r)/2;
		cout<<"mid: "<<mid<<endl;
		cout<<"a[mid]= "<<a[mid]<<endl;
		cout<<"v= "<<v<<endl;
		if(a[mid]==v){
			cout<<a[mid]<<" == "<<v<<endl;
			return;
		}else if(a[mid]<v){
			
			cout<<a[mid]<<" < "<<v<<endl;
			bs1(a,mid+1,r,v);
		}else if(a[mid]>v){
			cout<<a[mid]<<" > "<<v<<endl;
			bs1(a,l,mid-1,v);
			
		}
	}
	else{

		cout<<"else l>=r "<<l<<" >="<<r<<endl;
		return;
	}
}


int main(){
    int a[]={0, 1,1 ,2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int s = sizeof(a)/sizeof(*a);
	int sn=455;
	
		
		// b(a,0,(0+s)/2,s,sn);
	// bs1(a,0,s-1,sn);
	// b(a,0,s-1,sn);
	
	
	
	
}




























































