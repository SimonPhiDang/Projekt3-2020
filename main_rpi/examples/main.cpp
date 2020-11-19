#include <iostream>
#include <string>
#include <uWS/uWS.h>
#include <thread>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include "UC3.h"

struct Data
{
  uWS::Hub &h;
  void operator()(uWS::WebSocket<uWS::SERVER> *ws,
		  char *message, size_t length,
		  uWS::OpCode opCode) {
        std::cout << "Data: " << std::string(message, length) << std::endl;
        std::string last = std::string(message, length);
        string str_response = "Order sendt til PSoC: ";
        string str_message = string(message, length);
        str_response.append(str_message);
        int n = str_response.length();
        char response[n+1];
        strcpy(response, str_response.c_str());
        size_t length_response = sizeof(response);
        
        UC3* orderObj = new UC3;
        if (last.find("Bord: 0") != std::string::npos)
        {
          std::cout << "Order: No order yet" << std::endl;
        }

        if (last.find("Bord: 1") != std::string::npos)
        {
          char c_beerAmount = last.back();
          int beerAmount = std::atoi(&c_beerAmount);
          int tableNr = 1;
          orderObj->setOrder(tableNr,beerAmount);

          std::cout << "Order: Bord: " << orderObj->getTable() << ". Antal øl: " << orderObj->getBeerAmount() << std::endl;
          orderObj->sendOrderToPSoC();
          ws->send(response, length_response, opCode);
        }

        if (last.find("Bord: 2") != std::string::npos)
        {
          char c_beerAmount = last.back();
          int beerAmount = std::atoi(&c_beerAmount);
          int tableNr = 2;
          orderObj->setOrder(tableNr,beerAmount);

          std::cout << "Order: Bord: " << orderObj->getTable() << ". Antal øl: " << orderObj->getBeerAmount() << std::endl;
          orderObj->sendOrderToPSoC();
          ws->send(response, length_response, opCode);
        }
        delete orderObj;
  }
};

void async(uWS::Hub* h)
{
  for(;;)
  {
    sleep(1);
  }
}



int main()
{
  uWS::Hub hub;

  Data d { hub };
  hub.onMessage(d);
  if (hub.listen(3000)) {
    std::thread th(async, &hub);
    hub.run();
  }
}
