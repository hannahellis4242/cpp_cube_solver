#include "Instruction.h"

namespace cube {
std::string show(const Instruction &x) {
  switch (x) {
  case TopTwistRight:
    return "TopTwistRight";
  case TopTwistLeft:
    return "TopTwistLeft";
  case FrontTwistRight:
    return "FrontTwistRight";
  case FrontTwistLeft:
    return "FrontTwistLeft";
  case RightTwistFront:
    return "RightTwistFront";
  case RightTwistBack:
    return "RightTwistBack";
  case BottomTwistRight:
    return "BottomTwistRight";
  case BottomTwistLeft:
    return "BottomTwistLeft";
  case BackTwistRight:
    return "BackTwistRight";
  case BackTwistLeft:
    return "BackTwistLeft";
  case LeftTwistFront:
    return "LeftTwistFront";
  case LeftTwistBack:
    return "LeftTwistBack";
  case Halt:
    return "Halt";
  }
}
} // namespace cube
