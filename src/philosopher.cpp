//
// Created by Gueren Drive on 4/15/21.
//

#include <iostream>

#include "philosopher.hpp"

namespace sim{
  sim::Philosopher::Philosopher(int id, std::mutex *saying)
  : id_(id), saying_(saying) {}

  // Setters, getters
  void Philosopher::SetLeftFork(const std::shared_ptr<sim::Fork> &left_fork) {
    left_fork_ = left_fork;
  }

  const std::shared_ptr<sim::Fork> &Philosopher::GetLeftFork() const {
    return left_fork_;
  }

  void Philosopher::SetRightFork(const std::shared_ptr<sim::Fork> &right_fork) {
    right_fork_ = right_fork;
  }

  const std::shared_ptr<sim::Fork> &Philosopher::GetRightFork() const {
    return right_fork_;
  }

  void Philosopher::SetSaying(std::mutex *saying) {
    saying_ = saying;
  }

  void sim::Philosopher::SetId(int id) {
    id_ = id;
  }

  int Philosopher::GetId() const {
    return id_;
  }

  // Actions
  void Philosopher::Eat() {

  }

  // Saying
  void Philosopher::SayEating() {
    std::lock_guard<std::mutex>(*saying_);
    std::cout << id_ << " is eating" << std::endl;
  }
}
