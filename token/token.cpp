#include "token.hpp"

Token::Token(TokenType type, const std::string value) : type(type), value(value) {}

std::string Token::type_as_str() {
  switch (type) {
    case TokenType::KEYWORD:
      return "KEYWORD";
    case TokenType::IDENTIFIER:
      return "IDENTIFIER";
    case TokenType::LITERAL:
      return "LITERAL";
    case TokenType::OPERATOR:
      return "OPERATOR";
    case TokenType::PUNCTUATION:
      return "PUNCTUATION";
    case TokenType::WHITESPACE:
      return "WHITESPACE";
    case TokenType::COMMENT:
      return "COMMENT";
    case TokenType::UNKNOWN:
      return "UNKNOWN";
  }
}