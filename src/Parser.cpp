#include <iostream>
#include "AST.h"
#include "Parser.h"

std::unique_ptr<Expr> Parser::parse_number() {
	Token token = expect(TokenType::INT);
	std::string text = m_source_.substr(token.start_offset, token.length);
	uint64_t value = std::stoull(text);
	return std::make_unique<IntConstantExpr>(value);
}

std::unique_ptr<Expr> Parser::parse_expr() {
	Token token = peek();

	switch (token.type) {
	case TokenType::INT:
		return parse_number();
	default:
		return nullptr;
	}

}