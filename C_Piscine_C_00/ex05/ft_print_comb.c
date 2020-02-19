/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:59:48 by amassey           #+#    #+#             */
/*   Updated: 2020/02/13 17:08:09 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_and_next(int first, int second, int third)
{
	write(1, &first, 1);
	write(1, &second, 1);
	write(1, &third, 1);
	write(1, ", ", 2);
}

void	ft_increment(int *first, int *second, int *third)
{
	if (*third == '9')
	{
		*third = '0';
		*second = *second + 1;
	}
	if (*second == '9')
	{
		*second = '0';
		*third = '0';
		*first = *first + 1;
	}
	*third = *third + 1;
}

void	ft_print_comb(void)
{
	int first;
	int second;
	int third;

	first = '0';
	second = '0';
	third = '0';
	while (first != '7' || second != '8' || third != '9')
	{
		while (second == first || third == second || third == first ||
			third < second || second < first)
		{
			ft_increment(&first, &second, &third);
		}
		if (first != '7' || second != '8' || third != '9')
		{
			ft_write_and_next(first, second, third);
			ft_increment(&first, &second, &third);
		}
	}
	write(1, &first, 1);
	write(1, &second, 1);
	write(1, &third, 1);
}
