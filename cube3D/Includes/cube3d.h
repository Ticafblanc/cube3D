/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:47:38 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 14:47:50 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUBE3D_H
# define CUBE3D_H

# define TILES 50
# define PATH_W "./Assets/wall.xpm"

# include <mlx.h>
# include <fcntl.h>
# include <stdbool.h>
# include <libft.h>


enum	e_key
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53,
	ARROW_L = 123,
	ARROW_R = 124,
};

enum	e_mouse
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_asset
{
	void	*img;
	int		width;
	int		height;
}				t_asset;

typedef struct s_img
{
	t_asset	*wall;
	t_asset	*emp;
	t_asset	*exit;
	t_asset	*player_down;
	t_asset	*player_up;
	t_asset	*player_left;
	t_asset	*player_right;
	t_asset	*item;
	t_asset	*enemy;
}				t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		**map;
	int			error_map;
	int			wall_x;
	int			wall_y;
	int			player_x;
	int			player_y;
	int			player_side;
	int			item;
	int			enemy_win;
	int			end_game;
	int			steps;
	int			time;
}				t_vars;

	//1-0_check.c
void		check_map(char *argv, t_vars *vars);

	//1-1_check.c


	//2_init.c


	//4_put.c


	//5_move.c


	//6_utils.c

void		free_map(t_vars *vars);

#endif
