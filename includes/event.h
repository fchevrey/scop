/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:49:51 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/29 19:07:05 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "scop.h"

typedef struct			s_funar_keyb
{
	int					key;
	int					repeat;
	void				(*f)(t_data*);
}						t_funar_keyb;

void			main_loop(t_data *data);
int				ft_mouse(int x, int y, t_data *data);
int				ft_keyboard(int key, int repeat, SDL_Event *event,
		t_data *data);
int				ft_mouse_wheel(int y, t_data *data);
t_funar_keyb	*fill_funar_keyrelease(int *size);
t_funar_keyb	*fill_funar_keypress(int *size);
void			resize(t_data *data, int width, int height);

#endif
