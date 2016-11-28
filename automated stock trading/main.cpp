//
//  main.cpp
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/1/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//

// call all libraries needed
#include <chrono>   // time library
#include <iostream> // I/O library
#include <thread> //thread lib.
#include <mutex> // lock lib.
#include <vector> //vector lib.
#include <random> // random lib.
#include <string> // string lib.
#include "stock.h" // custom header file "stock"
#include "person.h"// custom header file "person"
// using names form standered library
using namespace std;
// declairing globel varibles that can be acceccble by all func.
mutex marketlock;
mutex PersonLock;
//condition_variable isPriceSatisfied;
Person p;
StockMarket sm; // updated price
// server thread that will display the balance of the person after he/she sell or buy
// This thread will wait for 10 seconds and then display the balance, knowing that buying and selling is done every 2 second, therefore there will be 5 transactions before the alance is being displayed.
void ServerThread(){
   // chrono::seconds waitTime(1);
    //this_thread::sleep_for(waitTime);
    lock_guard<mutex> lock(PersonLock);
    p.PrintPerson();
}
// This thread will set a new price to the stock
void PriceThread(){
    lock_guard<mutex> lock(marketlock);
    sm.setPrice(sm.getRandStockB(), RandNumbers(5, 50));
}
// stock market, this thread will create a market of 300 stock that will be available for sale
void CreateMarket(){
    for(int i = 0; i < 300; i++) {
        Stock randomStock;
        sm.addStock(randomStock);
        //sm.setPrice(randomStock, RandNumbers(10, 60));
    }
}

// Buying Thread, this thread is used by the person. It waits for 2 second and then will buy stocks from the availble stocks in the market based on person's decision, however, the person has to have enough balance to buy.It also display the quantity bought
void Person_Buy_Thread(){
    //chrono::milliseconds waitTime(500);
    //this_thread::sleep_for(waitTime);
    lock_guard<mutex> lock(marketlock);//marketlock
    lock_guard<mutex> lock1(PersonLock);
    Stock randomS = sm.getRandStockB(); 
    int  Quantity = RandQuantity(1, 10);
    if(p.buyDecision(randomS, Quantity))
    {
        cout << "Buy " << randomS.name  << ", Quantity of: " << Quantity << " $" <<randomS.price << endl;
        p.buyStock(randomS, Quantity);
    }
}
// selling thread. This thread is used by the person. It waits for 2 seconds and then will sell based on the person's decision. It also display the quantity sold.
void Person_Sell_Thread(){
    //chrono::milliseconds waitTime(500);
    //this_thread::sleep_for(waitTime);
    lock_guard<mutex> lock(marketlock);
    lock_guard<mutex> lock1(PersonLock);
    if (p.ownedStocks.size()==0) {
        return;
    }
    Stock myStock = p.getRandStockP();
    if(p.sellDecision(sm.getStock(myStock)))
    {
        int Quantity = p.getQuantity(myStock);
        p.sellStock(sm.getStock(myStock));
        cout << "Sold " << sm.getStock(myStock).name << ", Quantity of: " << Quantity << " $" << sm.getStock(myStock).price << endl;
    }
}

// main fuction of the program
int main()
{
    CreateMarket();
    for(int i = 0; i < 10000; i++) {
        if(i % 100) {
            thread Server = thread(ServerThread);
            Server.join();
        }
        thread buyme = thread(Person_Buy_Thread);
        buyme.join();
        thread(PriceThread).join();
        thread sellme = thread(Person_Sell_Thread);
        sellme.join();
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
