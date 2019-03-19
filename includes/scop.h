/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:53:17 by fchevrey          #+#    #+#             */
/*   Updated: 2019/03/19 15:13:58 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include "libpt.h"
# include "libmysdl.h"
# include "defines.h"
# include "struct.h"

int		ft_error(const char *str1, const char *str2, const char *str3);
void	ft_exit(t_data **data);

#endif
