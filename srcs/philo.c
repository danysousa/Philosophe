/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 12:32:42 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/08 12:01:06 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <libft.h>
#include "philo.h"

pthread_mutex_t chopstick[NB_PHIL];
static void		(*tb_fct[3])(t_data *) = {&rest, &think, &eat};


void	eat(t_data *data)
{
	data->action = EAT;
	sleep(EAT_T);
	data->life = MAX_LIFE;
	pthread_mutex_unlock(&chopstick[data->n]);
	pthread_mutex_unlock(&chopstick[(data->n + 1) % NB_PHIL]);
	tb_fct[choose_action(data)](data);
}

void	think(t_data *data)
{
	data->action = THINK;
	sleep(THINK_T);
	pthread_mutex_unlock(&chopstick[data->stick]);
	tb_fct[choose_action(data)](data);
}

void	rest(t_data *data)
{
	data->action = REST;
	sleep(REST_T);
	tb_fct[choose_action(data)](data);
}

int		choose_action(t_data *data)
{
	int		nb_action;
	int		prev;
	int		next;

	prev = data->shared->warning_nb - 1 == (-1) ? 6 : data->shared->warning_nb - 1;
	next = (data->shared->warning_nb + 1) % 7;
	nb_action = REST;
	if (data->n == next || data->n == prev)
	{
		data->action = REST;
		return (REST);
	}
	if (pthread_mutex_trylock(&chopstick[data->n]) != IS_BUSY)
	{
		nb_action++;
		data->stick = data->n;
	}
	if (data->action == EAT)
		return (nb_action);
	if (pthread_mutex_trylock(&chopstick[(data->n + 1) % NB_PHIL]) != IS_BUSY)
	{
		nb_action++;
		data->stick = (data->n + 1) % NB_PHIL;
	}
	data->action = nb_action;
	return (nb_action);
}

void	*func(void *p_data)
{
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
			if (((t_data *)tmp)->action != EAT)
				((t_data *)tmp)->life -= 1;
			print_philo((t_data *)tmp);
			if (((t_data *)tmp)->life < ((t_data *)tmp)->shared->warning_pv)
			{
				((t_data *)tmp)->shared->warning_pv = ((t_data *)tmp)->life;
				((t_data *)tmp)->shared->warning_nb = i;
			}
			tmp += sizeof(t_data);
			i++;
		}
		ft_printf("%d\n", start_time + TIMEOUT - time(NULL));
		ft_printf("-----\n");
	}
	exit(0);
	return (NULL);
}

int		main()
{
	pthread_t	philosopher[NB_PHIL];
	pthread_t	pv;
	t_data		data[NB_PHIL];
	t_shared	shared;
	int		i;
	int		k;

	shared.warning_pv = MAX_LIFE;
	shared.warning_nb = 1;
	for(i = 0; i < NB_PHIL; i++)
	{
		k=pthread_mutex_init(&chopstick[i],NULL);
		if(k==-1)
		{
			ft_printf("\n Mutex initialization failed");
			exit(1);
		}
	}
	for(i = 0; i < NB_PHIL; i++)
	{
		data[i].shared = &shared;
		data[i].life = MAX_LIFE;
		data[i].n = i;
		data[i].stick = -42;
		k = pthread_create(&philosopher[i],NULL, func, &data[i]);
		if(k!=0)
		{
			ft_printf("\n Thread creation error \n");
			exit(1);
		}
	}
	pthread_create(&pv, NULL, change_pv, data);
	for(i = 0; i < NB_PHIL; i++)
	{
		k=pthread_join(philosopher[i], NULL);
		if(k!=0)
		{
			ft_printf("\n Thread join failed \n");
			exit(1);
		}
	}
	pthread_join(pv, NULL);
	for(i = 0; i < NB_PHIL; i++)
	{
		k=pthread_mutex_destroy(&chopstick[i]);
		if(k!=0)
		{
			ft_printf("\n Mutex Destroyed \n");
			exit(1);
		}
	}
	return 0;
}
