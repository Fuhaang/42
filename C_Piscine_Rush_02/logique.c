/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logique.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:11:53 by amassey           #+#    #+#             */
/*   Updated: 2020/02/22 15:57:59 by amassey          ###   ########.fr       */
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

// Avec uservalue = 356, chiffre = 3 et emplacement = 100
//  puis uservalue = 56, chiffre = 5 et emplacement = 10
//  puis uservalue = 6,  chiffre = 6 et emplacement = 1
int		ft_write_str(char ***dico, char *uservalue, int nb_key)
{
	int i;
	char *actvalue;
	char *chiffre;
	char *emplacement;
	int found;

	actvalue = (char*)malloc(sizeof(*actvalue) * 1);
	i = 0;
	found = 0;
	chiffre = "";
	emplacement = "";
	actvalue = uservalue;
	while (ft_len_value(actvalue) >= 1)
	{
		chiffre = actvalue / ft_power(10, ft_len_value(actvalue) - 1); 
		emplacement = ft_power(10, ft_len_value(actvalue) - 1);
		while (i < nb_key && !(found))
		{
			if(ft_same_str(dico[0][i], chiffre))
			{
				ft_putstr(dico[1][i]);
				found = 1;
			}
			i++;
		}
		i = 0;
		found = 0;
		while (i < nb_key && !(found))
		{
			if(ft_same_str(dico[0][i], emplacement))
			{
				ft_putstr(dico[1][i]);
				found = 1;
			}
			i++;
		}
		actvalue = actvalue % ft_power(10, ft_len_value(actvalue) - 1);
	}
}

char	*result_with_one_arg(char ***dico, char *uservalue, int nb_key)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < nb_key)
	{
		if(ft_same_str(dico[0][i], uservalue))
		{
			ft_putstr(dico[1][i]);
			return (0);			
		}
		i++;
	}
	if(ft_write_str(dico, uservalue, nb_key))
	{
		return (0);	
	}
	ft_putstr("Dict Error\n");
	return (0);
}
/*
char	*result_with_two_arg(char ***dico, char *uservalue)
{

}
*/

int		ft_result_final(int argc, char *argv[])
{
	char ***dico;
	char **key;
	char **value;
	char *res;

	key = (char**)malloc(sizeof(**key) * 1);
	value = (char**)malloc(sizeof(**value) * 1);
	dico = (char***)malloc(sizeof(***dico) * 2);
	res = (char*)malloc(sizeof(*res) * 1);
	key[0] = "10";
	value[0] = "dix";
	dico[0] = key;
	dico[1] = value;
	if(ft_error_arg(argc, argv))					//Fin du programme si argc/argv non valide
		return (0);
	if(argc == 2)
	{
		result_with_one_arg(dico, argv[1], 1);
		return (0);
	}
	/*
	if(argc == 3)
		result_with_two_arg(dico, argv[2]);			//Resultat final si deux args
	*/
	return (0);
}

int		main(int argc, char *argv[])
{
	ft_result_final(argc, argv);
	return (0);
}
