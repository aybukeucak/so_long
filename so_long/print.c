/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybukeucak <aybukeucak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:21:29 by aybukeucak        #+#    #+#             */
/*   Updated: 2023/12/27 19:40:20 by aybukeucak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

void	print_game_image(t_solong *game, int x, int y)
{
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			mlx_put_image_to_window(game->mlx_ptr,
				game->mlx_window, game->background,
				x * IMG_SIZE, y * IMG_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
					game->wall, x * IMG_SIZE, y * IMG_SIZE);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr,
					game->mlx_window, game->exit,
					x * IMG_SIZE, y * IMG_SIZE);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr,
					game->mlx_window, game->coin,
					x * IMG_SIZE, y * IMG_SIZE);
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->p_way,
		game->p_x * IMG_SIZE, game->p_y * IMG_SIZE);
}
