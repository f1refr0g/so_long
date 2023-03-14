/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:10:19 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/14 19:50:15 by abeaudet         ###   ########.fr       */
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
# define PLAYER_IMG "../ressources/frog.png"
# define PLAYER 0
# define WALL_IMG "../ressources/wall.png"
# define WALL 1
# define BG_IMG "../ressources/background.png"
# define BG 2
# define COL_IMG "../ressource/tacos.png"
# define TACOS 3
# define EXIT_IMG "../ressource/Lily_Pad.png"
#define EXIT 4

typedef struct s_img {
	void	*player;
	mlx_texture_t *t_player;
	void	*wall;
	mlx_texture_t *t_wall;
	void	*exit;
	mlx_texture_t *t_exit;
	void	*background;
	mlx_texture_t *t_background;
	void	*collectible;
	mlx_texture_t *t_collectible;
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
mlx_texture_t	**ft_import_img(void);
void	ft_load_img(t_map *map, mlx_texture_t **img);
void	print_img(t_map *map);
#endif 

// PROGRAM MANAGEMENT