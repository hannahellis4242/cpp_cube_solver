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

  Configuration top_twist_right(const Configuration &) ;
  Configuration top_twist_left(const Configuration &) ;
Configuration front_twist_right(const Configuration &) ;
Configuration front_twist_left(const Configuration &) ;
Configuration right_twist_front(const Configuration &) ;
Configuration right_twist_back(const Configuration &) ;
Configuration bottom_twist_right(const Configuration &) ;
Configuration bottom_twist_left(const Configuration &) ;
Configuration back_twist_right(const Configuration &) ;
Configuration back_twist_left(const Configuration &) ;
Configuration left_twist_front(const Configuration &) ;
Configuration left_twist_back(const Configuration &) ;
}
#endif
