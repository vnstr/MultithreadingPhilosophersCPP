//
// Created by Gueren Drive on 4/15/21.
//

#include "philosopher.hpp"

namespace sim{
  sim::Philosopher::Philosopher(int id) : id_(id) {}

  // Setters, getters
  void sim::Philosopher::SetId(int id) {
    id_ = id;
  }

  int Philosopher::GetId() const {
    return id_;
  }
}
