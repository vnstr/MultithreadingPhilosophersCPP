//
// Created by Gueren Drive on 4/17/21.
//

#pragma once

#ifndef MULTITHREADINGPHILOSOPHERSCPP_CONFIG_HPP
#define MULTITHREADINGPHILOSOPHERSCPP_CONFIG_HPP

# include <map>
# include <mutex>

# include "timer.hpp"

namespace sim {
  class Config {
    // Singleton ---------------------------------------------------------------
   public:
    static Config &Instance();
   private:
    Config() = default;
    Config(const Config &x) = delete;
    Config &operator=(const Config &x) = delete;

   public:
    // Modifiers ---------------------------------------------------------------
    void Configurate(std::mutex *output_stream, utils::Timer *timer,
                     int nb_of_settings, char **configuration);

    // Setters, Getters --------------------------------------------------------
    void SetOutputStream(std::mutex *output_stream);
    void SetTimer(utils::Timer *timer);
    void SetPhilosophersAmount(int philosophers_amount);
    void SetLifetime(int lifetime);
    void SetEatingTime(int eating_time);
    void SetSleepingTime(int sleeping_time);
    void SetNbOfTimesEachShouldEat(int nb_of_times_each_should_eat);

    std::mutex *GetOutputStream();
    int        GetPhilosophersAmount() const;
    int        GetLifetime() const;
    int        GetEatingTime() const;
    int        GetSleepingTime() const;
    int        GetNbOfTimesEachShouldEat() const;


    utils::Timer *GetTimer() const;

    // Exception  --------------------------------------------------------------
    class ConfigError {
      virtual const char* what() const noexcept;
    };
   private:
    // Config fields
    std::mutex *output_stream_;
    utils::Timer *timer_;
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
