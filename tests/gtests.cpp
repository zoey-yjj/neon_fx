#include <cassert>
#include "../include/orderbook.h"
#include <iostream>

void TestAddOrders()
{
    OrderBook book;

    Order order1(1, OrderSide::BUY, 1.2, 3.5, Symbol::EUR_USD);
    book.add_order(&order1);
    Order order2(2, OrderSide::SELL, 3.2, 3.5, Symbol::EUR_USD);
    book.add_order(&order2);
    Order order3(3, OrderSide::BUY, 2.6, 3.5, Symbol::EUR_USD);
    book.add_order(&order3);

    const auto &bids = book.get_bids();
    assert(bids.size() == 2);
    assert(bids.begin()->first == 2.6);
}

void TestPricePriority()
{
    OrderBook book;
    Order order1(1, OrderSide::BUY, 1.0, 1.0, Symbol::EUR_USD);
    book.add_order(&order1);
    Order order2(2, OrderSide::BUY, 2.0, 1.0, Symbol::EUR_USD);
    book.add_order(&order2);

    assert(book.get_bids().begin()->first == 2.0);
}

int main()
{
    TestAddOrders();
    TestPricePriority();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}