#include<iostream>
#include<opencv2/opencv.hpp>
#include <random>
#include <string>

#define WIDTH 512
#define HEIGHT 512
#define TYPE CV_8UC3

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 255);

class smartImagePointer
{
    private:
    uint8_t *ip;

    public:
    smartImagePointer();
    ~smartImagePointer();
    void display();
    void getRawMemory();

};

smartImagePointer::smartImagePointer()
{
    ip = new uchar[HEIGHT*WIDTH*3];

    for (int i = 0; i < WIDTH * HEIGHT * 3; ++i) 
    {
        ip[i] = static_cast<uchar>(dis(gen));
    }

    std::cout<<"memory allocated\n";
}

// smartImagePointer::smartImagePointer(std::string file)
// {
//     ip = new uchar[HEIGHT*WIDTH*3];

//     for (int i = 0; i < WIDTH * HEIGHT * 3; ++i) 
//     {
//         ip[i] = static_cast<uchar>(dis(gen));
//     }

//     std::cout<<"memory allocated\n";
// }

smartImagePointer::~smartImagePointer()
{
    delete(ip);
    std::cout<<"deleted\n";
}

void smartImagePointer::display()
{
    cv::imshow("ramdom title", cv::Mat(HEIGHT, WIDTH, TYPE, ip));
    cv::waitKey(0);
}

int main()
{
    smartImagePointer sip[5];
    sip[3].display();

    return 0;
}