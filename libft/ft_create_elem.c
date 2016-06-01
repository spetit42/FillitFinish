/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:51:32 by spetit            #+#    #+#             */
/*   Updated: 2016/05/27 12:52:11 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *content)
{
	t_list *tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}
