#include "code_generator.h"

#include <iostream>

#include "ast.h"

CodeGenerator::CodeGenerator() {
  // Reserve space for the strings table at the beginning of the code
  code_.push_back(0);  // Placeholder for the number of strings
  code_.push_back(0);  // Placeholder for the length of the strings table

  // Reserve space for the function table at the end of the code
  code_.push_back(0);  // Placeholder for the number of functions
  code_.push_back(0);  // Placeholder for the length of the function table
}

void CodeGenerator::Generate(Block Statement* block) {
  // Generate code for each statement in the block
  for (Statement* stmt : block->GetStatements()) {
    Generate(stmt);
  }

  // Fill in the function table at the end of the code
  int function_count = functions_.size();
  int function_table_offset = code_.size();
  code_[2] = function_count;
  code_[3] = function_table_offset;
  for (const auto& function : functions_) {
    code_.push_back(function.second);  // Offset of the function code
    code_.push_back(function.first.size());  // Length of the function name
    for (char c : function.first) {
      code_.push_back(c);
    }
  }
}

void CodeGenerator::Generate( Statement* stmt) {
  switch (stmt->GetType()) {
    case STATEMENT_BLOCK:
      Generate(static_cast<BlockStatement*>(stmt));
      break;
    case STATEMENT_IF:
      Generate(static_cast<If Statement*>(stmt));
      break;
    case STATEMENT_FOR:
      Generate(static_cast<For Statement*>(stmt));
      break;
    case STATEMENT_WHILE:
      Generate(static_cast<While Statement*>(stmt));
      break;
    case STATEMENT_RET
