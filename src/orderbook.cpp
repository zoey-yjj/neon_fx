#include "orderbook.h"
#include <algorithm>
#include <vector>
#include <iostream>

OrderBook::OrderBook() : nextOrderId(1) {}

bool OrderBook::checkOrder(OrderSide side, double price)
{
    if (side == OrderSide::BUY && !asks.empty())
    {
        double bestAskPrice = asks.begin()->first;
        if (price >= bestAskPrice)
        {
            std::cout << "Reject buy order price " << price
                      << " >= best ask price " << bestAskPrice << std::endl;
            return false;
        }
    }
    if (side == OrderSide::SELL && !bids.empty())
    {
        double bestBidPrice = bids.begin()->first;
        if (price <= bestBidPrice)
        {
            std::cout << "Reject sell order price " << price
                      << " <= best bid price " << bestBidPrice << std::endl;
            return false;
        }
    }
    return true;
}

int OrderBook::addOrder(OrderSide side, double price, double amount)
{
    Order order(nextOrderId++, side, price, amount);
    if (side == OrderSide::BUY)
    {
        bids[order.price].push_back(order);
    }
    else
    {
        asks[order.price].push_back(order);
    }
    return order.id;
}

const std::map<double, std::vector<Order>, std::greater<double>> &OrderBook::getBids()
{
    return bids;
}

const std::map<double, std::vector<Order>> &OrderBook::getAsks()
{
    return asks;
}

void OrderBook::printOrders()
{
    if (!bids.empty())
    {
        std::cout << "\n\033[32m============= BID ORDERS (BUY) =============\033[0m\n";
        for (const auto &[_, orders] : bids)
        {
            for (const auto &order : orders)
            {
                std::cout << order << std::endl;
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
                std::cout << order << std::endl;
            }
        }
    }
    else
    {
        std::cout << "\n\033[31m[ No active ask orders ]\033[0m\n";
    }
}