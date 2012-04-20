#include <boost/test/minimal.hpp>
#include <boost/format.hpp>
#include <iostream>

int test_main(int argc, char* argv[]) {
  using namespace boost;
  format fmt("%d-%d");
  BOOST_CHECK(fmt.size() != 0);
  fmt % 12 % 34;
  BOOST_REQUIRE(fmt.str() == "12-34");
  BOOST_ERROR("an error message");
  fmt.clear();
  fmt % 12;
  try {
    std::cout << fmt << std::endl;
  } catch (...) {
    BOOST_FAIL("fatal error");
  }
  return 0;
}


