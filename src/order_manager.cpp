#include "order_manager.h"
#include <iostream>

OrderManager::OrderManager() : next_order_id(1) {}

bool OrderManager::submit_order(OrderSide side, double price, double amount, Symbol symbol)
{
    Order order(next_order_id++, side, price, amount, symbol);
    std::shared_ptr<Order> order_ptr = std::make_shared<Order>(order);
    return submit_order_ptr(order_ptr);
}

bool OrderManager::submit_order_ptr(std::shared_ptr<Order> order_ptr)
{
    active_orders.emplace(order_ptr->get_id(), order_ptr);
    OrderBook &orderbook = symbol_orderbooks[order_ptr->get_symbol()];
    return orderbook.add_order(order_ptr);
}

bool OrderManager::delete_order(int id)
{
    auto it = active_orders.find(id);
    if (it == active_orders.end())
    {
        return false;
    }
    std::shared_ptr<Order> order_ptr = it->second;
    OrderBook &orderbook = symbol_orderbooks[order_ptr->get_symbol()];
    orderbook.delete_order(order_ptr, id);
    active_orders.erase(it);
    return true;
}

bool OrderManager::edit_order(int id, double new_price, double new_amount)
{
    auto it = active_orders.find(id);
    if (it == active_orders.end())
    {
        return false;
    }
    std::shared_ptr<Order> order_ptr = it->second;
    if (new_price != 0.0)
    {
        delete_order(id);
        order_ptr->change_price(new_price);
        submit_order_ptr(order_ptr);
    }
    order_ptr->change_amount(new_amount);
    return true;
}

void OrderManager::print_orderbooks()
{
    for (auto &[symbol, orderbook] : symbol_orderbooks)
    {
        std::cout << "\n\033[1m=================== "
                  << SymbolUtils::SymbolToString(symbol) << " ===================\033[0m\n";
        orderbook.print_orders();
        std::cout << "\n\033[1m===================== END =====================\033[0m\n";
    }
}