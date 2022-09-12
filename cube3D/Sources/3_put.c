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

	size = 7;
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
				put_multipix(x, y, 42562, size);
		}
	}
	put_multipix(ft_t_vars()->pos_x, ft_t_vars()->pos_y, 16711680, size);
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
	t_ray ray;
	
	ray.raycount = 0;
	while (ray.raycount < WW)
	{
		ft_init_vtable()->reset_values(ft_t_vars(), &ray);
		ft_init_vtable()->wall_collision(ft_t_vars(), &ray);
		ft_init_vtable()->get_distance(&ray);
		ft_init_vtable()->get_wall_height(&ray);
		ft_init_vtable()->get_wall_h_l_pix(&ray);
		ft_init_vtable()->select_sprite(&ray);// //give x and y sides different brightnessif (side == 1) {color = color / 2;}
		ft_init_vtable()->print(&ray);
		ray.raycount += 1;
	}//update time to do
}

void	put_game(void)
{
	put_background();
	ft_raycasting(ft_t_vars());
	if (ft_t_vars()->map_on)
		put_mini_map();
	mlx_put_image_to_window(ft_t_vars()->mlx, \
		ft_t_vars()->win, ft_t_vars()->img, 0, 0);
	//if (ft_t_vars()->map_on)
	put_mini_map();
}
