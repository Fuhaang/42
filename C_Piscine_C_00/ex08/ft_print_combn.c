/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:36:25 by amassey           #+#    #+#             */
/*   Updated: 2020/02/13 17:11:05 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	int thisnumber;

	thisnumber = '0';
	if (n > 1)
	{
		ft_print_combn(n - 1);
	}
	while (thisnumber < n - 1 + '0')
		thisnumber++;
	write(1, &thisnumber, 1);
	write(1, ", ", 2);
}
