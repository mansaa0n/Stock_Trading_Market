//
//  person.h
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/10/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//

#ifndef person_h
#define person_h

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <ctime>
#include <condition_variable>
#include <string>
//#include <algorithm>
#include "stock.h"

using namespace std;

string RandNames()
{
    //srand(time(0));
    vector<string> PeopleNames = {"Ahmed","Jhon", "Paul", "Daivd", "Sam", "Naithen", "Chandler", "Suzan", "Steve", "Joy", "Ross" };
    random_device random_dev;
    mt19937 engine{random_dev()};
    uniform_int_distribution<int>dist(0, PeopleNames.size()- 1);
    string randName = PeopleNames[dist(engine)];
    return randName;
}

class Person{
public:
    string name;
    double balance;
    vector<Stock> ownedStocks;
    vector<int> quantityShares;
    double X;
    double Y;
    
    Person() {
        this->name = RandNames();
        this->balance = RandNumbers(1000,5000);
        this->X = RandNumbers(20,50) * 0.01;
        this->Y = RandNumbers(10,30) * 0.01;
    }
    
    Person(string n, double b){
        this->name = n;
        this->balance = b;
        this->X = RandNumbers(20,50) * 0.01;
        this->Y = RandNumbers(10,30) * 0.01;
    }
    
    void buyStock(Stock s, int q) {
        if(balance < s.price * q) return;
        ownedStocks.push_back(s);
        quantityShares.push_back(q);
        balance -= s.price * q;
    }
    
    void sellStock(Stock s) {
        // Look for the name of the same stock
        for(int i = 0; i < ownedStocks.size(); i++) {
            if(s.name == ownedStocks[i].name) {
                balance += s.price * quantityShares[i];
                ownedStocks.erase(ownedStocks.begin() + i);
                quantityShares.erase(quantityShares.begin() + i);
                return;
            }
        }
    }
    
    bool buyDecision(Stock s, int q) {
        double Z = (1 - (s.price*q)/balance);
        double randomNumber = RandNumbers(0, 100);
        if(randomNumber < Z*100)
            return true;
        else
            return false;
    }
    
    bool sellDecision(Stock s) {
        // Look for the name of the same stock
        int i;
        for(i = 0; i < ownedStocks.size(); i++) {
            if(s.name == ownedStocks[i].name) {
                break;
            }
        }
        
        if( ownedStocks[i].price*(1+X) <= s.price ||
           ownedStocks[i].price*(1-Y) >= s.price) {
            return true;
        }
        else {
            return false;
        }
        
    }
};

#endif
