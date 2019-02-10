			// the stack of DREAMS USING LL
	#include<iostream>
	#include "LL.cpp"
	
	using namespace std;
	

	// we already have a class for NODE as LL...make the class for STACKS
	
	class STACK{
	public:
	node * top;			// pointer from stack to heap as top...temporary node...
	LL l1;				// declare the object of class NODE for 
	
				// the default constructor
	STACK(){
	top=NULL;
	}
	
	// to push a new node on top
	void push(int val){
	l1.insertAT(1,val);
	top=l1.head;			// modify the top
	}
	
	void pop(){
	l1.deletAt(1);
	top=l1.head;			// modify the head
	}
	
	// check whether empty or not  
	bool Empty(){
	if (top==NULL)	cout<<" the STACK OF DREAMS IS == EMPTY";
	else cout<<" stack of DREAms is FIlled";
	}
	
	// to find the size of stack..
	int size(){
	return l1.countItems();
	}

	void display(){
	l1.display();
	}
	
	};
	
	// DRIVER FUNCTION
	int main(){
	STACK s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.display();
	s1.pop();
	s1.display();
	
		
	return 0;
	}
