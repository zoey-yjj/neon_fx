#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

enum class Symbol
{
    EUR_USD,
    USD_JPY,
    NUM_SYMBOLS,
};

namespace SymbolUtils
{
    std::string SymbolToString(Symbol sym);
    void PrintSymbols();
}

#endif