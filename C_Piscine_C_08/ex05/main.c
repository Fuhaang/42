/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:01:22 by amassey           #+#    #+#             */
/*   Updated: 2020/02/25 17:15:44 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char				*ft_strdup(char *src);
int					ft_strlen(char *str);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_show_tab(struct s_stock_str *par);

int		main(void)
{
	char *av[] =
	{
		"Jouer",
		"Manger",
		"Dormir"
	};

	ft_show_tab(ft_strs_to_tab(3, av));
	return (0);
}
