/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:11:10 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/10 18:31:23 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin3f(char *s1, char const *s2, const char *s3)
{
	char	*dst;
	int		i;
	int		j;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	j = -1;
	while (s2[++j])
		dst[i++] = s2[j];
	k = -1;
	while (s3[++k])
		dst[i++] = s3[k];
	ft_strdel(&s1);
	return (dst);
}
