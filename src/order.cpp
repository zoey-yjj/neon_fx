#include "order.h"
#include <ctime>
#include <iostream>
#include <iomanip>

Order::Order(int id, OrderSide side, double price, double amount, Symbol symbol)
    : id(id), symbol(symbol), side(side), price(price), amount(amount),
      timestamp(time(nullptr)), status(OrderStatus::PENDING) {}

int Order::get_id()
{
    return id;
}

double Order::get_price()
{
    return price;
}

double Order::get_amount()
{
    return amount;
}

Symbol Order::get_symbol()
{
    return symbol;
}

OrderSide Order::get_side()
{
    return side;
}

int Order::get_price_level()
{
    return int(price * 10000);
}

bool Order::set_price(double new_price)
{
    if (new_price <= 0.0)
        return false;
    price = new_price;
    return true;
}

bool Order::set_amount(double new_amount)
{
    if (new_amount <= 0.0)
        return false;
    amount = new_amount;
    return true;
}

void Order::print()
{
    std::cout << "Order #" << id
              << " [" << (side == OrderSide::BUY ? "BUY" : "SELL") << "] "
              << std::fixed << std::setprecision(4)
              << "amount " << amount << " @ " << price << std::endl;
}