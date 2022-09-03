/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:13:26 by adubeau           #+#    #+#             */
/*   Updated: 2022/08/10 21:13:29 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

 static float degreeToRadian(double degree)
{
	return degree * PI / 180;
}

void ft_reset_values(t_rays *self)
{
	self->distance = 0;
	self->wallH = 0;
	self->rayX = self->vars->pos_x;
	self->rayY = self->vars->pos_y;
	self->rayCos = cosf(degreeToRadian(self->rayAngle)) / 100;
	self->raySin = sinf(degreeToRadian(self->rayAngle)) / 100;
	self->wall = 0;
}

void ft_hit_wall(t_rays *self)
{
	while (self->wall != '1')
	{
		self->rayX += self->rayCos;
		self->rayY += self->raySin;
		self->wall = self->vars->map[(int)floor(self->rayY)][(int)floor(self->rayX)];
	}
}

void ft_calculate_distance(t_rays *self)
{
	self->distance = sqrt(pow(self->vars->pos_x - self->rayX, 2) + pow(self->vars->pos_y - self->rayY, 2));
	self->distance = self->distance * cosf(degreeToRadian(self->rayAngle - self->vars->playerAngle));
}

void ft_calculate_wall_height(t_rays *self)
{
	self->wallH = (floor(self->halfH / self->distance));
}
void ft_increment_angle(t_rays *self)
{
	self->rayAngle += self->incrementAngle;
}

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

void ft_print_walls(t_rays *self)
{
	int i;
	i = 0;
	//int a = 0;
	//int b = 0;
	 self->tmp = self->wallH;
	 while (self->wallH--) {
		 self->difx = (self->rayX - (int) (self->rayX + 0.1));
		 self->dify = (self->rayY - (int) (self->rayY + 0.1));
		 if (self->rayCount == WW / 2) {
			 while (i < WH - 1) {
				 my_mlx_pixel_put(self->vars, self->rayCount, i, ((255 << 16 | 186 << 8 | 252)));
				 i++;
			 }
		 }
		 if (fabs(self->difx) > fabs(self->dify) && self->rayY > self->vars->pos_y)
			 my_mlx_pixel_put(self->vars, self->rayCount, ((WH / 2) - (self->tmp / 2)) + self->wallH,
							  (3 << 16 | 186 << 8 | 252));
		 else if (fabs(self->difx) > fabs(self->dify))
			 my_mlx_pixel_put(self->vars, self->rayCount, ((WH / 2) - (self->tmp / 2)) + self->wallH,
							  (3 << 16 | 186 << 8 | 252) / 2);
		 else if (fabs(self->difx) < fabs(self->dify) && self->rayX > self->vars->pos_x)
			 my_mlx_pixel_put(self->vars, self->rayCount, ((WH / 2) - (self->tmp / 2)) + self->wallH,
							  (3 << 16 | 186 << 8 | 252) / 4);
		 else
			 my_mlx_pixel_put(self->vars, self->rayCount, ((WH / 2) - (self->tmp / 2)) + self->wallH,
							  (3 << 16 | 186 << 8 | 252) / 6);
		 /*
		 if (fabs(self->difx) > fabs(self->dify) && self->rayY > self->vars->pos_y)
			 ft_get_texture(self, ft_t_img()->NO);
		  else if (fabs(self->difx) > fabs(self->dify))
			  ft_get_texture(self, ft_t_img()->SO);
		  else if (fabs(self->difx) < fabs(self->dify) && self->rayX > self->vars->pos_x)
			  ft_get_texture(self, ft_t_img()->WE);
		 else
			 ft_get_texture(self, ft_t_img()->EA);*/
	 }
}

t_vtable_rays *ft_init_vtable()
{
	t_vtable_rays *vtable;
	vtable = malloc(sizeof(t_vtable_rays));
	vtable->reset_values = &ft_reset_values;
	vtable->wall_collision = &ft_hit_wall;
	vtable->get_distance = &ft_calculate_distance;
	vtable->get_wall_height = &ft_calculate_wall_height;
	vtable->increment_angle = &ft_increment_angle;
	vtable->print = &ft_print_walls;
	return (vtable);
}

t_rays 	*get_raycaster()
{
	static t_rays self;
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
	}
	return (&self);

}


void ft_rayCasting(t_vars *vars)
{
	t_rays *self;
	self = get_raycaster();
	self->vars = vars;
	self->rayAngle = self->vars->playerAngle - self->halfFOV;
	self->rayX = self->vars->pos_x;
	self->rayY = self->vars->pos_y;

	while (self->rayCount < WW)
	{
		self->operations->reset_values(self);
		self->operations->wall_collision(self);
		self->operations->get_distance(self);
		self->operations->get_wall_height(self);
	    self->operations->increment_angle(self);
		self->operations->print(self);
		self->rayCount+= 1;
	}
}

