/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logique.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:11:53 by amassey           #+#    #+#             */
/*   Updated: 2020/02/22 13:02:39 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_error_arg(int argc, char *argv[])
{
	if(argc > 3 || argc == 1 ||(argc == 2 && ft_atoi(argv[1]) < 0)
			|| (argc == 3 && ft_atoi(argv[2]) < 0))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int		ft_atoi(char *argv)
{
	int res;
	int isnegative;
	int i;

	i = 0;
	isnegative = 0;
	res = 0;
	while(argv[i])
		res = (res * 10) + argv[i++];
	return (res);
}


int		ft_len_value(char *value)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while(value[i])
		len++;
	return (len);
}

int		ft_same_len(char *dico, char *value)
{
	if(ft_len_value(dico) == ft_len_value(value))
		return (1);
	return (0);
}

int		ft_same_str(char *dico, char *value)
{
	int i;

	i = 0;
	if(ft_same_len(dico, value))
	{
		while(dico[i])
		{
			if(dico[i] != value[i])
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
char	*result_with_one_arg(char **dico, char *value)
{
	int i;

	i = 0;
	while(dico[0][i])
	{
		if(ft_same_str(dico[0][i], value))
			return (dico[1][i]);
		i++;
	}
}

char	*result_with_two_arg(char **dico, char *value)
{

}

int		main(int argc, char *argv[])
{
	char ***dico;
	char **key;
	char **value;

	key[0][0] = "0";
	value[0][0] = "zero";
	dico[0] = key;
	dico[1] = value;

	if(ft_error_arg(argc, argv))							//Fin du programme si argc/argv non valide
		return (0);
	if(argc == 2)
		result_with_one_arg(dico, argv[1]);		//Resultat final si un seul arg
	if(argc == 3)
	{
		result_with_two_arg(argv[1], argv[2]);		//Resultat final si deux args
	}
	return (0);
}
