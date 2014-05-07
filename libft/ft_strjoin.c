/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:47:49 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	tmp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	ft_strcpy(tmp, s1);
	tmp[ft_strlen(s1)] = 0;
	ft_strcat(tmp, s2);
	tmp[ft_strlen(s1) + ft_strlen(s2)] = 0;
	return (tmp);
}
