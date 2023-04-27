#ifndef _MODEL_DATE_H_
#define _MODEL_DATE_H_

namespace MyNamespace {
class Date {
 public:
  Date() = default;
  Date(int day, int month, int year);
  ~Date() = default;

  int GetDay() const;
  int GetMonth() const;
  int GetYear() const;

  void AddDays(int days);
  void AddMonths(int months);
  void AddYears(int years);

  int DaysInYear() const;

  bool operator==(const Date& other) const;
  bool operator!=(const Date& other) const;
  bool operator>(const Date& other) const;
  bool operator<(const Date& other) const;
  bool operator<=(const Date& other) const;
  bool operator>=(const Date& other) const;

 private:
  int day_;
  int month_;
  int year_;
  int count_month_;
  int count_year_;
  int start_day_;
  int start_month_;
  int start_year_;

  void Add(int day, int month, int year);
};
};  // namespace MyNamespace

#endif  // _MODEL_DATE_H_
