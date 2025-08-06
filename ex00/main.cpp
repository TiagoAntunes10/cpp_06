/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:32:11 by tialbert          #+#    #+#             */
/*   Updated: 2025/08/01 22:44:30 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Error: Wrong number of arguments" << std::endl;
    return (1);
  }
  ScalarConverter::convert(argv[1]);
}
