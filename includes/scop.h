/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:53:17 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/06 16:12:39 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# include "glad.h"

# include "libft.h"
# include "libpt.h"
# include "libmysdl.h"
# include "defines.h"
# include "struct.h"

int				ft_error(const char *str1, const char *str2, const char *str3);
void			ft_exit(t_data **data);
void			test_rectangle(t_data *data);
void			test_two_triangle(t_data *data);
void			test_texts(t_data *data);
void			test_double_tex(t_data *data);
void			malloc_failed(char *str);
void			test_3d(t_data *data);
void			m4_print(t_4matrix m);
void			set_uniform_matrix(t_data *data);

#endif
