#include<thread>
#include<iostream>
#include<string>
#include<cstdlib>
#include<mutex>
#include<chrono>
#include"semaphore.hpp"

// using namespace std;

float timee,angle;
std::mutex timee_angle_lock;
// std::counting_semaphore<1> prepareSignal(0);
binarySemp bS;

void fetchIMU()
{
    int i =0;
    while(i<5000)
    {
        timee_angle_lock.lock();
        timee =timee+1;
        //  int lb = 0, ub = 1; 
    
            // cout << (rand() % (ub - lb + 1)) + lb << " "; 
        //  angle = (rand() % (ub - lb + 1)) + lb;
        
        angle =angle + 2;
        std::cout << "fetchIMU: Data Fetch."  <<std::endl<<std::endl;
        timee_angle_lock.unlock();
        // std::cout<<" Data Generated!"<<std::endl;
        
        bS.release();
        std::chrono::milliseconds duration(20);
        std::this_thread::sleep_for(duration);
        i++;
        
    }
}

void printIMU()
{
    int i =0;
    while(i<5000)
    {
        bS.acquire();   
        timee_angle_lock.lock();
        std::cout<<"time :"<<timee<<std::endl;
        std::cout<<"angle :"<<angle<<std::endl;
        std::cout << "printIMU: Printing data." << std::endl<<std::endl;
        timee_angle_lock.unlock();
        i++;
        
    }
}


int main()
{

    std::thread t1(fetchIMU);
    std::thread t2(printIMU);

    t1.join();
    t2.join();


}