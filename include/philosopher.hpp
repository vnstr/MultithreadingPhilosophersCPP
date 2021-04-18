//
// Created by Gueren Drive on 4/15/21.
//

#pragma once

#ifndef MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP
#define MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP

#include <memory>

#include "config.hpp"
#include "timer.hpp"

namespace sim {
  class Philosopher {
   public:
    Philosopher() = default;
    explicit Philosopher(int id, std::mutex *saying);

    // Setters, getters
    void SetLeftFork(const std::shared_ptr<std::mutex> &left_fork);
    const std::shared_ptr<std::mutex> & GetLeftFork() const;

    void SetRightFork(const std::shared_ptr<std::mutex> &right_fork);
    const std::shared_ptr<std::mutex> & GetRightFork() const;

    void SetSaying(std::mutex *saying);

    void SetId(int id);
    int  GetId() const;

    // Actions
    void Eat();
    void Sleep() const;

    // Saying
    void SayEating() const;
    void SaySleeping() const;
    void SayThinking() const;
    void SayTakenFork() const;

    utils::Timer timer;

   private:
    std::shared_ptr<std::mutex> left_fork_;
    std::shared_ptr<std::mutex> right_fork_;
    std::mutex *saying_;
    int eating_time_{sim::Config::Instance().GetEatingTime()};
    int sleep_time_{sim::Config::Instance().GetSleepingTime()};
    int id_{};
  };
}

#endif //MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP
