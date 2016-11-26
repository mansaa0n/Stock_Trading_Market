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
    
    myMarket.addStock(newStock);
    myMarket.printMarket();
    
    cout << "====" << endl;
    
    cout << newPerson.name << "'s X/Y: " << newPerson.X << " and " << newPerson.Y << endl;
    
    if(newPerson.buyDecision(newStock, 10))
    {
        cout << "Buying." << endl;
        newPerson.buyStock(newStock, 10);
        cout << newPerson.name << " and " << newPerson.balance << endl;
        double newPrice = RandNumbers(5, 50);
        myMarket.setPrice(newStock,newPrice);
        cout << "Price is changed to: " << newPrice << endl;
        if(newPerson.sellDecision(myMarket.market[myMarket.market.size()-1]))
        {
            cout << "Sold!" << endl;
            newPerson.sellStock(myMarket.market[myMarket.market.size()-1]);
            cout << newPerson.name << " and " << newPerson.balance << endl;
        }
        else
        {
            cout << "No." << endl;
        }
    }
    else
    {
        cout << "Not buying." << endl;
    }
    
    
    return 0;
}
