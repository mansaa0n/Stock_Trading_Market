//
//  person.cpp
//  automated stock trading
//
//  Created by Ahmed Almansor on 11/10/16.
//  Copyright © 2016 Fresno State Electric & Computer Eng. All rights reserved.
//
using namespace std;
#include <vector>
#include "stock.h"

class person {
public:
    double balance;
    vector <stock_trading> PurchaseStocks;
    double buyThreshold;
    double sellThreshold;
};
