#include "include/orderbook.h"
#include <algorithm>

OrderBook::OrderBook() : nextOrderId(1) {}

int OrderBook::addOrder(OrderType type, double price, double amount)
{
    Order order(nextOrderId++, type, price, amount);
    orders.push_back(order);
    return order.id;
}
