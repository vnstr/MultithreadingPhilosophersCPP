//
// Created by Gueren Drive on 4/15/21.
//

// condition_variable::notify_one
//#include <thread>             // std::thread
//#include <mutex>              // std::mutex, std::unique_lock
//#include <chrono>
//#include <condition_variable> // std::condition_variable
//#include <future>

#include <iostream>

#include "config.hpp"

int main(int argc, char **argv) {
  std::cout << "Hello world" << std::endl;
  simulation::Config config;

  config.Configurate(argc - 1, argv + 1);
  return 0;
}
