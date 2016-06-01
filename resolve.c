/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:24:31 by vvenance          #+#    #+#             */
/*   Updated: 2016/05/26 15:26:22 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_recursive(t_map *map, t_tetri *tab)
{
	int i;

	i = 0;
	while (i < 26 && tab[i].letter != 'a')
		i++;
	if (ft_fill_map(*map, tab, (i - 1), -1) == 1)
	{
		print_map(map);
		free_map(map);
	}
	else
	{
		map = ft_enlarge_map(map->size + 1, map);
		ft_recursive(map, tab);
	}
}

int		ft_fill_map(t_map map, t_tetri *tab, int nbtetri, int i)
{
	int x;
	int y;

	y = 0;
	i++;
	while (y < map.size)
	{
		x = 0;
		while (x < map.size)
		{
			map = ft_place(y, x, tab[i], map);
			if (ft_fill_map2(&map, i, tab, nbtetri) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_fill_map2(t_map *map, int i, t_tetri *tab, int nbtetri)
{
	int rtrn;

	if (map->added == 1)
	{
		map->added = 0;
		if (i != nbtetri)
		{
			rtrn = ft_fill_map(*map, tab, nbtetri, i);
			if (rtrn == 1)
				return (1);
			else
				ft_remove_tetri(*map, tab[i].letter);
		}
		else if (check_full_map(tab, *map) == 1)
			return (1);
	}
	return (0);
}

t_map	ft_place(int y, int x, t_tetri tab, t_map map)
{
	if (ft_is_in_map(map.array, tab, map.size) != 1)
	{
		if (x + tab.width > map.size || y + tab.height > map.size)
			return (map);
		if (!(x + _X0 <= map.size && y + _Y0 <= map.size &&
			map.array[x + _X0][y + _Y0] == '.'))
			return (map);
		if (!(x + _X1 <= map.size && y + _Y1 <= map.size &&
			map.array[x + _X1][y + _Y1] == '.'))
			return (map);
		if (!(x + _X2 <= map.size && y + _Y2 <= map.size &&
			map.array[x + _X2][y + _Y2] == '.'))
			return (map);
		if (!(x + _X3 <= map.size && y + _Y3 <= map.size &&
			map.array[x + _X3][y + _Y3] == '.'))
			return (map);
		map.array[x + _X0][y + _Y0] = tab.letter;
		map.array[x + _X1][y + _Y1] = tab.letter;
		map.array[x + _X2][y + _Y2] = tab.letter;
		map.array[x + _X3][y + _Y3] = tab.letter;
	}
	map.added = 1;
	return (map);
}
