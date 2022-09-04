/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com        +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:30:47 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:30:53 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

t_vars	*ft_t_vars(void)
{
	static t_vars	vars;

	if (!vars.init)
	{
		//vars.raycasting = ft_raycasting_init(&vars);
		vars.map_x = 0;
		vars.map_y = 0;
		vars.pos = 0;
		vars.init = 1;
		vars.playerAngle = 89;
		vars.speed = 3.0;
		vars.rotation = 5;
	}
	return (&vars);
}

t_img	*ft_t_img(void)
{
	static t_img			img;
	static t_texture		NO;
	static t_texture		SO;
	static t_texture		WE;
	static t_texture		EA;

	if (!img.init)
	{
		img.NO = &NO;
		img.SO = &SO;
		img.WE = &WE;
		img.EA = &EA;
		img.F = 0;
		img.C = 0;
		img.init = 1;
	}
	return (&img);
}

void	init_color(int *color, char *element)
{
	char	**temp;
	int		r;
	int		g;
	int		b;

	temp = ft_split(element, ',');
	if (*temp)
	{
		r = atoi(temp[0]);
		g = atoi(temp[1]);
		b = atoi(temp[2]);
		ft_free_pp((void **)temp);
		if (r <= 255 && r >= 0 && g <= 255 && g >= 0 && b <= 255 && b >= 0)
		{
			*color = 65536 * r + 256 * g + b;
			return ;
		}		
	}
	exit(perror_cube3d("Color invalide !!", 0));
}

void	init_texture(t_vars *vars, t_texture *txt, char *element)
{
	txt->img = mlx_xpm_file_to_image(vars->mlx, element,
			&txt->width, &txt->height);
		if (!txt->img)
	exit(perror_cube3d("Texture invalide !!", 0));
	txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel, &txt->line_length,
								&txt->endian);		
}

