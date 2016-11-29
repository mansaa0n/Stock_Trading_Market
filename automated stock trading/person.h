//
//  person.h
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/10/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//

#ifndef person_h
#define person_h
#include <iostream> // I/O library
#include <vector> //vector lib.
#include <random> // random lib.
#include <string> // string lib.
#include "stock.h"  // custom file for the stocks
using namespace std;
// this func will generate random user from the list
string RandNames()
{
    vector<string> PeopleNames = {"Ahmed","Jhon", "Paul", "Daivd", "Sam", "Naithen", "Chandler", "Suzan", "Steve", "Joy", "Ross" };
    random_device random_dev;
    mt19937 engine{random_dev()};
    uniform_int_distribution<int>dist(0, PeopleNames.size()- 1);
    string randName = PeopleNames[dist(engine)];
    return randName;
}
// This class is used as person class. It has name ,balance ownedstocks and quantity and all the decition making proprety.
// inside the class there are 2 structs one for calling person and the other for the default
class Person{
public:
    string name;
    double balance;
    vector<Stock> ownedStocks;
    vector<int> quantityShares;
    double X;
    double Y;
    double originalBalance;
    
    Person() {
        this->name = RandNames();
        this->balance = RandNumbers(1000,5000);
        this->X = RandNumbers(15,25) * 0.01;
        this->Y = RandNumbers(60,90) * 0.01;
        this->originalBalance = this->balance;
        }
    
    Person(string n, double b){
        this->name = n;
        this->balance = b;
        this->X = RandNumbers(15,25) * 0.01;
        this->Y = RandNumbers(60,90) * 0.01;
        this->originalBalance = this->balance;
    }
    // this func will be called when a buying Decision is true and add the stock to the user collection
    void buyStock(Stock s, int q) {
        if(balance < s.price * q) return;
        ownedStocks.push_back(s);
        quantityShares.push_back(q);
        balance -= s.price * q;
    }
// this func will be called when a selling Decision is true and add the stock to the user collection
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
    // this function will make the buying decision
    bool buyDecision(Stock s, int q) {
        if(alreadyOwned(s))
            return false;
        double Z = (1 - (s.price*q)/balance);
        if(balance/originalBalance >= 1.25)
            Z *= 0.5;
        else {
            Z *= balance/originalBalance;
        }
        double randomNumber = RandNumbers(40, 200);
        if(randomNumber < Z*100)
            return true;
        else
            return false;
    }
    // this function will make the selling decision
    bool sellDecision(Stock s) {
        // Look for the name of the same stock
        int i;
        for(i = 0; i < ownedStocks.size(); i++) {
            if(s.name == ownedStocks[i].name) {
                break;
            }
        }
        double goodPrice = ownedStocks[i].price*(1+X); //if start to make money sell
        double badPrice = ownedStocks[i].price*(1-Y); // if start to get bad sell
        if(ownedStocks[i].price == s.price) {
            //cout << "==" << endl;
            return false;
        }
        if(goodPrice <= s.price) {
            //cout << "GOOD PRICE: " << goodPrice << " <= " << s.price << endl;
            return true;
        }
        else if (badPrice >= s.price) {
            //cout << "BAD PRICE: " << badPrice << " >= " << s.price << endl;
            return true;
        }
        else {
            //cout << "NO-SELL-G: " << goodPrice << " > " << s.price << endl;
            //cout << "NO-SELL-B: " << badPrice << " < " << s.price << endl;
            return false;
        }
    }
    // this function will print the users name the balance and the yielding from the transactions
    void PrintPerson(){
        cout << name << " $" << balance << " Yielding $" << getYielding() <<  endl;
        for ( int i =0;  i< ownedStocks.size(); i++){
            cout << ownedStocks[i].name << " $" << ownedStocks[i].price << " Quantity owned: " << quantityShares[i] << endl;
        }
        return;
    }
   // This function will get a random stock from the owned stocks so it can check if user want to sell
    Stock getRandStockP(){
        random_device random_devi;
        mt19937 engine{random_devi()};
        uniform_int_distribution<int>dist(0,ownedStocks.size()-1);
        return ownedStocks[dist(engine)];
    }
 // this func will get the quantity owned from the stock
    int getQuantity(Stock S){
        for (int i=0 ; i < ownedStocks.size() ; i++){
            if (S.name == ownedStocks[i].name){
                return quantityShares[i];
            }
        }
        return 0;
        
    }
    // this bool func will check if the same stock is owned dont buy.
    bool alreadyOwned(Stock S){
        for (int i =0; i < ownedStocks.size();i++){
            if(ownedStocks[i].name == S.name){
                return true;
            }
        }
        return false;
    }
    // this funct will calculate the yielding
    double getYielding(){
        return balance - originalBalance;
    }
};

#endif
