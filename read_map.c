/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:18:06 by jnicolas          #+#    #+#             */
/*   Updated: 2022/10/03 21:53:42 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	get_number_of_lines(char *path)
{
	int		fd;
	char	*line;
	int		number_of_lines;

	number_of_lines = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("Error: open file failure");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			number_of_lines++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (number_of_lines);
}

void	populate_map(int row, size_t column, int i, t_game *game)
{
	char	*line;

	line = get_next_line(game->map.fd);
	while (line != NULL)
	{
		game->map.map[row] = malloc((ft_strlen(line) + 1) * sizeof(char));
		while (line[i] != '\0')
			game->map.map[row][column++] = line[i++];
		game->map.map[row++][column] = '\0';
		i = 0;
		column = 0;
		free(line);
		line = get_next_line(game->map.fd);
	}
	game->map.map[row] = NULL;
}

void	map_display(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i] != NULL)
		printf("%s", game->map.map[i++]);
}

void	read_map(char *path, t_game *game)
{
	int		row;
	size_t	column;
	int		i;

	i = 0;
	row = 0;
	column = 0;
	game->map.number_of_lines = get_number_of_lines(path);
	game->map.path = path;
	game->map.map = malloc((game->map.number_of_lines + 1) * sizeof(char *));
	if (!(game->map.map))
		return ;
	game->map.fd = open(path, O_RDONLY);
	if (game->map.fd < 0)
		printf("did not open map");
	else
	{
		populate_map(row, column, i, game);
		close(game->map.fd);
	}
	map_display(game);
}
