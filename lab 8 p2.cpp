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
 
 
int main()
{
	Queue<int> iq;//integer queue
	int x;
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
	float y;
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
