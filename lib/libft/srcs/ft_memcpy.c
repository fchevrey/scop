/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:15:15 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/03 14:21:25 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*cpy_src;
	unsigned char			*cpy_dst;
	unsigned char			*temp;

	i = 0;
	cpy_src = src;
	cpy_dst = dst;
	if (n == 0)
		return (NULL);
	if (!(temp = (unsigned char*)malloc(sizeof(unsigned char) * n)))
		return (NULL);
	while (i < n)
	{
		temp[i] = (unsigned char)cpy_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		cpy_dst[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
