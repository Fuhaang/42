/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:34:26 by amassey           #+#    #+#             */
/*   Updated: 2020/02/19 17:38:19 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(int argc, char *argv[])
{
	int i;
	int j;

	i = argc - 1;
	j = 0;
	while (i > 0)
	{
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i--;
		j = 0;
	}
}

int		main(int argc, char *argv[])
{
	ft_rev_params(argc, argv);
	return (0);
}
