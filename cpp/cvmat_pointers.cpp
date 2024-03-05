#include<iostream>
#include<string>
#include<cstdlib>
#include<opencv2/opencv.hpp>
#include<memory>
#include <random>
using namespace std;
using namespace cv;

// Defining Global Variables
// Image dimensions and color channel
const int width = 512;
const int height = 512;
const int type = CV_8UC3;

// functiosn and variables for generating an image using a random uniform distribution

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 255);


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

class smartImagePointer
{
    public:
    uchar* iP;

    explicit smartImagePointer(uchar* iPval = NULL)
    {
        iP = iPval;
    }
    

    ~smartImagePointer()
    {
        delete (iP);

    }




    cv::Mat create_Image_Pointer(uchar * iPval)
    {

        // std::unique_ptr<uchar[]> data(new uchar[width * height * 3]);
        // iP = new uchar[width * height * 3];
        
        for (int i = 0; i < width * height * 3; ++i) 
        {
            iPval[i] = static_cast<uchar>(dis(gen));
        }
        cv::Mat randomImage(height, width, type, iPval);

        return randomImage;

           
    
    }
    int display_Image_Pointer(cv::Mat randomImage)
    {

        cv::imshow("Random Image", randomImage);
        cv::waitKey(0);
        return 0;   
    
    }

};


int main()
{
   
    // creating a smart pointer trial 1
    // Create an instance of smartImagePointer
    smartImagePointer SIP = smartImagePointer(new uchar());
    SIP.iP = new uchar[width * height * 3];
    cv::Mat r= SIP.create_Image_Pointer(SIP.iP);
    SIP.display_Image_Pointer(r);
    std::cout<<" Done! "<<endl;

    


    






}











