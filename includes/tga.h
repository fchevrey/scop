/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:35:31 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/08 13:54:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TGA_H
# define TGA_H

# include "scop.h"
# include <fcntl.h>
# include <unistd.h>

/*
** Parse TGA
*/

typedef struct			s_header
{
	unsigned char		id_length;
	unsigned char		color_map_type;
	unsigned char		image_type;
	unsigned char		color_map_spec[5];
	unsigned char		image_spec[15];
	unsigned char		*image_data;
	short				x;
	short				y;
}						t_header;

typedef union			u_fill
{
	short				value;
	struct				s_val
	{
		unsigned char	a;
		unsigned char	b;
	}					val;
}						t_fill;

//int						ft_load_texture(int *endian, char *str, t_texture *img);
t_texture				*ft_load_texture(char *filename);
unsigned char			*ft_decode_tga(t_header *header, unsigned char *image);
int						load_gl_texture(unsigned int *text_number,
		char *filename);
t_texture				*texture_new_no_sdl(t_point size);

/*
** Free
*/

void					malloc_failed(char *str);

#endif
