/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_put.c                                            :+:      :+:    :+:   */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>     +:+ +:+         +:+     */
/*   By: adubeau <adubeau@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:31:05 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/09/04 18:24:26 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void	put_multipix(int x, int y, int color, int size)
{
	int	i;
	int	i2;

	i = -1;
	while (i++ < size)
	{
		i2 = -1;
		while (i2++ < size)
			my_mlx_pixel_put(ft_t_vars(), x * 8 + i, y * 8 + i2, color);
	}
}

static void	put_mini_map(void)
{
	int	x;
	int	y;
	int	size;

	size = 8;
	y = -1;
	while (y++ < ft_t_vars()->map_y)
	{
		x = -1;
		while (x++ < ft_t_vars()->map_x)
		{
			if (x < ft_str_len(ft_t_vars()->map[y])
				&& y < ft_len_pp((void **)ft_t_vars()->map)
				&& ft_t_vars()->map[y][x] == '1')
				put_multipix(x, y, 255, size);
			else
				put_multipix(x, y, 000000, size);
		}
	}
	my_mlx_pixel_put(ft_t_vars(), ft_t_vars()->pos_x * size + size / 2, \
		ft_t_vars()->pos_y * size + size / 2, 16711680);
}

static void	put_background(void)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < WH / 2)
	{
		x = -1;
		while (x++ < WW)
			my_mlx_pixel_put(ft_t_vars(), x, y, ft_t_img()->F);
	}
	y--;
	while (y++ < WH - 2)
	{
		x = -1;
		while (x++ < WW)
			my_mlx_pixel_put(ft_t_vars(), x, y, ft_t_img()->C);
	}
}

void	ft_raycasting(t_vars *vars)
{
	t_rays	*self;

	self = get_raycaster();
	self->vars = vars;
	self->rayAngle = self->vars->playerAngle - self->halfFOV;
	ft_reset_sprite();
	while (self->rayCount < WW)
	{
		self->operations->reset_values(self);
		self->operations->wall_collision(self);
		self->operations->get_distance(self);
		self->operations->get_wall_height(self);
		self->operations->select_sprite(self);
		self->operations->print(self);
		self->operations->increment_angle(self);
		self->rayCount += 1;
	}
}

void	put_game(void)
{
	put_background();
	ft_raycasting(ft_t_vars());
	if (ft_t_vars()->map_on > 0)
		put_mini_map();
	mlx_put_image_to_window(ft_t_vars()->mlx, \
		ft_t_vars()->win, ft_t_vars()->img, 0, 0);
}
