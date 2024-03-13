

void SetupProjectionMatrices(Assignment05 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

	glm::mat4 S;
	
    // Perspective projections parameters
    float n = 0.1f;
    float f = 50.0f;
    float fov_y;
    
	// Fov-y = 60 deg
	S = glm::mat4(1);
    fov_y = glm::radians(60.0);
    S = glm::perspective(fov_y, Ar, n, f);
    S[1][1] *= -1;
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Fov-y = 105 deg
	S = glm::mat4(1);
    fov_y = glm::radians(105.0);
    S = glm::perspective(fov_y, Ar, n, f);
    S[1][1] *= -1;
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Fov-y = 25 deg
	S = glm::mat4(1);
    fov_y = glm::radians(25.0);
    S = glm::perspective(fov_y, Ar, n, f);
    S[1][1] *= -1;
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Right View, Fov-x = 45 deg
	S = glm::mat4(1);
//    fov_y = atan(tan(glm::radians(45.0/2))/Ar)*2;
    fov_y = glm::radians(45.0);
//    float fovx_radians = tan(glm::radians(45.0));
//    fov_y = atan(fovx_radians/Ar) * 2;
    S = glm::perspective(fov_y, Ar, n, f);
    S[1][1] *= -1;
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
