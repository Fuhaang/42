/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:39:18 by amassey           #+#    #+#             */
/*   Updated: 2020/02/19 19:03:24 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] && !(s2[i])) || (!(s1[i]) && s2[i]))
		return (s1[i] - s2[i]);
	return (0);
}

void	ft_sort_params(int argc, char *argv[])
{
	char	*tempo;
	int		f;
	int		i;

	f = 1;
	while (f)
	{
		f = 0;
		i = 0;
		while (++i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tempo = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tempo;
				f = 1;
			}
		}
	}
	i = 0;
	while (++i < argc)
		ft_putstr(argv[i]);
}

int		main(int argc, char *argv[])
{
	ft_sort_params(argc, argv);
	return (0);
}
