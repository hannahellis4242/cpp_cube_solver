#ifndef SOLUTIONSPACE_H
#define SOLUTIONSPACE_H

#include "Configuration.h"
#include "Instruction.h"

#include "boost/graph/adjacency_list.hpp"

#include <map>
#include <vector>

namespace cube {
using Weight = unsigned int;
using InstructionAndWeight = std::pair<Instruction, Weight>;
class SolutionSpace {
private:
  using Graph =
      boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
                            Configuration, InstructionAndWeight>;
  using vertex = boost::graph_traits<Graph>::vertex_descriptor;

  using ConfigToVertexMap = std::map<Configuration, vertex>;

  Graph graph_;
  ConfigToVertexMap map_;

public:
  SolutionSpace(const Configuration &);
  std::vector<InstructionAndWeight> next(const Configuration &,
                                         const Instruction);
  const Configuration &visit(const Configuration &, const Instruction) const;

  std::string show() const;
};
} // namespace cube

#endif
