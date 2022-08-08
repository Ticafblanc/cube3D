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

static int  find_next_dir(t_check_map map, t_vars *vars);

static int  find_next_one(t_check_map *map, t_vars *vars, int y, int x)
{
	int     save_y;
	int     save_x;

	//printf("\ny = %d\nx = %d\n", y, x);
	if (y >= 0 && x >= 0 && y < ft_len_pp((void **)vars->map) && x < ft_str_len(vars->map[map->y]))
	{
		save_y = map->y;
		save_x = map->x;
		map->y = y;
		map->x = x;
		//printf("\nin find next ONE\ndir = %d\nvar->map = %c\nmap.y/s_y = %d/%d\nmap.x/s_x = %d/%d\n", vars->map[map->y][map->x], map->dir,  map->y, map->s_y, map->x, map->s_x);
		if (map->y == map->s_y && map->x == map->s_x)
			return(1);
		if (vars->map[map->y][map->x] == '1')
		{
			//printf("\ndoubel check%c\n", vars->map[map->y][map->x]);
			if (map->dir == RIGHT)
				map->dir = UP;
			else if (map->dir == DOWN)
				map->dir = RIGHT;
			else if (map->dir == LEFT)
				map->dir = DOWN;
			else if (map->dir == UP)
				map->dir = LEFT;
			//usleep(1000000);
			if (find_next_dir(*map, vars))
				return (1);
		}
		map->y = save_y;
		map->x = save_x;
	}
	return (0);
}

static int  find_next_dir(t_check_map map, t_vars *vars)
{
	int     round;

	round = 3;
	while (round)
	{
		printf("\nin find next DIR\ndir = %d\nvar->map = %c\nmap.y = %d\nmap.x = %d\n", map.dir, vars->map[map.y][map.x], map.y, map.x);
		round--;
		if (map.dir == RIGHT)
		{
			if (find_next_one(&map, vars, map.y - 1, map.x))
				return(1);
			map.dir = DOWN;
		}
		else if (map.dir == DOWN)
		{
			if (find_next_one(&map, vars, map.y, map.x + 1))
				return(1);
			map.dir = LEFT;
		}
		else if (map.dir == LEFT)
		{
			if (find_next_one(&map, vars, map.y + 1, map.x))
				return(1);
			map.dir = UP;
		}
		else if (map.dir == UP)
		{
			if (find_next_one(&map, vars, map.y, map.x - 1))
				return(1);
			map.dir = RIGHT;
		}
	}
	//printf("\nin find next DIR\ndir = %d\nvar->map = %c\nmap.y = %d\nmap.x = %d\n", map.dir, vars->map[map.y][map.x], map.y, map.x);
	if (map.y == map.s_y && map.x == map.s_x)
		perror_cube3d("map not close", 0);
	return(0);
}

int  turn_around(t_vars *vars, int y, int x)
{
	t_check_map map;
   
	map.y = 0;
	map.x = 0;
	map.s_y = y;
	map.s_x = x;
	map.dir = RIGHT;
	while (vars->map[map.s_y][map.s_x] != '1')
		map.s_x++;
	map.x = map.s_x;
	if (vars->map[map.s_y][map.s_x] == '1')
		if (!find_next_dir(map, vars))
			return (0);
	return(1);
}

