/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:06:10 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/20 07:25:29 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_map	map;

	printf("%d\n", argc);
	if (argc == 2)
	{
		printf("Exension okay)");
		ft_memset(&map, 0, sizeof(t_map));
		printf("Exension okay)");
		ft_check_ext(argv[1]);
		ft_map_init(argv[1], &map);
		printf("test 123 \n");
		ft_import_img(&map);
		ft_load_img(&map);
		map.mlx = mlx_init(1200, 1200, "So_Long", true);
		mlx_loop(map.mlx);
	}
	else
		ft_error(WRG_ARG);
	printf("Exension okay)");
	
}
