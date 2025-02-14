#include <cassert>
#include "../include/orderbook.h"

void TestAddOrders()
{
    OrderBook book;

    book.addOrder(OrderSide::BUY, 1.2, 3.5);
    book.addOrder(OrderSide::SELL, 3.2, 3.5);
    book.addOrder(OrderSide::BUY, 2.6, 3.5);

    const auto &bids = book.getBids();
    assert(bids.size() == 2);
    assert(bids.begin()->first == 2.6);
}

void TestPricePriority()
{
    OrderBook book;
    book.addOrder(OrderSide::BUY, 1.0, 1.0);
    book.addOrder(OrderSide::BUY, 2.0, 1.0);

    assert(book.getBids().begin()->first == 2.0);
}

int main()
{
    TestAddOrders();
    TestPricePriority();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}