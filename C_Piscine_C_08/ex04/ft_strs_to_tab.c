/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:17:01 by amassey           #+#    #+#             */
/*   Updated: 2020/02/25 17:11:20 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char				*ft_strdup(char *src)
{
	char	*dest;
	int		src_len;
	int		i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (!(dest = (char *)malloc(sizeof(*dest) * (src_len + 1))))
		return (NULL);
	while (i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int					ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*s_av;
	int				i;

	if (!(s_av = (t_stock_str *)malloc(sizeof(*s_av) * (ac + 1))))
		return (0);
	i = 0;
	while (av[i] != 0 && i < ac)
	{
		s_av[i].size = ft_strlen(av[i]);
		s_av[i].str = av[i];
		s_av[i].copy = ft_strdup(av[i]);
		i++;
	}
	s_av[i].size = 0;
	s_av[i].str = 0;
	s_av[i].copy = 0;
	return (s_av);
}

#include <stdio.h>
int		main(void)
{
	int i = 0;
	char *av[] =
	{
		"Manger",
		"Jouer",
		"Dormir"
	};
	t_stock_str *s_av;
	s_av = ft_strs_to_tab(3, av);
	while (s_av[i].size)
	{
		printf("%deme index :\ns_av[%d].size = %d\ns_av[%d].str = %s\ns_av[%d].copy = %s\n\n\n", i, i, s_av[i].size, i, s_av[i].str, i, s_av[i].copy);
		i++;
	}
	return (0);
}
