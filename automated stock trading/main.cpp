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
#include "stock.h"
#include "person.cpp"
#include <random>
#include "STOCKCLASS.h"
#include <ctime>
// using names form standered library
using namespace std;
// declairing globel varibles(int, locks, codition vriables) that can be acceccble by all func.
int i = 0;
mutex marketlock;

// condition_variable isPriceSatisfied;



// Random generator of stocks and its prices
string RandomStock(int len){
    string ShareName;
    vector<string> SharesNames = {"BAC", "RF", "CHK", "GPS", "F", "WFC","GE","VALE","WFT","C","PFE","CRM","JPM","FCX","ANF","VRX","T","AKS","S","KEY","MS","KO","CX","X","WLL","KGC","IG","PG","ABX","MRO","HL","PBR","SWN","JCP","VALE.P","AUY","VZ","ECA","BBY","MT","NE","GGB","AGN","WMT","HPQ","LOW","BBD","CTL","MGM","UA","DNR","USB","GM","ETE","DIS","NEM","GG","HBI","XOM","COP","IAG","DAL","RAD","WNR","HST","CF","V","TCK","JNJ","MRK","BBT","ESV","CVS","NKE","RGC","RDC","CLF","GNW","ABT"};
    
        int randIndx = rand()% SharesNames.size();
    
        return SharesNames[randIndx];
}
double RandPrice(double fMin,double fMax){
                  double f = (double)rand()/RAND_MAX;
                  return fMin + f * (fMax-fMin);
              }

// Buying and Selling Thread

void Person_BS_Thread(){
    lock_guard<mutex> lock(marketlock); //marketlock
    
}

// main fuction of the program
int main()
{
    
    
    return 0;
}
