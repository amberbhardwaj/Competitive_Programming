/******************************************************************************
Author: Amber Bhardwaj
Date: March 15th, 2021
*******************************************************************************/
#include <iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<memory>
using namespace std;
int count = 0;
mutex m1,m2;
condition_variable cond;
bool done()
{
    return count == 1;
}
bool pend()
{
    return count == 0;
}
void boss()
{
    while(1)
    {
        unique_lock<mutex> lock(m1);
        cout <<"BOSS\t"<< "Do the Work....\n" << endl;
        cond.notify_one();
        
        cout << "Mesg Sent, waiting.... \n";
        cond.wait(lock, done);
        cout << "=================WELL DONE================\n";
        count = 0;
        this_thread::sleep_for(1000ms);
    }
}
void worker()
{
    while(1)
    {
        unique_lock<mutex> lock(m1);
        cond.wait(lock, pend);
        cout <<"WORKER\t Got the Msg, Working..." << endl;
        count++;
        cond.notify_one();
        cout<< "finish Sir...\n";
        this_thread::sleep_for(1000ms);
    }
}

int main()
{
   // printf("Hello World");
    
    thread t1 (boss);
    thread t2 (worker);
    
    t1.join();
    t2.join();
    
    return 0;
}
