//
// Created by Gueren Drive on 4/15/21.
//

#include "philosopher.hpp"

namespace sim{
  sim::Philosopher::Philosopher(int id) : id_(id) {}

  // Setters
  void sim::Philosopher::SetId(int id) {
    id_ = id;
  }
}
