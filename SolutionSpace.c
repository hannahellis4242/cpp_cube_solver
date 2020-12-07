#include "SolutionSpace.h"

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/graphviz.hpp"

#include "Configuration.h"
#include "Instruction.h"

namespace cube {
using Graph = boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
                                    Configuration, Instruction>;
using vertex = boost::graph_traits<Graph>::vertex_descriptor;
using edge = boost::graph_traits<Graph>::edge_descriptor;

class GraphWriter {
private:
  const Graph &graph_;

public:
  GraphWriter(const Graph &graph) : graph_(graph) {}
  void operator()(std::ostream &) const {}
  void operator()(std::ostream &os, const vertex_descriptor v) const {
    const Configuration &config = graph_[v];
    os << "[label=\"" << show(config) << "\"]";
  }
  void operator()(std::ostream &os, const edge_descriptor e) const {
    const Instruction &x = graph_[e];
      os << "[label=\""<< show(x)<<"\]";
  }
};
} // namespace cube
