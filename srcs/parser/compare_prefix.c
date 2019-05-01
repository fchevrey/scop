/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:21:22 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/01 18:27:05 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		compare_prefix(char const *s1, char const*cmp)
{
	int		i;

	i = 0;
	if (!s1 || cmp)
		return (-1);
	while (cmp[i])
	{
		if (cmp[i] != s1[i])
			return (-1);
		i++;
	}
	return (0);
}
