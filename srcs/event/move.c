/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:00:46 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/09 17:35:01 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void			move_down(t_data *data)
{
	data->view.n[1][3] -= 0.1f;
}

void			move_up(t_data *data)
{
	data->view.n[1][3] += 0.1f;
}

void			move_right(t_data *data)
{
	data->view.n[0][3] += 0.1f;
}

void			move_left(t_data *data)
{
	data->view.n[0][3] -= 0.1f;
}
