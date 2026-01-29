#include <iostream>
#include "Lexer.h"

int main() {

    try {
        
        std::string source = "while (i) + 123";
        std::vector<Token> tokens = tokenize(source);

        for (auto& t : tokens) {
            std::cout << get_token_type_name(t.type) << " @" << t.start_offset << "\n";
        }
    }
    catch (const SyntaxError& e) {
        std::cout << "Error: " << e.what() << " at position " << e.get_offset() << "\n";
    }
    return 0;
}