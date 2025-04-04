#include "order.h"
#include <ctime>
#include <iostream>
#include <iomanip>

Order::Order(int id, OrderSide side, double price, double amount, Symbol symbol)
    : id(id), symbol(symbol), side(side), price(price), amount(amount),
      timestamp(time(nullptr)), status(OrderStatus::PENDING) {}

double Order::get_price()
{
    return price;
}

Symbol Order::get_symbol()
{
    return symbol;
}

OrderSide Order::get_side()
{
    return side;
}

void Order::print()
{
    std::cout << "Order #" << id
              << " [" << (side == OrderSide::BUY ? "BUY" : "SELL") << "] "
              << std::fixed << std::setprecision(4)
              << "amount " << amount << " @ " << price << std::endl;
}