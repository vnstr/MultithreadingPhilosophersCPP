//
// Created by Gueren Drive on 4/15/21.
//

// condition_variable::notify_one
#include <thread>              // std::thread
#include <condition_variable>  // std::condition_variable
//#include <mutex>             // std::mutex, std::unique_lock
#include <chrono>
//#include <future>

#include <unistd.h>

#include <iostream>

#include "config.hpp"
#include "table.hpp"

std::mutex starting;
std::condition_variable alarm_clock;
bool start = false;

void live(sim::Philosopher &p) {
  std::unique_lock<std::mutex> lg(starting);
  while (!start) {alarm_clock.wait(lg);}
}

int main(int argc, char **argv) {
  std::cout << "Hello world" << std::endl;
  sim::Config::Instance().Configurate(argc - 1, argv + 1);
  sim::Table table;
  table.Visualize();
  return 0;
}
