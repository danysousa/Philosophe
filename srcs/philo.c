/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 12:32:42 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/09 16:49:31 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <semaphore.h>
#include <libft.h>
#include "philo.h"

void			*func(void *p_data)
{
	static void		(*tb_fct[3])(t_data *) = {&rest, &think, &eat};
	t_data			*data;

	data = p_data;
	tb_fct[choose_action(data)](data);
	return (NULL);
}

void			init_shared(t_shared *shared, t_env *env)
{
	int		i;

	i = 0;
	shared->warning_pv[0] = MAX_LIFE;
	shared->warning_nb[0] = 1;
	shared->death = 0;
	shared->env = env;
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

static void		textures_handler(t_env *env)
{
	add_texture(env, "textures/sleep.xpm");
	add_texture(env, "textures/think.xpm");
	add_texture(env, "textures/eat.xpm");
	add_texture(env, "textures/wait.xpm");
	add_texture(env, "textures/death.xpm");
	add_texture(env, "textures/dance.xpm");
}

int				key_hook(int key, t_env *env)
{
	(void)env;
	if (key == 65307)
		exit(0);
	return (0);
}

int				main(void)
{
	t_env		env;
	pthread_t	philosopher[NB_PHIL];
	pthread_t	pv;
	t_data		data[NB_PHIL];
	t_shared	shared;

	if ((env.mlx = mlx_init()) == NULL)
		return (error("mlx init error: "));
	if ((env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, "Philo")) == NULL)
		return (error("window error: "));
	init_shared(&shared, &env);
	textures_handler(&env);
	mlx_key_hook(env.win, key_hook, &env);
	create_phil(philosopher, &shared, data);
	pthread_create(&pv, NULL, change_pv, data);
	join_phil(philosopher);
	pthread_join(pv, NULL);
	return (0);
}
