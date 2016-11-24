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
#include <algorithm>
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
    Person() {
        this->name = RandNames();
        this->balance = RandNumbers(1000,5000);
    }
    Person(string n, double b){
        this->name = n;
        this->balance = b;
    }
};

#endif
