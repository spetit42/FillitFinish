/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:29:31 by vvenance          #+#    #+#             */
/*   Updated: 2016/05/28 14:52:54 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetri tab[26];
	t_map	*map;
	int		coor[2];

	if (argc != 2)
		ft_usage();
	coor[0] = 10;
	coor[1] = 0;
	ft_check_and_parse(argv, tab, 'A', coor);
	map = ft_create_tab(tab);
	ft_recursive(map, tab);
	return (0);
}
