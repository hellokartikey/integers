#ifndef HK_INTEGER_H
#define HK_INTEGER_H

#include <compare>
#include <concepts>
#include <cstdint>
#include <utility>

namespace hk {
template <typename I>
  requires std::integral<I>
class Integer {
 public:  // Types and aliases
  using value_type = I;
  using reference = value_type&;
  using const_reference = const value_type&;

  using self = Integer<value_type>;
  using self_reference = self&;
  using self_const_reference = const self&;

 public:
  Integer() = default;
  Integer(Integer&) = default;
  Integer(Integer&&) = default;
  ~Integer() = default;

 public:  // Conversions
  Integer(value_type value) : value(value) {}

 public:  // Getters
  auto get() -> reference { return value; }

  auto cget() const -> value_type { return get(); }

 public:  // Operators
  // Copy assignment
  auto operator=(self_const_reference rhs) -> self_reference {
    if (this == &rhs) {
      return *this;
    }

    value = rhs.value;
    return *this;
  }

  // Move assignment
  auto operator=(Integer&& rhs) noexcept -> self_reference {
    if (this == &rhs) {
      return *this;
    }

    value = std::exchange(rhs.value, 0);
    return *this;
  }

  // Prefix increment
  auto operator++() -> self_reference {
    value++;
    return *this;
  }

  // Postfix increment
  auto operator++(int) -> self {
    auto old = self{*this};
    operator++();
    return old;
  }

  // Prefix decrement
  auto operator--() -> self_reference {
    value--;
    return *this;
  }

  // Postfix decrement
  auto operator--(int) -> self {
    auto old = self{*this};
    operator--();
    return old;
  }

  // Unary plus
  auto operator+() const -> self { return self{+value}; }

  // Unary minus
  auto operator-() const -> self { return self(-value); }

  // Addition assignment
  auto operator+=(self_const_reference rhs) -> self_reference {
    value += rhs.value;
    return *this;
  }

  // Addition
  friend auto operator+(self lhs, self_const_reference rhs) -> self {
    lhs += rhs;
    return lhs;
  }

  // Subtraction assignment
  auto operator-=(self_const_reference rhs) -> self_reference {
    value -= rhs.value;
    return *this;
  }

  // Subtraction
  friend auto operator-(self lhs, self_const_reference rhs) -> self {
    lhs -= rhs;
    return lhs;
  }

  // Multiplication assignment
  auto operator*=(self_const_reference rhs) -> self_reference {
    value *= rhs.value;
    return *this;
  }

  // Multiplication
  friend auto operator*(self lhs, self_const_reference rhs) -> self {
    lhs *= rhs;
    return lhs;
  }

  // Division assignment
  auto operator/=(self_const_reference rhs) -> self_reference {
    value /= rhs.value;
    return *this;
  }

  // Division
  friend auto operator/(self lhs, self_const_reference rhs) -> self {
    lhs /= rhs;
    return lhs;
  }

  // Modulation assignment
  auto operator%=(self_const_reference rhs) -> self_reference {
    value %= rhs.value;
    return *this;
  }

  // Modulation
  friend auto operator%(self lhs, self_const_reference rhs) -> self {
    lhs %= rhs;
    return lhs;
  }

  // Bitwise not
  auto operator~() const -> self { return self{~value}; }

  // Bitwise and assignment
  auto operator&=(self_const_reference rhs) -> self_reference {
    value &= rhs.value;
    return *this;
  }

  // Bitwise and
  friend auto operator&(self lhs, self_const_reference rhs) -> self {
    lhs &= rhs;
    return lhs;
  }

  // Bitwise or assignment
  auto operator|=(self_const_reference rhs) -> self_reference {
    value |= rhs.value;
    return *this;
  }

  // Bitwise or
  friend auto operator|(self lhs, self_const_reference rhs) -> self {
    lhs |= rhs;
    return lhs;
  }

  // Bitwise xor assignment
  auto operator^=(self_const_reference rhs) -> self_reference {
    value ^= rhs.value;
    return *this;
  }

  // Bitwise xor
  friend auto operator^(self lhs, self_const_reference rhs) -> self {
    lhs ^= rhs;
    return lhs;
  }

  // Left shift assignment
  auto operator<<=(self_const_reference rhs) -> self_reference {
    value <<= rhs.value;
    return *this;
  }

  // Left shift
  friend auto operator<<(self lhs, self_const_reference rhs) -> self {
    lhs <<= rhs;
    return lhs;
  }

  // Right shift assignment
  auto operator>>=(self_const_reference rhs) -> self_reference {
    value >>= rhs.value;
    return *this;
  }

  // Right shift
  friend auto operator>>(self lhs, self_const_reference rhs) -> self {
    lhs >>= rhs;
    return lhs;
  }

  // Logical not
  auto operator!() const -> bool { return !value; }

  // Logical and
  friend auto operator&&(self_const_reference lhs, self_const_reference rhs)
      -> bool {
    return lhs.value && rhs.value;
  }

  // Logical or
  friend auto operator||(self_const_reference lhs, self_const_reference rhs)
      -> bool {
    return lhs.value || rhs.value;
  }

  // Comparators
  friend auto operator<=>(self_const_reference lhs,
                          self_const_reference rhs) = default;

 private:
  value_type value;
};

using signed_char = Integer<signed char>;
using unsigned_char = Integer<unsigned char>;

using short_int = Integer<short int>;
using unsigned_short_int = Integer<unsigned short int>;

using integer = Integer<int>;
using unsigend_integer = Integer<unsigned int>;

using long_int = Integer<long int>;
using unsigned_long_int = Integer<unsigned long int>;

using long_long_int = Integer<long long int>;
using unsigned_long_long_int = Integer<unsigned long long int>;

using int8_t = Integer<std::int8_t>;
using int16_t = Integer<std::int16_t>;
using int32_t = Integer<std::int32_t>;
using int64_t = Integer<std::int64_t>;

using int_fast8_t = Integer<std::int_fast8_t>;
using int_fast16_t = Integer<std::int_fast16_t>;
using int_fast32_t = Integer<std::int_fast32_t>;
using int_fast64_t = Integer<std::int_fast64_t>;

using int_least8_t = Integer<std::int_least8_t>;
using int_least16_t = Integer<std::int_least16_t>;
using int_least32_t = Integer<std::int_least32_t>;
using int_least64_t = Integer<std::int_least64_t>;

using intmax_t = Integer<std::intmax_t>;

using intptr_t = Integer<std::intptr_t>;

using uint8_t = Integer<std::uint8_t>;
using uint16_t = Integer<std::uint16_t>;
using uint32_t = Integer<std::uint32_t>;
using uint64_t = Integer<std::uint64_t>;

using uint_fast8_t = Integer<std::uint_fast8_t>;
using uint_fast16_t = Integer<std::uint_fast16_t>;
using uint_fast32_t = Integer<std::uint_fast32_t>;
using uint_fast64_t = Integer<std::uint_fast64_t>;

using uint_least8_t = Integer<std::uint_least8_t>;
using uint_least16_t = Integer<std::uint_least16_t>;
using uint_least32_t = Integer<std::uint_least32_t>;
using uint_least64_t = Integer<std::uint_least64_t>;

using uintmax_t = Integer<std::uintmax_t>;

using uintptr_t = Integer<std::uintptr_t>;
}  // namespace hk

#endif
