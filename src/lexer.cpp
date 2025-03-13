#include "lexer.h"
#include <cctype>
#include <stdexcept>
#include <stdexcept>
#include<vector>
#include<string>

Lexer::Lexer(const std::string &src): source(src) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < source.size()) {
        char c = source[pos];

        if (isspace(c)) { 
            pos++;
            continue;
        }

        if (isalpha(c)) {
            std::string identifier;

            while (pos < source.size() && isalnum(source[pos])) {
                identifier += source[pos++];
            }

            if (identifier == "BEGIN") tokens.push_back({ .type = BEGIN_TOK, .value = "BEGIN"});
            else if (identifier == "END") tokens.push_back({ .type = END_TOK, .value = "END"});
            else if (identifier == "let") tokens.push_back({ .type = LET_TOK, .value = "let"});
            else tokens.push_back({ .type = IDENTIFIER, .value = identifier});
        } else if (isdigit(c)) {
            std::string number;
            while (pos < source.size() && isdigit(source[pos])) {
                number += source[pos++];
            }
            tokens.push_back({.type = NUMBER, .value = number});

        } else if ( c == '=') {
            tokens.push_back({.type = EQUAL, .value = "="});
            pos++;
        } else if ( c == '+') {
            tokens.push_back({.type = PLUS, .value = "+"});
            pos++;
        } else if ( c == ';') {
            tokens.push_back({.type = SEMICOLON, .value = ";"});
            pos++;
        } else {
            throw std::runtime_error("Unexpected char: " + std::string(1,c));
        }
    }

    tokens.push_back({.type = EOF_TOK, .value = ""});

    return tokens;
}
