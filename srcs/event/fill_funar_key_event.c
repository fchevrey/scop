/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_funar_key_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:09:38 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/06 18:28:11 by fchevrey         ###   ########.fr       */
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
	int				nb_fct;
	int				i;

	i = 0;
	*size = 0;
	nb_fct = 7;
	if (!(tab = (t_funar_keyb*)malloc(sizeof(t_funar_keyb) * nb_fct)))
		return (NULL);
	*size = nb_fct;
	tab[i++] = add_one(SDLK_x, 0, &rotate_in_x_axis);
	tab[i++] = add_one(SDLK_y, 0, &rotate_in_y_axis);
	tab[i++] = add_one(SDLK_z, 0, &rotate_in_z_axis);
	tab[i++] = add_one(SDLK_KP_PLUS, 0, &rotation_speed_up);
	tab[i++] = add_one(SDLK_KP_MINUS, 0, &rotation_speed_down);
	tab[i++] = add_one(SDLK_m, 0, &change_render_mode);
	tab[i++] = add_one(SDLK_t, 0, &change_texture);
	/*tab[i++] = add_one(SDLK_UP, 0, &check_move);
	tab[i++] = add_one(SDLK_DOWN, 0, &check_move);
	tab[i++] = add_one(SDLK_LEFT, 1, &look_left_from_key);
	tab[i++] = add_one(SDLK_RIGHT, 1, &look_right_from_key);
	tab[i++] = add_one(SDLK_d, 0, &check_move);
	tab[i++] = add_one(SDLK_j, 0, &sound);
	tab[i++] = add_one(SDLK_k, 0, &next_song);
	tab[i++] = add_one(SDLK_SPACE, 0, &play_shot_sound);*/
	return (tab);
}

t_funar_keyb			*fill_funar_keyrelease(int *size)
{
	t_funar_keyb	*tab;
	int				nb_fct;
	int				i;

	i = 0;
	*size = 0;
	nb_fct = 8;
	return (NULL);
	if (!(tab = (t_funar_keyb*)malloc(sizeof(t_funar_keyb) * nb_fct)))
		return (NULL);
	*size = nb_fct;
	/*tab[i++] = add_one(SDLK_UP, 0, &check_move);
	tab[i++] = add_one(SDLK_DOWN, 0, &check_move);
	tab[i++] = add_one(SDLK_LEFT, 0, &check_move);
	tab[i++] = add_one(SDLK_RIGHT, 0, &check_move);
	tab[i++] = add_one(SDLK_w, 0, &check_move);
	tab[i++] = add_one(SDLK_s, 0, &check_move);
	tab[i++] = add_one(SDLK_a, 0, &check_move);
	tab[i++] = add_one(SDLK_d, 0, &check_move);*/
	return (tab);
}
