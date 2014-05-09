/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 13:37:47 by rbenjami          #+#    #+#             */
/*   Updated: 2014/05/09 14:14:12 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "philo.h"

void	add_texture(t_env *env, char *tex_path)
{
	static int	i = 0;
	int			size;
	void		*img;

	if (i > 6)
		error("error can't load wall texture: %s", tex_path);
	if (!(img = mlx_xpm_file_to_image(env->mlx, tex_path, &size, &size)))
		return ;
	env->textures[i].img = img;
	i++;
}
