#ifndef ORDER_H
#define ORDER_H

#include <ctime>

enum class OrderType
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
    OrderType type;
    double price;
    double amount;
    time_t timestamp;
    OrderStatus status;

    Order(int id, OrderType type, double price, double amount);
};

#endif