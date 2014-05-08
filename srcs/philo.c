/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 12:32:42 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/08 14:18:09 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "philo.h"

void	*func(void *p_data)
{
	static void		(*tb_fct[3])(t_data *) = {&rest, &think, &eat};
	t_data			*data;

	data = p_data;
	tb_fct[choose_action(data)](data);
	return (NULL);
}

void	init_shared(t_shared *shared)
{
	int		i;

	i = 0;
	shared->warning_pv = MAX_LIFE;
	shared->warning_nb = 1;
	while (i < NB_PHIL)
	{
		if (pthread_mutex_init(&(shared->stick[i]), NULL) == -1)
		{
			ft_printf("\n Mutex initialization failed");
			exit(1);
		}
		i++;
	}
}

int		main(void)
{
	pthread_t	philosopher[NB_PHIL];
	pthread_t	pv;
	t_data		data[NB_PHIL];
	t_shared	shared;

	init_shared(&shared);
	create_phil(philosopher, &shared, data);
	pthread_create(&pv, NULL, change_pv, data);
	join_phil(philosopher);
	pthread_join(pv, NULL);
	destroy_stick(data);
	return (0);
}
