/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:58:08 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *str)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
				i++;
			size++;
		}
	}
	return (size);
}

char			**ft_strsplit_space(char *str)
{
	char	**tab;
	size_t	size;
	int		i;
	int		start;

	if ((size = ft_words(str)) == 0)
		return (NULL);
	if (!str || !(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t'))
			i++;
		else
		{
			start = i;
			while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
				i++;
			tab[size++] = ft_strsub(str, start, i - start);
		}
	}
	tab[size] = '\0';
	return (tab);
}
