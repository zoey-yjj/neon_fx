#ifndef ORDER_H
#define ORDER_H

#include "symbol.h"
#include <ctime>
#include <memory>

struct Order;
using SharedOrderPtr = std::shared_ptr<Order>;

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
    SharedOrderPtr prev;
    SharedOrderPtr next;

    Order(int id, OrderSide side, double price, double amount, Symbol symbol);

    int get_id();
    double get_price();
    double get_amount();
    Symbol get_symbol();
    int get_price_level();
    OrderSide get_side();

    bool set_price(double new_price);
    bool set_amount(double new_amount);

    void print();
};

#endif