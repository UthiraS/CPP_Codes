#include <iostream>
#include <array>

using namespace std;

class DynamicArray {

private:
int length;
int capacity;
int* arr;

public:
    // will initialize an empty integer array with a capacity of capacity, where capacity > 0 and of length 0.
    DynamicArray(int capacity) {
        length =0;
        this->capacity= capacity;
        arr = new int[capacity];

    }
    // will return the element at index i. Assume that index i is valid.
    int get(int i) {

        int result = arr[i];
        return result;

    }
    // will set the element at index i to n. Assume that index i is valid
    void set(int i, int n) 
    {
        arr[i]= n;
    }
    //  will push the element n to the end of the array.
    void pushback(int n) 
    {
        // int i =0;
        // //printing all elemnets from start
        // while(i<length)
        // {
        //     std::cout<<arr[i]<<" ";
        //     i++;
        // }
        if(length<=capacity)
        {
            resize();
        }
        arr[length]= n;
        length++;

    }
    // will pop and return the element at the end of the array. Assume that the array is non-empty.
    int popback() 
    {
        if(length>0)
        {
            length--;
        }
        return arr[length];

    }
    // will double the capacity of the array.
    void resize() 
    {
       int *arr2 = new int[capacity*2];
       for(int j =0;j<capacity;j++)
       {
        arr2[j] = arr[j];
       }
        arr=arr2;
        delete arr;

    }
    //  will return the number of elements in the array.
    int getSize() {

        return (length);

    }
    // will return the capacity of the array
    int getCapacity() {

        return capacity;

    }
};

int main()
{
//   DynamicArray DA(2) ; // initalizing object DA with parameterized constructor way 1
  DynamicArray DA = DynamicArray(5) ; // initalizing object DA with parameterized constructor way 2
  DA.pushback(3);
  DA.pushback(4);
  std::cout<<"Capacity :"<<DA.getCapacity()<<std::endl;
  std::cout<<"Length :"<<DA.getSize()<<std::endl;
  DA.set(0,1);
  DA.set(1,-10);
  std::cout<<DA.popback()<<std::endl;
}
