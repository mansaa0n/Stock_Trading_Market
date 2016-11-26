//
//  stock.h
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/17/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//
#ifndef stock_h
#define stock_h
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <ctime>
#include <condition_variable>
#include <string>
//#include <algorithm>

using namespace std;

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
double RandNumbers(double fMin,double fMax){
    random_device random_devi;
    mt19937 engine{random_devi()};
    uniform_int_distribution<double>dist(fMin, fMax);
    uniform_int_distribution<int>decimal(0,99);
    return dist(engine)+(decimal(engine)*0.01);
}

class Stock{
public:
    string name;
    double price;
    Stock() {
        this->name = RandomStock();
        this->price = RandNumbers(10,30);
    }
    Stock(string n, double p) {
        this->name = n;
        this->price = p;
    }
};


class StockMarket{
public:
    vector<Stock> market;
    void addStock(Stock s){
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
        for(int i = 0; i < market.size(); i++) {
            if(market[i].name == s.name)
                market[i].price = newPrice;
        }

    }
    void printMarket() {
        // Couts the entire stock market and their prices.
        for(int i = 0; i < market.size(); i++) {
            cout << market[i].name << ", $" << market[i].price << endl;
        }
    }
    Stock getRandStock(){
        random_device random_devi;
        mt19937 engine{random_devi()};
        uniform_int_distribution<int>dist(0,market.size()-1);
        return market[dist(engine)];
    }
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
