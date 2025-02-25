/**
 * Licensed under Apache 2.0.
 * Developed by Aquiles Trindade (trindadedev).
 */

#include <string>
#include "lexer/lexer.hpp"

int main() {
  printf("\n\n");
  std::string code = "if (x > 10) { y = x + 5; }";
  Lexer lexer(code);
  std::list<Token> tokens = lexer.tokenize();
  for (Token token : tokens) {
    printf("Type: %s\nValue: %s\n\n", token.type_as_str().c_str(), token.value.c_str());
  }
  return 0;
}