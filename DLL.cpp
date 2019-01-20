			
		//  THE RESPECTED DOUBLE LINKED LIST....
	// ALSO FOR OUR GREAT MENTOR RESPECTED SUBHANKAR SIR...

	#include<iostream>
	using namespace std;
	
	// class for the double node......
	class Dnode{
		public:
		// has 3 types of data..
		int data;
		Dnode *next;
		Dnode *prev;
		// the default construction...
		Dnode(){
			next=NULL;
			prev=NULL;
		}
	};
	
	// class for dlll..
	class DLL{
		public:
		// has 1.head pointer
		// 	2.tail pointer..
		//	3. the default constructor..
		
		Dnode *head;
		Dnode *tail;
		DLL(){
			head=NULL;
			tail=NULL;
		};
		
		/* it some other functions like :-
			1.	inserting at last..
			2.inserting at a position
			3. deleting at last 
			4.deleting at a position
			5. display 
		*/
		
		// inserting at last
		void insert(int val){
			// make a new dnode in the the heap and access it from the STACK using a pointer ...temp i
			Dnode *temp=new Dnode;
			//STORE THE DATA;
			temp->data=val;
			// inserting
			if (head=NULL){
				head=temp;
				temp->next=NULL;
			}
			else{
				tail->next=temp;
				temp->next=NULL;
				temp->prev=tail;
			}
			tail=temp;
		}
		
		//inserting at a given position
		void insert(int pos,int val){
			//make the node
			Dnode *temp=new Dnode;
			//store the data
			temp->data=val;
			//now get the pointer to the one less position of the LL;
			Dnode *current=head;
			int i=1;
			while (i<pos-1){
				current=current->next;
				i++;
			}
			
			temp->next=current->next;
			//placing the back connection
			current->next->prev=temp;
			current->next=temp;
			temp->prev=current;
			
		}
	
	//DELETE AT LAST
	void DELETE(){
		// 1st store the tail...into temp;
		//get to the last position to be deleted
			Dnode *temp=tail;
			Dnode *current=tail->prev;
			tail->prev->next=NULL;
			delete temp;
			// update tail
			tail=current;
			
		}

		// delete at a position
		void DELETE(int pos){
			// go to the position 1 less to be DELETED
			int i=1;
			Dnode *current=head;
			while(i<pos-1){
				current=current->next;
				i++;
			}
			// store the Dnode to be deleted into a new pointer
			Dnode *temp=current->next;
			current->next=temp->next;
			temp->next->prev=current;
			// delete the temp
			delete temp;
		}
		
		// DISPLAY 
		void display(){
			Dnode *current=head;
			while(current->next!=NULL){
				cout<<current->data<<"->";
				current=current->next;
			}
			cout<<endl;
		}
	
	// COUNT THE ITEMS
	int count(){
		int i;
		Dnode *current=head;
		while(current->next!=NULL){
			current=current->next;
			i++;
		}
		cout<<" the total no of elements is :"<<i<<endl;
	}
	};
	
	// THE DRIVER FUNCTION
	int main(){
		DLL l1;
		l1.insert(1);
		l1.insert(2);
		l1.insert(3);
		l1.insert(4);
		l1.insert(5);
		l1.insert(6);
		l1.display();
		l1.count();
		l1.insert(2,10000);
		l1.DELETE();
		l1.DELETE(2);
		l1.display();
		l1.count();
	return 0;
	}

