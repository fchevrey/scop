/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:49:51 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/13 15:43:16 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "scop.h"

typedef struct	s_funar_keyb
{
	int		key;
	int		repeat;
	void	(*f)(t_data*);
}				t_funar_keyb;

void			main_loop(t_data *data);
int				ft_mouse(int x, int y, t_data *data);
int				ft_keyboard(int key, int repeat, SDL_Event *event,
					t_data *data);
int				ft_mouse_wheel(int y, t_data *data);
t_funar_keyb	*fill_funar_keyrelease(int *size);
t_funar_keyb	*fill_funar_keypress(int *size);
void			resize(t_data *data, int width, int height);
void			rotate_in_z_axis(t_data *data);
void			rotate_in_x_axis(t_data *data);
void			rotate_in_y_axis(t_data *data);
void			rotation_speed_up(t_data *data);
void			rotation_speed_down(t_data *data);
void			change_render_mode(t_data *data);
void			change_texture(t_data *data);
void			change_render_mode(t_data *data);
void			change_polygon_mode(t_data *data);
void			reload_shaders(t_data *data);
void			reset_position(t_data *data);

void			move_down(t_data *data);
void			move_up(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			move_front(t_data *data);
void			move_back(t_data *data);

#endif
