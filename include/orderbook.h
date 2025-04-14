#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "book.h"
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
    std::map<int, Book> bids;
    // ask orders match prices from high -> low
    std::map<int, Book> asks;

public:
    bool check_order(OrderSide side, double price);
    bool add_order(SharedOrderPtr order_ptr);
    bool delete_order(SharedOrderPtr order_ptr);

    const std::map<int, Book> &get_bids();
    const std::map<int, Book> &get_asks();
    void print_orders();
};

#endif