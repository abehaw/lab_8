#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType* next = NULL;
	NodeType* prev = NULL;
};
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
template <class ItemType>
class Stack
{
	private:
		NodeType<ItemType>* topPtr;
		int elmtNum;
	 
	public:
		Stack()
		{
			elmtNum = 0;
		}
		Stack(Stack<ItemType> &x)
		{
			elmtNum = 0;
			NodeType<ItemType>* temp;
			NodeType<ItemType>* pre;
			NodeType<ItemType>* temp2;
			temp2 = x.topPtr;
			
			/*cout << endl << "testing someting" << endl << endl;
			while(temp2 != NULL)
			{
				cout << temp2->info << endl;
				temp2 = temp2->next;
			}*/
			temp = new NodeType<ItemType>;
			topPtr = temp;
			
			while(temp2 != NULL)
			{
				//cout << endl <<"********" << temp2->info << endl;
				temp->info = temp2->info;
				pre = temp;
				
				temp2 = temp2->next;
				
				elmtNum++;
				
				/*if(elmtNum == 6) //un-needed statement
				{
					cout << "More then 5 elements were provided." << endl;
					cout << "only the first 5 elements will be stored" << endl;
				}*/
				
				if(elmtNum == 5)
				{
					break;
				}
				
				temp = new NodeType<ItemType>;
				
				pre->next = temp;
				
			}
		}
		void MakeEmpty()
		{
			delete topPtr;
			topPtr = NULL;
			elmtNum = 0;
		}
		bool isEmpty()
		{
			if(elmtNum == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool isFull()
		{
			if(elmtNum >= 5)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int length()
		{
		    return elmtNum;
		}
		void print()
		{
			NodeType<ItemType>* temp;
			temp = topPtr;
			cout << "\nThe elements in side the stack are:";
			while(temp!=NULL)
		    {
		    	//push back onto the vector the letter inside the node
			    cout << endl << temp->info;
			    //get the next node
		        temp=temp->next;
		    }
		}
		void push(ItemType x)   // Add an element
		{
			if(elmtNum <= 5)
			{
				if(elmtNum == 0)
				{
					NodeType<ItemType>* temp;
					temp = new NodeType<ItemType>;
					temp->info = x;
					temp->next = NULL;
					topPtr = temp;
					elmtNum++;
				}
				else
				{
					NodeType<ItemType>* pre;
					NodeType<ItemType>* temp;
					temp = topPtr;
					
					while(temp!= NULL)
					{
						pre = temp;
						temp = temp->next;
					}
					
					temp = new NodeType<ItemType>;
					temp->info = x;
					temp->next = NULL;
					pre->next = temp;
					elmtNum++;
				}
			}
			else
			{
				cout << "The stack is full and can not contain more elements." << endl;
			}
		}
		void pop(ItemType &x)   // Removes the top element
		{
			if(elmtNum != 0)
			{
				NodeType<ItemType>* pre;
				NodeType<ItemType>* temp;
				temp = topPtr;
				
				while(temp->next != NULL)
			    {
			    	pre = temp;
				    //get the next node
			        temp=temp->next;
			    }
			    
			    pre->next = NULL;
			    elmtNum--;
			    
			    delete temp;
			    temp = NULL;
			}
		}
		~Stack()
		{
			//do nothing
		}
};
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
template <class ItemType>
class Queue
{
	private:
		NodeType<ItemType>* front;
		NodeType<ItemType>* rear;
		int element;
	
	public:
		Queue()
		{
			element = 0;
		}
		Queue(const Queue<ItemType>&x)
		{
			element = 0;
			NodeType<ItemType>* temp;
			NodeType<ItemType>* prior;
			NodeType<ItemType>* temp2;
			temp2 = x.front;
			
			
			temp = new NodeType<ItemType>;
			front = temp;
			
			while (temp2 != NULL)
			{
			
				temp->info = temp2->info;
				prior = temp;
				
				temp2 = temp2->next;
				
				rear = temp;
				
				element++;
				
				if (element == 5)
				{
					break;
				}
				
				temp = new NodeType<ItemType>;
				
				prior->next = temp;
				temp->prev = prior;
			
			}
		}
			
		void MakeEmpty()
		{
			front = NULL;
			rear = NULL;
			element = 0;
		}
		
		bool isEmpty()
		{
			if (element == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool isFull() //assume MaxItem is equal to 5
		{
			if (element >= 5)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int length()
		{
			return element;
		}
		void print()
		{
			NodeType<ItemType>* temp;
			temp = front;
			cout << "\nThe elements in side the stack are:";
			while(temp!=NULL)
		    {
		    	//push back onto the vector the letter inside the node
			    cout << endl << temp->info;
			    //get the next node
		        temp=temp->next;
		    }
		}
		void Enqueue(ItemType x)   // Add an element
		{
			//add to the back of the list
			if(element <= 5)
			{
				if(element == 0)
				{
					NodeType<ItemType>* temp;
					temp = new NodeType<ItemType>;
					
					temp->info = x;
					
					temp->next = NULL;
					
					front = temp;
					element++;
				}
				else
				{
					NodeType<ItemType>* pre;
					NodeType<ItemType>* temp;
					temp = front;
					
					while(temp!= NULL)
					{
						pre = temp;
						temp = temp->next;
					}
					
					temp = new NodeType<ItemType>;
					
					temp->info = x;
					
					temp->next = NULL;
					pre->next = temp;
					
					temp->prev = pre;
					element++;
				}
			}
			else
			{
				cout << "The stack is full and can not contain more elements." << endl;
			}
			
		}
		void dequeue(ItemType &x)
		{
			// Removes the first element
			NodeType<ItemType>* temp;
			
			if(element == 0)
			{
				cout << "There are no elements to remove" << endl;
			}
			else if(element == 1)
			{
				MakeEmpty();
			}
			else
			{
				NodeType<ItemType>* first;
				NodeType<ItemType>* second;
				
				first = front;
				
				second = first->next;
				second->prev = NULL;
				
			    front = second;
			    first->next = NULL;
			    
			    delete first, second;
			    first = NULL;
			    second = NULL;
			}
		}
		~Queue()
		{
			delete rear;
			delete front;
			rear = NULL;
			front = NULL;
		}
};
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
int main()
{
	Stack<int> s;//stack
	int x;
	s.pop(x);
	s.push(11);
	s.push(22);
	cout << "int length 1 = " << s.length() << endl;
	s.pop(x);
	s.push(33);
	cout << "int length 2 = " << s.length() << endl;
	cout << "The int stack contains: " << endl;
	s.print();
	s.push(44);
	s.push(55);
	s.push(66);
	s.print();
	if (s.isFull() == false)
		cout << "\nThe stack is not full!" << endl;
	else
		cout << "\nThe stack is full!" << endl;
	Stack <int> s2(s);
	cout << "The stack 2 contains: " << endl;
	s2.print();
	s2.MakeEmpty();
	cout << "\nThe stack 2 contains: " << endl;
	s2.print();
	
	Stack <float> fs;//float stack
	float y;
	fs.pop(y);
	fs.push(7.1);
	cout << "\nfloat length 1 = " << fs.length() << endl;
	fs.push(2.3);
	fs.push(3.1);
	cout << "\nfloat length 2 = " << fs.length() << endl;
	fs.pop(y);
	cout << "\nThe float stack contains: " << endl;
	fs.print();
	Stack <float> fs2 = fs;
	fs2.print();
	cout << "\nThe float stack 2 contains: " << endl;
	fs2.print();
	fs.MakeEmpty();
	cout << "\nThe float stack 3 contains: " << endl;
	fs2.print();
	//*******************************************************************
	//*******************************************************************
	//*******************************************************************
	//*******************************************************************
	//*******************************************************************
	//*******************************************************************
	Queue<int> iq;//integer queue
	iq.MakeEmpty();
	iq.dequeue(x);
	iq.Enqueue(10);
	iq.Enqueue(20);
	iq.Enqueue(30);
	iq.Enqueue(40);
	cout << "int length 3 = " << iq.length() << endl;
	iq.dequeue(x);
	cout << "int length 4 = " << iq.length() << endl;
	cout << "The int stack contains: " << endl;
	iq.print();
	if (iq.isFull() == false)
		cout << "\nThe int queue is not full!" << endl;
	else
		cout << "\nThe int queue is full!" << endl;
		
	Queue<float>fq; //float queue
	fq.MakeEmpty();
	fq.dequeue(y);
	fq.dequeue(y);
	cout << "Float length 3 = " << fq.length() << endl;
	fq.Enqueue(y);
	cout << "float length 3 = " << fq.length() << endl;
	fq.Enqueue(2.3);
	fq.Enqueue(2.3);
	cout << "float length 4 = " << fq.length() << endl;
	fq.Enqueue(3.1);
	fq.dequeue(y);
	cout << "The float queue contains: " << endl;
	fq.print();
	
	Queue<float> fq2 = fq;
	cout << "The float queue 2 contains: " << endl;
	fq2.print();
	fq.MakeEmpty();
	cout << "The float queue 2 contains: " << endl;
	fq2.print();
	
	return 0;
}
