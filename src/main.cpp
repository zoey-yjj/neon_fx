#include "order.h"
#include "orderbook.h"
#include <iostream>

int main()
{
    OrderBook orderbook;
    orderbook.addOrder(OrderSide::BUY, 1.2, 3.5);
    orderbook.addOrder(OrderSide::SELL, 3.2, 3.5);
    orderbook.addOrder(OrderSide::BUY, 2.6, 3.5);
    orderbook.addOrder(OrderSide::SELL, 5.6, 3.5);
    orderbook.addOrder(OrderSide::BUY, 1.8, 3.5);
    orderbook.addOrder(OrderSide::SELL, 4.1, 3.5);
    std::cout << "orderbook contains: " << std::endl;
    orderbook.printOrders();

    return 0;
}