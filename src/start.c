/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:20:52 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/07 21:23:00 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_vars(t_game *game)
{
	game->count_move = 0;
	game->map.collect = 0;
	game->map.exit = 0;
	game->map.end_game = 0;
	game->map.cont_player = 0;
}

int	start_game(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, \
	game->map.count_column * 30, game->map.count_line * 30, "So Long");
	game->hero.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/knight_right.xpm", &game->hero.width, &game->hero.height);
	game->floor.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/floor.xpm", &game->floor.width, &game->floor.height);
	game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/wall.xpm", &game->wall.width, &game->wall.height);
	game->coins.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/coins.xpm", &game->coins.width, &game->coins.height);
	game->exit.img = mlx_xpm_file_to_image(game->vars.mlx, \
	"./assets/sprites/exit.xpm", &game->exit.width, &game->exit.height);
	return (0);
}

void	start_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->hero.img, game->map.player.x * 30, \
				game->map.player.y * 30);
			}
			x++;
		}
		y++;
	}
}

void	second_plain(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->coins.img, x * 30, y * 30);
			}
			if (game->map.map[y][x] == 'E')
			{
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->exit.img, x * 30, y * 30);
			}
			x++;
		}
		y++;
	}
}
