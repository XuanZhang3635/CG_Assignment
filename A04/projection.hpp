

void SetupProjectionMatrices(Assignment04 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/
    float angle_x = 25.0;
    float angle_y = 75.0;
    
	glm::mat4 S;
	// Parallel projections parameters： w=10,a=4.0/3.0,n=-50,f=50
    glm::mat4 Port = glm::mat4(1.0/10.0,0,0,0,//column 1
                               0,-Ar/10.0,0,0,
                               0,0,-1.0/100.0,0,
                               0,0,50.0/100.0,1);
    
	// Isometric projection
	S = glm::mat4(1);
    S = Port*S;
    S = glm::rotate(S, glm::radians(35.26f), glm::vec3(1,0,0));
    S = glm::rotate(S, glm::radians(-45.0f), glm::vec3(0,1,0));
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Dimetric
	S = glm::mat4(1);
    S = Port*S;
    S = glm::rotate(S, glm::radians(angle_x), glm::vec3(1,0,0));
    S = glm::rotate(S, glm::radians(-45.0f), glm::vec3(0,1,0));
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Trimetric
	S = glm::mat4(1);
    S = Port*S;
    S = glm::rotate(S, glm::radians(angle_x), glm::vec3(1,0,0));
    S = glm::rotate(S, glm::radians(-angle_y), glm::vec3(0,1,0));
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Cabinet
	S = glm::mat4(1);
    float cabinet_p = 0.5;
    float cabinet_angle = 45.0;
    S = Port*glm::mat4(1,0,0,0,//column1
                       0,1,0,0,
                       -cabinet_p*cos(cabinet_angle),-cabinet_p*sin(cabinet_angle),1,0,
                       0,0,0,1);
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
