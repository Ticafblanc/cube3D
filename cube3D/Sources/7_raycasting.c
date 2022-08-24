/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:13:26 by adubeau           #+#    #+#             */
/*   Updated: 2022/08/10 21:13:29 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

/*t_rays *ft_raycasting_init(t_vars *vars)
{
	t_rays *raycasting;

	raycasting = malloc(sizeof(t_rays));
	raycasting->operations = ft_init_vtable();
	raycasting->posx = 0;
	raycasting->posy = 0;
	raycasting->dirx = 0;
	raycasting->diry = 0;
	raycasting->planx = 0;
	raycasting->plany = 0;
	raycasting->hit = 0;
	raycasting->perpwalldist = 0;
	if (vars->pos == 'N')
	{
		raycasting->dirx = -1;
		raycasting->plany = 0.66;
	}
	if (vars->pos == 'S')
	{
		raycasting->dirx = 1;
		raycasting->plany = -0.66;
	}
	if (vars->pos == 'E')
	{
		raycasting->diry = 1;
		raycasting->planx = 0.66;
	}
	if (vars->pos == 'W')
	{
		raycasting->diry = -1;
		raycasting->planx = -0.66;
	}
	if (raycasting->raydirx == 0)
		raycasting->deltadisty = 1;
	else if (raycasting->raydiry == 0)
		raycasting->deltadistx = 0;
	else
		raycasting->deltadistx = sqrt(1 + raycasting->raydiry * raycasting->raydiry)
				/ (raycasting->raydirx * raycasting->raydirx);

	return (raycasting);
}

t_vtable_rays *ft_init_vtable(void)
{
	t_vtable_rays *operations = malloc(sizeof(t_vtable_rays));

	return (operations);
}*/
static double degreeToRadian(double degree)
{
	return degree * PI / 180;
}
void ft_rayCasting(t_vars *vars)
{
	//double halfW = WW / 2;
	double halfH = WH / 2;
	double incrementAngle = 0.09375;// FOV / WW;
	//double halfFOV = 30;//FOV / 2;
	double rayAngle = 60;//90 - halfFOV;
	int rayCount = 0;
	double rayX = vars->pos_x;
	double rayY = vars->pos_y;
	double rayCos = 0;
	double raySin = 0;
	int wall = 0;
	double distance = 0;
	int wallH = 0;

	while (rayCount < WW)
	{
		distance = 0;
		wallH = 0;
		rayX = vars->pos_x;
		rayY = vars->pos_y;
		rayCos = cos(degreeToRadian(rayAngle)) / 64;
		raySin = sin(degreeToRadian(rayAngle)) / 64;
		wall = 0;
		//printf("rayCos = %f, raySin = %f \n", cos(((rayAngle * PI) / 180) /64), sin(((rayAngle * PI) / 180) /64));
		while (wall != '1')
		{
			rayX += rayCos;
			rayY += raySin;
			wall = vars->map[(int)floor(rayY)][(int)floor(rayX)];
			//printf("map ctn at %dX & %dY = %d \n",(int)floor(rayX), (int)floor(rayY), vars->map[(int)floor(rayY)][(int)floor(rayX)]);
		}
		//printf("posX = %f, posY = %f\n", vars->pos_x,vars->pos_y);
		//printf("rayX = %f, rayY = %f \n", rayX,rayY);
		distance = sqrt(pow(vars->pos_x - rayX, 2) + pow(vars->pos_y - rayY, 2));
		distance = distance * cos(degreeToRadian(rayAngle - 90));
		//printf("distance = %f\n", distance);
		wallH = floor(halfH / distance);
		//printf("wallH = %d\n", wallH);
		rayAngle += incrementAngle;
		//printf("rayAngle = %f\n", rayAngle);
		int tmp = wallH;
		while (wallH > 1)
		{
			//my_mlx_pixel_put(vars, rayCount, ((WH / 2) - (tmp / 2)) + wallH,(216 << 16 | 129 << 8 | 47) );
			mlx_pixel_put(vars->mlx, vars->win, rayCount, ((WH / 2) - (tmp / 2)) + wallH,(216 << 16 | 129 << 8 | 47) );

			wallH--;
			//printf("tmp = %d, wallH = %d, raycount = %d\n",tmp, wallH, rayCount);
		}
		rayCount++;
		//sleep(1);
	}
}
