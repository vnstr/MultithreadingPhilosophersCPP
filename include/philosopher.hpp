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
    explicit Philosopher(int id, std::mutex *saying);

    // Setters, getters
    void SetLeftFork(const std::shared_ptr<sim::Fork> &left_fork);
    const std::shared_ptr<sim::Fork> &GetLeftFork() const;

    void SetRightFork(const std::shared_ptr<sim::Fork> &right_fork);
    const std::shared_ptr<sim::Fork> &GetRightFork() const;

    void SetSaying(std::mutex *saying);

    void SetId(int id);
    int  GetId() const;

    // Actions
    void Eat();

    // Saying
    void SayEating();

    utils::Timer timer;

   private:
    std::shared_ptr<sim::Fork> left_fork_;
    std::shared_ptr<sim::Fork> right_fork_;
    std::mutex *saying_;
    int id_{};
  };
}

#endif //MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP
