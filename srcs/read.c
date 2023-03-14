/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:27:41 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/14 18:29:22 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("Invalid FD");
	line = get_next_line(fd);
	// map->height = 0;
	map->width = ft_strlen(line) - 1;
	printf("\nwidth : %d\n", map->width);
	map->stringmap = ft_strdup_nonl(line);
		free(line);
	while (line)
	{
		map->height++;
		line = get_next_line(fd);
		if (line)
		{
			map->stringmap = ft_strjoin_nonl(map->stringmap, line);
			free(line);
		}
	}
	close (fd);
	printf("\n Hauteur : %d\n", map->height);
	printf("\n Stringmap : %d\n", (int)ft_strlen(map->stringmap));
	printf("\n Stringmap \n%s\n", map->stringmap);
	free (line);
}
