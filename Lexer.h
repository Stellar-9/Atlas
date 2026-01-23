#ifndef HEADER_ATLAS_LEXER
#define HEADER_ATLAS_LEXER

#include <vector>
#include <string>
#include <stdexcept>
#include "Token.h"


class SyntaxError : public std::exception {

public:
    SyntaxError(int offset, std::string message) : offset(offset), message(std::move(message)) {}

    int get_offset() const {
        return offset;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    int offset;
    std::string message;
};

std::vector<Token> tokenize(const std::string &source);

#endif