#include "date.h"

#include <algorithm>

Date::Date(int day, int month, int year) {
  std::tm tm{};
  tm.tm_year = year;
  tm.tm_mon = month;
  tm.tm_mday = day;
  std::mktime(&tm);
  year_ = tm.tm_year;
  month_ = tm.tm_mon;
  day_ = tm.tm_mday;
}

// Date::Date(const Date& other) {
//   if (this != &other) {
//     day_ = other.day_;
//     month_ = other.month_;
//     year_ = other.year_;
//   }
// }

// Date::Date(Date&& other) : day_{0}, month_{0}, year_{0} {
//   if (this != &other) {
//     std::swap(day_, other.day_);
//     std::swap(month_, other.month_);
//     std::swap(year_, other.year_);
//   }
// }

int Date::GetDay() { return day_; }
int Date::GetMonth() { return month_; }
int Date::GetYear() { return year_; }

void Date::Add(int day, int month, int year) {
  Date temp_date(day_ + day, month_ + month, year_ + year);
  day_ = temp_date.day_;
  month_ = temp_date.month_;
  year_ = temp_date.year_;
}

bool Date::operator==(const Date& other) const {
  bool result = true;
  if (this != &other) {
    result = false;
    if (year_ == other.year_ && month_ == other.month_ && day_ == other.day_) {
      result = true;
    }
  }
  return result;
}

bool Date::operator>(const Date& other) const {
  bool result = false;
  if (this != &other) {
    result = true;
    if (year_ > other.year_) {
    } else if (month_ > other.month_) {
    } else if (day_ > other.day_) {
    } else {
      result = false;
    }
  }
  return result;
}

bool Date::operator<(const Date& other) const {
  bool result = false;
  if (this != &other) {
    result = true;
    if (year_ < other.year_) {
    } else if (month_ < other.month_) {
    } else if (day_ < other.day_) {
    } else {
      result = false;
    }
  }
  return result;
}

bool Date::operator<=(const Date& other) const {
  return (*this == other || *this < other);
}

int Date::DaysInYear() {
  int daysInYear = 365;
  Date temp(29, 1, year_);
  if (temp.day_ == 29) {
    daysInYear = 366;
  }
  return daysInYear;
}
