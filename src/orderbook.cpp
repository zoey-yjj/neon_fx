#include "orderbook.h"
#include <algorithm>
#include <vector>
#include <iostream>

bool OrderBook::check_order(OrderSide side, double price)
{
    if (side == OrderSide::BUY && !asks.empty())
    {
        double best_ask_price = asks.begin()->first;
        if (price >= best_ask_price)
        {
            std::cout << "Reject buy order price " << price
                      << " >= best ask price " << best_ask_price << std::endl;
            return false;
        }
    }
    if (side == OrderSide::SELL && !bids.empty())
    {
        double best_bid_price = bids.begin()->first;
        if (price <= best_bid_price)
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
    if (!check_order(order_ptr->side, order_ptr->price))
        return false;

    if (order_ptr->side == OrderSide::BUY)
    {
        bids[order_ptr->price].push_back(order_ptr);
    }
    else
    {
        asks[order_ptr->price].push_back(order_ptr);
    }
    return true;
}

const std::map<double, std::vector<std::shared_ptr<Order>>, std::greater<double>> &OrderBook::get_bids()
{
    return bids;
}

const std::map<double, std::vector<std::shared_ptr<Order>>> &OrderBook::get_asks()
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