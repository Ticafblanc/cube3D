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
#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cube3d.h"

typedef struct s_vars		t_vars;
typedef struct s_rays		t_rays;
typedef struct s_texture	t_texture;

typedef struct s_vtable_rays{
	void	(*reset_values)(t_rays *self);
	void	(*wall_collision)(t_rays *self);
	void	(*get_distance)(t_rays *self);
	void	(*get_wall_height)(t_rays *self);
	void	(*select_sprite)(t_rays *self, float i, float i2);
	void	(*print)(t_rays *self);
	void	(*increment_angle)(t_rays *self);
	void	(*free)(t_rays *self);

}t_vtable_rays;

typedef struct s_rays
{
	t_vtable_rays	*operations;
	t_vars			*vars;
	t_texture		*texture;
	double			half_h;
	double			increment_angle;
	double			half_fov;
	double			ray_angle;
	int				ray_count;
	double			ray_x;
	double			ray_y;
	double			ray_cos;
	double			ray_sin;
	int				wall;
	double			distance;
	int				wall_h;
	int				init;
	double			difx;
	double			dify;
	int				tmp;
	int				pix;
}	t_rays;

void			ft_reset_sprite(void);
void			ft_raycasting(t_vars *vars);
void			ft_reset_values(t_rays *self);
void			ft_hit_wall(t_rays *self);
void			ft_calculate_distance(t_rays *self);
void			ft_calculate_wall_height(t_rays *self);
void			ft_increment_angle(t_rays *self);
t_vtable_rays	*ft_init_vtable(void);
t_rays			*get_raycaster(void);
float			degreetoradian(double degree);
void			ft_get_sprite(t_rays *self, float i, float i2);
void			ft_print_walls(t_rays *self);
void			free_table(t_rays *self);

#endif
