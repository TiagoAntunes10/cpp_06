/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:20:21 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/29 15:32:41 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
public:
  Data(void);
  Data(Data const &data);
  Data &operator=(Data const &data);
  ~Data(void);
  int getSomeData(void) const;
  std::string getOtherFormat(void) const;

private:
  int _some_data;
  std::string _other_format;
};

#endif
