/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_move.c                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:31:18 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:31:23 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	read_key(int keycode, t_vars *vars)
{
	void	(*keys[5])(t_vars *)= {&ft_left, &ft_down, &ft_right, &ft_up, &ft_esc};
	int realKey;

	realKey = get_keycode(keycode);
	if (realKey >= 0 && realKey <= 4)
		keys[realKey](vars);
	vars->playerCos = (cos(degreeToRadian(vars->playerAngle)));
	vars->playerSin = (sin(degreeToRadian(vars->playerAngle)));
	put_game();
	return (0);
}

int	get_keycode(int keycode)
{
	if (keycode == ESC)
		return (4);
	else if (keycode == UP)
		return (3);
	else if (keycode <= 2 && keycode >= 0)
		return (keycode);
	else
		return (6);
}

void	ft_up(t_vars *vars)
{
	double new_x;
	double new_y;
	new_x = vars->pos_x + vars->playerCos;
	new_y = vars->pos_y + vars->playerSin;
	printf("%f X, %f Y, len X %d, len Y %d \n", new_x, new_y,vars->map_y, ft_str_len(ft_t_vars()->map[(int)floor(new_y)]));

	if ((int)floor(new_y) < vars->map_y - 1 && (int)floor(new_x) < (ft_str_len(ft_t_vars()->map[(int)floor(new_y)])) - 1) {
			if ((int) floor(new_x) > 0 && (int) floor(new_y) > 0) {
				vars->pos_x = new_x;
				vars->pos_y = new_y;
			}
		}
}

void	ft_down(t_vars *vars)
{
	double new_x;
	double new_y;
	new_x = vars->pos_x - vars->playerCos;
	new_y = vars->pos_y - vars->playerSin;
	printf("%f X, %f Y, len X %d, len Y %d \n", vars->pos_x, vars->pos_y,ft_str_len(ft_t_vars()->map[(int)floor(new_y)]),vars->map_y);

	if ((int)floor(new_x) < (ft_str_len(ft_t_vars()->map[(int)floor(new_y)]) - 1) && (int)floor(new_y) < vars->map_y - 1)
		if ((int)floor(new_x) > 0 && (int)floor(new_y) > 0)
		{
			vars->pos_x = new_x;
			vars->pos_y = new_y;
		}
}

void	ft_left(t_vars *vars)
{
	if (vars->playerAngle - vars->rotation < 0)
		vars->playerAngle = 360 + vars->playerAngle - vars->rotation;
	else
		vars->playerAngle -= vars->rotation;
}

void	ft_right(t_vars *vars)
{
	vars->playerAngle += vars->rotation;
	vars->playerAngle %= 360;
}

void	ft_esc(t_vars *vars)
{
	close_game(vars);
}

int	ft_mouse(int button, int x, int y, t_vars *vars)
{
	/*if (button == ON_MOUSEMOVE) {
		if (x < WW / 2)
			ft_left(vars);
		else
			ft_right(vars);
	}*/
	if (button == ON_MOUSEUP)
		ft_left(vars);
	else if (button == ON_MOUSDOWN)
		ft_right(vars);
	read_key(-1, vars);
	y = 0;
	x = 0;
	button = 0;
	return (0);
}