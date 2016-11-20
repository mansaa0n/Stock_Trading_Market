//
//  main.cpp
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/1/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "stock.h"
#include "person.cpp"
#include <random>
#include "STOCKCLASS.h"

using namespace std;


// globle variables
int i = 0;
int transactions; // incremnt trans when ever b/s in man thread
mutex stockLock;  // protects i


string RandomStock(int len)
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int pos;
    while(str.size() != len) {
        pos = ((rand() % ((str.size() - 1))));
        str.erase (pos, 1);
    }
    return str;
}

double RandPrice(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void man_BS_thread()
{
    
    
    lock_guard<mutex> lock(stockLock);  //  stocklock
    ++i;
    
       cout << this_thread::get_id() << ": " << i << '\n' << stockName <<" $"<< price <<'\n';
    
    // i mutex is automatically released when lock goes out of scope
}
void stock_manager_thread()
{
           string name;
    int    share;
    double price_per_share;
    
    // thread goes here
    
}



int main()
{
    vector <> STOCKS;
    
    for (int i =0; i < 10; i++)
    {
    string [i]stockName = RandomStock(3);
    double [i]price = RandPrice(10, 50);
    STOCKS.pushback(
    }
    
    
    

     cout << __func__ << ": " << i << '\n';
    
    thread t1(man_BS_thread);
    thread t2(man_BS_thread);
    
    t1.join();
    t2.join();
    
    cout << __func__ << ": " << i << '\n';
}
