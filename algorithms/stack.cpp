#include<iostream>
#include<vector>
#include<array>

#define MAX 1000
class Stack
{
    
 public:
    int arr[MAX];
    int top_pointer;
    // stack() constructor
    Stack()
    {
        top_pointer = -1;
    }
    // push() to insert an element into the stack
    void push(int value);
    // pop() to remove an element from the stack
    int pop();
    // top() Returns the top element of the stack.
    int top();
    // isEmpty() returns true if stack is empty else false.
    bool isEmpty();
    // size() returns the size of stack.
    int size();


    

};


void Stack::push(int value)
{
  if(top_pointer>MAX)
  {
    std::cout<<" Stack Overflow !!"<<std::endl;
  }
  else
  {
   arr[++top_pointer] = value;
  }
}

int Stack::pop()
{
 if(top_pointer<0)
  {
    std::cout<<" Stack Underflow !!"<<std::endl;
    return -1;
  }
  else
  {
   return arr[--top_pointer] ;
  }

}

int Stack::top()
{
  if(top_pointer<0)
 {
   return -1;
 }
 else
 {
    return arr[top_pointer];
 }
}

bool Stack::isEmpty()
{
 if(top_pointer<0)
 {
   return true;
 }
 else
 {
    return false;
 }
}

int Stack::size()
{
  return (top_pointer+1);
}

int main()
{
 Stack S= Stack();
 std::cout<<S.isEmpty()<<std::endl;
 S.push(1);
 S.push(2);
 S.push(3);
 std::cout<<S.isEmpty()<<std::endl;
 std::cout<<S.pop()<<std::endl;
 std::cout<<S.top()<<std::endl;
 std::cout<<S.size()<<std::endl;
}