#ifndef INSTRUCTION_H
#define INSTRUCTION_H

namespace cube {
enum class Instruction {
  TopTwistRight,
  TopTwistLeft,
  FrontTwistRight,
  FrontTwistLeft,
  RightTwistFront,
  RightTwistBack,
  BottomTwistRight,
  BottomTwistLeft,
  BackTwistRight,
  BackTwistLeft,
  LeftTwistFront,
  LeftTwistBack,
  Halt
};
std::string show(const Instruction &);
} // namespace cube

#endif
