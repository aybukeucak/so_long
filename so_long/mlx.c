/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybukeucak <aybukeucak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:21:27 by aybukeucak        #+#    #+#             */
/*   Updated: 2023/12/27 20:30:43 by aybukeucak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

void	set_textures(t_solong *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->p_front = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/front.xpm", &x, &y);
	game->p_back = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/back.xpm", &x, &y);
	game->p_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/right.xpm", &x, &y);
	game->p_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/left.xpm", &x, &y);
	game->background = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/background.xpm", &x, &y);
	game->coin = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/coin.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall.xpm", &x, &y);
	if (!game->mlx_ptr || !game->mlx_window || !game->p_front || !game->p_back
		|| !game->p_right || !game->p_left || !game->background
		|| !game->coin || !game->exit || !game->wall)
		print_error("ERROR: MLX: Set textures!", free_mlx(game, 1));
}

void	set_mlx(t_solong *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == 0)
		print_error("ERROR: MLX: Can't initializing!", 1);
	game->mlx_window = mlx_new_window(game->mlx_ptr,
			(game->width - 1) * IMG_SIZE,
			(game->height - 1) * IMG_SIZE, "Stardew Valley");
	if (game->mlx_window == 0)
		print_error("ERROR: MLX: Can't create window!", 1);
}
