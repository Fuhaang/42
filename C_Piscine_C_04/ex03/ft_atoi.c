/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:11:20 by amassey           #+#    #+#             */
/*   Updated: 2020/02/18 13:18:13 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(char *str)
{
	int gonospace;
	int isnegative;
	int number;

	gonospace = 0;
	isnegative = 0;
	number = 0;
	while (str[gonospace] && (str[gonospace] == ' '
		|| str[gonospace] == '\t' || str[gonospace] == '\n'
		|| str[gonospace] == '\v' || str[gonospace] == '\f'
		|| str[gonospace] == '\r'))
		gonospace++;
	while (str[gonospace] && (str[gonospace] == '-' || str[gonospace] == '+'))
	{
		if (str[gonospace] == '-')
			isnegative++;
		gonospace++;
	}
	while (str[gonospace] && str[gonospace] >= '0' && str[gonospace] <= '9')
		number = (number * 10) + (str[gonospace++] - 48);
	if (isnegative % 2)
		number *= -1;
	return (number);
}
