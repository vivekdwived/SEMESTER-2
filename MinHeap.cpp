		// the min heap
	#include<iostream>
	using namespace std;
	 
	/* rules for binnary tree
	- its a compleltey balanced tree
	- can be min or max
	Array IMplementatin
	root- A[0]
	parent node:Arr[(i-1)/2]
	left child : Arr[(2*i)+1]
	right child : Arr[(2*i)+2]
	
	functions are-getmin-extract MIn decreasekey- insert-delete- display
	*/
	
	class BinaryHeap
	{
		public:
		//pointer to array of elements
		int*hARR;
		//maximum possible size of array
		int mSize;
		//current size
		int cSize;
		
		// the PARAMETERIZED CONSTRUCTOR
		BinaryHeap(int msize){
		hARR=new int[mSize];
		this->mSize=mSize;
		cSize=0;	
		}
		
	// the swap function
	void swap(int *a,int *b){
		// Swap elements...
		int temp=*a;
		*a=*b;
		*b=temp;
	}
	
	// for an ith element of the array
	int parent(int i){return (i-1)/2;}
	int left(int i){return (i*2)+1;}
	int right(int i){return i*2+2;}
	
	// the member function to get the minimum element of the ARR
	int getMin(){return hARR[0];}
	// the insert function
	void insert(int value){
		// base case
		if(cSize==0)
		{
			hARR[0]=value;
			cSize++;
		}
		else if(cSize==mSize)
		{
			cout<<" can't insert anymore elements";
			return;
		}
		else
		{
			if(value<=hARR[0])
			{
				for(int i=cSize;i>0;i--)
				{
					hARR[cSize+1]=hARR[cSize];
				}
				hARR[0]=value;
			}
			else
			{
				hARR[cSize]=value;
			int x=cSize;
				while(hARR[parent(x)]>hARR[x] || parent(x)!=cSize/2)
				{
					int temp;
					temp = hARR[x];
					hARR[x] = hARR[parent(x)];
					hARR[parent(x)] = temp;
					x=parent(x);
				}				
			}
			cSize++;
		}
		
	}
	
	// the display function
	
	void display()
	{
		if(cSize==0)
		{
			cout<<"empty heap"<<endl;
			return;
		}
		for(int i=0;i<cSize;i++)
		{
			cout<<hARR[i]<<",";
		}
		cout<<endl;
	}
	

	};

int main()
{
	BinaryHeap b1;
	b1.display();
	for(int i=0;i<10;i++)
	{
		b1.insert(i+1);
	}
	b1.insert(5);
	b1.display();
	return 0;
}
