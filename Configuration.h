#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <array>
#include <string>
#include "Value.h"

namespace cube
{
  using Configuration = std::array<Value,54>;
  std::string show_net(const Configuration & );
  Configuration solved() ;
}
#endif
