/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:33:11 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/28 23:09:14 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

static bool is_char(std::string const input) {
  if (input.length() == 1 && !std::isdigit(input[0]))
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
  if (input.find('.') != std::string::npos || is_pseudo(input)) {
    if (input[input.length() - 1] == 'f')
      return (2);
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

void ScalarConverter::convert(char *input) {
  char chr;
  int integer;
  float f;
  double d;
  short real_type;
  unsigned int num_dec = 1;

  real_type = real_num(input);
  if (real_type == 1) {
    d = double(atof(input));
    f = float(d);
    integer = int(d);
    chr = (unsigned char)d;
    num_dec = count_dec(input);
  } else if (real_type == 2) {
    f = float(atof(input));
    d = double(f);
    integer = int(f);
    chr = (unsigned char)f;
    num_dec = count_dec(input);
  } else if (is_char(input)) {
    chr = (unsigned char)input[0];
    d = (double)chr;
    f = float(chr);
    integer = int(chr);
  } else {
    integer = int(std::atoi(input));
    d = double(integer);
    f = float(integer);
    chr = (unsigned char)integer;
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
