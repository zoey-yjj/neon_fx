#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "order.h"
#include <vector>
#include <map>

class OrderLevel
{
    double price;
    double amount;
};

class OrderBook
{
private:
    // bid orders need to match from high -> low
    std::map<double, std::vector<Order>, std::greater<double>> bids;
    // ask orders match from high -> low
    std::map<double, std::vector<Order>> asks;
    int nextOrderId;

public:
    OrderBook();

    int addOrder(OrderSide side, double price, double amount);
    void printOrders();
};

#endif