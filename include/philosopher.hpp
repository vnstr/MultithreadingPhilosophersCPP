//
// Created by Gueren Drive on 4/15/21.
//

#pragma once

#ifndef MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP
#define MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP

#include <memory>

#include "timer.hpp"
#include "fork.hpp"

namespace sim {
  class Philosopher {
   public:
    Philosopher() = default;
    explicit Philosopher(int id);

    // Setters
    void SetId(int id);

    utils::Timer timer;

   private:
    int id_{};
    std::shared_ptr<sim::Fork> left_fork_;
    std::shared_ptr<sim::Fork> right_fork_;
  };
}

#endif //MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP
