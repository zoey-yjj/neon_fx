#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "order.h"
#include <vector>
#include <map>
#include <memory>

class OrderLevel
{
    double price;
    double amount;
};

class OrderBook
{
private:
    // bid orders need to match from high -> low
    std::map<double, std::vector<std::shared_ptr<Order>>, std::greater<double>> bids;
    // ask orders match from high -> low
    std::map<double, std::vector<std::shared_ptr<Order>>> asks;

public:
    bool check_order(OrderSide side, double price);
    bool add_order(std::shared_ptr<Order> order_ptr);

    const std::map<double, std::vector<std::shared_ptr<Order>>, std::greater<double>> &get_bids();
    const std::map<double, std::vector<std::shared_ptr<Order>>> &get_asks();
    void print_orders();
};

#endif