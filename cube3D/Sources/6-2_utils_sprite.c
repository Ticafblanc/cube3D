/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* 	 6-2_utils_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:13:26 by adubeau           #+#    #+#             */
/*   Updated: 2022/09/04 18:18:19 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static t_texture *ft_reset_sprite(t_rays *self, t_texture *txt)
{
	txt->pix_x+= self->rayCount / self->wallH;
	if (txt->pix_x > 64)
		txt->pix_x = self->rayCount / self->wallH;
	txt->pix_y = 0 ;
	return (txt);
}

t_texture *ft_get_sprite(t_rays *self)
{
	if ( self->vars->pos >=  0 && self->vars->pos <= 89)
		if (ft_t_vars()->map[(int)self->rayY + 1][(int)self->rayX] &&
			ft_t_vars()->map[(int)self->rayY + 1][(int)self->rayX] != '1')
			return (ft_reset_sprite(self, ft_t_img()->NO));
		else
			return (ft_reset_sprite(self, ft_t_img()->EA));
	else if ( self->vars->pos >=  90 && self->vars->pos <= 179)
		if (ft_t_vars()->map[(int)self->rayY - 1][(int)self->rayX] &&
			ft_t_vars()->map[(int)self->rayY - 1][(int)self->rayX] != '1')
			return (ft_reset_sprite(self, ft_t_img()->SO));
		else
			return (ft_reset_sprite(self, ft_t_img()->EA));
	else if ( self->vars->pos >=  180 && self->vars->pos <= 269)
		if (ft_t_vars()->map[(int)self->rayY - 1][(int)self->rayX] &&
			ft_t_vars()->map[(int)self->rayY - 1][(int)self->rayX] != '1')
			return (ft_reset_sprite(self, ft_t_img()->SO));
		else
			return (ft_reset_sprite(self, ft_t_img()->WE));
	else
		if (ft_t_vars()->map[(int)self->rayY + 1][(int)self->rayX] &&
			ft_t_vars()->map[(int)self->rayY + 1][(int)self->rayX] != '1')
			return (ft_reset_sprite(self, ft_t_img()->NO));
		else
			return (ft_reset_sprite(self, ft_t_img()->WE));
}


static int	ft_get_texture(t_texture *texture, t_rays *self)
{
	texture->pix_y += texture->width / self->tmp;
	if (texture->pix_y > 64)
		texture->pix_y += texture->width / self->tmp ;
	return (texture->addr[((int)texture->pix_y * texture->line_length)
		+ ((int)texture->pix_x * (texture->bits_per_pixel / 8))]);
}

void	ft_print_walls(t_rays *self, t_texture *texture)
{
	int	color;

	self->tmp = self->wallH;
	while (self->wallH--)
	{
		color = ft_get_texture(texture, self);
		if (color)
			my_mlx_pixel_put(self->vars, self->rayCount,
				((WH / 2) - (self->tmp / 2)) + self->wallH, 
				color);
	}
}



// 		self->difx = (self->rayX - (int)(self->rayX + 0.1));
// 		self->dify = (self->rayY - (int)(self->rayY + 0.1));
		
// 		if (fabs(self->difx) > fabs(self->dify) \
// 				&& self->rayY > self->vars->pos_y)
// 			my_mlx_pixel_put(self->vars, self->rayCount, \
// 				((WH / 2) - (self->tmp / 2)) + self->wallH, \
// 				(3 << 16 | 186 << 8 | 252));
// 		else if (fabs(self->difx) > fabs(self->dify))
// 			my_mlx_pixel_put(self->vars, self->rayCount, \
// 					((WH / 2) - (self->tmp / 2)) + self->wallH,
// 				(3 << 16 | 186 << 8 | 252) / 2);
// 		else if (fabs(self->difx) < fabs(self->dify) && \
// 			self->rayX > self->vars->pos_x)
// 			ry_mlx_pixel_put(self->vars, self->rayCount, \
// 					((WH / 2) - (self->tmp / 2)) + self->wallH, \
// 				(3 << 16 | 186 << 8 | 252) / 4);
// 		else
// 			my_mlx_pixel_put(self->vars, self->rayCount, \
// 					((WH / 2) - (self->tmp / 2)) + self->wallH, \
// 					(3 << 16 | 186 << 8 | 252) / 6);
// // 	}
// // }
