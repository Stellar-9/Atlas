#ifndef ATLAS_AST_H
#define ATLAS_AST_H

#include <memory>

class Expr {
public:
    Expr() = default;
    virtual ~Expr() = default;

    Expr(const Expr&) = delete;
    Expr(Expr&&) = delete;
    Expr& operator=(const Expr&) = delete;
    Expr& operator=(Expr&&) = delete;
};

enum BinaryOp { ADD, SUB, MUL, DIV };

class ParenExpr : public Expr {
private:
    std::unique_ptr<Expr> expr;

public:
    ParenExpr(std::unique_ptr<Expr> expr) : expr(std::move(expr)) {
    }
};

// TODO:
class BinaryExpr : public Expr {
    BinaryOp op;
    std::unique_ptr<Expr> left;
    std::unique_ptr<Expr> right;

};

// TODO:
class IntConstantExpr : public Expr {
public:
    IntConstantExpr(uint64_t value) : value(value){}
    uint64_t value;
};

#endif