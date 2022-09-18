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

void	free_table(t_rays *self)
{
	free(self->operations);
}

t_vtable_rays	*ft_init_vtable(void)
{
	static t_vtable_rays	vtable;

	vtable.reset_values = &ft_reset_values;
	vtable.wall_collision = &ft_hit_wall;
	vtable.get_distance = &ft_calculate_distance;
	vtable.get_wall_height = &ft_calculate_wall_height;
	vtable.select_sprite = &ft_get_sprite;
	vtable.print = &ft_print_walls;
	vtable.increment_angle = &ft_increment_angle;
	vtable.free = &free_table;
	return (&vtable);
}

t_rays	*get_raycaster(void)
{
	static t_rays	self;

	self.ray_count = 0;
	self.ray_cos = 0;
	self.ray_sin = 0;
	self.wall = 0;
	self.distance = 0;
	self.wall_h = 0;
	self.difx = 0;
	self.dify = 0;
	self.tmp = 0;
	if (!self.init)
	{
		self.operations = ft_init_vtable();
		self.half_h = (double) WH / 2;
		self.increment_angle = (double) FOV / (double) WW;
		self.half_fov = (double) FOV / 2;
		self.init = 1;
		self.texture = ft_t_img()->no;
	}
	return (&self);
}
