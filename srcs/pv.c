/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 13:12:29 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/08 17:59:02 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <time.h>
#include "philo.h"

static void		print_philo(t_data *data)
{
	static char		tb[4][7] = {"dors ", "pense", "mange", "attend"};
	int				act;

	act = data->action;
	ft_printf("Le philosophe %d %s avec %d PV ", data->n, tb[act], data->life);
	if (data->action == EAT)
		ft_printf(" | |\n");
	else if (data->action == THINK)
		ft_printf(" |\n");
	else
		ft_printf("\n");
}

static void		apply_change_pv(t_data *data, int i)
{
	int			tmp;

	if (data->action != EAT)
		data->life -= 1;
	print_philo(data);
	tmp = data->life;
	if (tmp <= data->shared->warning_pv[0] && tmp <= data->shared->warning_pv[1]
		&& data->action != EAT)
	{
		data->shared->warning_pv[0] = data->life;
		data->shared->warning_nb[0] = i;
	}
	else if (tmp <= data->shared->warning_pv[1] && data->action != EAT)
	{
		data->shared->warning_pv[1] = data->life;
		data->shared->warning_nb[1] = i;
	}
}

void			*change_pv(void *p_data)
{
	void			*tmp;
	int				i;
	int				start_time;

	start_time = time(NULL);
	while (time(NULL) < start_time + TIMEOUT)
	{
		sleep(1);
		tmp = p_data;
		((t_data *)tmp)->shared->warning_pv[0] = MAX_LIFE;
		((t_data *)tmp)->shared->warning_pv[1] = MAX_LIFE;
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
