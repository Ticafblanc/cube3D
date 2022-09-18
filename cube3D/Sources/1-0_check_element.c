/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-0_check_element.c                                :+:      :+:    :+:   */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>     +:+ +:+         +:+     */
/*   By: adubeau <adubeau@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:30:15 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:35:11 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static int	init_element(char *element, int val)
{
	if (element && val == NO)
		init_texture(ft_t_vars(), ft_t_img()->no, element, val);
	else if (element && val == SO)
		init_texture(ft_t_vars(), ft_t_img()->so, element, val);
	else if (element && val == WE)
		init_texture(ft_t_vars(), ft_t_img()->we, element, val);
	else if (element && val == EA)
		init_texture(ft_t_vars(), ft_t_img()->ea, element, val);
	else if (element && val == F)
		init_color(&ft_t_img()->f, element);
	else if (element && val == C)
		init_color(&ft_t_img()->c, element);
	else
		return (0);
	return (1);
}

static int	check_val(t_img *img, char *temp)
{
	if (!*temp)
		return (0);
	if (ft_strncmp(temp, "NO", 2) == 0 && !img->no->img)
		return (NO);
	if (ft_strncmp(temp, "SO", 2) == 0 && !img->so->img)
		return (SO);
	if (ft_strncmp(temp, "WE", 2) == 0 && !img->we->img)
		return (WE);
	if (ft_strncmp(temp, "EA", 2) == 0 && !img->ea->img)
		return (EA);
	if (ft_strncmp(temp, "F", 1) == 0 && !img->f)
		return (F);
	if (ft_strncmp(temp, "C", 1) == 0 && !img->c)
		return (C);
	return (0);
}

static int	find_element(char *element, int fd)
{
	int	val;
	int	i;

	i = 0;
	val = 0;
	while (*element && check_invisible_characters(*element))
		element++;
	val = check_val(ft_t_img(), element);
	if (val > 0)
	{
		element++;
		if (val < 5)
			element++;
		while (check_invisible_characters(*element))
			element++;
		while (element[i] && !check_invisible_characters(element[i]))
			i++;
		element[i] = '\0';
		if (init_element(element, val))
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
	if (temp)
		free(temp);
	if (i != 0)
	{
		close (fd);
		exit(perror_cube3d("missing element", 0));
	}
}
