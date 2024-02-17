/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:39:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/17 13:23:37 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include "errors.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>



//**********************************************//
//					DEFINES						//
//**********************************************//

# define BUFFER_SIZE 100


//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_raycast
{
	// double	camera;
	// double	diray_x;
	// double	diray_y;
	// int		map_x;
	// int		map_y;
	// double	side_dist_x;
	// double	side_dist_y;
	// double	delta_dist_x;
	// double	delta_dist_y;
	// double	ray_length;
	// int		step_x;
	// int		step_y;
	// int		hit;
	// int		side;
	// int		line_height;
	// double	wall_x;
	// int		tex_x;
	// double	step;
	// double	tex_pos;
	// int		draw_start;
	// int		draw_end;
}			t_raycast;

typedef struct s_game
{
	double	player_pos_x;
	double	player_pos_y;
	double	player_ori_x;
	double	player_ori_y;
	double	plane_x; //
	double	plane_y; //
	
	// double	cur_time;
	// double	old_time;
	// int		key_w;
	// int		key_s;
	// int		key_a;
	// int		key_d;
	// int		key_right;
	// int		key_left;
	// int		texture;
}			t_game;

typedef struct s_image
{
	void	*mlx_img;	// rename
	char	*addr;		// rename
	int		bpp;		// rename
	int		rowlen;		// rename
	int		end;		// rename
	int		img_height;
	int		img_width;
}			t_image;

typedef struct s_texture
{
	// t_image	*no; // rename
	// t_image	*so; // rename
	// t_image	*we; // rename
	// t_image	*ea; // rename
}			t_texture;

typedef struct s_e_scene
{
	int		no;
	int		so;
	int		ea;
	int		we;
	int		f;
	int		c;
}			t_e_scene;

typedef struct s_data
{
	
	t_error		*error;
	
	void		*mlx;
	void		*win;
	int			window_x; // a supp
	int			window_y; // a supp
	t_game		*game;
	t_raycast	*raycast;
	char		**scene;
	char		**f_scene;
	char		**f2_scene;
	char		**map;
	int			map_height;
	int			map_width;
	int			scene_height;
	t_e_scene	*e_scene;
	int			rgb_floor[3];
	int			rgb_ceiling[3];
	t_image		images[4];
	
	// t_img		*mini_img;
	// t_img		*img;
	// int			mouse_x;
	// int			fc;
	// double		rotation_speed;
	// int			mouse_active;
	// int			run;
	// double		movespeed;
}			t_data;


//**********************************************//
//					PROTOTYPES					//
//**********************************************//

//---------------   cub3D.c   ------------------//

int		main(int argc, char **argv);

//**********************************************//
//					PARSING						//
//**********************************************//

//**********************************************//
//					INIT						//
//**********************************************//

//---------------   init_data.c   --------------//
bool	init_data(t_data *data);

//---------------   init_game.c   --------------//
bool	init_game(t_data *data);
bool	get_player_pos(t_data *data);
void	get_first_orientation(t_data *data, char c);
void	get_first_orientation_two(t_data *data, char c);

//---------------   init_images.c   ------------//
bool	init_images(t_data *data);
bool	init_image(t_data *data, int i);
bool	clean_nl_scene(t_data *data);

//**********************************************//
//					PARSER						//
//**********************************************//

//---------------   map.c   --------------------//
bool	get_map(t_data *data);
void	get_map_size(t_data *data);
void	resize_map(t_data *data);

//---------------   parse_map.c   --------------//
bool	parse_map(t_data *data);
bool	check_map_char(t_data *data);
bool	is_map_char(char c, char *set);
bool	one_start_pos(t_data *data);
bool	char_is_in_set(char c, char *set);

//---------------   parse_scene.c   ------------//
bool	parse_scene(t_data *data);
bool	path_is_xpm(char *path);
bool	check_rgb(char *rgb, t_data *data, int fc);

//---------------   parsing.c   ----------------//
bool	parsing(int argc, char **argv, t_data *data);
bool	check_args(int argc, char **argv, t_data *data);
bool	is_cub(char **argv);

//---------------   rgb.c   --------------------//
bool	count_comma(char *str);
bool	rgb_format(char *str);
bool	rgb_value(char *str, t_data *data, int fc);
bool 	save_rgb_value(char *str, t_data *data, int rgb, int fc);
bool	correct_rgb_value(t_data *data);

//---------------   scene.c   ------------------//
bool	get_data_scene(char *scene_path, t_data *data);
int		scene_len(char *scene_path, t_data *data);
bool	get_scene(int fd, t_data *data);
void	clean_scene(t_data *data);
bool	remove_map_from_scene(t_data *data);

//---------------   sort_scene.c   -------------//
bool	sort_scene(t_data *data);
char 	**sort_scene_2(t_data *data);
bool	all_identifiants(t_data *data);

//---------------   wall.c   -------------------//
bool	closed_by_wall(t_data *data);
bool	no_void_around(t_data *data, char *to_replace);
bool	test_around(char **map, int y, int x, char *to_replace);
bool	is_start_pos(char c, char *str);


//**********************************************//
//					UTILS						//
//**********************************************//

//---------------   digit.c   ------------------//
bool	only_digit_or_comma(char *str);
// bool	only_digit(char *str);
bool	is_digit(char c);

//---------------   free.c   -------------------//
void 	free_all(t_data *data);
void	free_mlx(t_data *data);
void	free_map(t_data *data);
void 	exit_all(t_data *data); 
void	free_data(t_data *data);
void	free_scene(t_data *data);
void	free_map_scene(t_data *data);

//---------------   get_next_line.c   ----------//
char	*get_next_line(int fd);
char	*merge_stash_and_buff(char *stash, char *buff);
char	*buff_to_stash(char *buff);
bool	search_newline(const char *buff);
char	*stash_to_line(char *stash, char *buf);

//---------------	print.c			 ----------//

void	parsing_msg_error(t_error *error);
void	ft_putstr(char *str, int fd);

//---------------	libft.c			  ----------//

int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

//---------------	scene_utils.c ----------//

bool	line_is_empty(char *str);


//**********************************************//
//					EXEC						//
//**********************************************//

// dev
void	print_scene(char **scene);
void	print_map(char **map);
void	print_rgb(t_data *data);
void	print_img(t_data *data);

#endif