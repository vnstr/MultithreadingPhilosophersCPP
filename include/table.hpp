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

   private:
    std::unique_ptr<Philosopher[]> philosophers_;
    int philosopher_amount_;
  };
}

#endif //MULTITHREADINGPHILOSOPHERSCPP_TABLE_HPP
