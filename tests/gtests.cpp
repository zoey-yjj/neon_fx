#include "../include/order_manager.h"
#include <cassert>
#include <iostream>

void TestAddOrders()
{
    OrderBook orderbook;
    Order order1(1, OrderSide::BUY, 1.2, 3.5, Symbol::EUR_USD);
    SharedOrderPtr order1_ptr = std::make_shared<Order>(order1);
    orderbook.add_order(order1_ptr);
    Order order2(2, OrderSide::SELL, 3.2, 3.5, Symbol::EUR_USD);
    SharedOrderPtr order2_ptr = std::make_shared<Order>(order2);
    orderbook.add_order(order2_ptr);
    Order order3(3, OrderSide::BUY, 2.6, 3.5, Symbol::EUR_USD);
    SharedOrderPtr order3_ptr = std::make_shared<Order>(order3);
    orderbook.add_order(order3_ptr);

    const auto &bids = orderbook.get_bids();
    assert(bids.size() == 2);
    assert(bids.rbegin()->first == int(2.6 * 10000));
    const auto &asks = orderbook.get_asks();
    assert(asks.size() == 1);
    assert(asks.rbegin()->first == int(3.2 * 10000));
}

void TestDeleteOrders()
{
    OrderBook orderbook;
    Order order1(1, OrderSide::SELL, 3.2, 3.5, Symbol::EUR_USD);
    SharedOrderPtr order1_ptr = std::make_shared<Order>(order1);
    orderbook.add_order(order1_ptr);
    Order order2(2, OrderSide::BUY, 2.6, 3.5, Symbol::EUR_USD);
    SharedOrderPtr order2_ptr = std::make_shared<Order>(order2);
    orderbook.add_order(order2_ptr);
    Order order3(3, OrderSide::BUY, 2.9, 0.5, Symbol::EUR_USD);
    SharedOrderPtr order3_ptr = std::make_shared<Order>(order3);
    orderbook.add_order(order3_ptr);

    orderbook.delete_order(order3_ptr);
    const auto &bids = orderbook.get_bids();
    assert(bids.size() == 1);
    assert(bids.rbegin()->first == int(2.6 * 10000));
}

void TestEditOrders()
{
    OrderManager order_manager;
    order_manager.submit_order(OrderSide::SELL, 3.2, 3.5, Symbol::EUR_USD);
    order_manager.submit_order(OrderSide::BUY, 2.6, 3.5, Symbol::EUR_USD);
    order_manager.submit_order(OrderSide::BUY, 2.9, 0.5, Symbol::EUR_USD);

    order_manager.edit_order(1, 2.2, 1.0);
    SharedOrderPtr order_ptr = order_manager.get_order(1);
    assert(order_ptr->get_price() == 2.2);
    assert(order_ptr->get_amount() == 1.0);
}

int main()
{
    TestAddOrders();
    TestDeleteOrders();
    TestEditOrders();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}