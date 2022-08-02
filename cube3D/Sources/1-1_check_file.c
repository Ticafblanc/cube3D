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

static int  find_next_one( t_check_map *map, t_vars *vars)
{
    if (*dir == RIGHT)
    {
        if (map[*y - 1][*x] && map[*y - 1][*x] ==1)
        {
            *y--;
            *dir = UP;
            return (0);
        }
        *dir = DOWN;
        return (find_next_one(x, y, dir));
    }
    else if (*dir == DOWN)
    {
        if (map[*y][*x + 1] == 1)
        {
            *y--;
            *dir = RIGHT;
            return (0);
        }
        *dir = LEFT;
        return (find_next_one(x, y, dir));
    }
    else if (*dir == LEFT)
    {
        if (map[*y - 1][*x] == 1)
        {
            *y--;
            *dir = DOWN;
            return (0);
        }
        *dir = UP;
        return (find_next_one(x, y, dir));
    }
    else if (*dir == UP)
    {
        if (map[*y - 1][*x] == 1)
        {
            *y--;
            *dir = LEFT;
            return (0);
        }
        *dir = RIGHT;
        return (find_next_one(x, y, dir));
    }
    else
        return(-1);

}

static int  turn_around(t_vars *vars)
{
    t_check_map map;
   
    map.y = 1;
    map.x = 0;
    map.s_y = 1;
    map.s_x = 0;
    map.dir = RIGHT;
    while (vars->map[map.s_y][map.s_x] != '\0'
            && find_next_one(&map, vars) == -1)
        map.s_x++;
    find_next_one()
    while(s_x != x && s_y != 0)
    {
        if (find_next_one(map, &x, &y))
            return (-1);
    }
}

void    check_map(t_vars *vars);
{
    if (turn_around(vars))
        if (chexk in )
            return ;
    exit(perror_cube3d("Error\nmap not found", vars));
}