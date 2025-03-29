#include "order.h"
#include <ctime>
#include <iostream>
#include <iomanip>

Order::Order(int id, OrderSide side, double price, double amount, Symbol symbol)
    : id(id), symbol(symbol), side(side), price(price), amount(amount),
      timestamp(time(nullptr)), status(OrderStatus::PENDING) {}

void Order::print()
{
    std::cout << "Order #" << id
              << " [" << (side == OrderSide::BUY ? "BUY" : "SELL") << "] "
              << std::fixed << std::setprecision(4)
              << "amount " << amount << " @ " << price << std::endl;
}