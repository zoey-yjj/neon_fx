#include "order.h"
#include <ctime>
#include <iomanip>

Order::Order(int id, OrderSide side, double price, double amount)
    : id(id), side(side), price(price), amount(amount),
      timestamp(time(nullptr)), status(OrderStatus::PENDING) {}

std::ostream &operator<<(std::ostream &os, const Order &order)
{
    os << "Order #" << order.id
       << " [" << (order.side == OrderSide::BUY ? "BUY" : "SELL") << "] "
       << std::fixed << std::setprecision(4)
       << order.amount << " EUR @ " << order.price;
    return os;
}