/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:09:50 by vvenance          #+#    #+#             */
/*   Updated: 2016/05/28 15:58:36 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_and_parse(char **argv, t_tetri *tab, char lettre, int *coor)
{
	int		fd;
	int		boolean;
	char	buff[22];

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit();
	ft_null_table(tab);
	if ((coor[0] = read(fd, buff, 21)) == 0)
		ft_exit();
	else
		boolean = check_and_add(buff, coor[1]++, tab, lettre++);
	while (coor[0] > 0)
	{
		ft_memset(buff, '\0', sizeof(buff));
		if (lettre > 'Z')
			ft_exit();
		if ((coor[0] = read(fd, buff, 21)) > 0)
			boolean = check_and_add(buff, coor[1]++, tab, lettre++);
	}
	if (boolean || coor[0] == -1)
		ft_exit();
	tab = ft_list_push_left(tab);
}

t_tetri	ft_check_tetri(t_tetri tab, char *buff, t_pts pt)
{
	while (buff[++pt.i] != '\0')
	{
		if (buff[pt.i] == '.')
			pt.j++;
		else if (buff[pt.i] == '#')
		{
			pt.m = (pt.m + ft_check_diese(buff, pt.i));
			tab = ft_get_place(pt.i, tab, pt.n);
			pt.k++;
			pt.n++;
		}
		else if (buff[pt.i] == '\n')
		{
			if (buff[pt.i] == '\n' && buff[pt.i - 1] != '\n' && (pt.i % 5) != 4)
				ft_exit();
			pt.l++;
		}
		else
			ft_exit();
	}
	if (pt.j != 12 || pt.k != 4 || pt.l < 4 || pt.m < 6)
		ft_exit();
	return (tab);
}

int		ft_check_diese(char *buff, int position)
{
	int touch;

	touch = 0;
	if (buff[position + 1] == '#')
		touch++;
	if (buff[position - 1] == '#')
		touch++;
	if (buff[position + 5] == '#')
		touch++;
	if (buff[position - 5] == '#')
		touch++;
	return (touch);
}

t_tetri	ft_get_place(int place, t_tetri tab, int i)
{
	if (i <= 3)
	{
		tab.position[i].x = (place % 5);
		tab.position[i].y = place / 5;
	}
	return (tab);
}

t_tetri	ft_get_height_and_width(t_tetri tab)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (tab.position[i].x > tab.width)
			tab.width = tab.position[i].x;
		if (tab.position[i].y > tab.height)
			tab.height = tab.position[i].y;
	}
	tab.height += 1;
	tab.width += 1;
	return (tab);
}
