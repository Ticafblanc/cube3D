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
	self->difx = (self->ray_x - (int)(self->ray_x));
	self->dify = (self->ray_y - (int)(self->ray_y));
	if (self->texture->txt == EA || self->texture->txt == WE)
		self->texture->pix_x = (float)self->texture->width * self->dify;
	else
		self->texture->pix_x = (float)self->texture->width * self->difx;
	self->texture->pix_y = 0 ;
}

static int	ft_get_pixel(t_rays *self)
{
	char	*dst;

	if (self->pix > WH && self->texture->pix_y == 0)
		self->texture->pix_y = ((float)self->texture->height / (float)self->pix)
			* (self->pix - WH) / 2;
	else
		self->texture->pix_y += (float)self->texture->height / (float)self->pix;
	dst = self->texture->addr
		+ ((int)self->texture->pix_y * self->texture->line_length)
		+ ((int)self->texture->pix_x * (self->texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	ft_reset_sprite(void)
{
	ft_t_img()->no->pix_x = 0;
	ft_t_img()->no->pix_y = 0;
	ft_t_img()->so->pix_x = 0;
	ft_t_img()->so->pix_y = 0;
	ft_t_img()->we->pix_x = 0;
	ft_t_img()->we->pix_y = 0;
	ft_t_img()->ea->pix_x = 0;
	ft_t_img()->ea->pix_y = 0;
}

void	ft_get_sprite(t_rays *self, float i, float i2)
{
	self->texture = NULL;
	while (!self->texture)
	{
		if (self->ray_y < self->vars->pos_y && self->vars->map[(int) \
			(self->ray_y + i)][(int)(self->ray_x + i2)] != '1')
			self->texture = ft_t_img()->no;
		else if (self->ray_y >= self->vars->pos_y && self->vars->map[\
			(int)(self->ray_y - i)][(int)(self->ray_x - i2)] != '1')
			self->texture = ft_t_img()->so;
		else if (self->ray_x < self->vars->pos_x && self->vars->map[\
			(int)(self->ray_y + i2)][(int)(self->ray_x + i)] != '1')
			self->texture = ft_t_img()->we;
		else if (self->ray_x >= self->vars->pos_x && self->vars->map[\
			(int)(self->ray_y - i2)][(int)(self->ray_x - i)] != '1')
			self->texture = ft_t_img()->ea;
		i += 0.001;
		if (self->ray_y + i < self->vars->map_y \
			&& self->ray_x < self->vars->map_x)
			i2 += 0.001;
	}
	ft_set_sprite(self);
}

void	ft_print_walls(t_rays *self)
{
	self->pix = self->wall_h;
	if (self->wall_h > WH)
		self->wall_h = WH;
	self->tmp = self->wall_h;
	self->wall_h -= 1;
	while (self->wall_h--)
	{
		my_mlx_pixel_put(self->vars, self->ray_count,
			((WH / 2) - (self->tmp / 2)) + self->wall_h, \
			ft_get_pixel(self));
	}
}
