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
};

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
	
return 0;
}
