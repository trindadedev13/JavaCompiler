/**
 * Licensed under Apache 2.0.
 * Developed by Aquiles Trindade (trindadedev).
 */

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include "token_type.hpp"

class Token {
  public:
    TokenType type;
    std::string value;
    std::string type_as_str();

    Token(TokenType type, const std::string value);
};

#endif