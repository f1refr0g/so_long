/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:27:41 by abeaudet          #+#    #+#             */
/*   Updated: 2023/04/17 15:26:07 by abeaudet         ###   ########.fr       */
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
		ft_error("Error : Invalid FD.\n");
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
			if (map->sm[ft_strlen(map->sm) - 1] == '\n')
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
	while (*string)
	{
		if (*string != '1' && *string != 'C' && *string
			!= '0' && *string != 'E' && *string != 'P')
			ft_error(MAP_ERR);
		string++;
	}
	map->step = 0;
}

void	check_ll(t_map *map, char *file)
{
	int		fd;
	char	*checker;

	fd = open(file, O_RDONLY);
	checker = get_next_line(fd);
	while (checker[ft_strlen(checker)] == '\n')
	{
		if (((int)ft_strlen(checker)) != map->width)
		{
			ft_error(MAP_ERR);
			if (checker[0] == '\n' && (int)ft_strlen(checker) != map->width)
				ft_error(MAP_ERR);
		}
		free (checker);
		checker = get_next_line(fd);
	}
	free (checker);
}
