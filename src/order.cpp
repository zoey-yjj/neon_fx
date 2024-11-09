#include "order.h"
#include <ctime>
#include <iomanip>

Order::Order(int id, OrderType type, double price, double amount)
    : id(id), type(type), price(price), amount(amount),
      timestamp(time(nullptr)), status(OrderStatus::PENDING) {}

std::ostream &operator<<(std::ostream &os, const Order &order)
{
    os << "Order #" << order.id
       << " [" << (order.type == OrderType::BUY ? "BUY" : "SELL") << "] "
       << std::fixed << std::setprecision(4)
       << order.amount << " EUR @ " << order.price;
    return os;
}