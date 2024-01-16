/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybukeucak <aybukeucak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:20:53 by aybukeucak        #+#    #+#             */
/*   Updated: 2023/12/27 19:38:56 by aybukeucak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

int	free_map(char **line, int exit_num)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
	return (exit_num);
}

int	free_mlx(t_solong *game, int exit_num)
{
	if (game->p_front)
		mlx_destroy_image(game->mlx_ptr, game->p_front);
	if (game->p_back)
		mlx_destroy_image(game->mlx_ptr, game->p_back);
	if (game->p_right)
		mlx_destroy_image(game->mlx_ptr, game->p_right);
	if (game->p_left)
		mlx_destroy_image(game->mlx_ptr, game->p_left);
	if (game->background)
		mlx_destroy_image(game->mlx_ptr, game->background);
	if (game->coin)
		mlx_destroy_image(game->mlx_ptr, game->coin);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->mlx_window)
		mlx_destroy_window(game->mlx_ptr, game->mlx_window);
	free_map(game->map, exit_num);
	return (exit_num);
}
