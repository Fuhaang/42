/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:25:51 by amassey           #+#    #+#             */
/*   Updated: 2020/02/13 17:09:20 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_and_next(int *firstunit, int *firstdizaine, int *secondunit,
		int *seconddizaine)
{
	while (*seconddizaine <= '9')
	{
		write(1, firstdizaine, 1);
		write(1, firstunit, 1);
		write(1, " ", 1);
		write(1, seconddizaine, 1);
		write(1, secondunit, 1);
		if (*firstdizaine != '9' || *firstunit != '8'
		|| *seconddizaine != '9' || *secondunit != '9')
			write(1, ", ", 2);
		*secondunit = *secondunit + 1;
		if (*secondunit > '9')
		{
			*secondunit = '0';
			*seconddizaine = *seconddizaine + 1;
		}
	}
	*firstunit = *firstunit + 1;
	if (*firstunit > '9')
	{
		*firstunit = '0';
		*firstdizaine = *firstdizaine + 1;
	}
	*secondunit = *firstunit + 1;
	*seconddizaine = *firstdizaine;
}

void	ft_print_comb2(void)
{
	int firstunit;
	int firstdizaine;
	int secondunit;
	int seconddizaine;

	firstunit = '0';
	firstdizaine = '0';
	secondunit = '1';
	seconddizaine = '0';
	while (firstunit <= '8' || firstdizaine <= '9')
	{
		if (firstdizaine != '9' || firstunit != '9'
		|| seconddizaine != '9' || secondunit <= '9')
		{
			ft_print_and_next(&firstunit, &firstdizaine, &secondunit,
			&seconddizaine);
		}
		else
		{
			firstunit = '9';
			firstdizaine = 58;
		}
	}
}
