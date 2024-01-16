/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybukeucak <aybukeucak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:19:30 by ayucak            #+#    #+#             */
/*   Updated: 2023/12/27 21:31:16 by aybukeucak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_ber_control(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'r' && str[i - 2] == 'e'
			&& str[i - 3] == 'b' && str[i - 4] == '.'))
		print_error("ERROR: File extension must be .ber !", 1);
}

static void	map_new_split(t_solong *game, char *map_last,
	char *map_line)
{
	game->map = ft_split(map_last, '\n');
	if (!game->map)
	{
		free(map_line);
		print_error("ERROR: Map create error!", 1);
	}
	free(map_line);
}

void	map_new_create(t_solong *game, int fd,
	char *map_line, char *line)
{
	char	*map_last;

	game->width = (int)ft_strlen(line);
	map_last = ft_strdup("");
	while (line)
	{
		if (game->width != (int)ft_strlen(line))
			print_error("ERROR: Map not rectangle!", 1);
		game->height++;
		map_line = ft_strjoin(map_last, line);
		free(line);
		free(map_last);
		map_last = map_line;
		line = get_next_line(fd);
	}
	map_new_split(game, map_last, map_line);
}
