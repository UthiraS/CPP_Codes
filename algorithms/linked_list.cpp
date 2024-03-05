#include<iostream>
#include<vector>
#include<queue>

using namespace std;
//Singly linked Linked List

class Node{

 public:
   int value;
   Node* next;
  
   Node()
   {
    value =0;
    next = NULL;
   }

   Node(int value)
   {
    this->value = value;
    this->next = NULL;
   }
    

};

class LinkedList {

public:
   
    Node* head;
    int length;

    // will initialize an empty linked list.
    LinkedList() {

        head = NULL;
        length = 0;

    }
    // will return the value of the ith node (0-indexed). If the index is out of bounds, return -1.
    int get(int index) {
      int result;
      int i =0;
      int flag = 0;
      Node* ptr = head;   
      while (ptr!=NULL)  
        {  
            
            if(i==index)
            {
              result= ptr->value;
              flag = 1;
              break;
            }
            ptr = ptr -> next;  
            i++;
        }  
      
      if(flag ==0) 
      {
         result = -1;
      }
    return result;

    }
    // will insert a node with val at the head of the list.
    void insertHead(int val) {

          //create a new Node
      Node*  newNode =new Node(val);
      if (head != NULL)
       { 

        newNode->next = head;
       }

        head = newNode;         
        length++;
      

        
    }
    // will insert a node with val at the tail of the list.
    void insertTail(int val) 
    {
      // Node* ptr = head;   
      // int i =0;
      // while (ptr!=NULL)  
      //   {  
            
            
             
      //       ptr = ptr -> next;  
      //       i++;
           
      //   }  
      // std::cout<<i<<std::endl;
      // Node*  newNode =new Node(val);
      // ptr->next = newNode;
      Node* newNode = new Node(val);

    // Check if the list is empty
    if (head == NULL) {
        head = newNode;
    } else {
        Node* ptr = head;
        // Traverse to the end of the list
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        // Link the new node at the end
        ptr->next = newNode;
    }
    length++;
      

    }
    // will remove the ith node (0-indexed). If the index is out of bounds, return false, otherwise return true
    bool remove(int index) {
      
      
      int i =0;
      bool result;
      if(i>=length)
      {
        result = false;
      }
      Node* ptr = head;   
      while (ptr!=NULL)  
        {  
            
            if(i==index-1)
            {
             ptr= ptr ->next ->next;
             i++;
             result = true;
            }
            ptr = ptr -> next;  
            i++;
        }  

      
      return result;
        
    }
    // return an array of all the values in the linked list, ordered from head to tail.
    vector<int> getValues() {

      vector<int> result;
        
      Node* ptr = head;   
      while (ptr!=NULL)  
        {  
            
            result.push_back(ptr->value);
            ptr = ptr -> next;  
        }  
      
      return result;
    }
};

int main()
{

  LinkedList L1 = LinkedList();
  L1.insertHead(3);
  L1.insertTail(4);
  std::cout<<L1.get(4)<<endl;
  std::cout<<L1.remove(0)<<endl;
  vector<int> result = L1.getValues();
  for(auto x:result)
  {
    std::cout<<x<<" ";
  }
  std::cout<<std::endl;

}