/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybukeucak <aybukeucak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:20:55 by aybukeucak        #+#    #+#             */
/*   Updated: 2023/12/27 19:39:33 by aybukeucak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

int	close_game(t_solong *game)
{
	ft_printf("Dayyyuuuummmm\n");
	free_mlx(game, 1);
	exit(0);
	return (0);
}

void	move_player(t_solong *game, int x, int y)
{
	char	*step;

	step = ft_itoa(game->step_cnt);
	if (game->map[game->p_y + y][game->p_x + x] == '1')
	{
		free(step);
		return ;
	}
	game->p_y += y;
	game->p_x += x;
	game->step_cnt++;
	if (game->map[game->p_y][game->p_x] == 'C')
		game->cnt_coin--;
	if (game->map[game->p_y][game->p_x] != 'E')
		game->map[game->p_y][game->p_x] = '0';
	if (game->map[game->p_y][game->p_x] == 'E' && game->cnt_coin == 0)
	{
		ft_printf("You Won!\n");
		free_mlx(game, 0);
		exit(0);
	}
	print_game_image(game, -1, -1);
	mlx_string_put(game->mlx_ptr, game->mlx_window,
		10, 15, 0xfb00ff, step);
	free(step);
}

int	move(int key, t_solong *game)
{
	if (key == ESC)
		close_game(game);
	else if (key == W || key == UP)
	{
		game->p_way = game->p_back;
		move_player(game, 0, -1);
	}
	else if (key == S || key == DOWN)
	{
		game->p_way = game->p_front;
		move_player(game, 0, 1);
	}
	else if (key == A || key == LEFT)
	{
		game->p_way = game->p_left;
		move_player(game, -1, 0);
	}
	else if (key == D || key == RIGHT)
	{
		game->p_way = game->p_right;
		move_player(game, 1, 0);
	}
	ft_printf("number of movements = [%d]\n", game->step_cnt);
	return (0);
}
