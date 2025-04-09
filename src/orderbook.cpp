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

bool OrderBook::add_order(std::shared_ptr<Order> order_ptr)
{
    if (!check_order(order_ptr->get_side(), order_ptr->get_price()))
        return false;

    int price_level = order_ptr->get_price_level();
    if (order_ptr->get_side() == OrderSide::BUY)
    {
        bids[price_level].push_back(order_ptr);
    }
    else
    {
        asks[price_level].push_back(order_ptr);
    }
    return true;
}

bool OrderBook::delete_order(std::shared_ptr<Order> order_ptr, int id)
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
    auto order_it = std::find_if(
        orders.begin(), orders.end(),
        [&id](const std::shared_ptr<Order> &o)
        {
            return o->id == id;
        });
    if (order_it == orders.end())
    {
        std::cout << "delete failed due to: order is not found in price level" << std::endl;
        return false;
    }
    orders.erase(order_it);
    if (orders.empty())
    {
        book.erase(price_it);
    }
    return true;
}

const std::map<int, std::vector<std::shared_ptr<Order>>> &OrderBook::get_bids()
{
    return bids;
}

const std::map<int, std::vector<std::shared_ptr<Order>>> &OrderBook::get_asks()
{
    return asks;
}

void OrderBook::print_orders()
{
    if (!bids.empty())
    {
        std::cout << "\n\033[32m============= BID ORDERS (BUY) =============\033[0m\n";
        for (const auto &[_, orders] : bids)
        {
            for (const auto &order : orders)
            {
                order->print();
            }
        }
    }
    else
    {
        std::cout << "\n\033[32m[ No active bid orders ]\033[0m\n";
    }

    if (!asks.empty())
    {
        std::cout << "\n\033[31m============= ASK ORDERS (SELL) =============\033[0m\n";
        for (const auto &[_, orders] : asks)
        {
            for (const auto &order : orders)
            {
                order->print();
            }
        }
    }
    else
    {
        std::cout << "\n\033[31m[ No active ask orders ]\033[0m\n";
    }
}