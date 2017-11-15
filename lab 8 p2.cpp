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
	NodeType* pre = NULL;
};

template <class ItemType>
class Queue
{
	private:
		NodeType<ItemType>* front;
		NodeType<ItemType>* rear;
		int element = 0;
	
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
			
			element++;
			
			if (element == 5)
			{
				break;
			}
			
			temp = new NodeType<ItemType>;
			
			prior->next = temp;
		
		}
	}
		
	void MakeEmpty()
	{
		delete front, rear;
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
		//need to finish
	}
	void Enqueue(ItemType x)   // Add an element
	{
		//need to finish
	}
	void dequeue(ItemType &x)// Removes the top element
	{
		//need to finish
	}
	~Queue()
	{
		//do nothing
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
		cout << "The int queue is not full!" << endl;
	else
		cout << "The int queue is full!" << endl;
	Queue<float>fq; //float queue
	float y;
	fq.MakeEmpty();
	fq.dequeue(y);
	fq.dequeue(y);
	cout << "Float length 3 =" << fq.length() << endl;
	fq.Enqueue(y);
	cout << "float length 3" << fq.length() << endl;
	fq.Enqueue(2.3);
	fq.Enqueue(2.3);
	cout << "float length 4" << fq.length() << endl;
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
