#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "order.h"
#include <vector>

class OrderBook
{
private:
    std::vector<Order> orders;
    int nextOrderId;

public:
    OrderBook();

    int addOrder(OrderType type, double price, double amount);
    std::vector<Order> getOrders() const;
};

#endif