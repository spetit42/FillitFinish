/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:20:34 by spetit            #+#    #+#             */
/*   Updated: 2016/05/27 12:32:31 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;

	list = *begin_list;
	if (!list)
	{
		list = ft_create_elem(data);
	}
	else
	{
		while (list->next)
		{
			list = list->next;
		}
		list->next = ft_create_elem(data);
	}
}
