#ifndef ATLAS_PARSER_H
#define ATLAS_PARSER_H

#include <vector>
#include <stdexcept>
#include <string>

#include "ast.h"
#include "Token.h"
#include "Lexer.h"



class Parser {

public:
    Parser(std::string source, std::vector<Token> tokens) : m_source_(source), tokens_(tokens), current_token_(0) {}
    Token peek() {
        return tokens_[current_token_];
    }

    Token advance() {

        Token current_token = tokens_[current_token_];
        if (current_token.type != TokenType::TK_EOF) {
            current_token_++;
            return current_token;
        }

        return current_token;
        
    }

    Token expect(TokenType expected_type) {
        Token current_token = peek();
        if (current_token.type == expected_type) {
            return advance();
         }
        else {
            throw SyntaxError(current_token.start_offset, "Expected " + std::to_string(int(expected_type)) + " but got " + std::to_string(int(current_token.type)));
        }

        
    }

    std::unique_ptr<Expr> parse_number();
    std::unique_ptr<Expr> parse_expr();


private:
    std::string m_source_;
    std::vector<Token> tokens_;
    size_t current_token_;
};

//class ParserTem {
//
//public:
//    ParserTem(std::vector<Token> tokens) : tokens(tokens), current_token_index(0) {
//    }
//
//    std::unique_ptr<Expr> parse_expr();             // -> cpp
//
//private:
//    void consume(Token::Type expected_token);       // -> cpp
//
//private:
//    std::vector<Token> tokens;
//    size_t current_token_index;
//};

#endif //ATLAS_PARSER_H