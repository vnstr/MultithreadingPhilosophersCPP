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
    void SayIEat() const;
    void SayISleep() const;
    void SayIThink() const;
    void SayIDead() const;
    void SayTakenFork() const;

    std::atomic<utils::Timer> timer_{utils::Timer()};

   private:
    std::shared_ptr<std::mutex> left_fork_;
    std::shared_ptr<std::mutex> right_fork_;
    std::mutex *output_stream_{sim::Config::Instance().GetOutputStream()};
    std::atomic<utils::Timer> *simulation_timer_{sim::Config::Instance().GetTimer()};
    int eating_time_{sim::Config::Instance().GetEatingTime()};
    int sleep_time_{sim::Config::Instance().GetSleepingTime()};
    int id_{};
  };
}

#endif //MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP
