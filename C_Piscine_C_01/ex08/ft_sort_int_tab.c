/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:07:28 by amassey           #+#    #+#             */
/*   Updated: 2020/02/13 16:56:09 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int tempo;

	tempo = 0;
	i = 0;
	j = 0;
	while (i <= size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tempo = tab[i];
				tab[i] = tab[j];
				tab[j] = tempo;
			}
			j++;
		}
		i++;
	}
}
