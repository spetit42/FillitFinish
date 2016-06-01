/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:14:48 by vvenance          #+#    #+#             */
/*   Updated: 2016/05/28 16:17:58 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_and_add(char *buff, int coor, t_tetri *tab, char lettre)
{
	int i;

	buff[21] = '\0';
	tab[coor] = ft_check_tetri(tab[coor], buff);
	tab[coor].letter = lettre;
	if (buff[20] == '\n')
		i = 1;
	else
		i = 0;
	return (i);
}

void	ft_usage(void)
{
	ft_putstr("usage: ./fillit target_file\n");
	exit(0);
}
