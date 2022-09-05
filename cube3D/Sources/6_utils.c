/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_utils.c                                          :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:31:37 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:31:41 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	perror_cube3d(char *str, int flag)
{
	free_cube3d(ft_t_vars());
	dprintf (2, "Error\n");
	if (flag)
		perror (str);
	else
		dprintf (2, "%s\n", str);
	return (EXIT_FAILURE);
}

void	free_cube3d(t_vars *vars)
{
	if (vars->map)
		ft_free_pp((void **)vars->map);
}

void	size_map()
{
	int i;

	i = 0;
	ft_t_vars()->map_y = ft_len_pp((void**)ft_t_vars()->map) - 1;
	while(i < ft_t_vars()->map_y)
	{
		if (ft_str_len(ft_t_vars()->map[i]) > ft_t_vars()->map_x)
			ft_t_vars()->map_x = ft_str_len(ft_t_vars()->map[i]);
		i++;
	}
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

float degreeToRadian(double degree)
{
	return degree * PI / 180;
}

