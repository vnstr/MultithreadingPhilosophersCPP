//
// Created by Gueren Drive on 4/17/21.
//

#include <iostream>

#include "table.hpp"
#include "config.hpp"

namespace sim {
  Table::Table()
  : philosopher_amount_(Config::Instance().GetPhilosophersAmount()) {
    philosophers_.reset(new sim::Philosopher[philosopher_amount_]);
    forks_.reset(new sim::Fork[philosopher_amount_]);
    for (int i = 0; i < philosopher_amount_; ++i) {
      philosophers_.get()[i].SetId(i + 1);
      forks_.get()[i].SetId(i);
    }
  }

  void Table::Visualize() {
    std::cout << "\x1b[32mPhilosophers ==========\x1b[0m\n";
    for (int i = 0; i < philosopher_amount_; ++i) {
      std::cout << "id: " << philosophers_.get()[i].GetId() << " ";
    }
    std::cout << "\n";
    std::cout << "\x1b[32m=======================\x1b[0m" << std::endl;
    std::cout << "\x1b[32mForks =================\x1b[0m\n";
    for (int i = 0; i < philosopher_amount_; ++i) {
      std::cout << "id: " << forks_.get()[i].GetId() << " ";
    }
    std::cout << "\n";
    std::cout << "\x1b[32m=======================\x1b[0m" << std::endl;
  }
}
