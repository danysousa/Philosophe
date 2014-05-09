/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 13:22:22 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/09 16:34:20 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "philo.h"

void	create_phil(pthread_t phil[], t_shared *shared, t_data data[])
{
	int		i;

	i = 0;
	while (i < NB_PHIL)
	{
		data[i].shared = shared;
		data[i].life = MAX_LIFE;
		data[i].n = i;
		data[i].stick = -42;
		data[i].action = -42;
		if (pthread_create(&phil[i], NULL, func, &data[i]) != 0)
		{
			ft_printf("\n Thread creation failed \n");
			exit(1);
		}
		i++;
	}
}

void	join_phil(pthread_t phil[])
{
	int		i;

	i = 0;
	while (i < NB_PHIL)
	{
		if (pthread_join(phil[i], NULL) != 0)
		{
			ft_printf("\n Thread join failed \n");
			exit(1);
		}
		i++;
	}
}

void	destroy_stick(pthread_mutex_t stick[])
{
	int		i;

	i = 0;
	while (i < NB_PHIL)
	{
		pthread_mutex_unlock(&(stick[i]));
		if (pthread_mutex_destroy(&(stick[i])) != 0)
		{
			ft_printf("\n Mutex Destroyed \n");
			exit(1);
		}
		i++;
	}
}
