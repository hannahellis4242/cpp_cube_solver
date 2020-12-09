#include "Value.h"

namespace cube {
char show(const Value &value) {
  switch (value) {
  case Value::Red:
    return 'R';
  case Value::Orange:
    return 'O';
  case Value::Yellow:
    return 'Y';
  case Value::Green:
    return 'G';
  case Value::Blue:
    return 'B';
  case Value::White:
    return 'W';
  }
  return '-';
}
std::string showFull(const Value &value)
{
  switch (value) {
  case Value::Red:
    return "Red";
  case Value::Orange:
    return "Orange";
  case Value::Yellow:
    return "Yellow";
  case Value::Green:
    return "Green";
  case Value::Blue:
    return "Blue";
  case Value::White:
    return "White";
  }
  return "NONE???";
}
} // namespace cube
