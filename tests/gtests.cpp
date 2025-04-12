#include "../include/orderbook.h"
#include <cassert>
#include <iostream>

void TestAddOrders()
{
    OrderBook book;

    Order order1(1, OrderSide::BUY, 1.2, 3.5, Symbol::EUR_USD);
    SharedOrderPtr order1_ptr = std::make_shared<Order>(order1);
    book.add_order(order1_ptr);
    Order order2(2, OrderSide::SELL, 3.2, 3.5, Symbol::EUR_USD);
    SharedOrderPtr order2_ptr = std::make_shared<Order>(order2);
    book.add_order(order2_ptr);
    Order order3(3, OrderSide::BUY, 2.6, 3.5, Symbol::EUR_USD);
    SharedOrderPtr order3_ptr = std::make_shared<Order>(order3);
    book.add_order(order3_ptr);

    const auto &bids = book.get_bids();
    assert(bids.size() == 2);
    assert(bids.rbegin()->first == int(2.6 * 10000));
}

void TestPricePriority()
{
    OrderBook book;
    Order order1(1, OrderSide::BUY, 1.0, 1.0, Symbol::EUR_USD);
    SharedOrderPtr order1_ptr = std::make_shared<Order>(order1);
    book.add_order(order1_ptr);
    Order order2(2, OrderSide::BUY, 2.0, 1.0, Symbol::EUR_USD);
    SharedOrderPtr order2_ptr = std::make_shared<Order>(order2);
    book.add_order(order2_ptr);

    assert(book.get_bids().rbegin()->first == int(2.0 * 10000));
}

int main()
{
    TestAddOrders();
    TestPricePriority();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}