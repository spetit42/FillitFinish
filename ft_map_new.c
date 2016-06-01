/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:40:12 by vvenance          #+#    #+#             */
/*   Updated: 2016/05/26 15:40:15 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_create_tab(t_tetri *tab)
{
	int		i;
	int		tmp;
	int		size;
	t_map	*map;

	i = 1;
	while (tab[i].letter != 'a' && tab[i].letter < 'Z')
		i++;
	tmp = i;
	size = high_sqrt(i * 4);
	map = map_new(size);
	map->nbtetri = tmp;
	return (map);
}

int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->added = 0;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = (char *)ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}
