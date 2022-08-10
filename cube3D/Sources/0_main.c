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

#include <cube3d.h>

static int	close_game(t_vars *vars)
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
	//init_game(ft_t_vars(), ft_t_img());
	//put_game();
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_check_extension(argv[1], ".cub") > 0)
	{
	
		ft_t_vars()->mlx = mlx_init();
	 	ft_t_vars()->win = mlx_new_window(ft_t_vars()->mlx, 2000, 1000, "cube3D");
		ft_t_vars()->img = mlx_new_image(ft_t_vars()->mlx, 2000, 1000);
		ft_t_vars()->addr = mlx_get_data_addr(ft_t_vars()->img, &ft_t_vars()->bits_per_pixel, &ft_t_vars()->line_length,
								&ft_t_vars()->endian);
		my_mlx_pixel_put(ft_t_vars(), 5, 5, 0x00FF0000);
		mlx_put_image_to_window(ft_t_vars()->mlx, ft_t_vars()->win, ft_t_vars()->img, 0, 0);
		check_file(argv[1]);
	 	mlx_hook(ft_t_vars()->win, ON_DESTROY, 0, close_game, (void *)ft_t_vars());
	// 	//mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, read_key, (void *)vars);
	// 	//mlx_loop_hook(vars->mlx, update, vars);
	 	mlx_loop(ft_t_vars()->mlx);
	 }
	// if (argc == 2 && ft_strncmp(argv[1], "-b", 2))
	// {
	// 	init_game(ft_t_vars());
	// 	mlx_hook(ft_t_vars()->win, ON_DESTROY, 0, close_game, (void *)ft_t_vars());
	// 	//mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, read_key, (void *)vars);
	// 	//mlx_loop_hook(vars->mlx, update, vars);
	// 	mlx_loop(ft_t_vars()->mlx);
	// }
	exit(perror_cube3d("Just one map extension .cub !! ", 1));
}
