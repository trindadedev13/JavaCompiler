/**
 * Licensed under Apache 2.0.
 * Developed by Aquiles Trindade (trindadedev).
 */

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <list>
#include "../token/token.hpp"

class Lexer {
  private:
    std::string input;
    int current_position;
  public:
    std::list<Token> tokenize();
    Token nextToken();

  Lexer(const std::string value);
};

#endif