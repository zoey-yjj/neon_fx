#include "include/order.h"
#include <ctime>

Order::Order(int id, OrderType type, double price, double amount)
    : id(id), type(type), price(price), amount(amount),
      timestamp(time(nullptr)), status(OrderStatus::PENDING) {}
