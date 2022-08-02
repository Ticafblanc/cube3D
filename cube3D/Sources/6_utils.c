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

int	perror_cube3d(char *str, t_vars *vars)
{
	free_cube3d(vars);
	perror(str);
	return(EXIT_FAILURE);
}

void	free_cube3d(t_vars *vars)
{
	if (vars->element)
		ft_free_pp((void **)vars->element);
	if (vars->map)
		ft_free_pp((void **)vars->map);
	if (vars)
		free(vars);
}
