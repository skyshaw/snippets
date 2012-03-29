#include <boost/progress.hpp>
#include <boost/static_assert.hpp>
#include <iostream>

template <int N = 2>
class new_progress_timer : public boost::timer {
 public:
  new_progress_timer(std::ostream& os) : os_(os) {
    BOOST_STATIC_ASSERT(N >= 0 && N <= 10);
  }
  ~new_progress_timer() {
    try {
    } catch (...) {
    }
  }
 private:
  std::ostream& os_;
};
