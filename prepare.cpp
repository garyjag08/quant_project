#include "prepare.h"

StockAttributes::StockAttributes(){} // defo contructor

/*
    - void method to read in stock data from csv file
    - sets the appropriate data in order of the column labels in the csv file
    - make sure to be consistant with the order of the column labels
*/
void StockAttributes::readData(string filename){
    ifstream file(filename);
    string line; 
    getline(file, line);
    while(getline(file,line)){
        stringstream ss(line);
        StockData entry;
        string token;
        
        std::getline(ss, token, ',');
        entry.close = std::stod(token);

        std::getline(ss, token, ',');
        entry.high = std::stod(token);

        std::getline(ss, token, ',');
        entry.low = std::stod(token);

        std::getline(ss, token, ',');
        entry.open = std::stod(token);

        stockData.push_back(entry);
    }
}

float StockAttributes::computeSMA(int index, int period){
    if(index + 1 < period) return 0.0f;
    float sum = 0.0f;
    for(int i = index - period + 1; i <= index; i++){
        sum += stockData[i].close;
    }
    return sum / period;
}

StockAttributes::~StockAttributes(){} // destructor