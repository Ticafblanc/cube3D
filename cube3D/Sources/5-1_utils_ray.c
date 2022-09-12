/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-1_utils.c                                        :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:32:47 by adubeau           #+#    #+#             */
/*   Updated: 2022/09/04 18:21:19 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

double  delta_dist(double ray_dir)
{
	if (ray_dir == 0)
		return(1e30);
	else
		return(abs(1 / ray_dir));
}

static void init_side_dist(t_vars *vars, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
			{
				ray->step_x = -1;
				ray->side_dist_x = (vars->pos_x - ray->map_x) * delta_dist(ray->ray_dir_x);
			}
			else
			{
				ray->step_x = 1;
				ray->side_dist_x = (ray->map_x + 1.0 - vars->pos_x) * delta_dist(ray->ray_dir_x);
			}
			if (ray->ray_dir_y < 0)
			{
				ray->step_x = -1;
				ray->side_dist_y = (vars->pos_y - ray->map_y) * delta_dist(ray->ray_dir_y);
			}
			else
			{
				ray->step_x = 1;
				ray->side_dist_y = (ray->map_y + 1.0 - vars->pos_y) * delta_dist(ray->ray_dir_y);
			}
}

void	ft_hit_wall(t_vars *vars, t_ray *ray)
{
	init_side_dist(vars, ray);
	while (ray->hit != '1')
			{
				if (ray->side_dist_x < ray->side_dist_y)
				{
					ray->side_dist_x += delta_dist(ray->ray_dir_x);
					ray->map_x += ray->step_x;
					ray->side = 0;
				}
				else
				{
					ray->side_dist_y += delta_dist(ray->ray_dir_y);
					ray->map_x += ray->step_y;
					ray->side = 1;
				}
				ray->hit = vars->map[ray->map_x][ray->map_y];
			} 
}

void	ft_calculate_distance(t_ray *ray)
{
		if(ray->side == 0)
			ray->perp_wall_dist = (ray->side_dist_x - delta_dist(ray->ray_dir_x));
		else
			ray->perp_wall_dist = (ray->side_dist_y - delta_dist(ray->ray_dir_y));
}

void	ft_calculate_wall_height(t_ray *ray)
{
	ray->line_height = (int)(WH / ray->perp_wall_dist);
}

void			ft_get_wall_h_l_pix(t_ray *ray)
{
	ray->draw_start = -ray->line_height / 2 + WH / 2;
  if(ray->draw_start < 0)
		ray->draw_start = 0;
  ray->draw_end = ray->line_height / 2 + WH / 2;
  if(ray->draw_end >= WH)
		ray->draw_end = WH - 1;
}
