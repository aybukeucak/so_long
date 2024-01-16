/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybukeucak <aybukeucak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:21:32 by aybukeucak        #+#    #+#             */
/*   Updated: 2023/12/27 19:38:38 by aybukeucak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define IMG_SIZE 100
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

typedef struct s_control
{
	int	is_exit_reachable;
	int	is_coins_reachable;
}	t_control;

typedef struct s_solong
{
	void		*mlx_ptr;
	void		*mlx_window;
	void		*p_way;
	void		*p_front;
	void		*p_back;
	void		*p_right;
	void		*p_left;
	void		*wall;
	void		*background;
	void		*coin;
	void		*exit;
	char		**map;
	int			width;
	int			height;
	int			cnt_player;
	int			cnt_coin;
	int			cnt_exit;
	int			step_cnt;
	int			p_x;
	int			p_y;
	t_control	cntrl;
}	t_solong;

void	print_error(char *str, int err_num);
void	map_ber_control(char *str);
void	map_new_create(t_solong *game, int fd,
			char *map_line, char *map_last);
int		free_map(char **line, int exit_num);
int		free_mlx(t_solong *game, int exit_num);
void	map_wall_control(t_solong *game, int x, int y);
void	map_set_counts(t_solong *game, int x, int y);
void	map_check_counts(t_solong *game);
void	map_reachable(t_solong *game, int i, int map_size);
void	set_mlx(t_solong *game);
void	set_textures(t_solong *game);
void	print_game_image(t_solong *game, int x, int y);
int		close_game(t_solong *game);
int		move(int key, t_solong *game);

#endif
