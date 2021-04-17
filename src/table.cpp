//
// Created by Gueren Drive on 4/17/21.
//

#include "table.hpp"
#include "config.hpp"

namespace sim {
  Table::Table()
  : philosopher_amount_(Config::Instance().GetPhilosophersAmount()) {
    philosophers_.reset(new Philosopher[philosopher_amount_]);
    for (int i = 0; i < philosopher_amount_; ++i) {
      philosophers_.get()[i].SetId(i + 1);
    }
  }
}
