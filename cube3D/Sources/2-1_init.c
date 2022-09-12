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
	static t_vtable_rays	vtable;

	if (!vtable.init)
	{
		vtable.reset_values = &ft_reset_values;
		vtable.wall_collision = &ft_hit_wall;
		vtable.get_distance = &ft_calculate_distance;
		vtable.get_wall_height = &ft_calculate_wall_height;
		vtable.get_wall_h_l_pix = &ft_get_wall_h_l_pix;
		vtable.select_sprite = &ft_get_sprite;
		vtable.print = &ft_print_walls;
		vtable.increment_angle = &ft_increment_angle;
		vtable.init = 1;
	}
	return (&vtable);
}

void	ft_reset_values(t_vars *vars, t_ray *ray)
{
	ray->camera_x = 2 * ray->raycount / (double)WW - 1;
    ray->ray_dir_x = vars->dir_x + vars->plane_x * ray->camera_x;
    ray->ray_dir_y = vars->dir_y + vars->plane_y * ray->camera_x;
	ray->map_x = (int)vars->pos_x;
	ray->map_y = (int)vars->pos_y;
	ray->hit = 'x';
	
	
	
	self->distance = 0;
	self->wallH = 0;
	self->rayX = self->vars->pos_x;
	self->rayY = self->vars->pos_y;
	self->rayCos = cosf(degreetoradian(self->rayAngle)) / 4000;
	self->raySin = sinf(degreetoradian(self->rayAngle)) / 4000;
	self->wall = 0;
}
// t_rays	*get_raycaster(void)
// {
// 	static t_rays	self;

// 	if (self.init != 1)
// 	{
// 		self.operations = ft_init_vtable();
// 		self.halfH = (double) WH / 2;
// 		self.incrementAngle = (double) FOV / (double) WW;
// 		self.halfFOV = (double) FOV / 2;
// 		self.rayCount = 0;
// 		self.rayCos = 0;
// 		self.raySin = 0;
// 		self.wall = 0;
// 		self.distance = 0;
// 		self.wallH = 0;
// 		self.difx = 0;
// 		self.dify = 0;
// 		self.tmp = 0;
// 		self.texture = ft_t_img()->NO;
// 	}
// 	return (&self);
// }
