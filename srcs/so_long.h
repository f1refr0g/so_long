/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:10:19 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/31 03:47:33 by abeaudet         ###   ########.fr       */
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
# define INVALID_CHAR "Error : undefined character\n"
# define TOOMANY_CHAR "Error : Too many player instance.\n"
# define WALL_ERROR "Error : No wall\n"
# define TOO_MANY_EXIT "Error : Too many exit.\n"
# define WRONG_EXT "Error : Wrong file extension.\n"
# define IMG_ERR "Error loading images\n."
# define WRG_ARG "Wrong number of argument.\n"

// IMAGE
# define PLAYER_IMG "./ressources/frog.xpm42"
# define WALL_IMG "./ressources/wall.xpm42"
# define BG_IMG "./ressources/background.xpm42"
# define COL_IMG "./ressources/tacos.xpm42"
# define EXIT_IMG "./ressources/Lily_Pad.xpm42"

// MOVEMENT
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3

typedef struct s_img {
	mlx_image_t	*wall;
	xpm_t		*t_wall;
	mlx_image_t	*exit;
	xpm_t		*t_exit;
	mlx_image_t	*bg;
	xpm_t		*t_bg;
	mlx_image_t	*collectible;
	xpm_t		*t_collectible;
}			t_img;

typedef struct s_player {
	mlx_image_t	*player;
	xpm_t		*tp;
	int			x;
	int			y;
}			t_tp;

typedef struct s_vector2 {
	int	x;
	int	y;
}			t_vector2;

typedef struct s_map{
	mlx_t			*mlx;
	t_img			*img;
	t_tp			*player;
	int				collectible;
	int				playercount;
	int				exit;
	int				width;
	int				height;
	int				x;
	int				y;
	int				step;
	char			*sm;	
}				t_map;
// MAP RELATED

void	read_map(char *file, t_map *map);
void	ft_map_init(char *file, t_map *map);
void	ft_check_ext(char *file);
void	ft_import_img(t_map *map);
void	ft_load_img(t_map *map );
void	print_img(t_map *map);
void	movement(mlx_key_data_t keydata, void *param);
int		check_pos(t_map *map, int direction);
void	collect(t_map *map);
char	*ft_strjoinf(char *s1, char *s2, int flag);
void	ft_move(t_map *map, char axis, int dst);
void	simulate_map(t_map *map);
void	flood(char *sm, t_vector2 size, t_vector2 pos);
void	lookstring(char	*sm);
void	flood2(char *sm, t_vector2 size, t_vector2 pos);
void	ft_destroy(t_map *map);
void	ft_exit(t_map *map);

#endif 