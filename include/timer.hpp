//
// Created by Gueren Drive on 4/11/21.
//

#pragma once

#ifndef TIMER_HPP
# define TIMER_HPP

# include <chrono>
# include <mutex>

namespace utils {
  class Timer {
   public:
    // Constructors, destructor, operator= -------------------------------------
    Timer();

    // Member-functions --------------------------------------------------------
    void   Reset();
    size_t Elapsed();
    size_t MsElapsed();
    size_t McElapsed();

   private:
    using clock_t   = std::chrono::high_resolution_clock;
    using second_t  = std::chrono::duration<size_t, std::ratio<1> >;
    using msecond_t = std::chrono::duration<size_t, std::ratio<1, 1000> >;
    using mcsecond_t = std::chrono::duration<size_t, std::ratio<1, 1000000> >;
    std::mutex appeal_{};
    std::chrono::time_point<clock_t> m_beg_;
  };
}  // namespace utils

#endif  // TIMER_HPP
