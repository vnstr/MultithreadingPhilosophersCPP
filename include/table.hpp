//
// Created by Gueren Drive on 4/17/21.
//

#pragma once

#ifndef MULTITHREADINGPHILOSOPHERSCPP_TABLE_HPP
#define MULTITHREADINGPHILOSOPHERSCPP_TABLE_HPP

# include <memory>

# include "philosopher.hpp"

namespace sim {
  class Table {
   public:
    Table();

    // Setters, getters
    [[nodiscard]] int GetPhilosopherAmount() const;

    // Element access:
    const sim::Philosopher &AtPhilolosopher(int id);

    // Other
    void Visualize();

    // Public fields
    utils::Timer timer;


   private:
    std::unique_ptr<sim::Philosopher[]> philosophers_;
    std::mutex saying_;
    int philosopher_amount_;
  };
}

#endif //MULTITHREADINGPHILOSOPHERSCPP_TABLE_HPP
