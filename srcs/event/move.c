/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:00:46 by fchevrey          #+#    #+#             */
/*   Updated: 2019/03/19 15:27:56 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void		check_other_move(t_data *data, const Uint8 *keyboard)
{
	if (keyboard[SDL_SCANCODE_UP])
		data->walking = MOVE_UP;
	else if (keyboard[SDL_SCANCODE_A])
		data->walking = MOVE_LEFT;
	else if (keyboard[SDL_SCANCODE_D])
		data->walking = MOVE_RIGHT;
	else if (keyboard[SDL_SCANCODE_W])
		data->walking = MOVE_UP;
	else if (keyboard[SDL_SCANCODE_S])
		data->walking = MOVE_DOWN;
	else
		data->walking = MOVE_NONE;
}

void			check_move(t_data *data)
{
	const Uint8	*keyboard;

	keyboard = SDL_GetKeyboardState(NULL);
	if ((keyboard[SDL_SCANCODE_UP] && keyboard[SDL_SCANCODE_DOWN])
			|| (keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_S]))
		data->walking = MOVE_NONE;
	else if ((keyboard[SDL_SCANCODE_UP] && keyboard[SDL_SCANCODE_S])
			|| (keyboard[SDL_SCANCODE_DOWN] && keyboard[SDL_SCANCODE_W]))
		data->walking = MOVE_NONE;
	else if (keyboard[SDL_SCANCODE_A] && keyboard[SDL_SCANCODE_D])
		data->walking = MOVE_NONE;
	else if (keyboard[SDL_SCANCODE_DOWN])
		data->walking = MOVE_DOWN;
	else
		check_other_move(data, keyboard);
	if (data->walking == MOVE_NONE)
		Mix_Pause(data->walk_channel);
}

void			move(t_data *data, float deltatime)
{
	const int speed = 50;

	check_move(data);
	if (data->walking == MOVE_UP)
		move_foreward(data, deltatime, speed);
	else if (data->walking == MOVE_DOWN)
		move_backward(data, deltatime, speed);
	else if (data->walking == MOVE_LEFT)
		move_left(data, deltatime, speed);
	else if (data->walking == MOVE_RIGHT)
		move_right(data, deltatime, speed);
}
