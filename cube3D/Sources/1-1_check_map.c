/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-1_check_file.c                                   :+:      :+:    :+:   */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>     +:+ +:+         +:+     */
/*   By: adubeau <adubeau@student.42quebec.com>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:30:37 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:30:41 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	check_fill(t_vars *vars, int y, int x, int *i);

static void	check_fill_2(t_vars *vars, int y, int x, int *i)
{
	if (check_invisible_characters(vars->map[y][x])
		|| vars->map[y][x] == '0')
		vars->map[y][x] = 'x';
	else if ((vars->map[y][x] == 'N' || vars->map[y][x] == 'S'
		|| vars->map[y][x] == 'E' || vars->map[y][x] == 'W')
		&& !vars->pos)
	{
		vars->pos = vars->map[y][x];
		vars->pos_y = y;
		vars->pos_x = x;
		vars->map[y][x] = 'x';
	}
	else if (vars->map[y][x] != '1' && vars->map[y][x] != 'x')
		exit(perror_cube3d("Map invalide caracter!!", 0));
	else
		return ;
	check_fill(vars, y + 1, x, i);
	check_fill(vars, y, x + 1, i);
	check_fill(vars, y - 1, x, i);
	check_fill(vars, y, x - 1, i);
	check_fill(vars, y + 1, x - 1, i);
	check_fill(vars, y - 1, x + 1, i);
	check_fill(vars, y - 1, x - 1, i);
	check_fill(vars, y + 1, x + 1, i);
}

static void	check_fill(t_vars *vars, int y, int x, int *i)
{
	if (y >= 0 && x >= 0 && y < ft_len_pp((void **)vars->map))
	{
		if (x >= ft_str_len(vars->map[y]))
			*i = 0;
		else if ((y == 0 || x == 0 || y >= ft_len_pp((void **)vars->map) - 1)
			&& vars->map[y][x] != '1')
			*i = 0;
		if (y < ft_len_pp((void **)vars->map) && x < ft_str_len(vars->map[y]))
			check_fill_2(vars, y, x, i);
	}
}

static char	*find_map(int fd)
{
	char	*temp;
	int		i;

	temp = get_next_line(fd);
	while (temp)
	{
		i = 0;
		while (check_invisible_characters(temp[i]))
			i++;
		if (!temp[i])
		{
			free(temp);
			temp = get_next_line(fd);
		}
		else
			return (temp);
	}
	exit(perror_cube3d("map not found", 0));
}

void	fill_map(int fd, t_vars *vars)
{
	char	**t_map;
	char	*temp;
	int		i;

	i = 0;
	t_map = (char **)ft_calloc(2, sizeof(char *));
	temp = find_map(fd);
	*t_map = ft_strtrim(temp, "\n");
	free(temp);
	while (t_map[i++])
	{
		vars->map = ft_dup_cpp(t_map, ft_len_pp((void **)t_map));
		ft_free_pp((void **)t_map);
		t_map = ft_dup_cpp(vars->map, ft_len_pp((void **)t_map) + 1);
		temp = get_next_line(fd);
		t_map[i] = ft_strtrim(temp, "\n");
		free(temp);
		if (t_map[i])
			ft_free_pp((void **)vars->map);
	}
	ft_free_pp((void **)t_map);
	close(fd);
}

int	check_map(void)
{
	int	y;
	int	x;
	int	i;
	int	ok;

	y = -1;
	ok = 0;
	while (++y < ft_len_pp((void **)ft_t_vars()->map))
	{
		x = -1;
		while (++x < ft_str_len(ft_t_vars()->map[y]))
		{
			i = 1;
			if (ok != 1)
				ft_t_vars()->pos = 0;
			if (ft_t_vars()->map[y][x] != '1' && ft_t_vars()->map[y][x] != 'x'
				&& ft_t_vars()->map[y][x] != 'P')
			{
				check_fill(ft_t_vars(), y, x, &i);
				if (i == 1 && ft_t_vars()->pos != 0)
					ok = 1;
			}
		}
	}
	return (ok);
}
