/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:10:19 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/20 08:21:06 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft/libft.h"
# include "get_next_line.h"
# include "../includes/MLX42/include/MLX42/MLX42.h"
# include "stdlib.h"
# include "fcntl.h"

// ERROR MESSAGE
# define INVALID_CHAR "Error : undefined character"
# define TOOMANY_CHAR "Error : Too many player instance."
# define WALL_ERROR "Error : No wall"
# define TOO_MANY_EXIT "Error : Too many exit."
# define WRONG_EXT "Error : Wrong file extension."
# define IMG_ERR "Error loading images."
# define WRG_ARG "Wrong number of argument."

// IMAGE
# define PLAYER_IMG "../ressources/frog.xpm42"
# define WALL_IMG "../ressources/wall.xpm42"
# define BG_IMG "../ressources/background.xpm42"
# define COL_IMG "../ressource/tacos.xpm42"
# define EXIT_IMG "../ressource/Lily_Pad.xpm42"

typedef struct s_img {
	void	*player;
	xpm_t	*t_player;
	void	*wall;
	xpm_t	*t_wall;
	void	*exit;
	xpm_t	*t_exit;
	void	*background;
	xpm_t	*t_background;
	void	*collectible;
	xpm_t	*t_collectible;
}			t_img;

typedef struct s_mlx
{
	void		*mlx;
}				t_mlx;

typedef struct s_map{
	mlx_t			*mlx;
	t_img			*img;
	mlx_image_t		*mlximg;
	int				collectible;
	int				player;
	int				exit;
	int				width;
	int				height;
	int				x;
	int				y;
	int				step;
	char			*stringmap;	
}				t_map;
// MAP RELATED

void	read_map(char *file, t_map *map);
void	ft_map_init(char *file, t_map *map);
void	ft_check_ext(char *file);
void	ft_import_img(t_map *map);
void	ft_load_img(t_map *map );
void	print_img(t_map *map);
#endif 

// PROGRAM MANAGEMENT