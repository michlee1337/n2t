#include "symboltable/symboltable.h"

namespace n2t {

void SymbolTable::RegisterLabel(std::string label, int line) {
  symbol_table_[label] = line;
}

void SymbolTable::RegisterSymbol(std::string symbol) {
  if (symbol_table_.find(symbol) == symbol_table_.end()) {
    symbol_order_.push_back(symbol);  // remember insertion order
    symbol_table_[symbol] = -1;
  }
}

void SymbolTable::complete() {
  int available = 16;
  for (std::string symbol : symbol_order_) {
    if (symbol_table_[symbol] == -1) {
      symbol_table_[symbol] = available;
      ++available;
    }
  }
  return;
}

std::string SymbolTable::value(std::string symbol) {
  std::unordered_map< std::string, int >::const_iterator it =
    symbol_table_.find(symbol);
  if (it == symbol_table_.end()) {
    throw "Symbol not handled properly internally";
  }
  return std::to_string(it -> second);
}
}  // namespace n2t
