//
// Created by Gueren Drive on 4/17/21.
//

#include <iostream>
#include <memory>

#include "table.hpp"
#include "config.hpp"

namespace sim {
  Table::Table()
  : philosopher_amount_(Config::Instance().GetPhilosophersAmount()) {
    philosophers_ = std::make_unique<sim::Philosopher[]>(philosopher_amount_);
    for (int i = 0; i < philosopher_amount_; ++i) {
      philosophers_.get()[i].SetSaying(&saying_);
      philosophers_.get()[i].SetId(i + 1);
      philosophers_.get()[i].SetLeftFork(std::make_shared<sim::Fork>(i));
      if (i + 1 == philosopher_amount_) {
        philosophers_.get()[i].SetRightFork(std::make_shared<sim::Fork>(0));
      } else {
        philosophers_.get()[i].SetRightFork(std::make_shared<sim::Fork>(i + 1));
      }
    }
  }

  // Setters, getters
  int Table::GetPhilosopherAmount() const {
    return philosopher_amount_;
  }

  // Element access:
  sim::Philosopher &Table::AtPhilolosopher(int id) {
    return philosophers_[id];
  }

  // Other
  void Table::Visualize() {
    std::cout << "\x1b[32mPhilosophers ==========\x1b[0m\n";
    for (int i = 0; i < philosopher_amount_; ++i) {
      std::cout
      << "id: "             << philosophers_.get()[i].GetId()
      << " left_fork_id: "  << philosophers_.get()[i].GetLeftFork()->GetId()
      << " right_fork_id: " << philosophers_.get()[i].GetRightFork()->GetId()
      << "\n";
    }
    std::cout << "\x1b[32m=======================\x1b[0m" << std::endl;
  }
}
