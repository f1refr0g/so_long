/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:27:41 by abeaudet          #+#    #+#             */
/*   Updated: 2023/04/12 05:21:31 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Read the map and store it in a string
void	read_map(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("Invalid FD");
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	map->sm = ft_strdup(line);
	map->sm[ft_strlen(map->sm) - 1] = '\0';
	free(line);
	while (line && line[0] != '\n')
	{
		map->height++;
		line = get_next_line(fd);
		if (line)
		{
			map->sm = ft_strjoinf(map->sm, line, 1);
			map->sm[ft_strlen(map->sm) - 1] = '\0';
			free(line);
		}
	}
	close (fd);
}

void	ft_checkchar(t_map *map)
{
	char	*string;

	string = map->sm;
	while (*string != '\0')
	{
		if (*string != '1' && *string != 'C' && *string
			!= '0' && *string != 'E' && *string != 'P')
			ft_error("Invalid map\n");
		string++;
	}
	map->step = 0;
}
