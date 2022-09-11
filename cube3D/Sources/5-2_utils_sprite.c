/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* 	 6-2_utils_sprite.c                                 :+:      :+:    :+:   */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>     +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:13:26 by adubeau           #+#    #+#             */
/*   Updated: 2022/09/04 18:18:19 by adubeau          ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	ft_set_sprite(t_rays *self)
{
	self->difx = (self->rayX - (int)(self->rayX));
	self->dify = (self->rayY - (int)(self->rayY));
	if (self->texture->txt == EA || self->texture->txt == WE)
		self->texture->pix_x = (float)self->texture->width * self->dify;
	else
		self->texture->pix_x = (float)self->texture->width * self->difx;
	self->texture->pix_y = 0 ;
}

static int	ft_get_pixel(t_rays *self)
{
	char	*dst;

	self->texture->pix_y += (float)self->texture->height / (float)self->tmp;
	dst = self->texture->addr
		+ ((int)self->texture->pix_y * self->texture->line_length)
		+ ((int)self->texture->pix_x * (self->texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	ft_reset_sprite(void)
{
	ft_t_img()->NO->pix_x = 0;
	ft_t_img()->NO->pix_y = 0;
	ft_t_img()->SO->pix_x = 0;
	ft_t_img()->SO->pix_y = 0;
	ft_t_img()->WE->pix_x = 0;
	ft_t_img()->WE->pix_y = 0;
	ft_t_img()->EA->pix_x = 0;
	ft_t_img()->EA->pix_y = 0;
}

void	ft_get_sprite(t_rays *self)
{
	float	i;

	i = 0.01;
	self->texture = NULL;
	while (!self->texture)
	{
		if (self->rayY < self->vars->pos_y
			&& self->vars->map[(int)(self->rayY + i)][(int)self->rayX] != '1')
			self->texture = ft_t_img()->NO;
		else if (self->rayY >= self->vars->pos_y
			&& self->vars->map[(int)(self->rayY - i)][(int)self->rayX] != '1')
			self->texture = ft_t_img()->SO;
		else if (self->rayX < self->vars->pos_x
			&& self->vars->map[(int)self->rayY][(int)(self->rayX + i)] != '1')
			self->texture = ft_t_img()->WE;
		else if (self->rayX >= self->vars->pos_x
			&& self->vars->map[(int)self->rayY][(int)(self->rayX - i)] != '1')
			self->texture = ft_t_img()->EA;
		i += 0.01;
	}
	ft_set_sprite(self);
}

void	ft_print_walls(t_rays *self)
{
	if (self->wallH > WH)
		self->wallH = WH;
	self->tmp = self->wallH;
	while (self->wallH--)
	{
		my_mlx_pixel_put(self->vars, self->rayCount,
			((WH / 2) - (self->tmp / 2)) + self->wallH,
			ft_get_pixel(self));
	}
}
