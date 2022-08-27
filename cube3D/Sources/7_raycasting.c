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
/*

static void get_dir (t_vars *vars, double *dirX, double *dirY, double *planX, double *planY)
{
	*dirX = 0;
	*dirY = 0;
	*planX = 0;
	*planY = 0;
	if (vars->pos == 'N')
	{
		*dirX = -1;
		*planY = 0.66;
	}
	if (vars->pos == 'S')
	{
		*dirX = 1;
		*planY = -0.66;
	}
	if (vars->pos == 'E')
	{
		*dirY = 1;
		*planX = 0.66;
	}
	if (vars->pos == 'W')
	{
		*dirY = -1;
		*planX = -0.66;
	}
}
static void ft_draw(t_vars *vars, int rayCount, int drawStart, int wallH, int side)
{
	while (wallH)
	{
		if (side == 1)
			mlx_pixel_put(vars->mlx, vars->win, rayCount, drawStart + wallH,((3 << 16 | 186 << 8 | 252) / 2) );
		else
			mlx_pixel_put(vars->mlx, vars->win, rayCount, drawStart + wallH,(3 << 16 | 186 << 8 | 252) );
		wallH--;
	}
}

void ft_rayCasting(t_vars *vars)
{
	double dirX = 0;
	double dirY = 0;
	double planX = 0;
	double planY = 0;
	get_dir(vars, &dirX, &dirY, &planX, &planY);
	double cameraX = 0;

	int rayCount = 0;
	double perpWallDist;
	int stepX;
	int stepY;

	int side;

	while (rayCount < WW)
	{
		cameraX = 2 * rayCount / (double)WW - 1;
		int hit = 0;
		double sideDistX = 0;
		double sideDistY = 0;
		double mapX = vars->pos_x;
		double mapY = vars->pos_y;
		dirX = dirX + planX * cameraX;
		dirY = dirY + planY * cameraX;
		double deltaDistX = sqrt(1 + (dirY * dirY) / (dirX * dirX));
		double deltaDistY = sqrt(1 + (dirX * dirX) / (dirY * dirY));
		printf("deltaDistX = %f\n", deltaDistX);
		printf("deltaDistY = %f\n", deltaDistY);
		if(dirX < 0)
		{
			stepX = -1;
			sideDistX = (vars->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - vars->pos_x) * deltaDistX;
		}
		if(dirY < 0)
		{
			stepY = -1;
			sideDistY = (vars->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - vars->pos_y) * deltaDistY;
		}

		while(hit != 49)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			hit = vars->map[(int)floor(mapY)][(int)floor(mapX)];
	//		printf("hit = %d\n", hit);
		}
	//	printf("sideDistX = %f, deltaDistX = %f\n", sideDistX, deltaDistX);
	//	printf("sideDistY = %f, deltaDistY = %f\n", sideDistY, deltaDistY);

		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		int h = WH;
	//	printf("wallDist = %f\n", perpWallDist);
		int wallH = (h / perpWallDist);
		printf("wallH = %d\n", wallH);

		int drawStart = -wallH / 2 + h / 2;
		ft_draw(vars, rayCount, drawStart, wallH, side);
		rayCount++;
		//sleep(1);
	}
}

*/
 static double degreeToRadian(double degree)
{
	return degree * PI / 180;
}
  void ft_rayCasting(t_vars *vars)
{
	//double halfW = WW / 2;
	double halfH = (double)WH / 2;
	double incrementAngle = (double)FOV / (double)WW;
	double halfFOV = (double)FOV / 2;
	double rayAngle = vars->playerAngle - halfFOV;
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
		rayCos = cos(degreeToRadian(rayAngle)) / 100;
		raySin = sin(degreeToRadian(rayAngle)) / 100;
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
		distance = distance * cos(degreeToRadian(rayAngle - vars->playerAngle));
		//printf("distance = %f\n", distance);
		wallH = (floor(halfH / distance));
		printf("wallH = %d\n", wallH);
		rayAngle += incrementAngle;
		//printf("rayAngle = %f\n", rayAngle);
		int tmp = wallH;
		while (wallH > 1)
		{
			//my_mlx_pixel_put(vars, rayCount, ((WH / 2) - (tmp / 2)) + wallH,(216 << 16 | 129 << 8 | 47) );
			mlx_pixel_put(vars->mlx, vars->win, rayCount, ((WH / 2) - (tmp / 2)) + wallH,(3 << 16 | 186 << 8 | 252) );

			wallH--;
			//printf("tmp = %d, wallH = %d, raycount = %d\n",tmp, wallH, rayCount);
		}
		rayCount++;
		//sleep(1);
	}
}

