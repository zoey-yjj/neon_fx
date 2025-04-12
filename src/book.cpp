#include "book.h"
#include <memory>

Book::Book()
{
    head->next = tail;
    tail->prev = head;
}

bool Book::add_order(std::shared_ptr<Order> order_ptr)
{
    std::shared_ptr<Order> prev = tail->prev;
    tail->prev = order_ptr;
    prev->next = order_ptr;
    order_ptr->prev = prev;
    order_ptr->next = tail;
    return true;
}

bool Book::remove_order(std::shared_ptr<Order> order_ptr)
{
    std::shared_ptr<Order> prev = order_ptr->prev;
    std::shared_ptr<Order> next = order_ptr->next;
    prev->next = next;
    next->prev = prev;
    order_ptr->prev = nullptr;
    order_ptr->next = nullptr;
    // return true if all orders are removed, this book is empty
    return (head->next == tail);
}