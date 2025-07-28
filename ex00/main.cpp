/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:32:11 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/22 18:06:13 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

int main(int argc, char **argv) {
  ScalarConverter scalar;

  if (argc != 2)
    std::cout << "Error: Wrong number of arguments" << std::endl;
  scalar.convert(argv[1]);
}
