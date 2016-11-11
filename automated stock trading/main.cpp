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
using namespace std;

class stock_trading {
    vector <int> PurchaseStocks;
public:
    
           //     saprate files
};

// globle variables
int i = 0;
mutex stockLock;  // protects i


void man_BS_thread()
{
    double balance;
    vector <stock_trading> PurchaseStocks;
    double buyThreshold;
    double sellThreshold;
    
    lock_guard<std::mutex> lock(stockLock);  // change to stocklock
    ++i;
    
    std::cout << std::this_thread::get_id() << ": " << i << '\n';
    
    // g_i_mutex is automatically released when lock goes out of scope
}
void stock_manager_thread()
{
    std::string name;
    int    share;
    double price_per_share;
    
    // thread goes here
    
}



int main()
{
    std::cout << __func__ << ": " << i << '\n';
    
    std::thread t1(man_BS_thread);
    std::thread t2(man_BS_thread);
    
    t1.join();
    t2.join();
    
    cout << __func__ << ": " << i << '\n';
}
