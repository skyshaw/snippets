#include <boost/progress.hpp>
#include <boost/static_assert.hpp>
#include <iostream>

template <int N = 2>
class new_progress_timer : public boost::timer {
 public:
  new_progress_timer(std::ostream& os = std::cout) : os_(os) {
    BOOST_STATIC_ASSERT(N >= 0 && N <= 10);
  }
  ~new_progress_timer() {
    try {
      std::istream::fmtflags old_flags =
          os_.setf(std::istream::fixed, std::istream::floatfield);
      std::streamsize old_prec = os_.precision(N);
      os_ << elapsed() << " s\n" << std::endl;
      os_.flags(old_flags);
      os_.precision(old_prec);
    } catch (...) {
    }
  }
 private:
  std::ostream& os_;
};

template <>
class new_progress_timer<2> : public boost::progress_timer {
};
