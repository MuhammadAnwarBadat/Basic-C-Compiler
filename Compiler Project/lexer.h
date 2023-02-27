#pragma once

#include <istream>
#include <string>

enum TokenType {
  // Keywords
  TOKEN_IF,
  TOKEN_ELSE,
  TOKEN_FOR,
  TOKEN_WHILE,
  TOKEN_BREAK,
  TOKEN_CONTINUE,
  TOKEN_RETURN,
  TOKEN_PRINT,

  // Operators
  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_MULTIPLY,
  TOKEN_DIVIDE,
  TOKEN_MODULO,
  TOKEN_ASSIGN,
  TOKEN_EQUAL,
  TOKEN_NOT_EQUAL,
  TOKEN_GREATER_THAN,
  TOKEN_LESS_THAN,
  TOKEN_GREATER_THAN_EQUAL,
  TOKEN_LESS_THAN_EQUAL,
  TOKEN_AND,
  TOKEN_OR,
  TOKEN_NOT,

  // Delimiters
  TOKEN_LEFT_PAREN,
  TOKEN_RIGHT_PAREN,
  TOKEN_LEFT_BRACE,
  TOKEN_RIGHT_BRACE,
  TOKEN_COMMA,
  TOKEN_COLON,
  TOKEN_SEMICOLON,

  // Literals
  TOKEN_IDENTIFIER,
  TOKEN_INTEGER,
  TOKEN_FLOAT,
  TOKEN_STRING,

  // Others
  TOKEN_EOF
};

struct Token {
  TokenType type;
  std::string lexeme;
  int line;
};

class Lexer {
public:
  Lexer(std::istream& input);

  Token NextToken();
  Token Peek();

private:
  std::istream& input_;
  int line_;
  Token current_token_;
};

