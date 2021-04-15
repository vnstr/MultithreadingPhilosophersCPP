//
// Created by Gueren Drive on 4/15/21.
//

#pargma once

#ifndef MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP
#define MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP

class Philosopher {
 public:
  Philosopher() = default;
  Philosopher(int id);
  Philosopher(const Philosopher &x) = default;
  ~Philosopher() = default;
  Philosopher &operator=(const Philosopher &x) = default;

 private:
  int id_;
};

#endif //MULTITHREADINGPHILOSOPHERSCPP_PHILOSOPHER_HPP
