#include <string>

#ifndef HEADER_ATLAS_TOKEN
#define HEADER_ATLAS_TOKEN

enum class TokenType {
    IDENTIFIER, // [a-zA-Z][a-zA-Z0-9]*  n, y6, asdfa, U4453445
    INT,        // [0-9]+  0 11212 555 21085 000011
    LPAREN,     // (
    RPAREN,     // )
    LBRACE,     // }
    RBRACE,     // {
    EQ,         // =
    LT,         // <
    LT_EQ,      // <=
    PLUS_PLUS,  // ++
    PLUS_EQ,    // +=
    PLUS,       // +
    MINUS,      // -
    STAR,       // *
    SLASH,      // /
    SEMICOLON,  // ;
    KW_INT,     // int
    KW_WHILE,   // while
    KW_RETURN,  // return
    WHITESPACE, // whitespace
};

struct Token {
    TokenType type;
    int start_offset;              // 4 B
    int length;                    // 4 B
};

std::string get_token_type_name(TokenType type);

#endif