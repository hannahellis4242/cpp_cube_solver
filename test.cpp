#include "Configuration.h"
#include <algorithm>
#include <functional>
// for test
#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <vector>
namespace test {
using TestResult = std::pair<bool, std::string>;
class Test {
public:
  virtual ~Test() {}
  virtual void SetUp() {}
  virtual void TearDown() {}

  virtual std::string id() const = 0;
  virtual TestResult test() const = 0;

  TestResult run() {
    std::stringstream ss;
    ss << std::string(10, '-') << std::endl;
    SetUp();
    ss << "begin test : " << id() << std::endl;
    const auto result = test();
    bool out;
    if (result.first) {
      ss << "PASS" << std::endl;
      out = true;
    } else {
      ss << result.second << std::endl;
      ss << "FAIL" << std::endl;
      out = false;
    }
    ss << std::string(10, '=') << std::endl;
    return TestResult(out, ss.str());
  }
};

using CountAndMessage = std::pair<int, std::string>;
static CountAndMessage runSingleTest(const CountAndMessage &acc,
                                     const std::unique_ptr<Test> &test) {
  const auto result = test->run();
  if (!result.first) {
    return CountAndMessage(acc.first + 1, acc.second + result.second);
  } else {
    return CountAndMessage(acc.first, acc.second + result.second);
  }
}

class TestRunner {
private:
  std::vector<std::unique_ptr<Test>> tests_;

public:
  TestRunner &add(Test *test) {
    tests_.push_back(std::unique_ptr<Test>(test));
    return *this;
  }

  void run() const {
    const auto results = std::accumulate(tests_.begin(), tests_.end(),
                                         CountAndMessage(0, ""), runSingleTest);
    if (results.first > 0) {
      std::cout << results.second << std::endl << std::endl;
      std::cout << std::string(10, '=') << std::endl;
      std::cout << results.first << " fails out of " << tests_.size()
                << std::endl;
      std::cout << std::string(10, '=') << std::endl;
    } else {
      std::cout << results.second << std::endl << std::endl;
      std::cout << std::string(10, '=') << std::endl;
      std::cout << "OK" << std::endl;
      std::cout << std::string(10, '=') << std::endl;
    }
  }
};
} // namespace test

class TestValue : public test::Test {
public:
  std::string id() const final { return "TestValue"; }
  test::TestResult test() const final {
    return test::TestResult(cube::Value::Red != cube::Value::Blue, "");
  }
};

class TestOperation : public test::Test {
private:
  cube::Configuration in_;
  std::function<cube::Configuration(const cube::Configuration &)> function_;
  cube::Configuration expected_;

public:
  TestOperation(
      const cube::Configuration &in,
      const std::function<cube::Configuration(const cube::Configuration &)>
          &function,
      const cube::Configuration &expected)
      : in_(in), function_(function), expected_(expected) {}

  virtual ~TestOperation() {}

  test::TestResult test() const final {
    const auto result = function_(in_);
    if (!std::equal(result.begin(), result.end(), expected_.begin())) {
      const auto diff =
          std::mismatch(result.begin(), result.end(), expected_.begin());
      std::stringstream ss;
      ss << "element " << std::distance(result.begin(), diff.first)
         << " in result does not match expected" << std::endl;
      ss << "input : " << std::endl;
      ss << cube::show_net(in_) << std::endl;
      ss << "result : " << std::endl;
      ss << cube::show_net(result) << std::endl;
      ss << "expected : " << std::endl;
      ss << cube::show_net(expected_) << std::endl;
      return test::TestResult(false, ss.str());
    }
    return test::TestResult(true, "");
  }
};

class TestTopTwistRight : public TestOperation {
public:
  TestTopTwistRight(const cube::Configuration &in,
                    const cube::Configuration &expected)
      : TestOperation(in, cube::top_twist_right, expected) {}

  std::string id() const final { return "TestTopTwistRight"; }
};

int main() {
  test::TestRunner tests;
  tests.add(new TestValue);
  tests.add(new TestTopTwistRight(
      {
          cube::Value::White,  cube::Value::Blue,   cube::Value::White,
          cube::Value::Yellow, cube::Value::White,  cube::Value::White,
          cube::Value::Blue,   cube::Value::Red,    cube::Value::White,
          cube::Value::Orange, cube::Value::Orange, cube::Value::Orange,
          cube::Value::Yellow, cube::Value::White,  cube::Value::Green,
          cube::Value::Red,    cube::Value::Green,  cube::Value::Orange,
          cube::Value::Orange, cube::Value::Orange, cube::Value::Orange,
          cube::Value::Green,  cube::Value::Green,  cube::Value::Yellow,
          cube::Value::Red,    cube::Value::Red,    cube::Value::Green,
          cube::Value::Orange, cube::Value::Orange, cube::Value::Yellow,
          cube::Value::Blue,   cube::Value::Blue,   cube::Value::Green,
          cube::Value::Red,    cube::Value::Red,    cube::Value::Yellow,
          cube::Value::Red,    cube::Value::Red,    cube::Value::Blue,
          cube::Value::Blue,   cube::Value::Blue,   cube::Value::Green,
          cube::Value::Green,  cube::Value::White,  cube::Value::White,
          cube::Value::Blue,   cube::Value::Yellow, cube::Value::Red,
          cube::Value::White,  cube::Value::Yellow, cube::Value::Blue,
          cube::Value::Yellow, cube::Value::Yellow, cube::Value::Green,
      },
      {
          cube::Value::White,  cube::Value::White,  cube::Value::White,
          cube::Value::Blue,   cube::Value::White,  cube::Value::Red,
          cube::Value::White,  cube::Value::Yellow, cube::Value::Blue,
          cube::Value::Green,  cube::Value::Yellow, cube::Value::Yellow,
          cube::Value::Orange, cube::Value::Orange, cube::Value::Orange,
          cube::Value::Yellow, cube::Value::White,  cube::Value::Green,
          cube::Value::Orange, cube::Value::Orange, cube::Value::Orange,
          cube::Value::Green,  cube::Value::Green,  cube::Value::Yellow,
          cube::Value::Red,    cube::Value::Red,    cube::Value::Green,
          cube::Value::Orange, cube::Value::Orange, cube::Value::Yellow,
          cube::Value::Blue,   cube::Value::Blue,   cube::Value::Green,
          cube::Value::Red,    cube::Value::Red,    cube::Value::Yellow,
          cube::Value::Red,    cube::Value::Red,    cube::Value::Blue,
          cube::Value::Blue,   cube::Value::Blue,   cube::Value::Green,
          cube::Value::Green,  cube::Value::White,  cube::Value::White,
          cube::Value::Blue,   cube::Value::Yellow, cube::Value::Red,
          cube::Value::White,  cube::Value::Yellow, cube::Value::Blue,
          cube::Value::Orange, cube::Value::Green,  cube::Value::Red,
      }));
  tests.run();
  return 0;
}
