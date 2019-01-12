							// the linked list
			// 	TO STUDY LINLED LIST ..THINK  ABOUT CHEMICAL BONDS,
			//,,,as a group adds  to a diatomic molecule ...to become a triatomic molecule
	#include<iostream>
	using namespace std;
	
	//declare the data type having data as well as pointer
	class Node{
		public:
			// has data
			int data;
			//pointer to the next Node
			//NOTE THAT Node IS THE DATA TYPE HENCE POINTER SHOULD BE OF TYPE Node
			
			Node *next;
			
			// constructor that every next node  is initially  pointing to null 
			Node(){
				next =NULL;
			}	
	};
	
	//class for the data type Linkedlist
	class LinkedList{
		/* NOTE :
		it HAS NO   data as such...but SIMPLY ACCESSES FRON THE DATA TYPE NODE..
		.....BASICALLY NODE IS THE DATATYPE FOR LINKED LIST...so donot declare a data type but acces from the 
		class 
		NOTE 2: 
		it has a pointer
		 IT HAS JUST ONE VARIABLE
		 THIS HEAD IS A BASICALLY A POOINTER TO NUll
		
		
		steps are :
		1. declare HEAD in the linkedf list ...pointing to the NULL
		2. then add 1st loop ...then add 2nd loop...
		3..so on
		*/
		public:	
				//step 1
			Node *head;
			Node *tail;
		// the default constructor as head=tail=null at beginning
		LinkedList(){
			head=NULL;
		tail=NULL;
		}
		//	insert the first node
		void insert(int val){
			Node *temp=new Node;
			//insert the value in the node
			temp->data=val;
			
			//1st node only 
			if (head=NULL){
				head=temp;
			}
			else{
				tail->next=temp;
			}
			tail=temp;
		
		}
	
	//insert node at a position and given value
	void insertAT(int pos,int val){
		
		/* steps:
		1. declare a pointer temp to a new node 
		2. use counting variable as current to get to that position of node
		4. then chande the pointers properly
		*/
		Node *temp;
		temp->data=val;
		//  now get the pointer to a new position
		Node *current=head;
		int i =1;
		while (i<(pos-1)){
			current=current->next;
		}
		// SHIFTING THE POINTERS....
		temp->next=current->next;
		current->next=temp;
	}
	// for the 1st position
		 
		void insert_AT_ONE(int val){
			// make a new NOde
			Node *temp=new Node;
			//insert the value to the new node
			temp->data=val;
			//point the new node to the 2nd node
			temp=head;
			// REMOVE THE BOND OF head to  
			head=temp;
		}		
		
	// DELETE FUNCTION OF A LINKEDLIST...
	void DELETE(){
			// STEPS :
		//	1. first get current pointer to last;
		Node *current=head;
		int i=0;
		while(current ->next!=NULL){
			current=current->next;
		}
		//	3. then store the last node in the temp..temporary pointer;
		Node *temp=current->next;
		//	4. then make the last 2nd node point to null;
		current=temp;
		//	5. then delete the temp;
			
			delete temp;
	}

	// DISPLAY FUNCTION OF LINKED LIST;
	void display(){
		cout<< " the LINKED LIST FORMED IS --->"<<endl;
		Node *current=head;
		cout<<current->data<<"->";
		current=current->next;
		cout<<endl;
	}
	

	// delete at the position ..
	void DELETE(int pos){
		//  1st get the current pointer to the required pos. using while loop
		Node *current=head;
		int i=1;
		while(i<(pos-1)){
			current =current->next;
			i++;
		}
				// store this current pointer into another pointer INITIAL_CURRENT as we need it later;
		Node *initial_current=current;
				// if we want to remove pos=3...then right now current is pointing to position=2..means one less
				// now store the position 3 which is next to the current [position 2] IN TEMP...
		Node *temp=current->next;
				// NOW INCREASE VALUE OF CURRENT POSITION [ MAKE CURRRENT=3 ]
		current=current->next;
				// SO THAT WE WILL GET THE NEXT ELEMENT AS position 4==( current->next)
		
				//now we transfer THE POINTER OF INITIAL_CURRENT TO ...CURRENT_future...
		initial_current=current;
				//then remove the required position..3 which is between..2 and 4..
		delete temp;
		}

	//  	COIUNTING FUNCTION OF THE LINKEDLIST
	int countItems(){
		int i=1;
		Node *current=head;
		while(current->next!=NULL){
			current=current->next;
			i++;
		}
		return i;
	}	
			
	
};
	
	int main(){
		LinkedList l1;
		l1.insert(1);
		l1.insert(2);
		l1.insert(3);
		l1.insert(4);
		
		l1.display();
		cout<<"no. of elements in YOUR LINKED LIST IS"<<l1.countItems()<<endl;
		
		l1.DELETE(2);
		l1.DELETE();
		l1.display();
		l1.insertAT(2,16);
		l1.display();
		
		return 0;
	
	}

