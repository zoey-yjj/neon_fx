#include "order.h"
#include "orderbook.h"
#include <iostream>

int main()
{
    OrderBook orderbook;
    while (true)
    {
        std::cout << "\n1. Submit Order\n2. Print Order Book\n3. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Side (1=BUY, 2=SELL): ";
            int i_side;
            std::cin >> i_side;
            OrderSide side = (i_side == 1) ? OrderSide::BUY : OrderSide::SELL;

            double price;
            std::cout << "Price: ";
            std::cin >> price;

            double amount;
            std::cout << "Amount: ";
            std::cin >> amount;

            if (orderbook.checkOrder(side, price))
            {
                orderbook.addOrder(side, price, amount);
            }
        }
        else if (choice == 2)
        {
            orderbook.printOrders();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input, please enter again.\n";
        }
    }

    return 0;
}