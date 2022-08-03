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
	int		i;
	char	**t_map;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(perror_cube3d("Error\nWrong path of the map", vars));
	t_map = (char **)ft_calloc(3, sizeof(char *));
	if (!t_map)
	{
		close(fd);
		exit(perror_cube3d("Error\nmalloc map", vars));
	}
	*t_map = read_element(fd, vars);
	while (t_map[i++])
	{
		vars->map = ft_dup_cpp(t_map, ft_len_pp((void **)t_map));
		ft_free_pp((void **)t_map);
		t_map = ft_dup_cpp(vars->map, ft_len_pp((void **)t_map) + 1);
		t_map[i] = get_next_line(fd);
		if (t_map[i])
			ft_free_pp((void **)vars->map);
	}
	ft_free_pp((void **)t_map);
	close(fd);
	check_map(vars);
}

static t_vars	*init_t_vars(void)
{
	t_vars	*vars;


	vars = (t_vars *) malloc(sizeof(t_vars));
	if (!vars)
		exit(perror_cube3d("Error\ninit t_struct t_vars failure", NULL));
	vars->element = (char **)ft_calloc(sizeof(char *), 6);
	if (!vars->element)
		exit(perror_cube3d("Error\ninit t_struct t_vars failure", vars));
	vars->error_map = 0;
	vars->enemy_win = 0;
	vars->end_game = 0;
	vars->steps = 0;
	vars->item = 0;
	vars->time = 50000;
	return (vars);
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
	exit(perror_cube3d("Error\njust one map extension .cub !! ", NULL));
}
