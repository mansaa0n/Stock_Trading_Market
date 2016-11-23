//
//  STOCKCLASS.h
//  automated stock trading
//  This class will generate stocks and save them in a vector 
//  Created by Ahmed Almansor on 11/19/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//
#ifndef STOCKCLASS_h
#define STOCKCLASS_h

#include "libraries .h"

using namespace std;

string RandomStock(int len){
    vector<string> SharesNames = {"BAC", "RF", "CHK", "GPS", "F", "WFC","GE","VALE","WFT","C","PFE","CRM","JPM","FCX","ANF","VRX","T","AKS","S","KEY","MS","KO","CX","X","WLL","KGC","IG","PG","ABX","MRO","HL","PBR","SWN","JCP","VALE.P","AUY","VZ","ECA","BBY","MT","NE","GGB","AGN","WMT","HPQ","LOW","BBD","CTL","MGM","UA","DNR","USB","GM","ETE","DIS","NEM","GG","HBI","XOM","COP","IAG","DAL","RAD","WNR","HST","CF","V","TCK","JNJ","MRK","BBT","ESV","CVS","NKE","RGC","RDC","CLF","GNW","ABT"};
    
    int randIndx = rand()% SharesNames.size();
    return SharesNames[randIndx];
}
double RandNumbers(double fMin,double fMax){
    double f = (double)rand()/RAND_MAX;
    return fMin + f * (fMax-fMin);
}

struct Shares{
    string name = RandomStock(3);
    double price = RandNumbers(10, 40);
    
    Shares(string name, double price){
        this->name = name; this->price = price;
    }
};
class StockMarket{
private:
    vector <Shares> Share;
public:
    void addShare(Shares S){
        Share.push_back(S);
    }
    string getShare(Shares S){
        return S.name;  // fix it
    }
    void removeShares(Shares S){
        return;
    }
    double getValue(Shares S){
        return S.price;
    }
    void printShares(){
        
    }
};

#endif /* STOCKCLASS_h */
