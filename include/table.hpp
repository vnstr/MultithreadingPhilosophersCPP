//
// Created by Gueren Drive on 4/17/21.
//

#pragma once

#ifndef MULTITHREADINGPHILOSOPHERSCPP_TABLE_HPP
#define MULTITHREADINGPHILOSOPHERSCPP_TABLE_HPP

#include <memory>
#include <mutex>

#include "timer.hpp"
#include "philosopher.hpp"

namespace sim {
  // TODO(gdrive): atomic nb_of_each_eated
  class Table {
   public:
    Table();

    // Setters, getters
    [[nodiscard]] int GetPhilosopherAmount() const;

    // Element access:
    sim::Philosopher       &AtPhilolosopher(int id);
    const sim::Philosopher &AtPhilolosopher(int id) const;
    int                    HowManyPhilosophersHaveEaten() const;

    // Other
    void Visualize();

    // Public fields
    utils::Timer timer;

   private:
    std::unique_ptr<sim::Philosopher[]> philosophers_;
    std::atomic<int> nb_of_times_each_eat_{0};
    int philosopher_amount_{Config::Instance().GetPhilosophersAmount()};
  };
}  // namespace sim

#endif  // MULTITHREADINGPHILOSOPHERSCPP_TABLE_HPP
