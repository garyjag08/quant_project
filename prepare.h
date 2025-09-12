#ifndef PREPARE_H
#define PREPARE_H

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

/*
    - Struct to store attibutes of the stock
    - Stores basic stock information: Open, High, Low, Close
*/
struct StockData {
    // Basic OHLC data
    float open = 0, high = 0, low = 0, close = 0;
};

/*
    Class to hold stock information and engineered features
*/
class StockAttributes{
    public:
        StockAttributes(); // default contructor
        void readData(string filename); // method to read in csv file
        ~StockAttributes(); // destructor
    private:
        vector<StockData> stockData;
};

#endif