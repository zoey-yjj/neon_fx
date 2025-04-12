#include "order.h"
#include <memory>

struct Book
{
    std::shared_ptr<Order> head = nullptr;
    std::shared_ptr<Order> tail = nullptr;

    Book();

    bool add_order(std::shared_ptr<Order> order_ptr);
    bool remove_order(std::shared_ptr<Order> order_ptr);
};