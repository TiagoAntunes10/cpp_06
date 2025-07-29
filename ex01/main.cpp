/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:43:02 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/29 21:49:49 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

int main(void) {
  Data *data = new Data();
  Serializer s;
  uintptr_t i;
  Data *cpy;

  std::cout << GREEN << "Before serialization" << END << std::endl;
  std::cout << BLUE << "Pointer: " << END << data << std::endl;
  std::cout << BLUE << " Data 1: " << END << data->getSomeData() << std::endl;
  std::cout << BLUE << " Data 2: " << END << data->getOtherFormat()
            << std::endl;
  std::cout << std::endl;

  i = s.serialize(data);
  cpy = s.deserialize(i);

  std::cout << GREEN << "After serialization" << END << std::endl;
  std::cout << BLUE << "Pointer: " << END << cpy << std::endl;
  std::cout << BLUE << " Copy 1: " << END << cpy->getSomeData() << std::endl;
  std::cout << BLUE << " Copy 2: " << END << cpy->getOtherFormat() << std::endl;

  delete data;
}
