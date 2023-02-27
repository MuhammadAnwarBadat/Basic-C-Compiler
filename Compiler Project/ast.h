#pragma once

#include <vector>

enum DataType {
  TYPE_INTEGER,
  TYPE_FLOAT,
  TYPE_BOOLEAN,
  TYPE_STRING,
  TYPE_VOID
};

struct Variable {
  DataType type;
  std::string name;
};

class Expression {
public:
  virtual ~Expression() {}
  virtual DataType GetType() = 0;
};

class IntegerLiteral : public Expression {
public:
  IntegerLiteral(int value) : value_(value) {}
  DataType GetType() override { return TYPE_INTEGER; }
  int GetValue() { return value_; }

private:
  int value_;
};

class FloatLiteral : public Expression {
public:
  FloatLiteral(float value) : value_(value) {}
  DataType GetType() override { return TYPE_FLOAT; }
  float GetValue() { return value_; }

private:
  float value_;
};

class BooleanLiteral : public Expression {
public:
  BooleanLiteral(bool value) : value_(value) {}
  DataType GetType() override { return TYPE_BOOLEAN; }
  bool GetValue() { return value_; }

private:
  bool value_;
};

class StringLiteral : public Expression {
public:
  StringLiteral(const std::string& value) : value_(value) {}
  DataType GetType() override { return TYPE_STRING; }
  const std::string& GetValue() { return value_; }

private:
  std::string value_;
};

class BinaryOperator : public Expression {
public:
  BinaryOperator(Expression* left, Expression* right) : left_(left), right_(right) {}
  ~BinaryOperator() {
    delete left_;
    delete right_;
  }
  Expression* GetLeft() { return left_; }
  Expression* GetRight() { return right_; }

private:
  Expression* left_;
  Expression* right_;
};

class AdditionOperator : public BinaryOperator {
public:
  using BinaryOperator::BinaryOperator;
  DataType GetType() override {
    // In this example, we will assume that addition can be performed on
    // any combination of integer and float operands, and the result will
    // be a float.
    if (left_->GetType() == TYPE_INTEGER || right_->GetType() == TYPE_INTEGER) {
      return TYPE_FLOAT;
    }
    return TYPE_FLOAT;
  }
};

class SubtractionOperator : public BinaryOperator {
public:
  using BinaryOperator::BinaryOperator;
  DataType GetType() override {
    // In this example, we will assume that subtraction can be performed on
    // any combination of integer and float operands, and the result will
    // be a float.
    if (left_->GetType() == TYPE_INTEG
