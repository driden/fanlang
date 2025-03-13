#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

struct ASTNode {
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

struct IdentifierExpr : public ASTNode {
    std::string name;
    IdentifierExpr(std::string name) : name(name) {}
    void print(int indent = 0) const override;
};

struct NumberExpr : public ASTNode {
    int value;
    NumberExpr(int value) : value(value) {}
    void print(int indent = 0) const override;
};

struct BinaryExpr : public ASTNode {
    ASTNode* left;
    ASTNode* right;
    char op;
    BinaryExpr(ASTNode *left, char op, ASTNode* right): left(left), right(right), op(op){}
    void print(int indent = 0) const override;
};

struct VariableDeclaration: public ASTNode {
    std::string name;
    ASTNode* value;
    VariableDeclaration(std::string name, ASTNode* value): name(name), value(value) {}
    void print(int indent = 0) const override;
};

struct Program: public ASTNode {
    std::vector<ASTNode*> statements;
    void print(int indent = 0) const override;
};

class Parser {
    std::vector<Token> tokens;
    size_t pos = 0;

    Token& consume(TokenType expected);
    void currToken();
    ASTNode* parseExpression();
    ASTNode* parseIdentifierExpression();
    ASTNode* parsePrimary();
    ASTNode* parseStatement();
    ASTNode* parseProgram();
public:
    Parser(const std::vector<Token> &tokens): tokens(tokens) {}
    ASTNode* parse();
};

#endif // !PARSER_H
#define PARSER_H

