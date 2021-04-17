//
// Created by Gueren Drive on 4/11/21.
//

#include "timer.hpp"

namespace utils {
// Constructors, destructor, operator= -----------------------------------------
  Timer::Timer() : m_beg_(clock_t::now()) {}

// Member-functions ----------------------------------------------------------
  void   Timer::Reset() {
    m_beg_ = clock_t::now();
  }

  size_t Timer::Elapsed() const {
    return std::chrono::
           duration_cast<second_t>(clock_t::now() - m_beg_).count();
  }

  size_t Timer::MsElapsed() const {
    return std::chrono::
           duration_cast<msecond_t>(clock_t::now() - m_beg_).count();
  }

  size_t Timer::McElapsed() const {
    return std::chrono::
    duration_cast<mcsecond_t>(clock_t::now() - m_beg_).count();
  }

}
