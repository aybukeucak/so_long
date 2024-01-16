/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybukeucak <aybukeucak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:20:41 by aybukeucak        #+#    #+#             */
/*   Updated: 2023/12/27 21:50:23 by aybukeucak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_explore(t_control *cntrl, char **map, int y, int x)
{
	if (map[y][x] == 'G' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		cntrl->is_exit_reachable = 1;
	else if (map[y][x] == 'C')
		cntrl->is_coins_reachable++;
	map[y][x] = 'G';
	map_explore(cntrl, map, y + 1, x);
	map_explore(cntrl, map, y - 1, x);
	map_explore(cntrl, map, y, x + 1);
	map_explore(cntrl, map, y, x - 1);
}

void	map_reachable(t_solong *game, int i, int map_size)
{
	char	**tmp_map;

	while (game->map[map_size])
		map_size++;
	tmp_map = (char **)malloc(sizeof(char *) * (map_size + 1));
	while (game->map[++i])
		tmp_map[i] = ft_strdup(game->map[i]);
	map_explore(&game->cntrl, tmp_map, game->p_y, game->p_x);
	if (!game->cntrl.is_exit_reachable)
		print_error("ERROR: Exit not reachable!",
			free_map(game->map, 1));
	if (game->cntrl.is_coins_reachable != game->cnt_coin)
		print_error("ERROR: Coin not reachable!",
			free_map(game->map, 1));
	i = -1;
	while (tmp_map[++i])
		free(tmp_map[i]);
	free(tmp_map);
}

void	map_check_counts(t_solong *game)
{
	if (game->cnt_player != 1)
		print_error("ERROR: Map must be only one player!",
			free_map(game->map, 1));
	if (game->cnt_coin <= 0)
		print_error("ERROR: Map must be a coin!",
			free_map(game->map, 1));
	if (game->cnt_exit != 1)
		print_error("ERROR: Map must be only one exit!",
			free_map(game->map, 1));
	game->cntrl.is_coins_reachable = 0;
	game->cntrl.is_exit_reachable = 0;
}

void	map_set_counts(t_solong *game, int x, int y)
{
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P' || game->map[y][x] == 'C'
				|| game->map[y][x] == 'E' || game->map[y][x] == '0'
				|| game->map[y][x] == '1')
			{
				if (game->map[y][x] == 'P')
				{
					game->p_y = y;
					game->p_x = x;
					game->cnt_player++;
				}
				if (game->map[y][x] == 'C')
					game->cnt_coin++;
				if (game->map[y][x] == 'E')
					game->cnt_exit++;
			}
			else
				print_error("ERROR: Map set count!", free_map(game->map, 1));
		}
	}
}

void	map_wall_control(t_solong *game, int x, int y)
{
	if (game->map[++y])
		while (game->map[y][++x])
			if (game->map[y][x] != '1')
				print_error("ERROR: Up wall!", free_map(game->map, 1));
	x = -1;
	while (game->map[game->height - 2][++x])
		if (game->map[game->height - 2][x] != '1')
			print_error("ERROR: Down wall!", free_map(game->map, 1));
	while (y <= game->height - 2 && game->map[y][0])
		if (game->map[y++][0] != '1')
			print_error("ERROR: Left wall!", free_map(game->map, 1));
	y = -1;
	while (++y <= game->height - 2 && game->map[y][game->width - 2])
		if (game->map[y][game->width - 2] != '1')
			print_error("ERROR: Right wall!", free_map(game->map, 1));
}
