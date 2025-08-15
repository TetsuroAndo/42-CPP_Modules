/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PutLogLv.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:36:36 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 15:42:38 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTLOGLV_HPP
#define PUTLOGLV_HPP

#include <iostream>
#include <iomanip>
#include <string>

#define LOG_LV_WIDTH 15

void putLogLevel(const std::string& text, int width);

#endif // PUTLOGLV_HPP