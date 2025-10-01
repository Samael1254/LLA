#include "Matrix.hpp"
#include <cmath>

/**
 * @brief Compute a perspective projection matrix
 *
 * @param fov Field of view (in radians)
 * @param ratio Screen ratio
 * @param near Near plane distance from the camera
 * @param far Far plane distance from the camera
 * @return Projection matrix
 */
Matrix<4, 4, float> projection(float fov, float ratio, float near, float far)
{
	float tanFov2 = std::tan(fov / 2);
	float tanVFov2 = tanFov2 / ratio;

	Matrix<4, 4, float> proj = {{1 / tanFov2, 0, 0, 0},
	                            {0, 1 / tanVFov2, 0, 0},
	                            {0, 0, -far / (far - near), -far * near / (far - near)},
	                            {0, 0, -1, 0}};
	return proj;
}
