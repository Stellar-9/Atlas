#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main() {

    try {
        
        // std::string source = "while (i) + 123";
        std::string source = "197";
        std::vector<Token> tokens = tokenize(source);

        Parser parser(source, tokens);

        std::unique_ptr<Expr> result = parser.parse_expr();


        if (result) {
            std::cout << "Number parsed" << std::endl;
            IntConstantExpr* intExpr = static_cast<IntConstantExpr*>(result.get());
            std::cout << "Value " << intExpr->value << std::endl;
        }
        else {
            std::cout << "Failed parsing number" << std::endl;
        }

        for (auto& t : tokens) {
            std::cout << get_token_type_name(t.type) << " @" << t.start_offset << "\n";
        }
    }
    catch (const SyntaxError& e) {
        std::cout << "Error: " << e.what() << " at position " << e.get_offset() << "\n";
    }
    return 0;
}