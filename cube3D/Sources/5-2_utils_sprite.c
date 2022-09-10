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

static void	ft_set_sprite(t_rays *self, int mem)
{
	if (mem != self->texture->txt)
	{
		ft_reset_sprite();
		//printf("next spritte");
	}
	self->texture->pix_x = (float)self->texture->width * self->difx;// (float)self->wallH;
	//printf("pix = %f\nwidth = %f\ndif = %f\n", self->texture->pix_x, (float)self->texture->width,  self->difx);
	if (self->texture->pix_x > self->texture->width)
	{
		self->texture->pix_x = 0;
		self->texture->pix_x += (float)self->texture->width
			/ (float)self->wallH;
	}
	self->texture->pix_y = 0 ;
}

static int	ft_get_pixel(t_rays *self)
{
	char	*dst;

	self->texture->pix_y += (float)self->texture->height / (float)self->tmp;
	if (self->texture->pix_y > self->texture->height)
	{
		self->texture->pix_y = 0;
		self->texture->pix_y += (float)self->texture->height / (float)self->tmp;
	}
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
	int	mem;

	mem = self->texture->txt;
	self->difx = (self->rayX - (int)(self->rayX));
	self->dify = (self->rayY - (int)(self->rayY));
	if (fabs(self->difx) <= fabs(self->dify) && \
			self->rayX >= self->vars->pos_x)
		self->texture = ft_t_img()->EA;
	else if (fabs(self->difx) >= fabs(self->dify) \
				&& self->rayY >= self->vars->pos_y)
		self->texture = ft_t_img()->SO;
	else if (fabs(self->difx) >= fabs(self->dify))
		self->texture = ft_t_img()->NO;
	else
		self->texture = ft_t_img()->WE;
	ft_set_sprite(self, mem);
}

void	ft_print_walls(t_rays *self)
{
	int	color;

	color = 0;
	if (self->wallH > WH)
		self->wallH = WH;
	self->tmp = self->wallH;
	while (self->wallH--)
	{
		color = ft_get_pixel(self);
		my_mlx_pixel_put(self->vars, self->rayCount,
			((WH / 2) - (self->tmp / 2)) + self->wallH,
			color);
	}
}
