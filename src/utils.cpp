//
// Created by Gueren Drive on 4/17/21.
//

#include <string>
#include <cctype>  // std::isdigit(int c);

namespace utils {
  bool IsNumbers(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char ch) {
      return !std::isdigit(ch);
    }) == s.end();
  }

}
