/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-1_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:37:44 by adubeau           #+#    #+#             */
/*   Updated: 2022/09/04 18:19:36 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

t_vtable_rays	*ft_init_vtable(void)
{
	t_vtable_rays	*vtable;

	vtable = malloc(sizeof(t_vtable_rays));
	vtable->reset_values = &ft_reset_values;
	vtable->wall_collision = &ft_hit_wall;
	vtable->get_distance = &ft_calculate_distance;
	vtable->get_wall_height = &ft_calculate_wall_height;
	vtable->select_sprite = &ft_get_sprite;
	vtable->print = &ft_print_walls;
	vtable->increment_angle = &ft_increment_angle;
	return (vtable);
}

t_rays	*get_raycaster(void)
{
	static t_rays	self;

	if (self.init != 1)
	{
		self.operations = ft_init_vtable();
		self.halfH = (double) WH / 2;
		self.incrementAngle = (double) FOV / (double) WW;
		self.halfFOV = (double) FOV / 2;
		self.rayCount = 0;
		self.rayCos = 0;
		self.raySin = 0;
		self.wall = 0;
		self.distance = 0;
		self.wallH = 0;
		self.difx = 0;
		self.dify = 0;
		self.tmp = 0;
		self.texture = ft_t_img()->NO;
	}
	return (&self);
}
