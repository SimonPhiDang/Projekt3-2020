#include <iostream>
#include <stdlib.h>
using namespace std;

class UC3
{
public:
    UC3(/* args */);
    void setOrder(int, int);


    int getTable(); 
    int getBeerAmount();
    void setBeerAmount(int);
    void setTable(int);

    bool checkOrder();
    void sendOrderToLog(int, int);
    void sendOrderToPSoC();
     
private:
    void getOrder();
    int table_;
    int beerAmount_; 
    
};
