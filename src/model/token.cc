#include "token.h"

Token::Token(){};
Token::Token(std::string type, Precedence precedence,
             Associativity associativity, OperationType operation_type,
             double value, function_variant function)
    : type_(type),
      precedence_(precedence),
      value_(value),
      associativity_(associativity),
      operation_type_(operation_type),
      function_(function){};

Token::Token(const Token& other)
    : type_(other.type_),
      precedence_(other.precedence_),
      value_(other.value_),
      associativity_(other.associativity_),
      operation_type_(other.operation_type_),
      function_(other.function_){};

Token::~Token(){};

std::string Token::GetType() { return type_; }
int Token::GetPrecedence() { return precedence_; }
double Token::GetValue() { return value_; }
int Token::GetAssociativity() { return associativity_; }
int Token::GetOperationType() { return operation_type_; }
function_variant Token::GetFunction() { return function_; }
void Token::SetValue(double value) { value_ = value; }