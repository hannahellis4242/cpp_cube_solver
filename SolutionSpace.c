#include "SolutionSpace.h"

#include "boost/graph/graphviz.hpp"

namespace cube {

namespace detail {
std::vector<Instruction> generatePossibeSolutions(const Instruction last) {
  if (last == Halt) {
    return std::vector<Instruction>();
  }
  std::vector<Instruction> out;
  out.reserve(13);
  if (last != TopTwistLeft) {
    out.push_back(TopTwistRight);
  }
  if (last != TopTwistRight) {
    out.push_back(TopTwistLeft);
  }
  if (last != FrontTwistLeft) {
    out.push_back(FrontTwistRight);
  }
  if (last != FrontTwistRight) {
    out.push_back(FrontTwistLeft);
  }
  if (last != RightTwistBack) {
    out.push_back(RightTwistFront);
  }
  if (last != RightTwistFront) {
    out.push_back(RightTwistBack);
  }
  if (last != BottomTwistLeft) {
    out.push_back(BottomTwistRight);
  }
  if (last != BottomTwistRight) {
    out.push_back(BottomTwistLeft);
  }
  if (last != BackTwistLeft) {
    out.push_back(BackTwistRight);
  }
  if (last != BackTwistRight) {
    out.push_back(BackTwistLeft);
  }
  if (last != LeftTwistBack) {
    out.push_back(LeftTwistFront);
  }
  if (last != LeftTwistFront) {
    out.push_back(LeftTwistBack);
  }
  out.push_back(Halt);
  return out;
}

std::function<Configuration(const Configuration &)>
InstructionToFunction(const Instruction x) {
  switch (x) {
  case TopTwistRight:
    return top_twist_left;
  case TopTwistLeft:
    return top_twist_right;
  case FrontTwistRight:
    return front_twist_right;
  case FrontTwistLeft:
    return front_twist_left;
  case RightTwistFront:
    return right_twist_front;
  case RightTwistBack:
    return right_twist_back;
  case BottomTwistRight:
    return bottom_twist_right;
  case BottomTwistLeft:
    return bottom_twist_left;
  case BackTwistRight:
    return back_twist_right;
  case BackTwistLeft:
    return back_twist_left;
  case LeftTwistFront:
    return left_twist_front;
  case LeftTwistBack:
    return left_twist_back;
  case Halt:
    return [] Configuration(const Configuration &x) { return x; };
  }
}
} // namespace detail

using edge = boost::graph_traits<Graph>::edge_descriptor;

class GraphWriter {
private:
  const Graph &graph_;

public:
  GraphWriter(const Graph &graph) : graph_(graph) {}
  void operator()(std::ostream &) const {}
  void operator()(std::ostream &os, const vertex v) const {
    const Configuration &config = graph_[v];
    os << "[label=\"" << show(config) << "\"]";
  }
  void operator()(std::ostream &os, const edge e) const {
    const Instruction &x = graph_[e];
    os << "[label=\"" << show(x) << "\]";
  }
};

SolutionSpace::SolutionSpace(const Configuration &start) {
  const auto root = boost::add_vertex(graph_);
  graph_[root] = start;
  map_.insert(std::make_pair(start, root));
}

std::vector<InstructionAndWeight>
SolutionSpace::next(const Configuration &config, const Instruction last) {
  const auto it = map_.find(config);
  if (it != map_.end()) {
    const auto v = it->second;
    if (boost::out_degree(v, graph_) == 0) {
      // no children yet, so we need to generate them.
      const auto children = detail::generatePossibeSolutions(last);
      for (const auto child : children) {
        const auto u = boost::add_vertex(graph_);
        graph_[u] = detail::InstructionToFunction(child)(config);
        const auto edge = boost::add_edge(v, u, graph_);
        graph_[edge] = InstructionAndWeight(child, 1);
      }
    }
    std::vector<InstructionAndWeight> out;
    {
      boost::Graph::vertex_iterator vit, vend;
      for (boost::tie(vit, vend) = boost::out_edges(v, g); vit != vend; ++v) {
        out.push_back(*vit);
      }
    }
    return out;
  }
  return std::vector<InstructionAndWeight>();
}

std::string SolutionSpace::show() const {
  std::stringstream ss;
  const auto writer = GraphWriter(graph_);
  boost::write_graphviz(ss, graph, writer, writer, writer);
  return ss.str();
}

} // namespace cube
