#include<iostream>
#include "prepare.h"
using namespace std;

int main(){
    StockAttributes sa; // new object of StockAttribute class
    sa.readData("AAPL.csv"); // read in file

    cout << "End Program, data has been read in correctly" << endl;
    
    return 0;
}