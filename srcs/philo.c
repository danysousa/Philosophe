/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 12:32:42 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/08 12:48:30 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <semaphore.h>
#include <time.h>
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

void	print_philo(t_data *data)
{
	static char		tb[3][6] = {"dors ", "pense", "mange"};

	ft_printf("Le philosophe %d %s avec %d PV ", data->n, tb[data->action], data->life);
	if (data->action == EAT)
		ft_printf(" | |\n");
	else if (data->action == THINK)
		ft_printf(" |\n");
	else
		ft_printf("\n");
}

static void		apply_change_pv(t_data *data, int i)
{
	if (data->action != EAT)
		data->life -= 1;
	print_philo(data);
	if (data->life < data->shared->warning_pv)
	{
		data->shared->warning_pv = data->life;
		data->shared->warning_nb = i;
	}
}

void	*change_pv(void *p_data)
{
	void			*tmp;
	int				i;
	int				start_time;

	start_time = time(NULL);
	while (time(NULL) < start_time + TIMEOUT)
	{
		sleep(1);
		tmp = p_data;
		((t_data *)tmp)->shared->warning_pv = MAX_LIFE;
		i = 0;
		ft_printf("\033[H\033[J");
		while (i < NB_PHIL)
		{
			apply_change_pv(((t_data *)tmp), i);
			tmp += sizeof(t_data);
			i++;
		}
		ft_printf("%d\n-----\n", start_time + TIMEOUT - time(NULL));
	}
	exit(0);
	return (NULL);
}

void	init_shared(t_shared *shared)
{
	int					i;

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

int		main()
{
	pthread_t	philosopher[NB_PHIL];
	pthread_t	pv;
	t_data		data[NB_PHIL];
	t_shared	shared;
	int		i;


	init_shared(&shared);
	for(i = 0; i < NB_PHIL; i++)
	{
		data[i].shared = &shared;
		data[i].life = MAX_LIFE;
		data[i].n = i;
		data[i].stick = -42;
		if (pthread_create(&philosopher[i],NULL, func, &data[i]) != 0)
		{
			ft_printf("\n Thread creation error \n");
			exit(1);
		}
	}
	pthread_create(&pv, NULL, change_pv, data);
	for(i = 0; i < NB_PHIL; i++)
	{
		if (pthread_join(philosopher[i], NULL) != 0)
		{
			ft_printf("\n Thread join failed \n");
			exit(1);
		}
	}
	pthread_join(pv, NULL);
	for(i = 0; i < NB_PHIL; i++)
	{
		if (pthread_mutex_destroy(&(data[i].shared->stick[i])) != 0)
		{
			ft_printf("\n Mutex Destroyed \n");
			exit(1);
		}
	}
	return (0);
}
