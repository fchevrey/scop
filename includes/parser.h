/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:57:15 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 18:29:52 by fchevrey         ###   ########.fr       */
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

typedef struct		s_face_info
{
	unsigned int	*tmp_v;
	unsigned int	*tmp_t;
	unsigned int	*tmp_n;
	char			*format;
	int				len;
}					t_face_info;

typedef struct		s_int_buf
{
	t_list			*lst;
	unsigned int	*buf;
	size_t			size;
}					t_int_buf;

typedef struct		s_float_buf
{
	t_list		*lst;
	float		*buf;
	size_t		size;
}					t_float_buf;

typedef struct		s_parse
{
	int				fd;
	int				parse_type;
	int				is_texture;
	int				is_normal;
	t_list			*buf_lst;
	t_float_buf		*vertex_buffer;
	t_float_buf		*tex_buffer;
	t_float_buf		*normal_buffer;
	t_int_buf		*vert_index;
	t_int_buf		*norm_index;
	t_int_buf		*tex_index;
	t_vecfl			center;
	char			**cmp;
}					t_parse;

typedef struct		s_funar_parse
{
	int		key;
	int		(*f)(t_parse*, char**);
}					t_funar_parse;

int					parse(t_data *data, char *filename);
int					parse_obj_face(t_parse *parse, char **line);
int					parse_obj_normal(t_parse *parse, char **line);
int					parse_obj_texture(t_parse *parse, char **line);
int					parse_obj_vertex(t_parse *parse, char **line);
int					parse_next(t_parse *parse, char **line);
int					read_face(t_parse *parse, char **line, char *pref);
t_funar_parse		*fill_funar_parse(int *size);
int					prefix_ok(const char *s1, char **cmp);
int					compare_prefix(const char *s1, const char *cmp);
int					read_float_arr(t_parse *parse, char **line, char *pref,
		int size);
void				free_elem(void *elem);
size_t				lst_to_arr(t_list *lst, float **to_fill);
int					init_info(char *pref, int size, t_line_info *info);
void				del_info(t_line_info *info);
t_float_buf			*float_buf_new(void);
void				free_float_buf(t_float_buf **src);
void				del_face_info(t_face_info *info);
int					init_face_info(char *pref, int size, t_face_info *info);
void				free_int_buf(t_int_buf **src);
t_int_buf			*int_buf_new(void);
int					create_gl_buffer(t_data *data, t_parse *parse);
t_vecfl				centralize_vertex(t_float_buf *src);
int					add_to_lst4(t_parse *parse, t_face_info *info,
		int scan, int count);
#endif
