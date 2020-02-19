/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:04:48 by amassey           #+#    #+#             */
/*   Updated: 2020/02/17 16:10:30 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putnbr_base(int nbr, char *base)
{
	int size_base;
	int final_number[100];
	int i;

	i = 0;
	size_base = 0;
	if (ft_verif_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			final_number[i++] = nbr % size_base;
			nbr /= size_base;
		}
		while (--i >= 0)
			ft_putchar(base[final_number[i]]);
	}
}

int		main(void)
{
	ft_putnbr_base(12345, "0123456789ABCDEF");
	return (0);
}
