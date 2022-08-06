/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-1_check_file.c                                   :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:30:37 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:30:41 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void print_map(t_vars *vars)
{
	int i;

	i  = 0;
	while (vars->map[i])
	{
		printf("%s\n", vars->map[i++]);
	}

}

static void    check_fill(t_vars *vars, int y, int x, int *i)
{
	if (y >= 0 && x >= 0)
	{
		if (y >= ft_len_pp((void **)vars->map) || x >= ft_str_len(vars->map[y]))
	 		*i = 0;
		if (y < ft_len_pp((void **)vars->map) && x < ft_str_len(vars->map[y]))
		{
			printf("\nmap = %c\ny = %d\nx = %d\ni = %d\n",vars->map[y][x], y, x, *i);
			print_map(vars);
			if ((y == 0 || x == 0 || y == ft_len_pp((void **)vars->map) - 1 || x == ft_str_len(vars->map[y]) - 1)
				&& vars->map[y][x] != '1')
			 	*i = 0;
			if (check_invisible_characters(vars->map[y][x])
				|| vars->map[y][x] == '0')
				vars->map[y][x] = 'x';
			else if ((vars->map[y][x] == 'N' || vars->map[y][x] == 'S'
				|| vars->map[y][x] == 'E' || vars->map[y][x] == 'W')
				&& !vars->pos)
			{
				vars->pos = vars->map[y][x];
				vars->map[y][x] = 'P';
			}
			else if (vars->map[y][x] != '1' && vars->map[y][x] != 'x' && vars->map[y][x] != 'P')
				exit(perror_cube3d("Map invalide caracter!!", vars, 0));
			else
				return;
			usleep(10000);
			check_fill(vars, y + 1, x, i);
			check_fill(vars, y, x + 1, i);
			check_fill(vars, y - 1, x, i);
			check_fill(vars, y, x - 1, i);
		}
	}
	return;
}

static char	*find_map(int fd,  t_vars *vars)
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
	exit(perror_cube3d("map not found", vars, 0));
}

static void	fill_map(int fd, t_vars *vars)
{
	char	**t_map;
	char	*temp;
	int		i;

	i = 0;
	t_map = (char **)ft_calloc(3, sizeof(char *));
	if (!t_map)
	{
		close(fd);
		exit(perror_cube3d("Malloc map", vars, 1));
	}
	temp = find_map(fd, vars);
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

void    check_map(int fd, t_vars *vars)
{
	int	y;
	int	x;
	int i;
	int ok;

	y = 0;
	x = 0;
	i = 1;
	ok = 0;
	fill_map(fd, vars);
	while (y < ft_len_pp((void **)vars->map))
	{
		while (x < ft_str_len(vars->map[y]))
		{
			if (vars->map[y][x] != '1' && vars->map[y][x] != 'x' && vars->map[y][x] != 'P')
			{
				check_fill(vars, y, x, &i);
				if (i == 1)
					ok = 1;
				i = 1;
			}
			printf("ok = %d\n", ok);
			//usleep(100000);
			x++;
		}
		x = 1;
		y++;
	}
	if (!ok)
	{
		printf("\nmap invalide !!\n");
		print_map(vars);
		exit(perror_cube3d("Map invalide !!", vars, 0));
	}
}