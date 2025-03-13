#ifndef LEXER_H
#define LEXER_H

#include<vector>
#include<string>

enum TokenType { BEGIN_TOK, END_TOK, LET_TOK, IDENTIFIER, NUMBER, EQUAL, PLUS, SEMICOLON, EOF_TOK};
constexpr std::string_view TokenTypes[] =
{
"BEGIN_TOK",
"END_TOK",
"LET_TOK",
"IDENTIFIER",
"NUMBER",
"EQUAL",
"PLUS",
"SEMICOLON",
"EOF_TOK"
};


struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
    std::string source;
    size_t pos = 0;

public:
    Lexer(const std::string &src);
    std::vector<Token> tokenize();
};

#endif // !LEXER_H
