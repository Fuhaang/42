/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:50:31 by amassey           #+#    #+#             */
/*   Updated: 2020/02/20 16:12:53 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int min, int max)
{
	int size;
	int *tab;
	int i;

	i = 0;
	size = max - min;
	if (size <= 0)
		return (NULL);
	tab = (int*)malloc(sizeof(*tab) * (size + 1));
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int		main(void)
{
	int min;
	int max;
	int *tab;

	min = 1;
	max = 12;
	tab = ft_range(min, max);
	return (0);
}
