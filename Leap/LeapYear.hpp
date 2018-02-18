#ifndef LEAPYEAR_HPP
#define LEAPYEAR_HPP

class LeapYear {
 public:
  static bool is_leap_year(const int year) {
    bool d4 = year % 4 == 0;
    bool d100 = year % 100 == 0;
    bool d400 = year % 400 == 0;
    return (d4 && d100 && d400) || (d4 && !d100);
  }
};

#endif