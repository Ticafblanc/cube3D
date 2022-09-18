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

void	ft_left(t_vars *vars)
{
	double	new_x;
	double	new_y;

	vars->player_cos = (cos(degreetoradian(vars->player_angle - 90)));
	vars->player_sin = (sin(degreetoradian(vars->player_angle - 90)));
	new_x = vars->pos_x + (vars->player_cos / vars->speed);
	new_y = vars->pos_y + (vars->player_sin / vars->speed);
	if ((int)floor(new_y) < vars->map_y - 1 && (int)floor(new_x) < \
		(ft_str_len(ft_t_vars()->map[(int)floor(new_y)])) - 1)
	{
		if ((int) floor(new_x) > 0 && (int) floor(new_y) > 0)
		{
			if (vars->map[(int)floor(new_y + (vars->radius * \
			((vars->player_sin > 0) - (vars->player_sin < 0))))] \
			[(int)floor(new_x + (vars->radius * \
			((vars->player_cos > 0) - (vars->player_cos < 0))))] != '1')
			{
				vars->pos_x = new_x;
				vars->pos_y = new_y;
			}
		}
	}
}

void	ft_right(t_vars *vars)
{
	double	new_x;
	double	new_y;

	vars->player_cos = (cos(degreetoradian(vars->player_angle + 90)));
	vars->player_sin = (sin(degreetoradian(vars->player_angle + 90)));
	new_x = vars->pos_x + (vars->player_cos / vars->speed);
	new_y = vars->pos_y + (vars->player_sin / vars->speed);
	if ((int)floor(new_y) < vars->map_y - 1 && (int)floor(new_x) < \
		(ft_str_len(ft_t_vars()->map[(int)floor(new_y)])) - 1)
	{
		if ((int) floor(new_x) > 0 && (int) floor(new_y) > 0)
		{
			if (vars->map[(int)floor(new_y + (vars->radius * \
			((vars->player_sin > 0) - (vars->player_sin < 0))))] \
			[(int)floor(new_x + (vars->radius * \
			((vars->player_cos > 0) - (vars->player_cos < 0))))] != '1')
			{
				vars->pos_x = new_x;
				vars->pos_y = new_y;
			}
		}
	}
}

void	ft_look_left(t_vars *vars)
{
	if (vars->player_angle - vars->rotation < 0)
		vars->player_angle = 360 + vars->player_angle - vars->rotation;
	else
		vars->player_angle -= vars->rotation;
}

void	ft_look_right(t_vars *vars)
{
	vars->player_angle += vars->rotation;
	vars->player_angle %= 360;
}

void	ft_esc(t_vars *vars)
{
	close_game(vars);
}
