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
} // namespace cube
