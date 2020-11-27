#include "UC3.h"
#include <uWS/uWS.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>


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
    cout << "Checking Order: Bord: " << table_ << ". Antal øl: " << beerAmount_ << endl;
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

    cout << "Bord: " << table_ << " har ordret " << beerAmount_ << " øl. Sender til PSoC" << endl;
    int fd;
    int writeBuf[10];
    int num_write;
    int status;

    fd = open("/dev/i2c-1", O_RDWR);
    if (fd == -1)
    {
        std::cout << "Error on fd" << std::endl;
    };

    status = ioctl(fd,0x0703, 0x08);
    if (status > 0)
    {
        std::cout << "Error on status" << std::endl;
    }
    
    writeBuf[0] = 0b00000001;
    num_write = write(fd,writeBuf,1);
    if (num_write != 1)
    {
        std::cout << "Error on num_write" << std::endl;
    };
    
    
}


void UC3::setBeerAmount(int beerAmount){
    beerAmount_ = beerAmount;
}

void UC3::setTable(int table){
    table_ = table;
}