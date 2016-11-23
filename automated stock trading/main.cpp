//
//  main.cpp
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/1/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//

// call all library needed
#include "libraries .h"
// using names form standered library
using namespace std;
// declairing globel varibles(int, locks, codition vriables) that can be acceccble by all func.
int i = 0;
mutex marketlock;

// condition_variable isPriceSatisfied;

// Random generator of stocks and its prices,, also random balance for clients

//double RandNumbers(double fMin,double fMax){
            //      double f = (double)rand()/RAND_MAX;
            //      return fMin + f * (fMax-fMin);
            //  }
// generate random people
/*string RandPeople (){
    vector<string> People= { "Jhon", "Eddy", "Daivd", "Sara", "Phebee", "Raichal", "Monica", "Ahmed", "Sam", "Gorge", "Steve", "Madden"};
    int randIndx= rand()% People.size();
    return People[randIndx];
    }
*/
// Buying and Selling Thread

void Person_BS_Thread(){
    lock_guard<mutex> lock(marketlock); //marketlock
    
}

// main fuction of the program
int main()
{
    
    
    return 0;
}
