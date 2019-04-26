#include "libpt.h"
#include <math.h>

t_4matrix	m4_rotation(t_vecfl axe, float angle)
{
	t_4matrix	dst;
	float		cos;
	float		sin;

	angle = deg_to_rad(angle);
	angle *= 0.1;
	cos = cosf(angle);
	sin = sinf(angle);
//	dst = m4_identity();
	dst.n[0][0] = (cos + sqrtf(axe.x)) * (1 - cos);
	dst.n[0][1] = (axe.x * axe.y * (1 - cos)) - (axe.x * sin);
	dst.n[0][2] = (axe.x * axe.z * (1 - cos)) + (axe.y * sin);
	dst.n[0][3] = 0;
	dst.n[1][0] = (axe.y * axe.x * (1 - cos)) + (axe.z * sin);
	dst.n[1][1] = cos + (sqrtf(axe.y) * (1 - cos));
	dst.n[1][2] = (axe.y * axe.z * (1 - cos)) - (axe.x * sin);
	dst.n[1][3] = 0;
	dst.n[2][0] = (axe.z * axe.x * (1 - cos)) - (axe.y * sin);
	dst.n[2][1] = (axe.z * axe.y * (1 - cos)) + (axe.x * sin);
	dst.n[2][2] = cos + (sqrtf(axe.x) * (1 - cos));
	dst.n[2][3] = 0;
	dst.n[3][0] = 0;
	dst.n[3][1] = 0;
	dst.n[3][2] = 0;
	dst.n[3][3] = 1;
	return dst;
}
