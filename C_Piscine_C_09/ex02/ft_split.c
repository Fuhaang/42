/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:58:31 by amassey           #+#    #+#             */
/*   Updated: 2020/02/26 20:41:47 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_beginning_word(char c, char before_c, char *charset)
{
	if (!(ft_is_sep(c, charset)) && ft_is_sep(before_c, charset))
	{
		return (1);
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int nb_words;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		if(ft_beginning_word(str[i], str[i - 1], charset)
				|| (!(ft_is_sep(str[i], charset)) && i == 0))
			nb_words++;
		i++;
	}
	return (nb_words);
}

int		ft_size_of_word(char *str, char *charset)
{
	int index;
	int i;
	int count_words;
	int *size_words;

	i = 0;
	index = 0;
	count_words = ft_count_words(str, charset);
	size_words = (int *)malloc(sizeof(size_words) * count_words);
	while (i <= count_words)
	{
		size_words[i] = 0;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (!(ft_is_sep(str[i], charset)))
			size_words[index] += 1;
		else if (i > 0 && !(ft_is_sep(str[i - 1], charset)))
			index++;
		i++;
	}
	return (size_words);
}

char	**ft_split(char *str, char *charset)
{
	char **words;
	int i;
	int j;
	int index;
	int *size_words;

	words = malloc(sizeof(char*) * (ft_count_words(str, charset) + 1));
	size_words = ft_count_words(str, charset);
	index = 0;
	j = 0;
	i = -1;
	while (str[++i])
	{
		if (!(ft_is_sep(str[i], charset)))
		{
			if (i == 0 || ft_beginning_word(str[i], str[i - 1], charset))
				words[index] = malloc(sizeof(char) * size_words[index]);
			words[index][j] = str[i];
			j++;
			words[index][j] = '\0';
		}
		else if (i > 0 && !(ft_is_sep(str[i - 1], charset)) && ++index)
			j = 0;
	}
	words[ft_count_words(str, charset)] = 0;
	return (words);
}
