#include "order.h"
#include <memory>

struct Book
{
    SharedOrderPtr head;
    SharedOrderPtr tail;

    Book(OrderSide side, Symbol symbol);

    bool add_order(SharedOrderPtr order_ptr);
    bool remove_order(SharedOrderPtr order_ptr);
    void print() const;
};