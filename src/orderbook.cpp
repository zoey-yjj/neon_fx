#include "orderbook.h"
#include <algorithm>
#include <vector>
#include <iostream>

bool OrderBook::check_order(OrderSide side, double price)
{
    if (side == OrderSide::BUY && !asks.empty())
    {
        double best_ask_price = asks.begin()->first;
        if (int(price * 10000) >= best_ask_price)
        {
            std::cout << "Reject buy order price " << price
                      << " >= best ask price " << best_ask_price << std::endl;
            return false;
        }
    }
    if (side == OrderSide::SELL && !bids.empty())
    {
        double best_bid_price = bids.begin()->first;
        if (int(price * 10000) <= best_bid_price)
        {
            std::cout << "Reject sell order price " << price
                      << " <= best bid price " << best_bid_price << std::endl;
            return false;
        }
    }
    return true;
}

bool OrderBook::add_order(SharedOrderPtr order_ptr)
{
    if (!check_order(order_ptr->get_side(), order_ptr->get_price()))
        return false;

    int price_level = order_ptr->get_price_level();
    if (order_ptr->get_side() == OrderSide::BUY)
    {
        bids[price_level].add_order(order_ptr);
    }
    else
    {
        asks[price_level].add_order(order_ptr);
    }
    return true;
}

bool OrderBook::delete_order(SharedOrderPtr order_ptr, int id)
{
    auto &book = (order_ptr->get_side() == OrderSide::BUY) ? bids : asks;
    int price_level = order_ptr->get_price_level();
    auto price_it = book.find(price_level);
    if (price_it == book.end())
    {
        std::cout << "delete failed due to: price level "
                  << price_level << " is not found in orderbook" << std::endl;
        return false;
    }
    auto &orders = price_it->second;
    if (orders.remove_order(order_ptr))
    {
        book.erase(price_it);
    }
    return true;
}

const std::map<int, Book> &OrderBook::get_bids()
{
    return bids;
}

const std::map<int, Book> &OrderBook::get_asks()
{
    return asks;
}

void OrderBook::print_orders()
{
    if (!bids.empty())
    {
        std::cout << "\n\033[32m============= BID ORDERS (BUY) =============\033[0m\n";
        for (const auto &[_, book] : bids)
            book.print();
    }
    else
    {
        std::cout << "\n\033[32m[ No active bid orders ]\033[0m\n";
    }

    if (!asks.empty())
    {
        std::cout << "\n\033[31m============= ASK ORDERS (SELL) =============\033[0m\n";
        for (const auto &[_, book] : asks)
            book.print();
    }
    else
    {
        std::cout << "\n\033[31m[ No active ask orders ]\033[0m\n";
    }
}