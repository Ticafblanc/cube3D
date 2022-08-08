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

static void	check_file(char *argv, t_vars *vars)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(perror_cube3d("Wrong path of the map", vars, 1));
	read_element(fd, vars);
	printf("\ncoucou\n");
	check_map(fd , vars);
	printf("OK!!!\n");
	print_map(vars);
	exit(0);
}

t_vars	*init_t_vars(void)
{
	static t_vars	*vars;

<<<<<<< HEAD
	if (vars->init != 1) {
		vars = (t_vars *) malloc(sizeof(t_vars));
		if (!vars)
			ft_exit_perror("init t_struct t_vars failure");
		vars->error_map = 0;
		vars->wall_x = 0;
		vars->wall_y = 0;
		vars->enemy_win = 0;
		vars->end_game = 0;
		vars->steps = 0;
		vars->player_side = DOWN;
		vars->player_x = 0;
		vars->player_y = 0;
		vars->item = 0;
		vars->time = 50000;
		vars->radian = 0;
		vars->init = 1;
	}
	return (&vars);
=======

	vars = (t_vars *) malloc(sizeof(t_vars));
	if (!vars)
		exit(perror_cube3d("Init t_struct t_vars failure", NULL, 1));
	vars->element = (char **)ft_calloc(sizeof(char *), 7);
	if (!vars->element)
		exit(perror_cube3d("Init t_struct t_vars failure", vars, 1));
	vars->pos = 0;
	vars->end_game = 0;
	vars->time = 50000;
	return (vars);
>>>>>>> matthis/merge
}

int	main(int argc, char **argv)
{
	t_vars	*vars = NULL;

	if (argc == 2 && ft_check_extension(argv[1], ".cub") > 0)
	{
		vars = init_t_vars();
		check_file(argv[1], vars);
	//	init_game(vars);
		mlx_hook(vars->win, ON_DESTROY, 0, close_game, (void *)vars);
		//mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, read_key, (void *)vars);
		//mlx_loop_hook(vars->mlx, update, vars);
		mlx_loop(vars->mlx);
	}
	exit(perror_cube3d("Just one map extension .cub !! ", NULL, 1));
}
