/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com        +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:30:47 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:30:53 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

t_vars	*ft_t_vars(void)
{
	static t_vars	vars;

	if (!vars.init)
	{
		vars.element = (char **)ft_calloc(sizeof(char *), 7);
		vars.raycasting = ft_raycasting_init(&vars);
		if (!vars.element)
			exit(perror_cube3d("Init t_struct t_vars failure", 1));
		vars.pos = 0;
		vars.init = 1;
	}
	return (&vars);
}
