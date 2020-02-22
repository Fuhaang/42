/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logique.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:11:53 by amassey           #+#    #+#             */
/*   Updated: 2020/02/22 10:32:02 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *argv)
{
	int res;
	int isnegative;
	int i;

	i = 0;
	isnegative = 0;
	res = 0;
	while(argv[i])
		res = (res * 10) + argv[i];
	return (res);
}

char	*result_with_one_arg(int value)
{
	
}

char	*result_with_two_arg(char **dico, int value)
{

}

int		main(int argc, char *argv[])
{
	if (argc > 3 || argc == 1)
	{
		write(1, "Error\n", 6);
	}
	if(argc == 2)
	{
		result_with_one_arg(ft_atoi(argv[1]));
	}
	if(argc == 3)
	{

	}
}
