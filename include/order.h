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

    Order(int id, OrderSide side, double price, double amount, Symbol symbol);

    int get_id();
    double get_price();
    double get_amount();
    Symbol get_symbol();
    int get_price_level();
    OrderSide get_side();

    bool change_price(double new_price);
    bool change_amount(double new_amount);

    void print();
};

#endif