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

StockAttributes::~StockAttributes(){} // destructor