#include "orderbook.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

class OrderManager
{
private:
    // price is converted to integer due to floating point issue
    // map order id to order, support fast check and remove
    std::unordered_map<int, SharedOrderPtr> active_orders;
    // map symbol to sorted orderbook, support fast matching
    std::unordered_map<Symbol, OrderBook> symbol_orderbooks;
    // order id is auto generated integer in increasing order
    int next_order_id;

public:
    OrderManager();
    bool submit_order(OrderSide side, double price, double amount, Symbol symbol);
    bool submit_order_ptr(SharedOrderPtr order_ptr);
    bool delete_order(int id);
    bool edit_order(int id, double new_price, double new_amount);
    SharedOrderPtr get_order(int id);
    void print_orderbooks();
};