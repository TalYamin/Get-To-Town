//#include "Stack.h"
//
//Stack::Stack()
//{
//}
//
//void Stack::push(ItemType type)
//{
//	top++;
//	items.push_back(type);
//}
//
//ItemType Stack::pop()
//{
//	if (top <= 0) {
//		HandleError();
//	}
//	else {
//		int x = a[top--];
//		return x;
//	}
//}
//int Stack::peek()
//{
//	if (top < 0) {
//		cout << "Stack is Empty";
//		return 0;
//	}
//	else {
//		int x = a[top];
//		return x;
//	}
//}
//
//bool Stack::isEmpty()
//{
//	return top == 0;
//}
//
//// Driver program to test above functions
//int main()
//{
//	class Stack s;
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	cout << s.pop() << " Popped from stack\n";
//	//print all elements in stack :
//	cout << "Elements present in stack : ";
//	while (!s.isEmpty())
//	{
//		// print top element in stack
//		cout << s.peek() << " ";
//		// remove top element in stack
//		s.pop();
//	}
//
//	return 0;