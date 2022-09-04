/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:29:46 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 18:30:06 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


typedef struct s_vars t_vars;
typedef struct s_rays t_rays;


typedef struct s_vtable_rays{
	void (*reset_values)(t_rays *self);
	void (*wall_collision)(t_rays *self);
	void (*get_distance)(t_rays *self);
	void (*get_wall_height)(t_rays *self);
	void (*increment_angle)(t_rays *self);
	void (*print)(t_rays *self);

}t_vtable_rays;

typedef struct s_rays
{
	t_vtable_rays *operations;
	t_vars *vars;
	double halfH;
	double incrementAngle;
	double halfFOV;
	double rayAngle;
	int rayCount;
	double rayX;
	double rayY;
	double rayCos;
	double raySin;
	int wall;
	double distance;
	int wallH;
	int init;
	double difx;
	double dify;
	int tmp;
} t_rays;

void ft_rayCasting(t_vars *vars);
void ft_reset_values(t_rays *self);
void ft_hit_wall(t_rays *self);
void ft_calculate_distance(t_rays *self);
void ft_calculate_wall_height(t_rays *self);
void ft_increment_angle(t_rays *self);
t_vtable_rays *ft_init_vtable();
t_rays 	*get_raycaster();
float degreeToRadian(double degree);
void ft_print_walls(t_rays *self);

