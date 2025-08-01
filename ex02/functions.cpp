/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:08:48 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/31 15:49:11 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

Base *generate(void) {
  Base *base;
  int random;

  std::srand(time(0));
  random = std::rand() % 100 + 1;
  if (random % 2 == 0) {
    base = new A();
    std::cout << RED << "Object type A created" << END << std::endl;
  } else if (random % 3 == 0) {
    base = new C();
    std::cout << RED << "Object type C created" << END << std::endl;
  } else {
    base = new B();
    std::cout << RED << "Object type B created" << END << std::endl;
  }

  return (base);
}

void identify(Base *p) {
  try {
    A *a;
    B *b;
    C *c;

    a = dynamic_cast<A *>(p);
    b = dynamic_cast<B *>(p);
    c = dynamic_cast<C *>(p);
    if (a)
      std::cout << YELLOW << "Object type A" << END << std::endl;
    else if (b)
      std::cout << YELLOW << "Object type B" << END << std::endl;
    else if (c)
      std::cout << YELLOW << "Object type C" << END << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

void identify(Base &p) {
  A a;
  B b;
  C c;

  try {
    a = dynamic_cast<A &>(p);
    std::cout << YELLOW << "Object type A" << END << std::endl;
  } catch (...) {
  }
  try {
    b = dynamic_cast<B &>(p);
    std::cout << YELLOW << "Object type B" << END << std::endl;
  } catch (...) {
  }
  try {
    c = dynamic_cast<C &>(p);
    std::cout << YELLOW << "Object type C" << END << std::endl;
  } catch (...) {
  }
}
