/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:34:53 by vvenance          #+#    #+#             */
/*   Updated: 2016/05/26 15:34:55 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_list_push_left(t_tetri *tab)
{
	int i;
	int j;
	int less;

	i = 0;
	while (tab[i].letter != 'a' && i < 26)
	{
		j = 0;
		less = 5;
		while (j < 4)
		{
			if (tab[i].position[j].x < less)
				less = tab[i].position[j].x;
			j++;
		}
		ft_push(tab[i].position, less);
		tab[i] = ft_get_height_and_width(tab[i]);
		i++;
	}
	return (tab);
}

void	ft_push(t_place *position, int left)
{
	int i;
	int top;

	i = 0;
	top = 4;
	while (i < 4)
	{
		position[i].x = (position[i].x - left);
		if (position[i].y < top)
			top = position[i].y;
		i++;
	}
	i = 0;
	if (top > 0)
	{
		while (i < 4)
		{
			position[i].y = (position[i].y - top);
			i++;
		}
	}
}

void	ft_exit(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	ft_null_table(t_tetri *tab)
{
	int i;
	int j;

	i = 0;
	while (i < 26)
	{
		tab[i].letter = 'a';
		tab[i].width = 0;
		tab[i].height = 0;
		j = 0;
		while (j < 4)
		{
			tab[i].position[j].x = 9;
			tab[i].position[j].y = 9;
			j++;
		}
		i++;
	}
}

t_pts	ft_initialize(void)
{
	t_pts pt;

	pt.i = -1;
	pt.j = 0;
	pt.k = 0;
	pt.l = 0;
	pt.m = 0;
	pt.n = 0;
	return (pt);
}
