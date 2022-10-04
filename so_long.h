#ifndef SO_LONG_LIB_H
# define SO_LONG_LIB_H

# include <mlx.h>
# include <stdio.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"

typedef struct s_map
{
	int		number_of_lines;
	char	**map;
	char	*path;
	int		fd;

} t_map;
typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		height;
	int		width;
}	t_game;

void	read_map(char *path, t_game *game);
#endif
