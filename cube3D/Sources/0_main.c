/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:29:46 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:30:06 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	close_game(t_vars *vars)
{
	free_cube3d(vars);
	exit(EXIT_SUCCESS);
}

static void	check_file(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(perror_cube3d("Wrong path of the map", 1));
	read_element(fd);
	check_map(fd);
	size_map();
}

static void ft_set_pos(t_vars *vars)
{
	if (vars->pos == 'N')
		vars->playerAngle = 269;
	else if (vars->pos == 'S')
		vars->playerAngle = 89;
	else if (vars->pos == 'E')
		vars->playerAngle = 1;
	else
		vars->playerAngle = 179;
}


int	main(int argc, char **argv)
{
	if (argc == 2 && ft_check_extension(argv[1], ".cub") > 0)
	{
	
		ft_t_vars()->mlx = mlx_init();
		check_file(argv[1]);
		ft_set_pos(ft_t_vars());
		ft_t_vars()->win = mlx_new_window(ft_t_vars()->mlx, WW, WH, "cube3D");
		ft_t_vars()->img = mlx_new_image(ft_t_vars()->mlx, WW, WH);
		ft_t_vars()->addr = mlx_get_data_addr(ft_t_vars()->img, &ft_t_vars()->bits_per_pixel, &ft_t_vars()->line_length,
								&ft_t_vars()->endian);
		put_game();
	 	mlx_hook(ft_t_vars()->win, ON_DESTROY, 0, close_game, (void *)ft_t_vars());
		mlx_hook(ft_t_vars()->win, ON_KEYDOWN, 1L << 0, read_key, (void *)ft_t_vars());
		mlx_mouse_hook(ft_t_vars()->win, &ft_mouse, ft_t_vars());
		mlx_loop(ft_t_vars()->mlx);
	 }
	exit(perror_cube3d("Just one map extension .cub !! ", 1));
}
