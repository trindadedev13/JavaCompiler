/**
 * Licensed under Apache 2.0.
 * Developed by Aquiles Trindade (trindadedev).
 */

#include <list>
#include <regex>
#include "lexer.hpp"

Lexer::Lexer(const std::string input): input(input), current_position(0) { }

std::string Lexer::get_keywords_pattern() {
  return "abstract|assert|boolean|break|byte|case|catch|char|class|const|continue|default|do|double|else|enum|extends|final|finally|float|for|goto|if|implements|import|instanceof|int|interface|long|native|new|null|package|private|protected|public|return|short|static|strictfp|super|switch|synchronized|this|throw|throws|transient|try|void|volatile|while";
}

Token Lexer::nextToken() {
  if (current_position >= input.length()) {
    throw std::runtime_error("something wrong with current_position. ");
  }
  std::vector<std::string> token_patterns = {
    get_keywords_pattern(),
    "[a-zA-Z_][a-zA-Z0-9_]*",
    "\\d+",
    "[+-/*=<>!]",
    "[.,;(){}]"
  };
  std::vector<TokenType> token_types = {
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
  throw std::runtime_error("token not recognized. ");
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