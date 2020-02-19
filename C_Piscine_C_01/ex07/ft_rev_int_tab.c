/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:41:52 by amassey           #+#    #+#             */
/*   Updated: 2020/02/13 16:05:12 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int thisswap;
	int tempo;

	thisswap = 0;
	while (thisswap <= size / 2)
	{
		tempo = tab[thisswap];
		tab[thisswap] = tab[size - thisswap - 1];
		tab[size - thisswap - 1] = tempo;
		thisswap++;
	}
}
