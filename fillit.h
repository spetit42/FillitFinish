/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:44:06 by vvenance          #+#    #+#             */
/*   Updated: 2016/05/28 16:11:42 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define _X0 tab.position[0].x
# define _Y0 tab.position[0].y
# define _X1 tab.position[1].x
# define _Y1 tab.position[1].y
# define _X2 tab.position[2].x
# define _Y2 tab.position[2].y
# define _X3 tab.position[3].x
# define _Y3 tab.position[3].y
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"
# include <stdlib.h>

typedef struct	s_place
{
	int x;
	int y;
}				t_place;

typedef struct	s_tetri
{
	t_place		position[4];
	int			height;
	int			width;
	char		letter;
}				t_tetri;

typedef struct	s_pts
{
	int			i;
	int			j;
	int			k;
	int			l;
	int			m;
	int			n;
}				t_pts;

typedef struct	s_map
{
	int			size;
	int			added;
	int			nbtetri;
	char		**array;
}				t_map;

void			ft_check_and_parse(char **argv, t_tetri *tab, char lettre,
				int *coor);
void			ft_null_table(t_tetri *tab);
t_pts			ft_initialize(void);
t_tetri			ft_check_tetri(t_tetri tab, char *buff);
int				ft_check_diese(char *buff, int position);
t_tetri			ft_get_place(int place, t_tetri tab, int i);
t_tetri			*ft_list_push_left(t_tetri *tab);
t_tetri			ft_get_height_and_width(t_tetri tab);
void			ft_push(t_place *position, int left);
void			ft_exit(void);
void			ft_usage(void);
t_map			*ft_create_tab(t_tetri *tab);
int				high_sqrt(int n);
t_map			*map_new(int size);
void			free_map(t_map *map);
void			ft_recursive(t_map *map, t_tetri *tab);
t_map			*ft_enlarge_map(int size, t_map *map);
int				ft_fill_map(t_map map, t_tetri *tab, int nbtetri, int i);
int				ft_fill_map2 (t_map *map, int i, t_tetri *tab, int nbtetri);
t_map			ft_remove_tetri(t_map map, char letter);
int				check_full_map(t_tetri *tab, t_map map);
t_map			ft_place(int y, int x, t_tetri tab, t_map map);
int				ft_is_in_map(char **map, t_tetri tab, int sizemax);
void			print_map(t_map *map);
int				check_and_add(char *buff, int coor, t_tetri *tab, char lettre);

#endif
