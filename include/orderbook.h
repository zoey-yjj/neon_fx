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

    bool checkOrder(OrderSide side, double price);
    int addOrder(OrderSide side, double price, double amount);
    const std::map<double, std::vector<Order>, std::greater<double>> &getBids();
    const std::map<double, std::vector<Order>> &getAsks();
    void printOrders();
};

#endif