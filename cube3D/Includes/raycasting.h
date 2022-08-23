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
/*
typedef struct s_vtable_rays{

}t_vtable_rays;

typedef struct s_rays
{
	t_vtable_rays *operations;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;//
	double			raydirx;
	double			raydiry;
	double			camerax;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	int				hit;//
	int				side;
	double			perpwalldist; //
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				x;
	int				texture;
} t_rays;*/

/*t_rays *ft_raycasting_init(t_vars *vars);
t_vtable_rays *ft_init_vtable(void);*/
void ft_rayCasting(t_vars *vars);