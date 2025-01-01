#include "so_long.h"

t_ber_map	*new_map_from_file(char *filename)
{
	int			fd;
	char		*line;
	t_ber_map	*map;

	map = ft_calloc(1, sizeof(t_ber_map));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	while ((line = get_next_line(fd)))
	{
		if (!map->cols)
			map->cols = ft_strlen(line) - 1;
		ft_memcpy(line, map->grid[map->rows], map->cols);
		map->rows++;
		free(line);
	}
	close(fd);
	return (map);
}
