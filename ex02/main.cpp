/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:15:52 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/30 15:57:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

int main(void) {
  Base *base;

  base = generate();

  std::cout << std::endl;
  identify(base);
  std::cout << std::endl;

  identify(*base);

  delete base;
}
