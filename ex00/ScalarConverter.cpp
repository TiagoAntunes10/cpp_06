/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:33:11 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/01 22:58:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

static bool is_char(std::string const input) {
  if (input.length() == 1 && !std::isdigit(input[0]))
    return true;

  return false;
}

static bool int_limits(double d) {
  if (d > INT_MAX || d < INT_MIN)
    return true;

  return false;
}

static bool is_pseudo(std::string const input) {
  std::string pseudos[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};

  for (int i = 0; i < 6; i++) {
    if (!input.compare(pseudos[i]))
      return true;
  }

  return false;
}

static bool find_repeated(std::string const input) {
  std::string chr_to_find = "+-f.";
  int length = input.length();
  int count;
  int count_signs = 0;

  for (int i = 0; i < 4; i++) {
    count = 0;

    for (int j = 0; j < length; j++) {
      if (chr_to_find[i] == input[j] && i < 2)
        count_signs++;
      else if (chr_to_find[i] == input[j])
        count++;
    }

    if (count > 1 || count_signs > 1)
      return true;
  }

  return false;
}

static bool invalid_f(std::string const input) {
  unsigned long int f_pos = input.find('f');
  unsigned long int last_digit_pos = input.find_last_of(DIGITS);

  if (f_pos != std::string::npos &&
      (last_digit_pos == std::string::npos || f_pos < last_digit_pos))
    return true;

  return false;
}

static bool is_invalid(std::string const input, int type) {
  double d;

  if (input.length() >= 2 && !is_pseudo(input)) {
    if (input.find_first_not_of(VALID_CHR) != std::string::npos ||
        find_repeated(input) || invalid_f(input))
      return true;
  }

  if (type == 0) {
    d = std::strtod(input.c_str(), 0);

    if (int_limits(d))
      return true;
  }

  return false;
}

static bool float_limits(double d) {
  if (!std::isnan(d) && !std::isinf(d) && (d > FLT_MAX || d < -FLT_MAX))
    return true;

  return false;
}

static short real_num(std::string const input) {
  double d;
  unsigned int last_pos = input.length() - 1;

  if (last_pos > 0 &&
      (input.find('.') != std::string::npos || is_pseudo(input))) {
    if (input[last_pos] == 'f') {
      d = std::strtod(input.c_str(), 0);

      if (float_limits(d))
        return (0);

      return (2);
    } else if (!is_pseudo(input) && !std::isdigit(input[last_pos]))
      return (0);

    return (1);
  }

  return (0);
}

static bool char_limits(int integer) {
  if (integer > UCHAR_MAX || integer < 0)
    return true;
  return false;
}

static unsigned int count_dec(std::string const input) {
  int last_pos = input.length() - 1;

  if (!std::isdigit(input[last_pos])) {
    while (!std::isdigit(input[last_pos]))
      last_pos--;
    return (last_pos - input.find('.'));
  }
  return (last_pos - input.find('.'));
}

void ScalarConverter::convert(char *input) {
  char chr;
  int integer;
  float f;
  double d;
  short real_type;
  unsigned int num_dec = 1;

  real_type = real_num(input);
  if (is_invalid(input, real_type)) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;

    return;
  }

  if (real_type == 1) {
    d = std::strtod(input, 0);

    f = static_cast<float>(d);
    integer = static_cast<int>(d);
    chr = static_cast<char>(d);
    num_dec = count_dec(input);
  } else if (real_type == 2) {
    f = std::strtof(input, 0);

    d = static_cast<double>(f);
    integer = static_cast<int>(f);
    chr = static_cast<char>(f);
    num_dec = count_dec(input);
  } else if (is_char(input)) {
    chr = input[0];

    d = static_cast<double>(chr);
    f = static_cast<float>(chr);
    integer = static_cast<int>(chr);
  } else {
    integer = std::atoi(input);

    d = static_cast<double>(integer);
    f = static_cast<float>(integer);
    chr = static_cast<char>(integer);
  }

  if (std::isnan(d) || std::isinf(d))
    std::cout << "char: impossible\nint: impossible" << std::endl;
  else {
    std::cout << "char: ";

    if (char_limits(integer))
      std::cout << "impossible" << std::endl;
    else if (isprint(chr))
      std::cout << "'" << chr << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;

    std::cout << "int: ";
    if (int_limits(d))
      std::cout << "impossible" << std::endl;
    else
      std::cout << integer << std::endl;
  }

  std::cout << std::fixed << "float: ";
  if (float_limits(d))
    std::cout << "impossible" << std::endl;
  else
    std::cout << std::setprecision(num_dec) << f << "f" << std::endl;

  std::cout << "double: ";
  std::cout << std::setprecision(num_dec) << d << std::endl;
}
