#ifndef ORDER_H
#define ORDER_H

#include "symbol.h"
#include <ctime>

enum class OrderSide
{
    BUY,
    SELL,
};

enum class OrderStatus
{
    PENDING,
    FILLED,
    CANCELLED,
};

struct Order
{
    int id;
    Symbol symbol;
    OrderSide side;
    double price;
    double amount;
    time_t timestamp;
    OrderStatus status;

    void print();

    Order(int id, OrderSide side, double price, double amount, Symbol symbol);
};

#endif