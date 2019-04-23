/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_tga.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:57:18 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/23 16:23:30 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tga.h"

static int				find_endian(void)
{
	int		s;
	char	*c;

	s = 1;
	c = (char*)&s;
	if (*c == 1)
		return (1);
	else
		return (0);
}

static unsigned char	*ft_decode_tga_little_endian(t_header *header,
		unsigned char *image)
{
	unsigned char	*end;
	unsigned char	*begin;
	unsigned char	argb[4];

	begin = image;
	end = image + (header->x * header->y * 4);
	while (image < end)
	{
		argb[0] = (unsigned char)(*(image + 0));
		argb[1] = (unsigned char)(*(image + 1));
		argb[2] = (unsigned char)(*(image + 2));
		argb[3] = (unsigned char)(*(image + 3));
		image[0] = argb[0];
		image[1] = argb[1];
		image[2] = argb[2];
		image[3] = argb[3];
		image += 4;
	}
	return (begin);
}

static unsigned char	*ft_decode_tga_big_endian(t_header *header,
		unsigned char *image)
{
	unsigned char	*end;
	unsigned char	*begin;
	unsigned char	argb[4];

	begin = image;
	end = image + (header->x * header->y * 4);
	while (image < end)
	{
		argb[0] = (unsigned char)(*(image + 0));
		argb[1] = (unsigned char)(*(image + 1));
		argb[2] = (unsigned char)(*(image + 2));
		argb[3] = (unsigned char)(*(image + 3));
		image[3] = argb[0];
		image[2] = argb[1];
		image[1] = argb[2];
		image[0] = argb[3];
		image += 4;
	}
	return (begin);
}

unsigned char			*ft_decode_tga(t_header *header,
		unsigned char *image)
{
	unsigned char	*end;
	unsigned char	*begin;
	int endian = find_endian();

	begin = image;
	end = image + (header->x * header->y * 4);
	if (endian == 0)
		begin = ft_decode_tga_little_endian(header, image);
	else
		begin = ft_decode_tga_big_endian(header, image);
	return (begin);
}
