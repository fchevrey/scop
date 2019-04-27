#include "libpt.h"
#include <math.h>

t_4matrix	m4_rotation(t_vecfl axe, float angle)
{
	t_4matrix	dst;
	float		cos;
	float		sin;
	float		cos_inverse;

	angle = deg_to_rad(angle);
	//angle *= 0.1;
	cos = cosf(angle);
	cos_inverse = 1 - cos;
	sin = sinf(angle);
//	dst = m4_identity();
	/*dst.n[0][0] = (cos + (axe.x * axe.x)) * (cos_inverse);
	dst.n[0][1] = (axe.x * axe.y * (cos_inverse)) - (axe.x * sin);
	dst.n[0][2] = (axe.x * axe.z * (cos_inverse)) + (axe.y * sin);
	dst.n[0][3] = 0;
	dst.n[1][0] = (axe.y * axe.x * (cos_inverse)) + (axe.z * sin);
	dst.n[1][1] = cos + ((axe.y * axe.y) * (cos_inverse));
	dst.n[1][2] = (axe.y * axe.z * (cos_inverse)) - (axe.x * sin);
	dst.n[1][3] = 0;
	dst.n[2][0] = (axe.z * axe.x * (cos_inverse)) - (axe.y * sin);
	dst.n[2][1] = (axe.z * axe.y * (cos_inverse)) + (axe.x * sin);
	dst.n[2][2] = cos + ((axe.x * axe.x) * (cos_inverse));
	dst.n[2][3] = 0;
	dst.n[3][0] = 0;
	dst.n[3][1] = 0;
	dst.n[3][2] = 0;
	dst.n[3][3] = 1;*/
	/*matrice openclassroom*/
	dst.n[0][0] = (axe.x * axe.x * cos_inverse) + cos;
	dst.n[0][1] = (axe.x * axe.y * cos_inverse) - (axe.z * sin);
	dst.n[0][2] = (axe.x * axe.z * cos_inverse) + (axe.y * sin);
	dst.n[0][3] = 0;
	dst.n[1][0] = (axe.x * axe.y * cos_inverse) + (axe.z * sin);
	dst.n[1][1] = (axe.y * axe.y * cos_inverse) + cos;
	dst.n[1][2] = (axe.y * axe.z * cos_inverse) - (axe.x * sin);
	dst.n[1][3] = 0;
	dst.n[2][0] = (axe.x * axe.z * cos_inverse) - (axe.y * sin);
	dst.n[2][1] = (axe.y * axe.z * cos_inverse) + (axe.x * sin);
	dst.n[2][2] = (axe.z * axe.z * cos_inverse) + cos;
	dst.n[2][3] = 0;
	dst.n[3][0] = 0;
	dst.n[3][1] = 0;
	dst.n[3][2] = 0;
	dst.n[3][3] = 1;
	/*matrice openclassroomi inverse*/
/*	dst.n[0][0] = (axe.x * axe.x * cos_inverse) + cos;
	dst.n[1][0] = (axe.x * axe.y * cos_inverse) - (axe.z * sin);
	dst.n[2][0] = (axe.x * axe.z * cos_inverse) + (axe.y * sin);
	dst.n[3][0] = 0;
	dst.n[0][1] = (axe.x * axe.y * cos_inverse) + (axe.z * sin);
	dst.n[1][1] = (axe.y * axe.y * cos_inverse) + cos;
	dst.n[2][1] = (axe.y * axe.z * cos_inverse) - (axe.x * sin);
	dst.n[3][1] = 0;
	dst.n[0][2] = (axe.x * axe.z * cos_inverse) - (axe.y * sin);
	dst.n[1][2] = (axe.y * axe.z * cos_inverse) + (axe.x * sin);
	dst.n[2][2] = (axe.z * axe.z * cos_inverse) + cos;
	dst.n[3][2] = 0;
	dst.n[0][3] = 0;
	dst.n[1][3] = 0;
	dst.n[2][3] = 0;
	dst.n[3][3] = 1;
	*/
	return dst;
}
