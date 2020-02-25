/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:27:51 by amassey           #+#    #+#             */
/*   Updated: 2020/02/25 13:19:21 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*finalconcat;

	allsize = 0;
	i = 0;
	while (i < size)
		allsize += ft_strlen(strs[i++]);
	return (allsize);
}

char	*ft_concat(int size, char **strs, char *sep, char *finalconcat)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			finalconcat[k++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] && i < size - 1)
			finalconcat[k++] = sep[j++];
		j = 0;
		i++;
	}
	finalconcat[i] = '\0';
	return (finalconcat);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*finalconcat;
	int		i;
	int		j;
	int		k;
	int		allsize;

	i = 0;
	j = 0;
	k = 0;
	if (!(allsize = ft_allstrlen(size, strs, sep)))
		return (NULL);
	if (!(finalconcat = (char*)malloc((sizeof(*finalconcat) * allsize)
				+ sizeof(*sep) * (size - 1))))
		return (NULL);
	finalconcat = ft_concat(size, strs, sep, finalconcat);
	return (finalconcat);
}
