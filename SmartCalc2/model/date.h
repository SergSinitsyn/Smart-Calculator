#ifndef _MODEL_DATE_H_
#define _MODEL_DATE_H_

#include <ctime>

class Date {
 public:
    Date();
  Date(int day, int month, int year);
  //   Date(const Date& other);
  //   Date(Date&& other);
  //   Date& operator=(const Date& other);
  //   Date& operator=(Date&& other);

  int GetDay();
  int GetMonth();
  int GetYear();

  void Add(int day, int month, int year);
  int DaysInYear();

  bool operator==(const Date& other) const;
  bool operator>(const Date& other) const;
  bool operator<(const Date& other) const;
  bool operator<=(const Date& other) const;

 private:
  int day_;
  int month_;
  int year_;
};

#endif  // _MODEL_DATE_H_
