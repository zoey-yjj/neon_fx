#include "order_manager.h"
#include <iostream>
#include <limits>

int main()
{
    OrderManager order_manager;
    while (true)
    {
        std::cout << "\n1. Submit Order\n2. Print Order Book\n3. Delete Order\n4. Edit Order\n5. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            SymbolUtils::PrintSymbols();
            std::cout << "Select Symbol (1-"
                      << static_cast<int>(Symbol::NUM_SYMBOLS) << "): ";

            int symbolChoice;
            while (!(std::cin >> symbolChoice) || symbolChoice < 1 ||
                   symbolChoice > static_cast<int>(Symbol::NUM_SYMBOLS))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again: ";
            }
            Symbol symbol = static_cast<Symbol>(symbolChoice - 1);

            std::cout << "Side (1=BUY, 2=SELL): ";
            int i_side;
            while (!(std::cin >> i_side) || symbolChoice < 1 || symbolChoice > 2)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again: ";
            }
            OrderSide side = (i_side == 1) ? OrderSide::BUY : OrderSide::SELL;

            double price;
            std::cout << "Price: ";
            std::cin >> price;

            double amount;
            std::cout << "Amount: ";
            std::cin >> amount;

            order_manager.submit_order(side, price, amount, symbol);
        }
        else if (choice == 2)
        {
            order_manager.print_orderbooks();
        }
        else if (choice == 3)
        {
            std::cout << "Delete order id: ";
            int id;
            std::cin >> id;
            order_manager.delete_order(id);
        }
        else if (choice == 4)
        {
            std::cout << "Edit order id: ";
            int id;
            std::cin >> id;
            double new_price;
            std::cout << "New price: (enter 0 if not changing) ";
            std::cin >> new_price;
            double new_amount;
            std::cout << "New amount: (enter 0 if not changing) ";
            std::cin >> new_amount;
            order_manager.edit_order(id, new_price, new_amount);
        }
        else if (choice == 5)
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