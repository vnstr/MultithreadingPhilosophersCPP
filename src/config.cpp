//
// Created by Gueren Drive on 4/17/21.
//

#include <string>

#include "config.hpp"
#include "utils.hpp"

namespace sim {
  // Singleton ---------------------------------------------------------------
  Config &Config::Instance() {
    static Config singleton;
    return singleton;
  }

  // Initialization static fields
  std::map<int, Config::Setter> Config::setters_ = {
          {0, &Config::SetPhilosophersAmount},
          {1, &Config::SetLifetime},
          {2, &Config::SetEatingTime},
          {3, &Config::SetSleepingTime},
          {4, &Config::SetNbOfTimesEachShouldEat}};

  // Modifiers ---------------------------------------------------------------
  void Config::Configurate(std::mutex *output_stream, utils::Timer *timer,
                           int nb_of_settings, char **configuration) {
    if (nb_of_settings != 4 && nb_of_settings != 5) {
      throw Config::ConfigError();
    }
    output_stream_  = output_stream;
    timer_ = timer;
    int parameter;
    for (int i = 0; i < nb_of_settings; ++i) {
      if (!utils::IsDigits(configuration[i])) {
        throw Config::ConfigError();
      }
      parameter = std::stoi(configuration[i]);
      if (!parameter || (i == 0 && parameter == 1)) {
        throw Config::ConfigError();
      }
      (this->*setters_[i])(parameter);
    }
  }

  // Setters, Getters --------------------------------------------------------
  void Config::SetOutputStream(std::mutex *output_stream) {
    output_stream_ = output_stream;
  }

  void Config::SetTimer(utils::Timer *timer) {
    timer_ = timer;
  }

  void Config::SetPhilosophersAmount(int philosophers_amount) {
    philosophers_amount_ = philosophers_amount;
  }

  void Config::SetLifetime(int lifetime) {
    lifetime_ = lifetime;
  }

  void Config::SetEatingTime(int eating_time) {
    eating_time_ = eating_time;
  }

  void Config::SetSleepingTime(int sleeping_time) {
    sleeping_time_ = sleeping_time;
  }

  void Config::SetNbOfTimesEachShouldEat(int nb_of_times_each_should_eat) {
    nb_of_times_each_should_eat_ = nb_of_times_each_should_eat;
  }

  std::mutex *Config::GetOutputStream() {
    return output_stream_;
  }

  utils::Timer *Config::GetTimer() const {
    return timer_;
  }

  int  Config::GetPhilosophersAmount() const {
    return philosophers_amount_;
  }

  int  Config::GetLifetime() const {
    return lifetime_;
  }

  int  Config::GetEatingTime() const {
    return eating_time_;
  }

  int  Config::GetSleepingTime() const {
    return sleeping_time_;
  }

  int  Config::GetNbOfTimesEachShouldEat() const {
    return nb_of_times_each_should_eat_;
  }

  // Exception  --------------------------------------------------------------
  const char* Config::ConfigError::what() const noexcept {
    return "bad configuration";
  }
}
