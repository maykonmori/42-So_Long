/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 10:28:19 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/06 20:15:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] == (char)n)
		{
			return ((char *)str + cont);
		}
		cont++;
	}
	if (n == '\0')
		return ((char *)str + cont);
	return (0);
}

