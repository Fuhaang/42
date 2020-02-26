/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:27:51 by amassey           #+#    #+#             */
/*   Updated: 2020/02/26 13:57:11 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_allstrlen(int size, char **strs, char *sep)
{
	int		allsize;
	int		i;

	allsize = 0;
	i = 0;
	while (i < size)
	{
		allsize += ft_strlen(strs[i]);
		i++;
	}
	allsize = allsize + (size - 1) * ft_strlen(sep);
	return (allsize);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_allstrlen(size, strs, sep) + 1))))
		return (NULL);
	str[0] = '\0';
	if (size == 0)
		return (str);
	while (i < size - 1)
	{
		ft_strcat(str, strs[i]);
		ft_strcat(str, sep);
		i++;
	}
	ft_strcat(str, strs[i]);
	return (str);
}
