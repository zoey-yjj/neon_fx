#include "order.h"
#include "orderbook.h"
#include <iostream>

int main()
{
    OrderBook orderbook;
    orderbook.addOrder(OrderSide::BUY, 1.2, 3.5);
    std::cout << "orderbook contains: " << std::endl;
    orderbook.printOrders();

    return 0;
}