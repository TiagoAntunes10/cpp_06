/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:25:29 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/29 15:32:48 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/includes.hpp"

Data::Data(void) {
  _some_data = 10;
  _other_format = "some string";
}

Data::Data(Data const &data) {
  _some_data = data.getSomeData();
  _other_format = data.getOtherFormat();
}

Data &Data::operator=(Data const &data) {
  _some_data = data.getSomeData();
  _other_format = data.getOtherFormat();

  return (*this);
}

Data::~Data(void) {}

int Data::getSomeData(void) const { return (_some_data); }

std::string Data::getOtherFormat(void) const { return (_other_format); }
