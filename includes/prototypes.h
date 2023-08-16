/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesmart <mdesmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:57:36 by mdesmart          #+#    #+#             */
/*   Updated: 2023/08/16 16:03:03 by mdesmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*****************************  GAME INITIATION  ******************************/

t_data	*ft_game_init(void);
void	ft_load_textures(t_data *game);

/***********************************  UTILS  **********************************/

void	ft_check_arg(int ac, char **av);
void	ft_free_tab(char **tab);
int		ft_quit(t_data *data);
void	ft_error(t_data *data, char *str);
int		ft_key(int key, t_data *game);
void	ft_position_cal(t_data *game, int forward, int strafe);
void	free_main(t_data	*game);
void	main_parsing_test(t_data	*game);

/***********************************  DRAW  ***********************************/

void	ft_draw_floor_ceiling(t_data *game);
int		ft_refresh_img(t_data *game);
void	ft_draw_map(t_data *game, char **map);
void	ft_render_player(t_data *game, int x, int y);
void	ft_mlx_pixel_put(t_data *game, int x, int y, int color);
void	ft_draw_fov(t_data *game);
void	ft_add_x_line(t_line *line, int x0, int x1, float degree);
void	ft_add_y_line(t_line *line, int y0, int y1, float degree);
void	ft_draw_3d(t_data *game);
float	ft_wall_position(t_point point, char face);
char	ft_wall_face(float x, float y);
void	print_line(t_data *game, t_display_line line);

/********************************  RAY CASTING  *******************************/

t_point	ft_wall_collision(t_data *game, t_line *line);
int		ft_ray_collision(t_data *game, int new_x, int new_y);
void	ft_draw_ray(t_data *game, t_line *line, int color, int scale);

/*********************************  GAMEPLAY  *********************************/

int		ft_check_collision(t_data *game, int new_x, int new_y);

/**********************************  PARSING  *********************************/

int		check_elements(t_parsing *parsed);
int		check_map(t_parsing *parsed);
void	fill_map(t_data	*game, char **av);
int		get_color_code(t_parsing *parsed, char *element, int size, int *color);
int		get_description(t_parsing *parsed, char **av);
int		get_elements(t_data *game, t_parsing *parsed);
int		get_map(t_data *game, t_parsing *parsed);
int		get_map_cardinal_limits(t_parsing *parsed);
int		get_player(t_data *game, t_parsing *parsed);
int		is_cardinal_point(char c);
int		is_map_symbol(char c);
int		is_whitespace(char c);
int		is_whitespace_or_end(char c);
int		parsing(t_data	*game, char **av);

#endif