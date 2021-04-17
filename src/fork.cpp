//
// Created by Gueren Drive on 4/17/21.
//

#include "fork.hpp"

namespace sim {
  Fork::Fork(int id) : id_(id) {}

  void Fork::SetId(int id) {
    id_ = id;
  }

  int Fork::GetId() const {
    return id_;
  }
}
