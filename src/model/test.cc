#include "model.h"

int main() {
  Calculator A("sin(x+ 1+2*3 )");

  //   string input2 = "77777";ß
  //   double x = 10;
  double res = A.CalculateValue(100);
  std::cout << "result = " << res << std::endl;
  //   double f;
  //   string str = "12345.133";
  //   f = atof(str.c_str());
  //   cout << "строка =" << str << " значение =" << f << endl;
  //   cout.precision(10);
  //   std::string str = "1.212342300";

  //   // convert string to float
  //   float num_float = std::stof(str);

  //   // convert string to double
  //   double num_double = std::stod(str);

  //   std::cout << "num_float = " << num_float << std::endl;
  //   std::cout << "num_double = " << num_double << std::endl;

  //   stringstream ss("6.02e-22");
  //   double d = 0;
  //   ss >> d;
  //   cout << d << endl;
  //   //   cout << sciToDub("6.02e-2") << endl;
  //   //   cout << sciToDub("asdf") << endl;
  //   double D = 1234.2435346545365;

  //   cout.precision(10);
  //   cout << D << endl;

  return 0;
}
