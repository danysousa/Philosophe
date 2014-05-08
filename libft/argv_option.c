/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 16:36:40 by rbenjami          #+#    #+#             */
/*   Updated: 2014/04/28 17:32:20 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		argv_option(const char *argv[], char option)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '-')
			break ;
		if (ft_strchr(argv[i], option) != 0)
			return (1);
		i++;
	}
	return (0);
}
