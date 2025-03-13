#include "parser.h"
#include "lexer.h"
#include <iostream>
#include <stdexcept>
#include <string>

void IdentifierExpr::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Id(" << name << ")\n";
}

void NumberExpr::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Number(" << value << ")\n";
}

void BinaryExpr::print(int indent) const {
    std::cout << std::string(indent, ' ') << "BinaryExpr(\"" << op << "\"\n";
    left -> print(indent + 2);
    right -> print(indent + 2);
    std::cout << std::string(indent, ' ') << ")\n";
}

void VariableDeclaration::print(int indent) const {
    std::cout << std::string(indent, ' ') << "LetExpr(\"" << name << "\"\n";
    value -> print(indent + 2);
    std::cout << std::string(indent, ' ') << ")\n";
}

void Program::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Program\n";
    for (auto stmt : statements) {
        stmt -> print(indent + 2);
    }
}

void Parser::currToken() {
    std::cout << TokenTypes[tokens[pos].type];
}

Token& Parser::consume(TokenType expected) {
    if (tokens[pos].type != expected) {
        throw std::runtime_error("Unexpected token. Expected: " + std::to_string(expected) + ", Got: " + std::to_string(tokens[pos].type));
    }
    return tokens[pos++];
}

ASTNode* Parser::parseExpression() {
    ASTNode* left;
    if (tokens[pos].type == NUMBER) {
        left = new NumberExpr(std::stoi(tokens[pos].value));
        pos++;
    } else if (tokens[pos].type == IDENTIFIER) {
        left = new VariableDeclaration(tokens[pos].value, nullptr);
        pos++;
    } else {
        throw std::runtime_error("Expected primary expression");
    }

    while (tokens[pos].type == PLUS) {
        pos++;
        ASTNode* right = parseExpression();
        left = new BinaryExpr(left, '+', right);
    }
    return left;
}

ASTNode* Parser::parseIdentifierExpression() {
    Token& varName = consume(IDENTIFIER);
    return new IdentifierExpr(tokens[pos].value);
}

ASTNode* Parser::parseStatement() {
    if (tokens[pos].type == LET_TOK) {
        consume(LET_TOK);
        Token& varName = consume(IDENTIFIER);
        consume(EQUAL);
        ASTNode* value = parseExpression();
        consume(SEMICOLON);
        return new VariableDeclaration(varName.value, value);
    }
    throw std::runtime_error("Unknown statement");
}

ASTNode* Parser::parseProgram() {
    consume(BEGIN_TOK);
    Program* program = new Program();

    while (tokens[pos].type != END_TOK) {
        program -> statements.push_back(parseStatement());
    }

    consume(END_TOK);
    return program;
}

ASTNode* Parser::parse() {
    return parseProgram();

}
