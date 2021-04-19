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
    explicit Philosopher(int id);

    // Setters, getters
    void SetLeftFork(const std::shared_ptr<std::mutex> &left_fork);
    void SetRightFork(const std::shared_ptr<std::mutex> &right_fork);
    void SetNbOfTimesEachEat(std::atomic<int> *nb_of_times_each_eat);
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

    utils::Timer timer_;

   private:
    std::shared_ptr<std::mutex> left_fork_{nullptr};
    std::shared_ptr<std::mutex> right_fork_{nullptr};
    std::mutex *output_stream_{sim::Config::Instance().GetOutputStream()};
    utils::Timer *simulation_timer_{sim::Config::Instance().GetTimer()};
    std::atomic<int> *nb_of_times_each_eat_{nullptr};
    int eating_time_{sim::Config::Instance().GetEatingTime()};
    int sleep_time_{sim::Config::Instance().GetSleepingTime()};
    int id_{};
  };
}

#endif //MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP
