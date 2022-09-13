/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_move.c                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:31:18 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/09/11 07:58:13 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	ft_mouse(int button, int x, int y, t_vars *vars)
{
	int	i;

	i = 3;
	if (button == ON_MOUSEUP)
		while (i--)
			ft_look_left(vars);
	else if (button == ON_MOUSDOWN)
		while (i--)
			ft_look_right(vars);
	read_key(-1, vars);
	y = 0;
	x = 0;
	return (0);
}

int	read_key(int keycode, t_vars *vars)
{
	void	(*keys[7])(t_vars *);
	int		real_key;

	keys[0] = &ft_left;
	keys[1] = &ft_down;
	keys[2] = &ft_right;
	keys[3] = &ft_up;
	keys[4] = &ft_esc;
	keys[5] = &ft_look_left;
	keys[6] = &ft_look_right;
	if (keycode == MAP)
		vars->map_on *= -1;
	real_key = get_keycode(keycode);
	if (real_key >= 0 && real_key <= 6)
		keys[real_key](vars);
	vars->playerCos = (cos(degreetoradian(vars->playerAngle)));
	vars->playerSin = (sin(degreetoradian(vars->playerAngle)));
	put_game();
	return (0);
}

int	get_keycode(int keycode)
{
	if (keycode == ESC)
		return (4);
	else if (keycode == UP)
		return (3);
	else if (keycode == LOOK_LEFT)
		return (5);
	else if (keycode == LOOK_RIGHT)
		return (6);
	else if (keycode <= 2 && keycode >= 0)
		return (keycode);
	else
		return (-1);
}

void	ft_up(t_vars *vars)
{
	double	new_x;
	double	new_y;

	new_x = vars->pos_x + (vars->playerCos / vars->speed);
	new_y = vars->pos_y + (vars->playerSin / vars->speed);
	if ((int)floor(new_y) < vars->map_y - 1 && (int)floor(new_x) < \
		(ft_str_len(ft_t_vars()->map[(int)floor(new_y)])) - 1)
	{
		if ((int) floor(new_x) > 0 && (int) floor(new_y) > 0)
		{
			vars->pos_x = new_x;
			vars->pos_y = new_y;
		}
	}
}

void	ft_down(t_vars *vars)
{
	double	new_x;
	double	new_y;

	new_x = vars->pos_x - (vars->playerCos / vars->speed);
	new_y = vars->pos_y - (vars->playerSin / vars->speed);
	if ((int)floor(new_x) < \
		(ft_str_len(ft_t_vars()->map[(int)floor(new_y)]) - 1) && \
		(int)floor(new_y) < vars->map_y - 1)
	{
		if ((int) floor(new_x) > 0 && (int) floor(new_y) > 0)
		{
			vars->pos_x = new_x;
			vars->pos_y = new_y;
		}
	}
}
