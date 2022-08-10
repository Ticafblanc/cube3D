/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_put.c                                            :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:31:05 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:31:09 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static int	read_map(int y, int x)
{
	if (ft_t_vars()->map[y][x] == '1')
		return (5244936);
	if (ft_t_vars()->map[y][x] == 'P')
		return (8704);
	return (0);
}


void	put_game(void)
{
	int	x;
	int y;
	

	y = -1;
	while (y++ < 500)
	{
		x = -1;
		while (x++ < 2000)
		{
			//printf("x= %d\ny= %d\n", ft_t_vars()->map_x, ft_t_vars()->map_y);
			if (x < ft_t_vars()->map_x && y < ft_t_vars()->map_y)
				my_mlx_pixel_put(ft_t_vars(), x, y, read_map(y, x));
			else
				my_mlx_pixel_put(ft_t_vars(), x, y, ft_t_img()->F);
		}	
	}
	y--;
	while (y++ < 999)
	{
		x = -1;
		while (x++ < 2000)
			my_mlx_pixel_put(ft_t_vars(), x, y, ft_t_img()->C);
	}
	mlx_put_image_to_window(ft_t_vars()->mlx, ft_t_vars()->win, ft_t_vars()->img, 0, 0);
}