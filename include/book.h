#include "order.h"
#include <memory>

struct Book
{
    SharedOrderPtr head = nullptr;
    SharedOrderPtr tail = nullptr;

    Book();

    bool add_order(SharedOrderPtr order_ptr);
    bool remove_order(SharedOrderPtr order_ptr);
    void print() const;
};