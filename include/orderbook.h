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
    std::map<int, std::vector<SharedOrderPtr>> bids;
    // ask orders match prices from high -> low
    std::map<int, std::vector<SharedOrderPtr>> asks;

public:
    bool check_order(OrderSide side, double price);
    bool add_order(SharedOrderPtr order_ptr);
    bool delete_order(SharedOrderPtr order_ptr, int id);

    const std::map<int, std::vector<SharedOrderPtr>> &get_bids();
    const std::map<int, std::vector<SharedOrderPtr>> &get_asks();
    void print_orders();
};

#endif