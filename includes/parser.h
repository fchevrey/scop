/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:57:15 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/30 18:13:23 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "scop.h"
int		parse_obj_face(float *faces, t_data *data);
int		parse_obj_normal(float *normal, t_data *data);
int		parse_obj_texture(float *texture, t_data *data);
int		parse_obj_vertex(float *vertex, t_data *data);

struct		s_parse
{
	int		is_texture;
	int		is_normal;
	char	*vertex_buffer;
	char	*tex_buffer;
	char	*normal_buffer;
	char	*face_buffer;
}			t_parse

#endif
