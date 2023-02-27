#pragma once

#include <unordered_map>
#include <vector>

#include "ast.h"

class CodeGenerator {
public:
  CodeGenerator();

  void Generate(BlockStatement* block);

private:
  void Generate(Statement* stmt);
  void Generate(Expression* expr);

  std::vector<int> code_;
  std::unordered_map<std::string, int> strings_;
  std::unordered_map<std::string, int> variables_;
  std::unordered_map<std::string, int> functions_;
};
