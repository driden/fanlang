#include "lexer.h"
#include "parser.h"
#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file.fan>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error opening file: " << argv[1] << "\n";
        return 1;
    }

    std::string source((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    Lexer lexer(source);

    auto tokens = lexer.tokenize();
    Parser parser(tokens);
    ASTNode* ast = parser.parse();

    std::cout << "Done parsing.\n";
    ast -> print();

    delete ast;

    return 0;
} 
