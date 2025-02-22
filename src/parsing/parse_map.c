#include "../../include/cub3d.h"

static size_t	get_map_rows(const char *file_name)
{
	int		fd;
	char	*line;
	size_t	rows;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_panic(file_name);
	rows = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
		free(line);
	}
	close(fd);
	return (rows);
}

char	**parse_map(const char *file_name)
{
	int		fd;
	char	**map;
	size_t	rows;
	size_t	i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_panic(file_name);
	rows = get_map_rows(file_name);
	map = ft_calloc(rows + 1, sizeof(char *));
	if (!map)
		ft_panic("malloc");
	i = 0;
	while (i < rows + 1)
		map[i++] = get_next_line(fd);
	close(fd);
	return (map);
}
