#include <map>
#include <string>

class SymbolTable {
 public:
  // Add a symbol to the table
  void AddSymbol(std::string name, std::string type);

  // Look up a symbol in the table
  std::string LookupSymbol(std::string name);

  // Remove a symbol from the table
  void RemoveSymbol(std::string name);

 private:
  std::map<std::string, std::string> symbols_;
};

void SymbolTable::AddSymbol(std::string name, std::string type) {
  symbols_[name] = type;
}

std::string SymbolTable::LookupSymbol(std::string name) {
  if (symbols_.count(name) == 0) {
    return "";
  } else {
    return symbols_[name];
  }
}

void SymbolTable::RemoveSymbol(std::string name) {
  symbols_.erase(name);
}
