#include "date.h"

#include <algorithm>
#include <ctime>

MyNamespace::Date::Date(int day, int month, int year) {
  std::tm temp_date{};
  temp_date.tm_year = year;
  temp_date.tm_mon = month;
  temp_date.tm_mday = day;
  std::mktime(&temp_date);
  year_ = temp_date.tm_year;
  month_ = temp_date.tm_mon;
  day_ = temp_date.tm_mday;
  start_year_ = year_;
  start_month_ = month_;
  start_day_ = day_;
  count_month_ = 0;
  count_year_ = 0;
}

int MyNamespace::Date::GetDay() const { return day_; }

int MyNamespace::Date::GetMonth() const { return month_; }

int MyNamespace::Date::GetYear() const { return year_; }

void MyNamespace::Date::AddDays(int days) { Add(days, 0, 0); }

void MyNamespace::Date::AddMonths(int months) {
  ++count_month_;
  Date start(start_day_, start_month_, start_year_);
  Date temp(start_day_, start_month_, start_year_);
  temp.Add(0, months * count_month_, 0);
  while (temp.GetMonth() % 12 !=
         (start.GetMonth() + months * count_month_) % 12) {
    temp.AddDays(-1);
  }
  day_ = temp.GetDay();
  month_ = temp.GetMonth();
  year_ = temp.GetYear();
}

void MyNamespace::Date::AddYears(int years) {
  ++count_year_;
  Date start(start_day_, start_month_, start_year_);
  Date temp(start_day_, start_month_, start_year_);
  Add(0, 0, years);
  temp.Add(0, 0, years * count_year_);
  while (temp.GetMonth() != start.GetMonth()) {
    temp.AddDays(-1);
  }
  day_ = temp.GetDay();
  month_ = temp.GetMonth();
  year_ = temp.GetYear();
}

bool MyNamespace::Date::operator==(const Date& other) const {
  if (this == &other) {
    return true;
  }
  if (year_ == other.year_ && month_ == other.month_ && day_ == other.day_) {
    return true;
  } else {
    return false;
  }
}

bool MyNamespace::Date::operator!=(const Date& other) const {
  return !(*this == other);
}

bool MyNamespace::Date::operator>(const Date& other) const {
  if (this == &other) {
    return true;
  }
  if (year_ > other.year_) {
    return true;
  } else if (year_ < other.year_) {
    return false;
  }
  if (month_ > other.month_) {
    return true;
  } else if (month_ < other.month_) {
    return false;
  }
  if (day_ > other.day_) {
    return true;
  } else {
    return false;
  }
}

bool MyNamespace::Date::operator<(const Date& other) const {
  if (this == &other) {
    return true;
  }
  if (year_ < other.year_) {
    return true;
  } else if (year_ > other.year_) {
    return false;
  }
  if (month_ < other.month_) {
    return true;
  } else if (month_ > other.month_) {
    return false;
  }
  if (day_ < other.day_) {
    return true;
  } else {
    return false;
  }
}

bool MyNamespace::Date::operator<=(const Date& other) const {
  return (*this == other || *this < other);
}

bool MyNamespace::Date::operator>=(const Date& other) const {
  return (*this == other || *this > other);
}

int MyNamespace::Date::DaysInYear() const {
  int daysInYear = 365;
  Date temp(29, 1, year_);
  if (temp.day_ == 29) {
    daysInYear = 366;
  }
  return daysInYear;
}

void MyNamespace::Date::Add(int day, int month, int year) {
  Date temp_date(day_ + day, month_ + month, year_ + year);
  day_ = temp_date.day_;
  month_ = temp_date.month_;
  year_ = temp_date.year_;
}
