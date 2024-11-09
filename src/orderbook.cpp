#include "orderbook.h"
#include <algorithm>
#include <vector>

OrderBook::OrderBook() : nextOrderId(1) {}

int OrderBook::addOrder(OrderType type, double price, double amount)
{
    Order order(nextOrderId++, type, price, amount);
    orders.push_back(order);
    return order.id;
}

std::vector<Order> OrderBook::getOrders() const
{
    return orders;
}