#include "book.h"
#include <memory>

Book::Book()
{
    head->next = tail;
    tail->prev = head;
}

bool Book::add_order(SharedOrderPtr order_ptr)
{
    SharedOrderPtr prev = tail->prev;
    tail->prev = order_ptr;
    prev->next = order_ptr;
    order_ptr->prev = prev;
    order_ptr->next = tail;
    return true;
}

bool Book::remove_order(SharedOrderPtr order_ptr)
{
    SharedOrderPtr prev = order_ptr->prev;
    SharedOrderPtr next = order_ptr->next;
    prev->next = next;
    next->prev = prev;
    order_ptr->prev = nullptr;
    order_ptr->next = nullptr;
    // return true if all orders are removed, this book is empty
    return (head->next == tail);
}

void Book::print() const
{
}