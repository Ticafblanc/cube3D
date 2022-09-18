/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-1_utils.c                                        :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:32:47 by adubeau           #+#    #+#             */
/*   Updated: 2022/09/04 18:21:19 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	ft_reset_values(t_rays *self)
{
	self->distance = 0;
	self->wall_h = 0;
	self->ray_x = self->vars->pos_x;
	self->ray_y = self->vars->pos_y;
	self->ray_cos = cosf(degreetoradian(self->ray_angle)) / 4000;
	self->ray_sin = sinf(degreetoradian(self->ray_angle)) / 4000;
	self->wall = 0;
}

void	ft_hit_wall(t_rays *self)
{
	while (self->wall != '1')
	{
		self->ray_x += self->ray_cos;
		self->ray_y += self->ray_sin;
		self->wall = self->vars->map[(int)floor(self->ray_y)] \
			[(int)floor(self->ray_x)];
	}
}

void	ft_calculate_distance(t_rays *self)
{
	self->distance = sqrt(pow(self->vars->pos_x - self->ray_x, 2) + \
			pow(self->vars->pos_y - self->ray_y, 2));
	self->distance = self->distance * \
			cosf(degreetoradian(self->ray_angle - \
			self->vars->player_angle));
}

void	ft_calculate_wall_height(t_rays *self)
{
	self->wall_h = (floor(self->half_h / self->distance));
}

void	ft_increment_angle(t_rays *self)
{
	self->ray_angle += self->increment_angle;
}
