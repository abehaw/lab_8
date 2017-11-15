#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <sstream>

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
			else
			{
				cout << "There are no elements to pop" << endl;
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
	ofstream outFile;
	outFile.open ("log.txt");
	outFile << "**************************beginning of program*******************************";
	
	float i, j;
	int length;
	ifstream inFile, filestr;
	string infilename, str;
	
	//requesting file from the user
	//*****************file validation*******************************************file validation***************************
	//*****************file validation*******************************************file validation***************************
	cout << "Hello, Please enter the file name contaning integers: " << flush;
    getline(cin, infilename);
    outFile << "Prompted user for file name (contaning data) to open";
	
	inFile.open(infilename.c_str());
    filestr.open(infilename.c_str(), ios::binary); // open same file
	filestr.seekg(0, ios::end); // put the "cursor" at the end of the file
	length = filestr.tellg(); // find the position of the cursor
	
	outFile << "attempting to open the file and check if file was empty or does not exist";

	while(true)
	{
		//if the file failed to open/ doesn not exsist reprompt for file name
		if(!ifstream(infilename.c_str()) || length == 0)
		{
			inFile.close();
			filestr.close();
			cout << "This file does not exist or empty. Please enter a file name: ";
			outFile << "file provided does not exist. File provided:" << infilename.c_str();
			getline(cin, infilename);
			inFile.open(infilename.c_str());
			filestr.open(infilename.c_str(), ios::binary); // open your file
			filestr.seekg(0, ios::end); // put the "cursor" at the end of the file
			length = filestr.tellg(); // find the position of the cursor
		}
		//no issues send feedback to the user
		else
		{
			cout << "File processed suscessfuly." << endl << endl;
			outFile << "File processed suscessfuly. File: " << infilename.c_str();
			break;
		}
	}
	//*****************end of file validation*******************************************end of file validation***************************
	//*****************end of file validation*******************************************end of file validation***************************
	
	Stack<string> stackOne;
	Queue<string> queueOne;
	while (inFile >> str)
	{
		stackOne.push(str);
		queueOne.Enqueue(str);
		
	}	
	
	outFile << "reading file and storing data in a stack";
	//*****************end of part one*******************************************end of part one***************************
	//*****************end of part one*******************************************end of part one***************************
	//*****************end of part one*******************************************end of part one***************************
	//*****************end of part one*******************************************end of part one***************************
	
	Stack<int> s;//stack
	outFile << "\ncrating a new instence of stacks";
	int x;
	s.pop(x);
	outFile << "\nremoving a value";
	s.push(11);
	s.push(22);
	outFile << "\npush two values";
	cout << "int length 1 = " << s.length() << endl;
	outFile << "\nresquesting length " << s.length(); 
	s.pop(x);
	outFile << "\nremoved value";
	s.push(33);
	outFile << "\nadded value";
	cout << "int length 2 = " << s.length() << endl;
	outFile << "\nrequested lenght " << s.length();
	cout << "The int stack contains: " << endl;
	s.print();
	outFile << "\nprinting the stack";
	s.push(44);
	s.push(55);
	s.push(66);
	outFile << "\npushed 3 items";
	s.print();
	outFile << "\nprinted stack";
	if (s.isFull() == false)
		cout << "\nThe stack is not full!" << endl;
	else
		cout << "\nThe stack is full!" << endl;
	outFile << "\nrequested stack status. isFull: " << s.isFull();
	
	Stack <int> s2(s);
	outFile << "\nnew instence declared";
	cout << "The stack 2 contains: " << endl;
	s2.print();
	outFile << "\nprinted stack values";
	s2.MakeEmpty();
	outFile << "\ndeleted all values in stack";
	cout << "\nThe stack 2 contains: " << endl;
	s2.print();
	outFile << "\nprinted stack values";
	
	Stack <float> fs;//float stack
	outFile << "\ncreated new float instence";
	float y;
	fs.pop(y);
	outFile << "\nremoved value";
	fs.push(7.1);
	outFile << "\nadded value to the stack";
	cout << "\nfloat length 1 = " << fs.length() << endl;
	fs.push(2.3);
	fs.push(3.1);
	outFile << "\nadded two value to the stack";
	cout << "\nfloat length 2 = " << fs.length() << endl;
	fs.pop(y);
	outFile << "\nremoved a value from the stack";
	cout << "\nThe float stack contains: " << endl;
	fs.print();
	outFile << "\nprinted the values in the stack";
	Stack <float> fs2 = fs;
	outFile << "\nsetting stacks equal to each other";
	fs2.print();
	cout << endl << "*****************A defect happened here!!!***********************" << endl;
	outFile << "\nprinted stack values";
	cout << "\nThe float stack 2 contains: " << endl;
	fs2.print();
	cout << endl << "*****************A defect happened here!!!***********************" << endl;
	outFile << "\nprinted stack values";
	fs.MakeEmpty();
	outFile << "\ndeleting all values in stack";
	cout << "\nThe float stack 3 contains: " << endl;
	fs2.print();
	cout << endl << "*****************A defect happened here!!!***********************" << endl;
	outFile << "\nprint values in stack";
	//*******************************************************************
	//*******************************************************************
	//*******************************************************************
	//*******************************************************************
	//*******************************************************************
	//*******************************************************************
	Queue<int> iq;//integer queue
	outFile << "\ndeclaring a queue";
	iq.MakeEmpty();
	outFile << "\ndeleted all values from queue";
	iq.dequeue(x);
	outFile << "\nremoved value from queue";
	iq.Enqueue(10);
	iq.Enqueue(20);
	iq.Enqueue(30);
	iq.Enqueue(40);
	outFile << "\nadded values to queue";
	cout << "int length 3 = " << iq.length() << endl;
	iq.dequeue(x);
	outFile << "\nremoved value from queue";
	cout << "int length 4 = " << iq.length() << endl;
	cout << "The int stack contains: " << endl;
	iq.print();
	outFile << "\nprinting the values in the queue";
	if (iq.isFull() == false)
		cout << "\nThe int queue is not full!" << endl;
	else
		cout << "\nThe int queue is full!" << endl;
	outFile << "\nrequested values in queue";
		
	Queue<float>fq; //float queue
	fq.MakeEmpty();
	outFile << "\ndeleting all values in queue";
	fq.dequeue(y);
	fq.dequeue(y);
	outFile << "\nremoveing two values from queue";
	cout << "Float length 3 = " << fq.length() << endl;
	fq.Enqueue(y);
	outFile << "\nadding value to the queue";
	cout << "float length 3 = " << fq.length() << endl;
	fq.Enqueue(2.3);
	fq.Enqueue(2.3);
	outFile << "\nadding two values to the queue";
	cout << "float length 4 = " << fq.length() << endl;
	fq.Enqueue(3.1);
	fq.dequeue(y);
	outFile << "\nadded and removed values from the queue";
	cout << "The float queue contains: " << endl;
	fq.print();
	outFile << "\nprinting values in queue";
	
	Queue<float> fq2 = fq;
	outFile << "\ncreating new instence";
	cout << "The float queue 2 contains: " << endl;
	fq2.print();
	outFile << "\nprinted values to the user";
	cout << endl << "*****************A defect happened here!!!***********************" << endl;
	fq.MakeEmpty();
	outFile << "\ndeleting all values in queue";
	cout << "The float queue 2 contains: " << endl;
	fq2.print();
	outFile << "\nprinting all values in queue";
	cout << endl << "*****************A defect happened here!!!***********************" << endl;
	//**********************************************************************************************
	//*************************end of program portion***********************************************
	//**********************************************************************************************
	//*******************************programmer test portions***************************************
	//**********************************************************************************************
	string g;
	//testing stacks and que with same data
	Stack<string> stack4(stackOne);
	Queue<string> queue4(queueOne);
	
	cout << "after overloaded constructor print: " << endl;
	stack4.print();
	queue4.print();
	
	stack4.pop(g);
	queue4.dequeue(g);
	
	cout << "after pop print: " << endl;
	stack4.print();
	queue4.print();
	
	stack4.MakeEmpty();
	queue4.MakeEmpty();
	
	cout << "after make empty print: " << endl;
	stack4.print();
	queue4.print();
	
	
	//*************************************************************************
	outFile << "\n***********************end of program********terminating****************";
	//*************************************************************************
	outFile.close();
	return 0;
}
