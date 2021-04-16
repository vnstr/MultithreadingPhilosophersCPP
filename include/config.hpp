//
// Created by Gueren Drive on 4/17/21.
//

#pragma once

#ifndef MULTITHREADINGPHILOSOPHERSCPP_CONFIG_HPP
#define MULTITHREADINGPHILOSOPHERSCPP_CONFIG_HPP

# include <map>

namespace simulation {
  class Config {
   public:
    // Modifiers ---------------------------------------------------------------
    void Configurate(int nb_of_settings, char **configuration);

    // Setters, Getters --------------------------------------------------------
    void SetPhilosophersAmount(int philosophers_amount);
    void SetLifetime(int lifetime);
    void SetEatingTime(int eating_time);
    void SetSleepingTime(int sleeping_time);
    void SetNbOfTimesEachShouldEat(int nb_of_times_each_should_eat);

    // Exception  --------------------------------------------------------------
    class ConfigError {
      virtual const char* what() const noexcept;
    };
   private:
    // Config fields
    int philosophers_amount_;
    int lifetime_;
    int eating_time_;
    int sleeping_time_;
    int nb_of_times_each_should_eat_;

    // Map of Setters
    typedef void(Config::*Setter)(int);
    static std::map<int, Setter> setters_;
  };
}

#endif //MULTITHREADINGPHILOSOPHERSCPP_CONFIG_HPP
