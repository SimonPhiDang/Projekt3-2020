#include <iostream>
#include <queue>

std::queue<int> orderQueue;

struct order
{
    int tableNr_;
    int beerAmount_;
};

void pushOrder(int tableNr, int beerAmount)
{
    orderQueue.push(tableNr);
    orderQueue.push(beerAmount);
}

order popOrder()
{
    order newOrder;
    newOrder.tableNr_ = orderQueue.front();
    orderQueue.pop();
    newOrder.beerAmount_ = orderQueue.front();
    orderQueue.pop();
    return newOrder;
}