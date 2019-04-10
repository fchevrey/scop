/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:26:10 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/10 18:19:09 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include "scop.h"
char			*load_shader(char *filename);
unsigned int	add_shader(const char *shadersource,
		unsigned int *shaderprogram, GLenum define);

#endif
