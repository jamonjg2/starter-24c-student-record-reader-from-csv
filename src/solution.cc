#include "solution.hpp"

#include <iostream>
#include <string>

Student ReadStudentRecFromStream(std::istream& is) {
  // your implementation here...
  std::string first_name;
  std::string last_name;
  unsigned int uin = 0;
  double gpa = 0.0;
  char throw_away = '\0';
  is >> first_name >> last_name >> uin >> throw_away >> gpa;
  if (is.fail()) return Student{};
  if (throw_away != ',') return Student{};
  if (last_name[last_name.size() - 1] != ',') return Student{};
  last_name.erase((last_name.size() - 1));
  return Student{first_name + ' ' + last_name, uin, gpa};
}