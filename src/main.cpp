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

utils::Timer timer;
std::mutex starting;
std::mutex output_stream;
std::condition_variable alarm_clock;
bool start = false;

void check_philosophers(const sim::Table &table) {
  int id = 1;

  while (true) {
    if (table.AtPhilolosopher(id).timer_.MsElapsed() >= sim::Config::Instance().GetLifetime()) {
      table.AtPhilolosopher(id).SayIDead();
      output_stream.lock();
      return;
    }
    ++id;
    if (id > table.GetPhilosopherAmount()) {
      id = 1;
    }
  }
}

void live(sim::Philosopher &p) {
  std::unique_lock<std::mutex> preparation(starting);

  while (!start) {alarm_clock.wait(preparation);}
  preparation.unlock();
  if (p.GetId() % 2) {
    std::this_thread::sleep_for(std::chrono::microseconds(60));
  }
  while (true) {
    p.SayIThink();
    p.Eat();
    p.Sleep();
  }
}

int main(int argc, char **argv) {
  std::cout << "Hello world" << std::endl;
  sim::Config::Instance().Configurate(&output_stream, &timer, argc - 1,
                                      argv + 1);
  sim::Table table;

  for (int i = 0; i < table.GetPhilosopherAmount(); ++i) {
    std::thread(live, std::ref(table.AtPhilolosopher(i + 1))).detach();
  }
  std::this_thread::sleep_for(std::chrono::milliseconds (100));
  start = true;
  timer.Reset();
  alarm_clock.notify_all();
  check_philosophers(table);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  return 0;
}
