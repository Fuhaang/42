/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:20:21 by amassey           #+#    #+#             */
/*   Updated: 2020/02/20 13:49:55 by amassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	copy = malloc(sizeof(*copy) * (len + 1));
	while (i < len)
		copy[i] = src[i++];
	return (copy);
}
