#include "include/numeric_die.h"

#include <utility>

template<int n>
NumericDie<n>::NumericDie(void) : Die<int, n>(std::make_index_sequence<n>()) {}
