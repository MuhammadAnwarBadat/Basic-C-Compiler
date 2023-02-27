#pragma once

#include <unordered_map>
#include <vector>

#include "ast.h"
#include "lexer.h"

enum DataType {
  TYPE_INTEGER,
  TYPE_FLOAT,
  TYPE_BOOLEAN,
  TYPE_STRING,
  TYPE_VOID
};

struct Variable {
  DataType type;
  std::string name;
};

struct Function {
  DataType return_type;
  std::string name;
  std::vector<Variable> parameters;
  BlockStatement* body;
};

class SemanticAnalyzer {
public:
  SemanticAnalyzer(Lexer& lexer) : lexer_(lexer) {}

  void Analyze();

private:
  Lexer& lexer_;
  std::unordered_map<std::string, Variable> variables_;
  std::unordered_map<std::string, Function> functions_;

  // Helper functions for parsing different parts of the program
  BlockStatement* ParseBlock();
  Statement* ParseStatement();
  Expression* ParseExpression();
  Expression* ParseTerm();
  Expression* ParseFactor();
};
