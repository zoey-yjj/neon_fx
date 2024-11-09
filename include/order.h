#ifndef ORDER_H
#define ORDER_H

#include <ctime>
#include <iostream>

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
    OrderSide side;
    double price;
    double amount;
    time_t timestamp;
    OrderStatus status;

    Order(int id, OrderSide side, double price, double amount);

    friend std::ostream &operator<<(std::ostream &os, const Order &order);
};

#endif