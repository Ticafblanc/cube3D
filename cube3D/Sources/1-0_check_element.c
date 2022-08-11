/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-0_check_element.c                                :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:30:15 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:35:11 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"
//vreification de la validiter de l'element
static int	check_element(char *element)
{
	if (element)
	{
		printf("element = %s\n", element);
		usleep(500000);
		return (1);
	}
	return (0);
}

static int	check_val(t_vars *vars, char *temp)
{
	if (!*temp)
		return (0);
	if (ft_strncmp(temp, "NO", 2) == 0 && !vars->element[NO])
		return (NO);
	if (ft_strncmp(temp, "SO", 2) == 0 && !vars->element[SO])
		return (SO);
	if (ft_strncmp(temp, "WE", 2) == 0 && !vars->element[WE])
		return (WE);
	if (ft_strncmp(temp, "EA", 2) == 0 && !vars->element[EA])
		return (EA);
	if (ft_strncmp(temp, "F", 1) == 0 && !vars->element[F])
		return (F);
	if (ft_strncmp(temp, "C", 1) == 0 && !vars->element[C])
		return (C);
	return (0);
}

static int	find_element(char *temp, int fd)
{
	int	val;

	val = 0;
	while (*temp && check_invisible_characters(*temp))
		temp++;
	val = check_val(ft_t_vars(), temp);
	if (val > 0)
	{
		temp++;
		if (val < 5)
			temp++;
		while (check_invisible_characters(*temp))
			temp++;
		ft_t_vars()->element[val] = ft_strdup(temp);
		if (check_element(ft_t_vars()->element[val]))
			return (1);
		close (fd);
		exit(perror_cube3d("element not found", 0));
	}
	return (0);
}

void	read_element(int fd)
{
	int		i;
	char	*temp;

	i = 6;
	temp = get_next_line(fd);
	while (i && temp)
	{
		i -= find_element(temp, fd);
		free(temp);
		temp = get_next_line(fd);
	}
	if (i != 0)
	{
		close (fd);
		exit(perror_cube3d("missing element", 0));
	}
}
