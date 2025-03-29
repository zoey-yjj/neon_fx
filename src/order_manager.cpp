#include "order_manager.h"
#include <iostream>

OrderManager::OrderManager() : next_order_id(1) {}

bool OrderManager::submit_order(OrderSide side, double price, double amount, Symbol symbol)
{
    Order order(next_order_id++, side, price, amount, symbol);
    std::shared_ptr<Order> order_ptr = std::make_shared<Order>(order);
    active_orders.emplace(order.id, order_ptr);
    OrderBook &orderbook = symbol_orderbooks[symbol];
    return orderbook.add_order(order_ptr);
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