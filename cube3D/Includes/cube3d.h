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
# include <math.h>
# include "raycasting.h"

# define WW 640
# define WH 640
# define FOV 60
# define PI 3.14159265

enum	e_key
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53,
	ARROW_L = 123,
	ARROW_R = 124,
	MAP = 46,
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
	IN = 7,
	OUT = 8,
	UNK = 9,
	TILES = 50,
};

typedef struct s_texture
{
	int			txt;
	void		*img;
	int			width;
	int			height;
	float		pix_x;
	float		pix_y;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_img
{
	t_texture	*NO;
	t_texture	*SO;
	t_texture	*WE;
	t_texture	*EA;
	int			F;
	int			C;
	int			init;
}				t_img;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			raycount;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	char		hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;


}				t_ray;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	int			map_y;//size map
	int			map_x;//size map
	int			pos;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	t_ray		*ray;

	int			map_on;
	int			enemy_win;
	int			end_game;
	int			steps;
	int 		init;
	int 		radian;
	int 		playerAngle;
	int 		rotation;
	float 		playerCos;
	float 		playerSin;
	double 		speed;
}				t_vars;

typedef struct s_check_map
{
	int	y;
	int	x;
	int	s_y;
	int	s_x;
	int	dir;
}				t_check_map;

typedef struct s_vtable_rays{
	void	(*reset_values)(t_vars *vars, t_ray *ray);
	void	(*wall_collision)(t_vars *vars, t_ray *ray);
	void	(*get_distance)(t_vars *vars);
	void	(*get_wall_height)(t_vars *vars);
	void	(*get_wall_h_l_pix)(t_vars *vars);
	void	(*select_sprite)(t_vars *vars);
	void	(*print)(t_vars *vars);
	void	(*increment_angle)(t_vars *vars);
	int		init;

}t_vtable_rays;

	//1-0_check_element.c

void	read_element(int fd);

	//1-1_check.c

void	fill_map(int fd, t_vars *vars);
int		check_map(void);

	//2_init.c

t_vars			*ft_t_vars(void);
t_img			*ft_t_img(void);
void			init_texture(t_vars *vars, t_texture *txt, char *element, int val);
void			init_color(int *color, char *element);

	//2_init.c

t_vtable_rays	*ft_init_vtable();
void			ft_reset_values(t_vars *vars, t_ray *ray);

	//3_put.c

void			put_game(void);

	//5_move.c

int				read_key(int keycode, t_vars *vars);
int				get_keycode(int keycode);
void			ft_up(t_vars *vars);
void			ft_down(t_vars *vars);
void 			t_left(t_vars *vars);
void			ft_right(t_vars *vars);
void 			t_esc(t_vars *vars);
int				ft_mouse(int button, int x, int y, t_vars *vars);

	//5_utils.c

int				perror_cube3d(char *str, int flag);
void			free_cube3d(t_vars *vars);
void			size_map();
void			my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int				close_game(t_vars *vars);
int				ft_get_texture(t_texture *texture, t_rays *self);

	//5-1_utils_ray.c

double 			delta_dist(double ray_dir);
void			ft_hit_wall(t_vars *vars, t_ray *ray);
void			ft_calculate_distance(t_ray *ray);
void			ft_calculate_wall_height(t_ray *ray);
void			ft_get_wall_h_l_pix(t_ray *ray);


void			ft_reset_sprite();
void			ft_raycasting(t_vars *vars);
void			ft_reset_values(t_vars *vars, t_ray *ray);		



void ft_increment_angle(t_rays *self);

float degreetoradian(double degree);
void ft_get_sprite(t_rays *self);
void ft_print_walls(t_rays *self);

#endif
