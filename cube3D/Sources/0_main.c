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
	mlx_destroy_image(ft_t_vars()->mlx, ft_t_vars()->img);
	mlx_destroy_image(ft_t_vars()->mlx, ft_t_img()->no->img);
	mlx_destroy_image(ft_t_vars()->mlx, ft_t_img()->so->img);
	mlx_destroy_image(ft_t_vars()->mlx, ft_t_img()->we->img);
	mlx_destroy_image(ft_t_vars()->mlx, ft_t_img()->ea->img);
	mlx_destroy_window(ft_t_vars()->mlx, ft_t_vars()->win);
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
	fill_map(fd, ft_t_vars());
	if (!check_map())
		exit(perror_cube3d("Map invalide !!", 0));
	size_map();
}

static void	ft_set_pos(t_vars *vars)
{
	if (vars->pos == 'N')
		vars->player_angle = 269;
	else if (vars->pos == 'S')
		vars->player_angle = 89;
	else if (vars->pos == 'E')
		vars->player_angle = 1;
	else
		vars->player_angle = 179;
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = ft_t_vars();
	if (argc == 2 && ft_check_extension(argv[1], ".cub") > 0)
	{
		vars->mlx = mlx_init();
		check_file(argv[1]);
		ft_set_pos(vars);
		vars->win = mlx_new_window(vars->mlx, \
			WW, WH, "cube3D");
		vars->img = mlx_new_image(vars->mlx, WW, WH);
		vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
			&vars->line_length, &vars->endian);
		put_game();
		mlx_hook(vars->win, ON_DESTROY, 0, close_game, (void *)vars);
		mlx_hook(vars->win, ON_KEYDOWN,
			1L << 0, read_key, (void *)vars);
		mlx_mouse_hook(vars->win, &ft_mouse, (void *)vars);
		mlx_loop(vars->mlx);
	}
	exit (perror_cube3d("Just one map extension .cub !! ", 1));
}
