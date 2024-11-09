#include "order.h"
#include "orderbook.h"
#include <iostream>

int main()
{
    OrderBook orderbook;
    orderbook.addOrder(OrderType::BUY, 1.2, 3.5);
    std::cout << "orderbook contains: " << std::endl;
    for (const auto &order : orderbook.getOrders())
    {
        std::cout << order << std::endl;
    }

    return 0;
}