/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:28:43 by vvenance          #+#    #+#             */
/*   Updated: 2016/05/26 15:28:48 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			ft_putchar(map->array[x][y]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

t_map	*ft_enlarge_map(int size, t_map *map)
{
	int tmp;

	tmp = map->nbtetri;
	map = map_new(size);
	map->nbtetri = tmp;
	return (map);
}

t_map	ft_remove_tetri(t_map map, char letter)
{
	int x;
	int y;

	y = 0;
	while (y < map.size)
	{
		x = 0;
		while (x < map.size)
		{
			if (map.array[x][y] == letter)
				map.array[x][y] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

int		check_full_map(t_tetri *tab, t_map map)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 26 && tab[i].letter == 'a')
	{
		y = 0;
		while (map.array[x][y] != tab[i].letter && y < map.size)
		{
			x = 0;
			while (map.array[x][y] != tab[i].letter && x < map.size)
				x++;
			y++;
		}
		if (map.array[x][y] == tab[i].letter)
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_is_in_map(char **map, t_tetri tab, int sizemax)
{
	int x;
	int y;

	y = 0;
	while (y < sizemax)
	{
		x = 0;
		while (x < sizemax)
		{
			if (map[x][y] == tab.letter)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
