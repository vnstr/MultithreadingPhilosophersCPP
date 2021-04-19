//
// Created by Gueren Drive on 4/17/21.
//

#include <iostream>
#include <memory>

#include "table.hpp"
#include "config.hpp"

namespace sim {
  Table::Table() {
    if (!sim::Config::Instance().IsFull()) {
      throw sim::Config::ConfigError();
    }
    std::shared_ptr<std::mutex> left_fork;
    std::shared_ptr<std::mutex> right_fork;

    philosophers_ = std::make_unique<sim::Philosopher[]>(philosopher_amount_);
    for (int i = 0; i < philosopher_amount_ - 1; ++i) {
      philosophers_[i].SetId(i + 1);
      if (Config::Instance().GetNbOfTimesEachShouldEat()) {
        philosophers_[i].SetNbOfTimesEachEat(&nb_of_times_each_eat_);
      }

      if (i == 0) {
        left_fork = std::make_shared<std::mutex>();
        philosophers_[i].SetLeftFork(left_fork);
        philosophers_[philosopher_amount_ - 1].SetRightFork(left_fork);
        philosophers_[philosopher_amount_ - 1].SetId(philosopher_amount_);
        if (Config::Instance().GetNbOfTimesEachShouldEat()) {
          philosophers_[philosopher_amount_ - 1].SetNbOfTimesEachEat(
                                                        &nb_of_times_each_eat_);
        }

        right_fork = std::make_shared<std::mutex>();
        philosophers_[i].SetRightFork(right_fork);
        philosophers_[i + 1].SetLeftFork(right_fork);
      } else {
        right_fork = std::make_shared<std::mutex>();
        philosophers_[i].SetRightFork(right_fork);
        philosophers_[i + 1].SetLeftFork(right_fork);
      }
    }
  }

  // Setters, getters
  int Table::GetPhilosopherAmount() const {
    return philosopher_amount_;
  }

  // Element access:
  sim::Philosopher &Table::AtPhilolosopher(int id) {
    return philosophers_[id - 1];
  }

  const sim::Philosopher &Table::AtPhilolosopher(int id) const {
    return philosophers_[id - 1];
  }

  int Table::HowManyPhilosophersHaveEaten() const {
    return nb_of_times_each_eat_.load();
  }
}
