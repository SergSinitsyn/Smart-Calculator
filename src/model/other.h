#ifndef _MODEL_OTHER_H_
#define _MODEL_OTHER_H_

#include <map>

#include "token.h"

bool is_number(char c);
bool is_symbol(char c);
bool is_letter(char c);
bool is_E(char c);
bool is_pm(char c);

double Addition(double a, double b);        //!
double Subtraction(double a, double b);     //!
double Multiplication(double a, double b);  //!
double Division(double a, double b);        // !

double UnaryNegation(double a);  //!

std::map<std::string, Token> CreateTokenMap();

#endif  // _MODEL_OTHER_H_