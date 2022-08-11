/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:13:26 by adubeau           #+#    #+#             */
/*   Updated: 2022/08/10 21:13:29 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

t_rays *ft_raycasting_init(t_vars *vars)
{
	t_rays *raycasting;

	raycasting = malloc(sizeof(t_rays));
	raycasting->operations = ft_init_vtable();
	raycasting->posx = 0;
	raycasting->posy = 0;
	raycasting->dirx = 0;
	raycasting->diry = 0;
	raycasting->planx = 0;
	raycasting->plany = 0;
	raycasting->hit = 0;
	raycasting->perpwalldist = 0;
	if (vars->pos == 'N')
	{
		raycasting->dirx = -1;
		raycasting->plany = 0.66;
	}
	if (vars->pos == 'S')
	{
		raycasting->dirx = 1;
		raycasting->plany = -0.66;
	}
	if (vars->pos == 'E')
	{
		raycasting->diry = 1;
		raycasting->planx = 0.66;
	}
	if (vars->pos == 'W')
	{
		raycasting->diry = -1;
		raycasting->planx = -0.66;
	}
	if (raycasting->raydirx == 0)
		raycasting->deltadisty = 1;
	else if (raycasting->raydiry == 0)
		raycasting->deltadistx = 0;
	else
		raycasting->deltadistx = sqrt(1 + raycasting->raydiry * raycasting->raydiry)
				/ (raycasting->raydirx * raycasting->raydirx);
	return (raycasting);
}

t_vtable_rays *ft_init_vtable(void)
{
	t_vtable_rays *operations = malloc(sizeof(t_vtable_rays));

	return (operations);

}
