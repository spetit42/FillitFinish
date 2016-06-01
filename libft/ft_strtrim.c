/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:02:01 by spetit            #+#    #+#             */
/*   Updated: 2016/05/27 13:02:04 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	j--;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
	{
		str[j] = '\0';
		j--;
	}
	return (str);
}
