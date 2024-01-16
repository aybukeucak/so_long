/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybukeucak <aybukeucak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:20:59 by aybukeucak        #+#    #+#             */
/*   Updated: 2023/12/27 19:51:10 by aybukeucak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <fcntl.h>

static void	map_controls(t_solong *game, char **av)
{
	int		fd;
	char	*line;

	map_ber_control(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("ERROR: File not opened!", 1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		print_error("ERROR: Empty map!", 1);
	}
	map_new_create(game, fd, NULL, line);
	map_wall_control(game, -1, -1);
	map_set_counts(game, -1, -1);
	map_check_counts(game);
	map_reachable(game, -1, 0);
}

int	main(int ac, char **av)
{
	t_solong	game;

	if (ac != 2)
		print_error("ERROR: Argument count error!", 1);
	game.cnt_player = 0;
	game.cnt_coin = 0;
	game.cnt_exit = 0;
	game.step_cnt = 0;
	game.height = 1;
	map_controls(&game, av);
	set_mlx(&game);
	set_textures(&game);
	game.p_way = game.p_front;
	print_game_image(&game, -1, -1);
	mlx_hook(game.mlx_window, ON_KEYDOWN, 0, move, &game);
	mlx_hook(game.mlx_window, ON_DESTROY, 0, close_game, &game);
	mlx_loop(game.mlx_ptr);
}
