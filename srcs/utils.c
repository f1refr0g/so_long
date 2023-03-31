/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:31:11 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/31 03:49:18 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Str join that remove the \n at the end and not remalloc over.
char	*ft_strjoinf(char *s1, char *s2, int flag)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	s = ft_malloc(len + i + 1, sizeof * s);
	if (!s)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		s[len + i] = s2[i];
	if (flag == 1)
		free(s1);
	return (s);
}

//Free loaded xpm
void	ft_destroy(t_map *map)
{
	mlx_delete_xpm42(map->img->t_wall);
	mlx_delete_xpm42(map->img->t_bg);
	mlx_delete_xpm42(map->img->t_collectible);
	mlx_delete_xpm42(map->img->t_exit);
	mlx_delete_xpm42(map->player->tp);
}

//Function to properly free everything and close the program.
void	ft_exit(t_map *map)
{
	ft_destroy(map);
	free(map->player);
	free(map->img);
	free(map->sm);
	mlx_terminate(map->mlx);
	mlx_close_window(map->mlx);
	exit(0);
}
