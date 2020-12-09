#ifndef VALUE_H
#define VALUE_H

#include <string>

namespace cube {
enum class Value { Red, Orange, Yellow, Green, Blue, White };
char show(const Value &);
std::string showFull(const Value &);
} // namespace cube
#endif
