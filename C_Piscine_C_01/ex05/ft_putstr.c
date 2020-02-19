/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:03:05 by amassey           #+#    #+#             */
/*   Updated: 2020/02/13 15:22:31 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
	{
		write(1, &str[cpt], 1);
		cpt++;
	}
}
