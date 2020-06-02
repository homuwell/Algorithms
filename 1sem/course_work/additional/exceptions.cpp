#ifndef ALGORITHMS_CPP
#define ALGORITHMS_CPP
#include <exception>
class WeightError : public std::exception {
  const char *what() const noexcept override {
    return 0;
  }
};
class ItemsNumError : public std::exception {
  const char *what() const noexcept override {

    return 0;
  }
};
class PriceError : public std::exception {
  const char *what() const noexcept {
    return "price can't be negative";
  }
};
class ItemsLimitError : public std::exception {
  const char *what() const noexcept override {
    return "Limit of items can't be negative or 0";
  }
};
class BackpackWeightError : public std::exception {
  const char *what() const noexcept override {
    return "Backpack wight can't be negative or 0";
  }
};

#endif


