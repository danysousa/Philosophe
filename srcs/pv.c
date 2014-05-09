/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 13:12:29 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/09 16:47:35 by rbenjami         ###   ########.fr       */
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

static void		display_philo(t_data *data)
{
	t_env			*e;
	static char		tb[6][7] = {"dors", "pense", "mange", "attend", "mort", "dance"};
	static char		name[7][8] = {"Roger", "Francis", "Auguste", "Marcus", "Bernard", "Bruce", "George"};

	e = data->shared->env;
	mlx_put_image_to_window(e->mlx, e->win, e->textures[data->action].img, 128 * data->n, 10);
	mlx_string_put(e->mlx, e->win, 128 * data->n, 150, 0xFFFFFF, name[data->n]);
	mlx_string_put(e->mlx, e->win, 128 * data->n, 170, 0xFFFFFF, "-PV: ");
	mlx_string_put(e->mlx, e->win, 40 + 128 * data->n, 170, 0xFFFFFF, ft_itoa(data->life));
	mlx_string_put(e->mlx, e->win, 128 * data->n, 185, 0xFFFFFF, "-Action: ");
	mlx_string_put(e->mlx, e->win, 60 + 128 * data->n, 185, 0xFFFFFF, tb[data->action]);
}

static void		clear_win(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
}

static void		apply_change_pv(t_data *data, int i)
{
	int			tmp;

	if (data->action != EAT)
		data->life -= 1;
	if (data->life <= 0)
	{
		data->shared->death = 1;
		data->action = 4;
	}
	print_philo(data);
	display_philo(data);
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
	while (time(NULL) < start_time + TIMEOUT && !((t_data *)p_data)->shared->death)
	{
		sleep(1);
		tmp = p_data;
		clear_win(((t_data *)tmp)->shared->env);
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
	if (!((t_data *)p_data)->shared->death)
		ft_printf("Now, it is time... To DAAAAAAAANCE !!!\n");
	tmp = p_data;
	i = 0;
	clear_win(((t_data *)tmp)->shared->env);
	destroy_stick(((t_data *)tmp)->shared->stick);
	while (i < NB_PHIL)
	{
		if (!((t_data *)p_data)->shared->death)
			((t_data *)tmp)->action = 5;
		print_philo((t_data *)tmp);
		display_philo((t_data *)tmp);
		tmp += sizeof(t_data);
		i++;
	}

	mlx_loop(((t_data *)p_data)->shared->env->mlx);
	exit(0);
	return (NULL);
}
