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

#include <cube3d.h>

static int check_element(char *element)
{
	return (1);//vreification de la validiter de l'element 
}

static int	check_val(t_vars *vars, char *temp)
{
	if (!*temp)
		return(0);
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

}

static int	find_element( t_vars *vars, char *temp, int fd)
{
	int	val;

	val = 0;
	while(*temp)
	{
		while (check_invisible_characters(*temp))
			temp++;
		val = check_val(vars, temp);
	}
	if (val)
	{
		while (check_invisible_characters(*temp))
			temp++;
		vars->element[val] = ft_strdup(temp);
		if (check_element(vars->element[val]))
			return (1);
		close (fd);
		exit(perror_cube3d("Error\nelement not found", vars));
	}
	return (0);	
}

static	char	*find_map(int fd)
{
	char	*temp;
	int		i;

	temp = get_next_line(fd);
	while (temp)
	{
		i = 0;
		while (check_invisible_characters(temp[i]))
			i++;
		if (!temp[i])
		{
			free(temp);
			temp = get_next_line(fd);
		}
		else
			return (temp);
	}

}

char	*read_element(int fd, t_vars *vars)
{
	int		i;
	char	*temp;

	i = 6;
	while (i && temp)
	{
		temp = get_next_line(fd);
		i -= find_element(vars, temp, fd);
		free(temp);
	}
	if (!temp)
	{
		close (fd);
		exit(perror_cube3d("Error\nmissing element", vars));
	}
	return (find_map(fd));
}
