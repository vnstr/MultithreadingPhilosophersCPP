//
// Created by Gueren Drive on 4/17/21.
//

#include <iostream>
#include <memory>

#include "table.hpp"
#include "config.hpp"

namespace sim {
  Table::Table(std::mutex *output_mutex) : output_mutex_(output_mutex) {
    std::shared_ptr<std::mutex> left_fork;
    std::shared_ptr<std::mutex> right_fork;

    philosophers_ = std::make_unique<sim::Philosopher[]>(philosopher_amount_);
    for (int i = 0; i < philosopher_amount_ - 1; ++i) {
      philosophers_.get()[i].SetSaying(output_mutex_);
      philosophers_.get()[i].SetId(i + 1);

      if (i == 0) {
        left_fork = std::make_shared<std::mutex>();
        philosophers_.get()[i].SetLeftFork(left_fork);
        philosophers_.get()[philosopher_amount_ - 1].SetRightFork(left_fork);
        philosophers_.get()[philosopher_amount_ - 1].SetSaying(output_mutex_);
        philosophers_.get()[philosopher_amount_ - 1].SetId(philosopher_amount_);

        right_fork = std::make_shared<std::mutex>();
        philosophers_.get()[i].SetRightFork(right_fork);
        philosophers_.get()[i + 1].SetLeftFork(right_fork);
      } else {
        right_fork = std::make_shared<std::mutex>();
        philosophers_.get()[i].SetRightFork(right_fork);
        philosophers_.get()[i + 1].SetLeftFork(right_fork);
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

  // Other
  void Table::Visualize() {
    std::cout << "\x1b[32mPhilosophers ==========\x1b[0m\n";
    for (int i = 0; i < philosopher_amount_; ++i) {
      std::cout << "id: " << philosophers_.get()[i].GetId() << "\n";
    }
    std::cout << "\x1b[32m=======================\x1b[0m" << std::endl;
  }
}
