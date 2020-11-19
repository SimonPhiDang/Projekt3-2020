#include "UC3.h"
#include <uWS/uWS.h>

UC3::UC3(/* args */)
{
}

void UC3::setOrder(int table, int beerAmount){
    setTable(table);
    setBeerAmount(beerAmount);
}

int UC3::getTable(){
    return table_;
}

int UC3::getBeerAmount(){
    return beerAmount_;
}

bool UC3::checkOrder(){
    cout << "Checking Order" << endl;
    return 0;
}

void UC3::sendOrderToLog(int table, int beerAmount){
    if (beerAmount == 1)
    {
        cout << "Table " << table << " has ordered " << beerAmount << " beer. Sending order to log" << endl;
    }
    else
    {
        cout << "Table " << table << " has ordered " << beerAmount << " beers. Sending order to log" << endl;
    }
}

void UC3::sendOrderToPSoC(){
    if (beerAmount_ == 1)
    {
        cout << "Table " << table_ << " has ordered " << beerAmount_ << " beer. Sending order to PSoC" << endl;
    }
    else
    {
        cout << "Table " << table_ << " has ordered " << beerAmount_ << " beers. Sending order to PSoC" << endl;
    }
}


void UC3::setBeerAmount(int beerAmount){
    beerAmount_ = beerAmount;
}

void UC3::setTable(int table){
    table_ = table;
}