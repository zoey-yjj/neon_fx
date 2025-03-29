#include "symbol.h"
#include <iostream>
#include <string>

namespace SymbolUtils
{
    std::string SymbolToString(Symbol sym)
    {
        switch (sym)
        {
        case Symbol::EUR_USD:
            return "EUR/USD";
        case Symbol::USD_JPY:
            return "USD/JPY";
        default:
            return "UNKNOWN";
        }
    }

    void PrintSymbols()
    {
        std::cout << "Available Symbols:\n";
        for (int i = 0; i < static_cast<int>(Symbol::NUM_SYMBOLS); ++i)
        {
            std::cout << i + 1 << ": "
                      << SymbolToString(static_cast<Symbol>(i)) << "\n";
        }
    }
}
