/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:49:02 by jnicolas          #+#    #+#             */
/*   Updated: 2022/10/03 17:51:30 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_map(t_game *game)
{
	game->win_height = data->map.line_count * IMG_SIZE;
	game->win_width = ((ft_strlen(game->map.map[0] - 1) * IMG_SIZE));
	game->img.height = IMG_SIZE;
	game->img.width = IMG_SIZE:
}
