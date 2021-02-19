/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:07:19 by yomoon            #+#    #+#             */
/*   Updated: 2021/02/19 18:07:33 by yomoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "key_macos.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define RETURN_LINE			1
# define RETURN_EOF				0
# define RETURN_ERROR			-1
# define TEX_HEIGHT 64
# define TEX_WIDTH 64
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1440

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef	struct	s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef	struct	s_spr
{
	double		x;
	double		y;
	double		dist;
	int			bonus;
}				t_spr;

typedef struct	s_spr_ray
{
	double		x;
	double		y;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			height;
	int			width;
	double		inversion_detection;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			v_move_screen;
	int			tex_x;
	int			tex_y;
	int			bonus;
}				t_spr_ray;

typedef struct	s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			hit;
	int			step_x;
	int			step_y;
	double		side_dist_x;
	double		side_dist_y;
	int			side;
	double		perp_wall_dist;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		tex_pos;
	double		floor_x_wall;
	double		floor_y_wall;
	double		dist_wall;
	double		dist_player;
	double		current_dist;
	double		weight;
	double		current_floor_x;
	double		current_floor_y;
	int			floor_tex_x;
	int			floor_tex_y;
}				t_ray;

typedef struct	s_info
{
	int			fd;
	int			width;
	int			height;
	char		*n_tex_path;
	char		*s_tex_path;
	char		*w_tex_path;
	char		*e_tex_path;
	char		*p_tex_path;
	char		*b_tex_path;
	char		*f_tex_path;
	int			floor;
	int			ceil;
	int			map_width;
	int			map_height;
	char		**map;
	char		dir;
	int			num_sprite;
	t_player	player;
	t_spr		*spr;
	void		*mlx;
	void		*win;
	int			**buf;
	double		*z_buffer;
	int			**tex;
	t_img		img;
	t_ray		ray;
	t_spr_ray	s_ray;
}				t_info;

/*
**	get_next_line
*/

int				get_next_line(int fd, char **line);
int				split_line(char **str, char **line);

/*
**	main
*/

void			init_player(t_player *player);
int				init_game(char *cub, int bmp);
int				check_name(char *file, char *str);

/*
**	bmp
*/
void			set_int_in_char(unsigned char *start, int value);
void			write_bmp_header(t_info *info, int fd, int size);
void			write_data(t_info *info, int fd);
void			save_bmp(t_info *info);
int				print_bmp(t_info *info);

/*
**	check_map
*/

void			check_map_top(t_info *info);
void			check_map_left(t_info *info, int i, int j);
void			check_map_middle(t_info *info, int i, int j);
void			check_map_right(t_info *info, int i, int j);
void			check_map_bottom(t_info *info, int i);

/*
**	move_player
*/

void			move_player(t_info *info, t_player *player, double move_speed);
void			move_player_left_right(t_info *info, t_player *player, \
				double move_speed);
int				key_press(int key, t_info *info);
void			rotate_player(t_player *player, double rot_angle);

/*
**	parse_cub_sub
*/

int				get_screen_size(t_info *info, char *line);
int				get_texture(t_info *info, char *line, char c);
int				get_rgb(char **rgb);
int				get_color(t_info *info, char *line, char c);

/*
**	parse_cub
*/

int				parse_line_element(t_info *info, char *line);
void			parse_cub(t_info *info);

/*
**	parse_map_sub
*/

void			count_arg(t_info *info, int i, int j, int *dir_count);
int				is_dir(char c);
int				is_map_arg(char c);

/*
**	parse_map
*/

void			fill_map(t_info *info, t_list *lst);
int				get_max_line_size(t_list *lst);
void			init_map(t_info *info, t_list *lst);
void			parse_map(t_info *info, char *line);

/*
**	parse
*/

void			init_element(t_info *info);
void			is_valid_map(t_info *info);
void			check_info(t_info *info);
void			init_buffer(t_info *info);
void			start_parse(t_info *info, char *cub);

/*
**	floor_raycasting
*/

void			floor_init(t_ray *ray);
void			floor_raycasting(t_info *info, t_ray *ray, int x);

/*
**	raycasting_sub
*/

void			calculate_wall_distance(t_player *player, t_ray *ray);
void			calculate_wall_height(t_info *info, t_ray *ray);
void			get_wall_tex(t_player *player, t_ray *ray);
void			get_wall_color(t_info *info, t_ray *ray, int x);

/*
**	raycasting
*/

void			raycasting(t_info *info);
void			cast_floor_ceiling(t_info *info);
void			init_ray(t_info *info, t_player *player, t_ray *ray, int x);
void			calculate_step_direction(t_player *player, t_ray *ray);
void			perform_dda(t_info *info, t_ray *ray);

/*
**	set_info
*/

void			set_pos_spr(t_info *info, int i, int x, int y);
void			set_sprite(t_info *info);
void			set_dir(t_info *info);

/*
**	sprite_raycasting_sub
*/

void			translate_sprite(t_info *info, t_player *player,\
				t_spr_ray *s_ray, int i);
void			calculate_sprite_height(t_info *info, t_spr_ray *s_ray);
void			calculate_sprite_width(t_info *info, t_spr_ray *s_ray);
void			get_sprite_color(t_info *info, t_spr_ray *s_ray, int stripe);

/*
**	sprite_raycasting
*/

void			sprite_raycasting(t_info *info, t_player *player);
void			sort(t_info *info);
void			sort_sprite(t_info *info, t_player *player);

/*
**	start_game
*/

void			draw(t_info *info);
int				main_loop(t_info *info);
int				start_game(t_info *info);

/*
**	texture
*/

void			init_texture(t_info *info);
void			load_img(t_info *info, int *tex, char *path, t_img *img);
void			load_texture(t_info *info);

/*
**	utils
*/

int				ft_exit(int n);
void			print_error(int n, char *str, t_info *info);
void			skip_space(char **line);
void			free_2d(char **str);

#endif
