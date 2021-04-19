//
// Created by Gueren Drive on 4/15/21.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "philosopher.hpp"

namespace sim{
  sim::Philosopher::Philosopher(int id, std::mutex *saying)
  : id_(id), output_stream_(saying) {}

  // Setters, getters
  void Philosopher::SetLeftFork(const std::shared_ptr<std::mutex> &left_fork) {
    left_fork_ = left_fork;
  }

  const std::shared_ptr<std::mutex> & Philosopher::GetLeftFork() const {
    return left_fork_;
  }

  void Philosopher::SetRightFork
  (const std::shared_ptr<std::mutex> &right_fork) {
    right_fork_ = right_fork;
  }

  const std::shared_ptr<std::mutex> & Philosopher::GetRightFork() const {
    return right_fork_;
  }

  void Philosopher::SetSaying(std::mutex *saying) {
    output_stream_ = saying;
  }

  void sim::Philosopher::SetId(int id) {
    id_ = id;
  }

  int Philosopher::GetId() const {
    return id_;
  }

  // Actions
  void Philosopher::Eat() {
    std::lock_guard<std::mutex> l_fork(*left_fork_);
    this->SayTakenFork();
    std::lock_guard<std::mutex> r_fork(*right_fork_);
    timer_.Reset();
    this->SayTakenFork();
    this->SayIEat();
    std::this_thread::sleep_for(std::chrono::milliseconds(eating_time_));
  }

  void Philosopher::Sleep() const {
    this->SayISleep();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time_));
  }

  // Saying
  void Philosopher::SayIEat() const {
    std::lock_guard<std::mutex> l(*output_stream_);
    std::cout << simulation_timer_->MsElapsed() << " ";
    std::cout << id_ << " is eating" << std::endl;
  }

  void Philosopher::SayISleep() const {
    std::lock_guard<std::mutex> l(*output_stream_);
    std::cout << simulation_timer_->MsElapsed() << " ";
    std::cout << id_ << " is sleeping" << std::endl;
  }

  void Philosopher::SayIThink() const {
    std::lock_guard<std::mutex> l(*output_stream_);
    std::cout << simulation_timer_->MsElapsed() << " ";
    std::cout << id_ << " is thinking" << std::endl;
  }

  void Philosopher::SayIDead() const {
    std::lock_guard<std::mutex> l(*output_stream_);
    std::cout << simulation_timer_->MsElapsed() << " ";
    std::cout << id_ << " is dead" << std::endl;
  }

  void Philosopher::SayTakenFork() const {
    std::lock_guard<std::mutex> l(*output_stream_);
    std::cout << simulation_timer_->MsElapsed() << " ";
    std::cout << id_ << " has taken fork" << std::endl;
  }
}
