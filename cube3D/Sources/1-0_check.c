/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-0_check.c                                        :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:30:15 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:35:11 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void	read_arg(char *argv, t_vars *vars)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit_perror("Wrong path of the map");
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	printf("%d", i);
	close(fd);
	vars->map = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!vars->map)
		ft_exit_strerror(errno);
	fill_map(argv, vars);
}

// void	fill_map(char *argv, t_vars *vars)
// {
// 	int		fd;
// 	int		i;
// 	char	*temp;

// 	fd = open(argv, O_RDONLY);
// 	if (fd < 0)
// 		ft_exit_perror("Wrong path of the map");
// 	i = 0;
// 	temp = get_next_line(fd);
// 	while (temp)
// 	{
// 		vars->map[i] = ft_strtrim(temp, "\n");
// 		free(temp);
// 		temp = get_next_line(fd);
// 		i++;
// 	}
// 	vars->map[i] = NULL;
// 	close(fd);
// }

void	check_map(char *argv, t_vars *vars)
{
	read_arg(argv, vars);
	if (check_wall_up(vars) < 0 || check_wall_side(vars) < 0
		|| check_wall_down(vars) < 0)
	{
		ft_free_pp(vars->map);
		free(vars);
		ft_exit_perror("the map must not have closed walls");
	}
	if (vars->wall_x == vars->wall_y)
	{
		ft_free_pp(vars->map);
		free(vars);
		ft_exit_perror("the card should only have a rectangular shape");
	}
	if (check_caractere(vars) < 0)
	{
		ft_free_pp(vars->map);
		free(vars);
		ft_exit_perror("1 item, 1 exit and 1 player");
	}
}
