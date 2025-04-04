#include "orderbook.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

class OrderManager
{
private:
    // map order id to order, support fast check and remove
    std::unordered_map<int, std::shared_ptr<Order>> active_orders;
    // map symbol to sorted orderbook, support fast matching
    std::unordered_map<Symbol, OrderBook> symbol_orderbooks;
    // order id is auto generated integer in increasing order
    int next_order_id;

public:
    OrderManager();
    bool submit_order(OrderSide side, double price, double amount, Symbol symbol);
    bool delete_order(int id);
    void print_orderbooks();
};