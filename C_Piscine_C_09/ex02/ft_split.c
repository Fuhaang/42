/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:35:01 by ccai              #+#    #+#             */
/*   Updated: 2020/02/26 18:17:43 by ccai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_find_word(char *str, char *charset)
{
	int i;
	int mots;

	i = 0;
	if (!str[i])
		return (0);
	mots = 1;
	while (str[i + 1] != '\0')
	{
		if (i == 0)
			i++;
		if (i != 0 && ft_is_charset(str[i], charset)
				&& !ft_is_charset(str[i + 1], charset))
			mots++;
		i++;
	}
	return (mots);
}

char	*ft_rmpl(char *str, int size_word, int i)
{
	int		x;
	char	*res;

	x = 0;
	res = malloc(sizeof(char) * (size_word + 1));
	while (x < size_word)
	{
		res[x] = str[i];
		x++;
		i++;
	}
	res[x] = '\0';
	return (res);
}

int		ft_split2(char *str, char *charset, char **tab)
{
	int		i;
	int		y;
	int		size_word;

	i = 0;
	y = 0;
	while (str[i] != '\0')
	{
		size_word = 0;
		while (!ft_is_charset(str[i], charset) && str[i] != '\0')
		{
			size_word++;
			i++;
		}
		if (size_word != 0)
		{
			if (!(tab[y] = malloc(sizeof(char) * (size_word + 1))))
				return (0);
			tab[y] = ft_rmpl(str, size_word, i - size_word);
			y++;
		}
		i++;
	}
	tab[y] = 0;
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;

	if (!str[0])
		return (0);
	if (!(tab = malloc(sizeof(char *) * (ft_find_word(str, charset) + 1))))
		return (NULL);
	ft_split2(str, charset, tab);
	return (tab);
}
