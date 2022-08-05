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

static void    check_fill(t_vars *vars, int y, int x)
{
	if ((y >= 0 && x >= 0 && y < ft_len_pp((void **)vars->map) && x < ft_str_len(vars->map[y]))
		&& vars->map[y][x] != '1' && vars->map[y][x] != 'x' && vars->map[y][x] != 'P')
	{
		//printf("\nmap = %c\ny = %d\nx = %d\n",vars->map[y][x], y, x);
		print_map(vars);
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
		else
		{
			printf("\nmap = %c\ny = %d\nx = %d\n",vars->map[y][x], y, x);
			exit(perror_cube3d("Map invalide caractere !!", vars, 0));
		}
		usleep(100000);
		check_fill(vars, y + 1, x);
		check_fill(vars, y, x + 1);
		check_fill(vars, y - 1, x);
		check_fill(vars, y, x - 1);
	}
	return ;
}

void    check_map(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (vars->map[y][x])
	{
		while (vars->map[y][x] != '\0')
		{
			//print_map(vars);
			//printf("\nmap = %c\ny = %d\nx = %d\n",vars->map[y][x], y, x);
			check_fill(vars, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

