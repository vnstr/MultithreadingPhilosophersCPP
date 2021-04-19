//
// Created by Gueren Drive on 4/15/21.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "philosopher.hpp"

namespace sim{
  sim::Philosopher::Philosopher(int id) : id_(id) {}

  // Setters, getters
  void Philosopher::SetLeftFork(const std::shared_ptr<std::mutex> &left_fork) {
    left_fork_ = left_fork;
  }

  void Philosopher::SetRightFork
  (const std::shared_ptr<std::mutex> &right_fork) {
    right_fork_ = right_fork;
  }

  void sim::Philosopher::SetId(int id) {
    id_ = id;
  }

  void Philosopher::SetNbOfTimesEachEat(
          std::atomic<int> *nb_of_times_each_eat) {
    nb_of_times_each_eat_ = nb_of_times_each_eat;
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
    if (nb_of_times_each_eat_) {
      ++(*nb_of_times_each_eat_);
    }
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
    std::cout << id_ << "\x1b[32m is eating\x1b[0m" << std::endl;
  }

  void Philosopher::SayISleep() const {
    std::lock_guard<std::mutex> l(*output_stream_);
    std::cout << simulation_timer_->MsElapsed() << " ";
    std::cout <<  id_ << "\x1b[34m is sleeping\x1b[0m" << std::endl;
  }

  void Philosopher::SayIThink() const {
    std::lock_guard<std::mutex> l(*output_stream_);
    std::cout << simulation_timer_->MsElapsed() << " ";
    std::cout << id_ << "\x1b[33m is thinking\x1b[0m" << std::endl;
  }

  void Philosopher::SayIDead() const {
    std::lock_guard<std::mutex> l(*output_stream_);
    std::cout << simulation_timer_->MsElapsed() << " ";
    std::cout << id_ << "\x1b[31m is dead\x1b[0m" << std::endl;
  }

  void Philosopher::SayTakenFork() const {
    std::lock_guard<std::mutex> l(*output_stream_);
    std::cout << simulation_timer_->MsElapsed() << " ";
    std::cout << id_ << " has taken fork" << std::endl;
  }
}
