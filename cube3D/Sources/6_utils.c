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

#include "../Includes/cube3d.h"


int	perror_cube3d(char *str, int flag)
{
	free_cube3d(ft_t_vars());
	dprintf (2, "Error\n");
	if (flag)
		perror (str);
	else
		dprintf (2, "%s\n", str);
	return (EXIT_FAILURE);
}

void	free_cube3d(t_vars *vars)
{
	if (vars->element)
		ft_free_pp((void **)vars->element);
	if (vars->map)
		ft_free_pp((void **)vars->map);
}

void	print_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		printf("%s\n", vars->map[i++]);
	}
}
