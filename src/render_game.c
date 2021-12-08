/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:16:47 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/07 21:18:31 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->wall.img, x * 30, y * 30);
			else
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->floor.img, x * 30, y * 30);
			x++;
		}
		y++;
	}
	if (game->count_move == 0)
	{
		start_player(game);
	}
	second_plain(game);
}

int	render_game(t_game *game)
{
	render_map(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->hero.img, \
	game->map.player.x * 30, game->map.player.y * 30);
	return (0);
}
