/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:14:27 by amassey           #+#    #+#             */
/*   Updated: 2020/02/19 18:38:20 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_program_name(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
		write(1, &argv[i++], 1);
	write(1, "\n", 1);
}

int		main(int argc, char *argv[0])
{
	(void)argc;
	ft_print_program_name(argv[0]);
	return (0);
}
