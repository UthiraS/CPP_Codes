
#include <iostream>
using namespace std;
#include<vector>
// fixed-size circular buffer that is used as a queue


//queue q ={f1,f2,f3,f4}
// push - add an element- first in first out
// pop - delete an element 
// size
// peek
class Queue
{ 
  
  public:
  
  //variables
  int size;
  int head;
  int capacity;
  vector<float> Queue_values;
  //functions
  Queue()
  {
    size =0;
    head =0;
  }
  Queue(int c)
  {
    capacity = c;
    size =0;
    head =0;
  }
   void push(float element);
   float pop();
   int display_size();
   float peek();

};

void Queue::push(float element)
{
 
  
  
  //  Queue_values.push_back(element);
  //  size++;
  //size >capcity, then call pop()
  //size <= capcity, just push
  std::cout<<"Inside push function"<<endl;
  std::cout<<element<<endl;
  if(size>=capacity)
  {
    float f = pop();   
    std::cout<<"calling pop inside push "<<f<<endl;
    Queue_values[head] = element;
    size++;
    std::cout<<"push :  first loop"<<endl;
    
  }
  else 
  if(size<capacity)
  {
   Queue_values.push_back(element);
   size++;
   std::cout<<"push :second loop"<<endl;
  }
 
}

float Queue::pop()
{
  // std::cout<<" Poped element :"<<Queue_values[head]<<endl;
  float result = Queue_values[head]; 
//   std::cout<<" Poped element :"<<result<<endl;
  if(head == (capacity-1))
  {
    head = head -(capacity-1);
  }
  else 
  {
  head++;
  }
  
  size--;
  return result;

}

int Queue::display_size()
{
  std::cout<<"Size :"<<size<<endl;
  return size;

}

float Queue::peek()
{
  std::cout<<" Poped element :"<<Queue_values[0]<<endl;
  
  return Queue_values[0];
}
// To execute C++, please define "int main()"
int main() 
{
  int cap = 3; //fixed size queue
  Queue Q = Queue(cap);
  Q.push(1.1);
  Q.push(2.2);
  Q.push(3.3);
  Q.push(4.4);
  float K = Q.pop();
  std::cout<<"popped element :"<<K<<endl;
  float L = Q.pop();
  std::cout<<"popped element :"<<L<<endl;
  float M= Q.pop(); 
  std::cout<<"popped element :"<<M<<endl;
  // std::cout<<"popped element :"<<K<<endl;
  return 0;
}