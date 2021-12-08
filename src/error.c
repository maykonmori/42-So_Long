/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:10:22 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/07 21:11:56 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *s, int n)
{
	printf("ERROR: %s\n", s);
	exit(n);
}

void	error_cep(t_game *game)
{
	if (game->map.cont_player != 1)
	{
		free_vector(game);
		error("Invalid player quantity", EXIT_FAILURE);
	}
	if (game->map.exit < 1)
	{
		free_vector(game);
		error("There are no exit", EXIT_FAILURE);
	}
	if (game->map.collect < 1)
	{
		free_vector(game);
		error("There are no collect", EXIT_FAILURE);
	}
}

void	verify_arg(int argc)
{
	if (argc > 2)
		error("Too many arguments", EXIT_FAILURE);
	if (argc < 2)
		error("Have few arguments", EXIT_FAILURE);
}
