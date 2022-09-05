/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:13:26 by adubeau           #+#    #+#             */
/*   Updated: 2022/09/04 18:18:19 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

/*
void ft_get_texture(t_rays *self, t_texture *texture)
{
	char *dst =  mlx_get_data_addr(texture->img, &self->vars->bits_per_pixel, &self->vars->line_length, &self->vars->endian);
	int color;
	float a = self->wallH / texture->height;
	int y = 1;
	while (self->wallH--)
	{
		color = dst[(int)floor(y * texture->width + texture->count)];

		y = floor(y + a);
		my_mlx_pixel_put(self->vars, self->rayCount, ((WH / 2) - (self->tmp / 2)) + self->wallH, color );
		if (y > 0)
			printf("y = %d, count = %d, dst = %c\n", y, texture->count, color);
	}
	texture->count++;
	texture->count %= 64;
}*/

void	ft_print_walls(t_rays *self)
{
	int	i;

	i = 0;
	self->tmp = self->wallH;
	while (self->wallH--)
	{
		self->difx = (self->rayX - (int)(self->rayX + 0.1));
		self->dify = (self->rayY - (int)(self->rayY + 0.1));
		if (self->rayCount == WW / 2)
		{
			while (i < WH - 1)
			{
				my_mlx_pixel_put(self->vars, self->rayCount, i, \
				((255 << 16 | 186 << 8 | 252)));
				i++;
			}
		}
		if (fabs(self->difx) > fabs(self->dify) \
				&& self->rayY > self->vars->pos_y)
			my_mlx_pixel_put(self->vars, self->rayCount, \
				((WH / 2) - (self->tmp / 2)) + self->wallH, \
				(3 << 16 | 186 << 8 | 252));
		else if (fabs(self->difx) > fabs(self->dify))
			my_mlx_pixel_put(self->vars, self->rayCount, \
					((WH / 2) - (self->tmp / 2)) + self->wallH,
				(3 << 16 | 186 << 8 | 252) / 2);
		else if (fabs(self->difx) < fabs(self->dify) && \
			self->rayX > self->vars->pos_x)
			ry_mlx_pixel_put(self->vars, self->rayCount, \
					((WH / 2) - (self->tmp / 2)) + self->wallH, \
				(3 << 16 | 186 << 8 | 252) / 4);
		else
			my_mlx_pixel_put(self->vars, self->rayCount, \
					((WH / 2) - (self->tmp / 2)) + self->wallH, \
					(3 << 16 | 186 << 8 | 252) / 6);
	}
}
