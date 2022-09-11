/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_move.c                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:31:18 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/09/11 07:59:19 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

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
