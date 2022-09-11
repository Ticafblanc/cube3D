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
			ft_left(vars);
	else if (button == ON_MOUSDOWN)
		while (i--)
			ft_right(vars);
	read_key(-1, vars);
	y = 0;
	x = 0;
	return (0);
}

int	read_key(int keycode, t_vars *vars)
{
	void	(*keys[5])(t_vars *);
	int		real_key;

	keys[0] = &ft_left;
	keys[1] = &ft_down;
	keys[2] = &ft_right;
	keys[3] = &ft_up;
	keys[4] = &ft_esc;
	if (keycode == MAP && vars->map_on == 0)
		vars->map_on = 1;
	if (keycode == MAP && vars->map_on == 1)
		vars->map_on = 0;
	real_key = get_keycode(keycode);
	if (real_key >= 0 && real_key <= 4)
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
	else if (keycode <= 2 && keycode >= 0)
		return (keycode);
	else
		return (-1);
}
