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
	self->wallH = 0;
	self->rayX = self->vars->pos_x;
	self->rayY = self->vars->pos_y;
	self->rayCos = cosf(degreetoradian(self->rayAngle)) / 4000;
	self->raySin = sinf(degreetoradian(self->rayAngle)) / 4000;
	self->wall = 0;
}

void	ft_hit_wall(t_rays *self)
{
	while (self->wall != '1')
	{
		self->rayX += self->rayCos;
		self->rayY += self->raySin;
		self->wall = self->vars->map[(int)floor(self->rayY)] \
			[(int)floor(self->rayX)];
	}
}

void	ft_calculate_distance(t_rays *self)
{
	self->distance = sqrt(pow(self->vars->pos_x - self->rayX, 2) + \
			pow(self->vars->pos_y - self->rayY, 2));
	self->distance = self->distance * \
			cosf(degreetoradian(self->rayAngle - \
			self->vars->playerAngle));
}

void	ft_calculate_wall_height(t_rays *self)
{
	self->wallH = (floor(self->halfH / self->distance));
}

void	ft_increment_angle(t_rays *self)
{
	self->rayAngle += self->incrementAngle;
}
