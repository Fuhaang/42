/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:59:12 by amassey           #+#    #+#             */
/*   Updated: 2020/02/17 17:05:07 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_verif_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(base[0]) || !(base[1]))
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_size_base(char *base)
{
	int i;

	i = 0;
	if (ft_verif_base(base))
	{
		while (base[i])
			i++;
		return (i);
	}
	return (0);
}

int		convert_nb(char c, char *base)
{
	int i;

	i = 0;
	if (ft_verif_base(base))
	{
		while (base[i] && base[i] != c)
			i++;
		return (i);
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int sizebase;
	int finalnumber;
	int i;
	int isnegative;

	isnegative = 0;
	i = 0;
	finalnumber = 0;
	sizebase = ft_size_base(base);
	if (sizebase)
	{
		while (str[i] == ' ')
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
			{
				if (isnegative)
					isnegative = 0;
				else
					isnegative = 1;
			}
			i++;
		}
		while (str[i++] != ' ' && str[i] != '+' && str[i] != '-')
			finalnumber = (finalnumber * sizebase) + (convert_nb(str[i], base));
	}
	return (finalnumber);
}

int		main(void)
{
	char *str = "122";
	char *base = "0123456789";

	printf("%d",ft_atoi_base(str, base));
	return (0);
}
