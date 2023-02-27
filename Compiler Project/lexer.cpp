#include "lexer.h"

#include <cctype>
#include <sstream>
#include <unordered_map>

Lexer::Lexer(std::istream& input) : input_(input), line_(1) {
  // Initialize the keyword map
  keywords_["if"] = TOKEN_IF;
  keywords_["else"] = TOKEN_ELSE;
  keywords_["for"] = TOKEN_FOR;
  keywords_["while"] = TOKEN_WHILE;
  keywords_["break"] = TOKEN_BREAK;
  keywords_["continue"] = TOKEN_CONTINUE;
  keywords_["return"] = TOKEN_RETURN;
  keywords_["print"] = TOKEN_PRINT;
}

Token Lexer::NextToken() {
  // Read and skip whitespace characters
  char c = input_.get();
  while (isspace(c)) {
    if (c == '\n') {
      line_++;
    }
    c = input_.get();
  }

  // Identify the token type based on the first non-whitespace character
  Token token;
  token.line = line_;
  switch (c) {
    case '+':
      token
