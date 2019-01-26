	 		// THE GREAT CIRCULAR LINKED LIST
	#include<iostream>
	using namespace std;
	
	// create the node datatype for the CLL
	
	class cnode{
		public:
		// has 2 pointers and one data
		int data;
		cnode *next;
		cnode *prev;
		
		// the default constructor
		cnode(){
			next=NULL;
			prev=NULL;
		}	
	
	};
	
	// the CLL
	class CLL{
		public:
		// has head + tail = head is joined to the tail
		cnode *head;
		cnode *tail;
		// default constructor
		CLL(){
			head=NULL;
			tail=NULL;
			
		}
	
		/* some other functions in CLL  like	1.INSERT at last
												2. insert at any position
												3. delete from last
												4. delete at position
												5. counting the elements
												6. displaying the data		*/
		
		// insert at last;
		void insert(int val){
			cnode *temp= new cnode;
			temp->data=val;
			
			if(head=NULL){
				head=temp->prev;
			} 
		
		else{
			tail->next=temp->prev;
			temp->prev=tail->next;
		}
		//update tail
		tail=temp;
		tail->next=head;
		}
		
		//insert at any position 
		void insertAt(int pos,int val){
			// make a new cnode in HEAP and declare a pointer temp for it and add data to it
			cnode* temp=new cnode;
			temp->data=val;
			// declare a current pointer to point to current cnode
			cnode*current=head;
			// then move to one pos-1..which will be your current
			int i=1;
			while(i<pos-1){
				current=current->next;
				i++;
			}
						// then add temp cnode just after current;

			temp->next=current->next;
			current->next->prev=temp->next;
			current->next=temp->prev;
			temp->prev=current->next;
			
		}
			
		// DISPLAY THE FUNCTION DATATATATATTAAT;
		void display(){
			cnode*current=new cnode;
			current=head;
			while(current->next!=head){
				cout<<current->data;
				current=current->next;
			}
		}	
	
		//DELETE AT LAST
		void DELETE(){
			// get the current pointer to the tail
			cnode*current=head;
			while(current->next->next!=head){
				current=current->next;
			}
			//store tail into other pointer
			cnode*temp=tail;
			// make the connectios and delete the required
			current->next=head->prev;
			head->prev=current->next;
			//delete the temp
			delete temp;
			// update tail
			tail=current;
		}
		
		//deleting at a position
		void DELETE(int pos){
			// get a new poiner 
					cnode*current=head;
					int i=0;
			while(i<pos-1){
				current=current->next;
				i++;
			}
			//store tail into other pointer
			cnode*temp=current->next;
			// make the connectios and delete the required
			current->next->next->prev=current->next;
			current->next=current->next->next;
			
			//delete the temp
			delete temp;
		}
		
		//count the no of cnodes
		void count(){
			int i=0;
			cnode*current=new cnode;
			current=head;
			while(current->next!=head){
				cout<<current->data;
				current=current->next;
				i++;
			}
			cout<<"total no. of n=cnodes is :"<<i<<endl;
		}
	};
	
	int main(){
		CLL l1;
		l1.insert(1);
		l1.insert(2);
		l1.insert(3);
		l1.insert(4);
		l1.insert(5);
		l1.display();
		l1.count();
		l1.insertAt(2,16);
		l1.DELETE(2);
		l1.DELETE();
		l1.count();
	return 0;
	}
