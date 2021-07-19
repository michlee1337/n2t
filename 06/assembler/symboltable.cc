#include "symboltable.h"

namespace n2t {

void SymbolTable::RegisterLabel(std::string label, int line) {
    symbol_table_[label] = line;
}

void SymbolTable::RegisterSymbol(std::string symbol) {
    if (symbol_table_.find(symbol) == symbol_table_.end()) {
        symbol_table_[symbol] = -1;
    }
}

void SymbolTable::complete() {
    int available = 16;
    for (auto& it: symbol_table_) {
        if (it.second == -1) {
            it.second = available;
            ++available;
        }
        std::cout << it.first << ":"<< it.second << std::endl;
    }
    return;
}

std::string SymbolTable::value(std::string symbol) {
    std::unordered_map< std::string, int >::const_iterator it = symbol_table_.find(symbol);
    if (it == symbol_table_.end()) {
        throw "Symbol not handled properly internally";
    }
    return std::to_string(it -> second);
}
}
