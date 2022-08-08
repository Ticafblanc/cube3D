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
	printf ("OK!!!\n");
	print_map(ft_t_vars());
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_check_extension(argv[1], ".cub") > 0)
	{
		check_file(argv[1]);
	//	init_game(vars);
		mlx_hook(ft_t_vars()->win, ON_DESTROY, 0, close_game, (void *)ft_t_vars());
		//mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, read_key, (void *)vars);
		//mlx_loop_hook(vars->mlx, update, vars);
		mlx_loop(ft_t_vars()->mlx);
	}
	exit(perror_cube3d("Just one map extension .cub !! ", 1));
}
