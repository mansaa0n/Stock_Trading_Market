//
//  stock.h
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/17/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//
#ifndef stock_h
#define stock_h
#include <iostream> // I/O library
#include <vector> //vector lib.
#include <random> // random lib.
#include <string> // string lib.

using namespace std;
// this function is list of stock names that was pulled online. This func will randomly genrate names of stocks, letter "A" was added as suffix so it can generate more names.
string RandomStock(){
    vector<string> SharesNames = {"BAC", "RF", "CHK", "GPS", "F", "WFC","GE","VALE","WFT","C","PFE","CRM","JPM","FCX","ANF","VRX","T","AKS","S","KEY","MS","KO","CX","X","WLL","KGC","IG","PG","ABX","MRO","HL","PBR","SWN","JCP","VALE.P","AUY","VZ","ECA","BBY","MT","NE","GGB","AGN","WMT","HPQ","LOW","BBD","CTL","MGM","UA","DNR","USB","GM","ETE","DIS","NEM","GG","HBI","XOM","COP","IAG","DAL","RAD","WNR","HST","CF","V","TCK","JNJ","MRK","BBT","ESV","CVS","NKE","RGC","RDC","CLF","GNW","ABT"};
    random_device random_devi;
    mt19937 engine{random_devi()};
    uniform_int_distribution<int>dist(0, SharesNames.size()-1);
    uniform_int_distribution<int>alphabet(0, 25);
    char suffix = 'A' + alphabet(engine);
    string randShares = SharesNames[dist(engine)];
    return randShares + suffix;
}
// this func is used to genrate randome decimal numbers, to genrate the prices
double RandNumbers(double fMin,double fMax){
    random_device random_devi;
    mt19937 engine{random_devi()};
    uniform_int_distribution<double>dist(fMin, fMax);
    uniform_int_distribution<int>decimal(1,99);
    return dist(engine)+(decimal(engine)*0.01);
}
// this func is used to generate random numbers that will be assigned for the quantity
int RandQuantity( int fMin, int fMax){
    random_device random_devi;
    mt19937 engine{random_devi()};
    uniform_int_distribution<int>dist(fMin, fMax);
    return dist(engine);
}
// This class is used as stock class. It has name and price, Obviously what Property of stock is
// inside the class there are 2 structs one for calling stock and the other for the default
class Stock{ 
public:
    string name;
    double price;
    Stock() {
        this->name = RandomStock();
        this->price = RandNumbers(5,30);
    }
    Stock(string n, double p) {
        this->name = n;
        this->price = p;
    }
};
// This class has necessary functions of what a stock market should do!
class StockMarket{
public:
    vector<Stock> market; // vector to hold the market genrated
    
    void addStock(Stock s){      // add stocks to the market vector
        // Adds a stock s into vector<Stock> market.
        market.push_back(s);
    }
    double getCurrentPrice(Stock s){
        // Gets the current price of Stock s in the market.
        // If it can't find Stock s in the market, return -1.
        for(int i = 0; i < market.size(); i++) {
            if(market[i].name == s.name)
                return market[i].price;
        }
        return -1;
    }
    void setPrice(Stock s, double newPrice){
        // this func will set price to the stock
        for(int i = 0; i < market.size(); i++) {
            if(market[i].name == s.name) {
                market[i].price = newPrice;
            }
        }

    }
    void printMarket() {
        // Couts the entire stock market and their prices.
        for(int i = 0; i < market.size(); i++) {
            cout << market[i].name << ", $" << market[i].price << endl;
        }
    }
    // this func is used to pick a random stock from the created market so the user can check the prices
    Stock getRandStockB(){
        random_device random_devi;
        mt19937 engine{random_devi()};
        uniform_int_distribution<int>dist(0,market.size()-1);
        return market[dist(engine)];
    }
    // this will return all stock from the market created 
    Stock getStock(Stock S){
        for (int i=0 ; i < market.size() ; i++){
            if (S.name == market[i].name){
                return market[i];
            }
        }
        return Stock();
    }
    
};

#endif /* stock_h */
