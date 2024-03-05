#include<iostream>
#include<string>
#include<cstdlib>
#include <opencv2/opencv.hpp>
#include<memory>
#include <random>
using namespace std;
using namespace cv;

// Random Class storing CV matrix to process image later 
class Matrix
{
    public:
      cv::Mat a;
      int pointer;

    Matrix()
    {
        a = cv::Mat::zeros(2,2,CV_8UC1);
    }

    // printfunction()
    // {
    //     std::cout<<a;
    // }
};



//Smart Pointer

class SmartPtr {
    int* ptr; // Actual pointer
public:
    // Constructor: Refer https:// www.geeksforgeeks.org/g-fact-93/
    // for use of explicit keyword
    explicit SmartPtr(int* p = NULL) { ptr = p; }
 
    // Destructor
    ~SmartPtr() { delete (ptr); }
 
    // Overloading dereferencing operator
    int& operator*() { return *ptr; }
};




int main()
{
    // //1. Calling three pointers using Smart Pointers

    // SmartPtr ptr1(new int());
    // SmartPtr ptr2(new int());
    // SmartPtr ptr3(new int());

    // *ptr1 = 20;
    // *ptr2 = 50;
    // *ptr3 = 17;

    // cout <<"Smart Pointer1 "<< *ptr1 << endl;
    // cout <<"Smart Pointer2 "<< *ptr2 << endl;
    // cout <<"Smart Pointer3 "<< *ptr3 << endl;
   
    // //2. Calling one Unique pointer using C++ standard functions
   
    // unique_ptr<int> uPtr(new int(20));
    
    // cout <<"Unique Pointer "<< *uPtr << endl;

    // //3. Calling Shared and Weak POinters using C++ standard functions
   
    // shared_ptr<int> sPtr = make_shared<int>(30);

    // // Creating a weak_ptr that points to the same integer
    // weak_ptr<int> wPtr = sPtr;

    // // Converting weak_ptr to shared_ptr to access the value
    // shared_ptr<int> temp = wPtr.lock();
    // if (temp) { // Check if the weak_ptr is valid
    //     cout <<"Check if Weak Pointer is Valid "<<*temp << endl;
    // }

    //1. Create CV mat using smart pointers and display them
    // Creating a cv::mat using unique pointer
    const int width = 512;
    const int height = 512;
    const int type = CV_8UC3; // 8-bit unsigned integers with 3 channels

    // Use a smart pointer to manage the memory for image data
    std::unique_ptr<uchar[]> data(new uchar[width * height * 3]);

    // Fill the data with random values
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    for (int i = 0; i < width * height * 3; ++i) {
        data[i] = static_cast<uchar>(dis(gen));
    }

    // Create a cv::Mat object using the smart pointer's data
    cv::Mat randomImage(height, width, type, data.get());

    // Display the image
    cv::imshow("Random Image", randomImage);
    cv::waitKey(0);
    return 0;

    //2. Create a array of smart pointers holding that class

    






}











