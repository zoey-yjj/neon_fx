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
    // bid orders need to match prices from high -> low
    std::map<int, std::vector<std::shared_ptr<Order>>> bids;
    // ask orders match prices from high -> low
    std::map<int, std::vector<std::shared_ptr<Order>>> asks;

public:
    bool check_order(OrderSide side, double price);
    bool add_order(std::shared_ptr<Order> order_ptr);
    bool delete_order(std::shared_ptr<Order> order_ptr, int id);

    const std::map<int, std::vector<std::shared_ptr<Order>>> &get_bids();
    const std::map<int, std::vector<std::shared_ptr<Order>>> &get_asks();
    void print_orders();
};

#endif