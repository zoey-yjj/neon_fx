#include "book.h"
#include <memory>

Book::Book(OrderSide side, Symbol symbol)
{
    Order dummy_head(-1, side, -1.0, -1.0, symbol);
    Order dummy_tail(-1, side, -1.0, -1.0, symbol);
    head = std::make_shared<Order>(dummy_head);
    tail = std::make_shared<Order>(dummy_tail);
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
    return (head->next->get_id() == tail->get_id());
}

void Book::print() const
{
    auto p = head->next;
    while (p->get_id() != tail->get_id())
    {
        p->print();
        p = p->next;
    }
}