//
//  main.cpp
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/1/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//

// call all library needed
#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <ctime>
#include <condition_variable>
#include <string>
#include "stock.h"
#include "person.h"

// using names form standered library
using namespace std;
// declairing globel varibles(int, locks) that can be acceccble by all func.
int i = 0;
mutex marketlock;
mutex PersonLock;
//condition_variable isPriceSatisfied;



// server thread

Person p;
StockMarket sm;

void ServerThread(){
    //chrono::seconds waitTime(5);
    //this_thread::sleep_for(waitTime);
    lock_guard<mutex> lock(PersonLock);
    p.PrintPerson();
}

void PriceThread(){
    lock_guard<mutex> lock(marketlock);
    sm.setPrice(sm.getRandStock(), RandNumbers(5, 100));
}

// stock market

void CreateMarket(){
    for(int i = 0; i < 50; i++) {
        Stock randomStock;
        sm.addStock(randomStock);
    }
}

// Buying Thread

void Person_Buy_Thread(){
    //chrono::seconds waitTime(2);
    //this_thread::sleep_for(waitTime);
    lock_guard<mutex> lock(marketlock);//marketlock
    lock_guard<mutex> lock1(PersonLock);
    Stock randomS = sm.getRandStock();
    if(p.buyDecision(randomS, 10)) // change it
    {
        cout << "Buy " << randomS.name << " quantity of: 10" << " $" <<randomS.price << endl;
        p.buyStock(randomS, 10);
    }
}

// selling thread
void Person_Sell_Thread(){
    //chrono::seconds waitTime(2);
    //this_thread::sleep_for(waitTime);
    lock_guard<mutex> lock(marketlock);
    lock_guard<mutex> lock1(PersonLock);
    Stock myStock = p.getRandStock();
    if(p.sellDecision(sm.getStock(myStock)))
    {
        p.sellStock(sm.getStock(myStock));
        cout << "Sell " << sm.getStock(myStock).name << " quantity of: 10" << " $" << sm.getStock(myStock).price << endl;
    }
}

// main fuction of the program
int main()
{
    CreateMarket();
    for(int i = 0; i < 200; i++) {
        thread buyme = thread(Person_Buy_Thread);
        buyme.join();
        if(i%10==0) {
        thread Server = thread(ServerThread);
        Server.join();
        }
        thread sellme = thread(Person_Sell_Thread);
        sellme.join();
        for(int j = 0; j < 5; j++)
            thread(PriceThread);
    }
    
    return 0;
}

void test_driver() {
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
}
