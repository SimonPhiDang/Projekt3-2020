#include <iostream>
#include <string>
#include <uWS/uWS.h>
#include <thread>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <pthread.h>
#include "UC3.h"
#include "orderQueue.hpp"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>




static pthread_mutex_t lockOrder;
static pthread_cond_t  beertressWorking;
bool isOrderCompletion = true;

struct Data
{
  uWS::Hub &h;
  void operator()(uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) 
  {
    pthread_mutex_lock(&lockOrder);
    std::cout << "Data: " << std::string(message, length) << std::endl;
    std::string last = std::string(message, length);
    string str_response = "Order sendt til PSoC: ";
    string str_message = string(message, length);
    str_response.append(str_message);
    int n = str_response.length();
    char response[n+1];
    strcpy(response, str_response.c_str());
    size_t length_response = sizeof(response);
    int maxTable = 2; 

    int pos = last.find("Bord: ") + 6;
    char c_tableNr = last.at(pos);
    int tableNr = c_tableNr - '0';
      
    char c_beerAmount = last.back();
    int beerAmount = c_beerAmount - '0';
       
    if(tableNr != 0 && tableNr <= maxTable)
    {
      pushOrder(tableNr,beerAmount);
     
      // wait here until beertress is ready
      while (isOrderCompletion == false)
      {
        std::cout << "Beertress is working. Waiting before pushing next order" << std::endl;
        pthread_cond_wait(&beertressWorking, &lockOrder);
      }
      isOrderCompletion = false;
      UC3* orderObj = new UC3;
      order newOrder;
      newOrder = popOrder();

      orderObj->setOrder(newOrder.tableNr_,newOrder.beerAmount_);
          
      std::cout << "Order: Bord: " << orderObj->getTable() << ". Antal øl: " << orderObj->getBeerAmount() << std::endl;
      orderObj->sendOrderToPSoC();
      ws->send(response, length_response, opCode);
      delete orderObj;
    }
    else
    {
      std::cout << "Order: No order yet" << std::endl;
    }     
    pthread_mutex_unlock(&lockOrder);
  }
};

void async(uWS::Hub* h)
{
  for(;;)
  {
    sleep(1);
  }
}

uWS::Hub hub;
void *orderControllerFunction(void *ptr);
void *awatingSuccessFunction(void *ptr);
void readGPIO();

int main()
{
  pthread_t orderControllerThread, awatingSuccessThread;
  pthread_mutex_init(&lockOrder,nullptr);
  std::cout << "Creating threads" << std::endl;
  pthread_create(&awatingSuccessThread,NULL,awatingSuccessFunction,NULL);
  pthread_create(&orderControllerThread,NULL,orderControllerFunction,NULL);

  pthread_join(orderControllerThread,NULL);
  std::cout << "orderControllerThread terminated" << std::endl;
  pthread_join(awatingSuccessThread, NULL);
  std::cout << "awatingSuccessThread terminated" << std::endl;
}

void *orderControllerFunction(void *ptr)
{
  std::cout << "orderControllerFunction created" << std::endl;
  Data d { hub };
  hub.onMessage(d);
  if (hub.listen(3000)) {
    std::thread th(async, &hub);
    hub.run();
  }
  return 0;
}

void *awatingSuccessFunction(void *ptr)
{
  std::cout << "awatingSuccessFunction created" << std::endl;
  
  while (1)
  {
    //readGPIO();
    sleep(20);
    //readGPIO();
    std::cout << "Beertress completed an order. Wating for new order" << std::endl;
    isOrderCompletion = true;
    pthread_cond_signal(&beertressWorking);
  }
  

  return 0;
}

void readGPIO()
{
  size_t fd;
  char read_buf[2];
  if((fd = open("/dev/orderCompleteGPIO", O_RDWR)) < 0) 
  {
    printf("ERROR: Error opening /dev/orderCompleteGPIO\n");
  }
  read(fd, read_buf, sizeof(read_buf));
  printf("Reading from orderCompleteGPIO: %s \n", read_buf);
}