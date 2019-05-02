/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:57:15 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/02 19:50:42 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scop.h"
# define PARSE_EXIT -1
# define PARSE_VERTEX 0
# define PARSE_TEXTURE 1
# define PARSE_NORMAL 2
# define PARSE_FACE 3
# define PARSE_OTHER 4

typedef struct		s_line_info
{
	float	*tmp;
	char	*format;
	int		len;
}					t_line_info;

typedef struct		s_parse
{
	int			fd;
	int			parse_type;
	int			is_texture;
	int			is_normal;
	t_list		*buf_lst;
	float		*vertex_buffer;
	float		*tex_buffer;
	float		*normal_buffer;
	float		*face_buffer;
	char		**cmp;
}			t_parse;

typedef struct			s_funar_parse
{
	int					key;
	int				(*f)(t_parse*, char**);
}						t_funar_parse;

int				parse(t_data *data, char *filename);
int				parse_obj_face(t_parse *parse, char **line);
int				parse_obj_normal(t_parse *parse, char **line);
int				parse_obj_texture(t_parse *parse, char **line);
int				parse_obj_vertex(t_parse *parse, char **line);
int				parse_next(t_parse *parse, char **line);
t_funar_parse	*fill_funar_parse(int *size);
int				prefix_ok(const char *s1, char **cmp);
int				compare_prefix(const char *s1, const char *cmp);
int				read_float_arr(t_parse *parse, char **line, char *pref,
		int size);
void			free_elem(void *elem);
size_t			lst_to_arr(t_list *lst, float **to_fill);
/*int		parse_obj_face(float *faces, t_data *data);
int		parse_obj_normal(float *normal, t_data *data);
int		parse_obj_texture(float *texture, t_data *data);
int		parse_obj_vertex(float *vertex, t_data *data);*/
#endif
