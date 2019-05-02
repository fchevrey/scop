
#include "parser.h"
/*static void		print_float(t_list *elem)
{
	static int		i = 0;
	float			*arr;

	arr = (float*)elem->content;
	printf("%d : %f %f %f\n", i, arr[0], arr[1], arr[2]);
	i++;
}*/

int				parse_obj_face(t_parse *parse, char **line)
{
	ft_putendl("face");
	ft_strdel(line);
	if (!parse || !line)
		return (1);
	return (1);
}
