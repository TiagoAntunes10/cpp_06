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
#include <cctype>
#include <climits>

static bool is_char(std::string const input) {
  if (input.length() == 1 && !std::isdigit(input[0]))
    return true;
  return false;
}

static bool is_invalid(std::string const input) {
  int count = 0;
  double d;

  if (input.length() >= 2) {
    if (input[0] == '+' || input[0] == '-')
      count++;

    if ((count == 1 && !std::isdigit(input[1])) ||
        (count == 0 && !std::isdigit(input[0])))
      return true;
  }

  d = std::strtod(input.c_str(), 0);
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

static short real_num(std::string const input) {
  double d;

  if (input.find('.') != std::string::npos || is_pseudo(input)) {
    if (input[input.length() - 1] == 'f') {
      d = std::strtod(input.c_str(), 0);
      if (!std::isnan(d) && !std::isinf(d) && (d > FLT_MAX || d < FLT_MIN))
        return (0);
      return (2);
    }
    return (1);
  }
  return (0);
}

static bool int_limits(double d) {
  if (d > INT_MAX || d < INT_MIN)
    return true;
  return false;
}

static bool char_limits(int integer) {
  if (integer > UCHAR_MAX || integer < 0)
    return true;
  return false;
}

static bool float_limits(double d) {
  if (!std::isnan(d) && !std::isinf(d) && (d > FLT_MAX || d < -FLT_MAX))
    return true;
  return false;
}

static unsigned int count_dec(std::string const input) {
  int last_pos = input.length() - 1;

  if (input[last_pos] == 'f')
    return (last_pos - input.find('.') - 1);
  return (last_pos - input.find('.'));
}

// TODO: Handle int max, float max and double max
void ScalarConverter::convert(char *input) {
  char chr;
  int integer;
  float f;
  double d;
  short real_type;
  unsigned int num_dec = 1;

  real_type = real_num(input);
  if (real_type == 1) {
    d = std::strtod(input, 0);
    f = static_cast<float>(d);
    integer = int(d);
    chr = static_cast<char>(d);
    num_dec = count_dec(input);
  } else if (real_type == 2) {
    f = std::strtof(input, 0);
    d = static_cast<double>(f);
    integer = int(f);
    chr = static_cast<char>(f);
    num_dec = count_dec(input);
  } else if (is_char(input)) {
    chr = input[0];
    d = static_cast<double>(chr);
    f = static_cast<float>(chr);
    integer = int(chr);
  } else if (is_invalid(input)) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;

    return;
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
