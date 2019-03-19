/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:53:17 by fchevrey          #+#    #+#             */
/*   Updated: 2019/03/19 20:01:35 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include "libpt.h"
# include "libmysdl.h"
# include "defines.h"
# include "struct.h"
# include "glew.h"
# ifdef __APPLE__
//#  include <OpenGL/gl.h>
//#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
# else
#  include <GL/glut.h>
# endif

int		ft_error(const char *str1, const char *str2, const char *str3);
void	ft_exit(t_data **data);

#endif
