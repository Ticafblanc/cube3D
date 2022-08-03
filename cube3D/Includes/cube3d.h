/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:47:38 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 14:47:50 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUBE3D_H
# define CUBE3D_H

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
	ON_DESTROY = 17,
};

enum	e_element
{
	NO = 1,
	SO = 2,
	WE = 3,
	EA = 4,
	F = 5,
	C = 6,
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

}				t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		**map;
	char		**element;
	int			error_map;
	int			player_side;
	int			item;
	int			enemy_win;
	int			end_game;
	int			steps;
	int			time;
}				t_vars;

typedef struct s_check_map
{
	int		y;
	int		x;
	int		s_y;
	int		s_x;
	int		dir;
}				t_check_map;

	//1-0_check_element.c

char	*read_element(int fd, t_vars *vars);

	//1-1_check.c

void    check_map(t_vars *vars);

	//2_init.c


	//4_put.c


	//5_move.c


	//6_utils.c

int		perror_cube3d(char *str, t_vars *vars);
void	free_cube3d(t_vars *vars);



#endif
