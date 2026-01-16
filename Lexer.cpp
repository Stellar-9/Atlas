#include "Lexer.h"
#include <iostream>

// add include guards ifdef to headers files -> done
// add static to functions -> done
// simplify switch, make it into function -> done
// simplify switch, make it into function -> done
// fix comments
// maybe rewrite it to the class. Learn why into deep knowledge

static bool is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

static bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

static void consume_while(const std::string& source, int& pos, bool (*condition)(char)) {

    while (pos < source.length() && condition(source[pos])) {
        pos++;
    }

}

static bool is_alphanumeric(char c) {
    return is_alpha(c) || is_digit(c);
}

static TokenType parse_slash(const std::string& source, int& pos) {
    if (pos < source.length() && source[pos] == '/') {
        pos++;

        while (pos < source.length() && source[pos] != '\n') {
            pos++;
        }

        return TokenType::WHITESPACE;
    }

    return TokenType::SLASH;

}

static TokenType parse_plus(const std::string& source, int& pos) {
    if (pos < source.length()) { // Safety check
        if (source[pos] == '=') {
            pos += 1;
            return TokenType::PLUS_EQ;
        }
        if (source[pos] == '+') {
            pos += 1;
            return TokenType::PLUS_PLUS;
        }
    }
    return TokenType::PLUS;
}


static TokenType parse_token_type(const std::string& source, int& pos) {
    char c = source[pos];
    pos++; // Advance position

    switch (c) {
    case ' ':
    case '\t':
    case '\n':
        return TokenType::WHITESPACE;
    case '(':
        return TokenType::LPAREN;
    case ')':
        return TokenType::RPAREN;
    case '+':
        return parse_plus(source, pos);
    case'/':
        return parse_slash(source, pos);
    default:
        if (is_alpha(c)) {
            // Keep eating characters while they are letters or numbers
            consume_while(source, pos, is_alphanumeric);
            return TokenType::IDENTIFIER;
        }

        else if (is_digit(c)) {
            consume_while(source, pos, is_digit);
            return TokenType::INT;
        }

        throw SyntaxError(pos - 1, "invalid character");
    }
}

// The main public function that main.cpp calls
std::vector<Token> tokenize(const std::string& source) {
    std::vector<Token> result;
    int pos = 0;

    while (pos < source.length()) {
        int start = pos;

        // Call the helper to figure out what the next token is
        TokenType type = parse_token_type(source, pos);

        // Filter out logic
        if (type != TokenType::WHITESPACE) {

            // Check specific keywords for Identifiers
            if (type == TokenType::IDENTIFIER) {
                std::string_view text = std::string_view(source).substr(start, pos - start);
                if (text == "int") {
                    type = TokenType::KW_INT;
                }
                else if (text == "return") {
                    type = TokenType::KW_RETURN;
                }
                else if (text == "while") {
                    type = TokenType::KW_WHILE;
                }
            }

            // Add to list
            result.push_back(Token{ type, start, pos - start });
        }
    }

    return result;
}

/* source code
 * lexical analysis
 * list of tokens    [ IDENTIFIER(name), INT(value), STRING_LITERAL, LPAREN, RPAREN, EQ, ... ]
 * syntax analysis
 * Abstract Syntax Tree
 */



 /*
 int factorial(int n) {
     int result = 1;
     int i = 0;
     while (i < n) {
         result = result * i;
         i = i + 1;
     }
     return result;
 }

 fun factorial(n: int) -> int {
     var result: int = 1;
     var i: int = 0;
     while (i < n) {
         result = result * i;
         i = i + 1;
     }
     return result;
 }
 */

std::string get_token_type_name(TokenType type) {
    switch (type) {
    case TokenType::IDENTIFIER:
        return "IDENTIFIER";
    case TokenType::KW_INT:
        return "KW_INT";
    case TokenType::KW_WHILE:
        return "KW_WHILE";
    case TokenType::LPAREN:
        return "LPAREN";
    case TokenType::RPAREN:
        return "RPAREN";
    case TokenType::PLUS:
        return "PLUS";
    case TokenType::PLUS_EQ:
        return "PLUS_EQ";
    case TokenType::WHITESPACE:
        return "WHITESPACE";
    default:
        return "???";
    }
}