/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_funar_key_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:09:38 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/13 15:42:48 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include <stdlib.h>

static t_funar_keyb		add_one(int key, int repeat, void (*f)(t_data*))
{
	t_funar_keyb	item;

	item.key = key;
	item.repeat = repeat;
	item.f = f;
	return (item);
}

t_funar_keyb			*fill_funar_keypress(int *size)
{
	t_funar_keyb	*tab;
	int				i;

	i = 0;
	*size = 16;
	if (!(tab = (t_funar_keyb*)malloc(sizeof(t_funar_keyb) * *size)))
		return (NULL);
	tab[i++] = add_one(SDLK_x, 0, &rotate_in_x_axis);
	tab[i++] = add_one(SDLK_y, 0, &rotate_in_y_axis);
	tab[i++] = add_one(SDLK_z, 0, &rotate_in_z_axis);
	tab[i++] = add_one(SDLK_KP_PLUS, 0, &rotation_speed_up);
	tab[i++] = add_one(SDLK_KP_MINUS, 0, &rotation_speed_down);
	tab[i++] = add_one(SDLK_m, 0, &change_render_mode);
	tab[i++] = add_one(SDLK_t, 0, &change_texture);
	tab[i++] = add_one(SDLK_p, 0, &change_polygon_mode);
	tab[i++] = add_one(SDLK_w, 1, &move_up);
	tab[i++] = add_one(SDLK_s, 1, &move_down);
	tab[i++] = add_one(SDLK_a, 1, &move_left);
	tab[i++] = add_one(SDLK_d, 1, &move_right);
	tab[i++] = add_one(SDLK_q, 1, &move_front);
	tab[i++] = add_one(SDLK_e, 1, &move_back);
	tab[i++] = add_one(SDLK_r, 0, &reload_shaders);
	tab[i++] = add_one(SDLK_i, 0, &reset_position);
	return (tab);
}
