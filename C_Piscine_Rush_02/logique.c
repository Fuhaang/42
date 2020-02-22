/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logique.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:11:53 by amassey           #+#    #+#             */
/*   Updated: 2020/02/22 14:16:14 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int		ft_atoi(char *argv)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while(argv[i])
		res = (res * 10) + argv[i++];
	return (res);
}

int		ft_error_arg(int argc, char *argv[])
{
	if(argc > 3 || argc == 1 ||(argc == 2 && ft_atoi(argv[1]) < 0)
			|| (argc == 3 && ft_atoi(argv[2]) < 0))
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int		ft_len_value(char *value)
{
	int len;

	len = 0;
	while(value[len])
		len++;
	return (len);
}

int		ft_same_len(char *dico, char *uservalue)
{
	int i;

	i = 0;
	while(dico[i])
	{
		if(ft_len_value(dico) == ft_len_value(uservalue))
			return (1);
		i++;
	}
	return (0);
}

int		ft_same_str(char *dico, char *uservalue)
{
	int i;

	i = 0;
	if(ft_same_len(dico, uservalue))
	{
		while(dico[i])
		{
			if(dico[i] != uservalue[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
/*
int		ft_power(int value, int power)
{
	int i;
	int res;

	i = 1;
	res = 1;
	while (i <= power)
	{
		res *= value;
		i++;
	}
	return (res);
}
*/
char	*result_with_one_arg(char ***dico, char *uservalue)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(dico[0][i])
	{
		if(ft_same_str(dico[0][i], uservalue))
			return (dico[1][i]);
		i++;
	}
	ft_putstr("Dict Error\n");
	return (0);
}
/*
char	*result_with_two_arg(char ***dico, char *uservalue)
{

}
*/
int		main(int argc, char *argv[])
{
	char ***dico;
	char **key;
	char **value;
	char *res;

	key = (char**)malloc(sizeof(**key) * 1);
	value = (char**)malloc(sizeof(**value) * 1);
	dico = (char***)malloc(sizeof(***dico) * 2);
	res = (char*)malloc(sizeof(*res) * 1);
	key[0] = "0";
	value[0] = "zero";
	dico[0] = key;
	dico[1] = value;

	if(ft_error_arg(argc, argv))					//Fin du programme si argc/argv non valide
		return (0);
	if(argc == 2)
	{
		res = result_with_one_arg(dico, argv[1]);
		if(!res)									//Resultat final si un seul arg
			return (0);
		ft_putstr(res);
	}/*
	if(argc == 3)
		result_with_two_arg(dico, argv[2]);		//Resultat final si deux args
	*/
	return (0);
}
