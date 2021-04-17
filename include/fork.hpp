//
// Created by Gueren Drive on 4/17/21.
//

#pragma once

#ifndef MULTITHREADINGPHILOSOPHERSCPP_FORK_HPP
#define MULTITHREADINGPHILOSOPHERSCPP_FORK_HPP

#include <mutex>  // std::mutex, std::unique_lock

namespace sim {
  class Fork {
   public:
    Fork(int id);

   private:
    int id_;
    std::mutex mutex_;
  };
}

#endif //MULTITHREADINGPHILOSOPHERSCPP_FORK_HPP
