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
    Config(const Config &x) = delete;
    Config &operator=(const Config &x) = delete;
    static Config &Instance();
   private:
    Config() = default;

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

    std::mutex        *GetOutputStream();
    [[nodiscard]] int GetPhilosophersAmount() const;
    [[nodiscard]] int GetLifetime() const;
    [[nodiscard]] int GetEatingTime() const;
    [[nodiscard]] int GetSleepingTime() const;
    [[nodiscard]] int GetNbOfTimesEachShouldEat() const;


    [[nodiscard]] utils::Timer *GetTimer() const;

    // Exception  --------------------------------------------------------------
    class ConfigError {
      [[maybe_unused]] virtual const char* what() const noexcept;
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
