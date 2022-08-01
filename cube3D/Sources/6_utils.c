/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_utils.c                                          :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:31:37 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:31:41 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	free_map(t_vars *vars)
{
	free (vars->img->wall);
	free (vars->img->emp);
	free (vars->img->item);
	free (vars->img->exit);
	free (vars->img->enemy);
	free (vars->img->player_down);
	free (vars->img->player_up);
	free (vars->img->player_left);
	free (vars->img->player_right);
	free (vars->img);
	//ft_free_pp(vars->map);
	free(vars);
}
