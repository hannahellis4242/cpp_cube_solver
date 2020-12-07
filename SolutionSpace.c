#include "SolutionSpace.h"

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/graphviz.hpp"

#include "Configuration.h"
#include "Instruction.h"

namespace cube
{
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
                                Configuration, Instruction>
      Graph;
  typedef boost::graph_traits<Graph>::vertex_descriptor vertex_descriptor;
  typedef boost::graph_traits<Graph>::edge_descriptor edge_descriptor;

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
      os << "[label=\"<< show(x)<<"\]";
    }
  };
}
