//
//  main.cpp
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/1/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//

// call all library needed
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <ctime>
#include <condition_variable>
#include <string>
#include <algorithm>
#include "stock.h"
#include "person.h"

// using names form standered library
using namespace std;
// declairing globel varibles(int, locks, codition vriables) that can be acceccble by all func.
int i = 0;
mutex marketlock;
condition_variable isPriceSatisfied;

// Random generator of people
 

// Buying and Selling Thread

void Person_BS_Thread(){
    lock_guard<mutex> lock(marketlock); //marketlock
    
}

// main fuction of the program
int main()
{
    Stock newStock;
    Person newPerson;
    
    cout << newStock.name << " and " << newStock.price << endl;
    cout << newPerson.name << " and " << newPerson.balance << endl;
    
    StockMarket myMarket;
    
    for(int i = 0; i < 10; i++) {
        Stock randomStock;
        myMarket.addStock(randomStock);
    }
    
    myMarket.printMarket();
    
    
    
    return 0;
}
