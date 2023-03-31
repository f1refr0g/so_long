/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:31:11 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/31 02:56:08 by abeaudet         ###   ########.fr       */
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

//Cleaning texture
void	ft_destroy(t_map *map)
{
	mlx_delete_texture(&map->img->t_bg->texture);
	mlx_delete_texture(&map->img->t_collectible->texture);
	// mlx_delete_texture(map->img->t_exit);
	mlx_delete_texture(&map->img->t_exit->texture);
	mlx_delete_texture(&map->img->t_wall->texture);
	// mlx_delete_texture(map->img->tp);
	mlx_delete_texture(&map->player->tp->texture);
}