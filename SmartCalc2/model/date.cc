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
  start_year_ = year_;
  start_month_ = month_;
  start_day_ = day_;
  count_month_ = 0;
  count_year_ = 0;
}

int Date::GetDay() { return day_; }

int Date::GetMonth() { return month_; }

int Date::GetYear() { return year_; }

void Date::AddDays(int days) { Add(days, 0, 0); }

void Date::AddMonths(int months) {
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

void Date::AddYears(int years) {
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

bool Date::operator==(const Date& other) const {
  if (this == &other) {
    return true;
  }
  if (year_ == other.year_ && month_ == other.month_ && day_ == other.day_) {
    return true;
  } else {
    return false;
  }
}

bool Date::operator!=(const Date& other) const { return !(*this == other); }

bool Date::operator>(const Date& other) const {
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

bool Date::operator<(const Date& other) const {
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

bool Date::operator<=(const Date& other) const {
  return (*this == other || *this < other);
}

bool Date::operator>=(const Date& other) const {
  return (*this == other || *this > other);
}

int Date::DaysInYear() {
  int daysInYear = 365;
  Date temp(29, 1, year_);
  if (temp.day_ == 29) {
    daysInYear = 366;
  }
  return daysInYear;
}

void Date::Add(int day, int month, int year) {
  Date temp_date(day_ + day, month_ + month, year_ + year);
  day_ = temp_date.day_;
  month_ = temp_date.month_;
  year_ = temp_date.year_;
}
