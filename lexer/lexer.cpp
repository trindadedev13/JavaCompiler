#include <memory>
#include <cctype>
#include <list>
#include <regex>
#include "lexer.hpp"

Lexer::Lexer(const std::string input): input(input), current_position(0) { }

Token Lexer::nextToken() {
  if (current_position >= input.length()) {
    throw std::invalid_argument("token is null");
  }
  std::array<std::string, 5> token_patterns = {
    "if|else|while|for",
    "[a-zA-Z_][a-zA-Z0-9_]*",
    "\\d+",
    "[+-/*=<>!]",
    "[.,;(){}]"
  };
  TokenType token_types[5] = {
    TokenType::KEYWORD,
    TokenType::IDENTIFIER,
    TokenType::LITERAL,
    TokenType::OPERATOR,
    TokenType::PUNCTUATION
  };
  for (int i = 0; i < token_patterns.size(); i++) {
    std::regex pattern("^" + token_patterns[i]);
    std::smatch matches;
    std::string remain_input = input.substr(current_position);
    if (std::regex_search(remain_input, matches, pattern)) {
      std::string value = matches.str(0);
      current_position += value.length();
      return Token(token_types[i], value);
    }
  }
  throw std::invalid_argument("token is null");
}

std::list<Token> Lexer::tokenize() {
  std::list<Token> tokens;
  while (current_position < input.length()) {
    char current_char = input.at(current_position);
    if (isspace(current_char)) {
      current_position++;
      continue;
    }
    Token token = nextToken();
    tokens.push_back(token);
  }
  return tokens;
}