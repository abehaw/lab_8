//Program Name: template class stack
//Programmer Name: Chris Josebalan
//Description: implementing class stack
//Date Created: 11/9/17
 
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
using namespace std;
 
template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType* next;
};
 
template <class ItemType>
class Stack 
{
	private:
		NodeType<ItemType>* topPtr;
	
	public:
		Stack();
		Stack(const Stack<ItemType>&x);
		void MakeEmpty();
		bool isEmpty();
		bool isFull();
		int length();
		void print();
		void push(ItemType x);   // Add an element
		void pop(ItemType &x);   // Removes the top element
		~Stack()
		{
			//do nothing
		}
};
// 
//template <class ItemType>
//void Stack<ItemType>::push(ItemType x)
//{
//              elements.push_back(element);
//}
// 
//template <class ItemType>
//void Stack<ItemType>::pop(ItemType &x)
//{
//              if (elements.empty())
//                           throw std::out_of_range("Stack is empty");
//              else
//                           elements.pop_back();
//}
// 
////Description: Used to display values inside the stack
////pre-condition:
////post-condition:Called in main to display values inside the stack
//template <class ItemType>
//void Stack<ItemType>::print()
//{
//              return elements.print();
//}
// 
//template <class ItemType>
//int Stack<T>::length()
//{
//              return elements.size();
//} 
 
int main()
{
	/*Stack<int> s;//stack
	int x;
/*	s.pop(x);
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
	if (s.isFull() == false)
		cout << "The stack is not full!" << endl;
	else
		cout << "The stack is full!" << endl;
	Stack <int> s2(s);
	cout << "The stack 2 contains: " << endl;
	s2.print();
	//s2.makeEmpty();
	cout << "The stack 2 contains: " << endl;
	s2.print();
	
	Stack <float> fs;//float stack
	float y;
	fs.pop(y);
	fs.push(7.1);
	cout << "float length 1 = " << fs.length() << endl;
	fs.push(2.3);
	fs.push(3.1);
	cout << "float length 2 = " << fs.length() << endl;
	fs.pop(y);
	cout << "The float stack contains: " << endl;
	fs.print();
	Stack <float> fs2 = fs;
	cout << "The float stack 2 contains: " << endl;
	fs2.print();
	fs.MakeEmpty();
	cout << "The float stack 3 contains: " << endl;
	fs2.print();*/
	
return 0;
}
