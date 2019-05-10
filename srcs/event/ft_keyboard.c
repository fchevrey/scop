/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:01:26 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 12:39:25 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include <stdlib.h>

static int		keypress_do_event(int key, int repeat, t_data *data)
{
	static t_funar_keyb		*tab_fct = NULL;
	static int				size_tab;
	int						i;

	if (tab_fct == NULL)
		tab_fct = fill_funar_keypress(&size_tab);
	i = 0;
	if (key == SDLK_ESCAPE)
	{
		free(tab_fct);
		return (-1);
	}
	while (i < size_tab)
	{
		if (tab_fct[i].key == key)
		{
			if (tab_fct[i].f && (!repeat || tab_fct[i].repeat == repeat))
				tab_fct[i].f(data);
			return (1);
		}
		i++;
	}
	return (0);
}

int				ft_keyboard(int key, int repeat, SDL_Event *event, t_data *data)
{
	int			ret;

	ret = 0;
	if (event->type == SDL_KEYDOWN)
	{
		if ((ret = keypress_do_event(key, repeat, data)) == 1)
			return (0);
	}
	if (ret == -1)
	{
		ft_exit(&data);
	}
	return (0);
}
