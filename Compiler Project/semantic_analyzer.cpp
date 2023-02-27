#include "semantic_analyzer.h"

#include <iostream>

#include "ast.h"

void SemanticAnalyzer::Analyze() {
  // Parse the top-level block of the program
  BlockStatement* block = ParseBlock();

  // Make sure that the main function is defined
  if (functions_.count("main") == 0) {
    std::cerr << "Error: main function is not defined" << std::endl;
    exit(1);
  }

  // Make sure that the main function has the correct signature
  Function main = functions_["main"];
  if (main.return_type != TYPE_VOID || main.parameters.size() > 0) {
    std::cerr << "Error: main function has invalid signature" << std::endl;
    exit(1);
  }
}

BlockStatement* SemanticAnalyzer::ParseBlock() {
  std::vector< Statement*> statements;

  // Parse statements until the end of the block is reached
  while (true) {
    Token token = lexer_.Peek();
    if (token.type == TOKEN_RIGHT_BRACE) {
      lexer_.NextToken();
      break;
    }
    statements.push_back(ParseStatement());
  }
  return new Block Statement(statements);
}

Statement* SemanticAnalyzer::ParseStatement() {
  Token token = lexer_.Peek();
  switch (token.type) {
    case TOKEN_IF:
      return ParseIf Statement();
    case TOKEN_FOR:
      return ParseFor Statement();
    case TOKEN_WHILE:
      return ParseWhile Statement();
    case TOKEN_RETURN:
      return ParseReturn Statement();
    case TOKEN_PRINT:
      return ParsePrint Statement();
    case TOKEN_LEFT_BRACE:
      return ParseBlock();
    default:
      return ParseExpressionStatement();
