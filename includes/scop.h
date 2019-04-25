/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:53:17 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/25 20:00:22 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# ifdef __APPLE__
//#  include <OpenGL/gl.h>
//#  include <OpenGL/glu.h>
//#  include <GLUT/glut.h>
//#  include <GL/glew.h>
#  include "glad.h"
#  include <GLFW/glfw3.h>
//#  include <GL/gl3w.h>
//#  include "GLFW/glfw3.h"
# else
//#  include <GL/glut.h>
# endif

# include "libft.h"
# include "libpt.h"
# include "libmysdl.h"
# include "defines.h"
# include "struct.h"

int		ft_error(const char *str1, const char *str2, const char *str3);
void	ft_exit(t_data **data);
void			test_rectangle(t_data *data);
void			test_two_triangle(t_data *data);
void			test_texts(t_data *data);
void			test_double_tex(t_data *data);
void			malloc_failed(char *str);
void			test_3d(t_data *data);
void			m4_print(t_4matrix m);

#endif
