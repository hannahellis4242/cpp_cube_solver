#ifndef SOLUTIONSPACE_H
#define SOLUTIONSPACE_H

#include "Configuration.h"
#include "Instruction.h"

#include <vector>
namespace cube {
using InstructionAndWeight = std::pair<Instruction, unsigned int>;
class SolutionSpace {
public:
  std::vector<InstructionAndWeight> next(const Configuration &,
                                         const Instruction) const;
  const Configuration &visit(const Configuration &, const Instruction);

  std::string show() const;
};
} // namespace cube

#endif
