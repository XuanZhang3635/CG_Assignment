

void GameLogic(Assignment07 *A, float Ar, glm::mat4 &ViewPrj, glm::mat4 &World) {
    // The procedure must implement the game logic  to move the character in third person.
    // Input:
    // <Assignment07 *A> Pointer to the current assignment code. Required to read the input from the user
    // <float Ar> Aspect ratio of the current window (for the Projection Matrix)
    // Output:
    // <glm::mat4 &ViewPrj> the view-projection matrix of the camera
    // <glm::mat4 &World> the world matrix of the object
    // Parameters
    // Camera FOV-y, Near Plane and Far Plane
    const float FOVy = glm::radians(45.0f);
    const float nearPlane = 0.1f;
    const float farPlane = 100.f;
    
    // Player starting point
    const glm::vec3 StartingPosition = glm::vec3(-41.50, 0.0, -19.5);
    
    // Camera target height and distance
    const float camHeight = 0.25;
    const float camDist = 1.5;
    // Camera Pitch limits(alpha)
    const float minPitch = glm::radians(-8.75f);
    const float maxPitch = glm::radians(60.0f);
    // Rotation and motion speed
    const float ROT_SPEED = glm::radians(120.0f);
    const float MOVE_SPEED = 2.0f;
    
    // Integration with the timers and the controllers
    // returns:
    // <float deltaT> the time passed since the last frame
    // <glm::vec3 m> the state of the motion axes of the controllers (-1 <= m.x, m.y, m.z <= 1)
    // <glm::vec3 r> the state of the rotation axes of the controllers (-1 <= r.x, r.y, r.z <= 1)
    // <bool fire> if the user has pressed a fire button (not required in this assginment)
    float deltaT;
    glm::vec3 m = glm::vec3(0.0f), r = glm::vec3(0.0f);
    bool fire = false;
    A->getSixAxis(deltaT, m, r, fire);
    
    // Game Logic implementation
    // Current Player Position - statc variables make sure that their value remain unchanged in subsequent calls to the procedure
    static glm::vec3 pos = StartingPosition;
    static float alpha = 0, beta = 0, rho = 0;
    
    // To be done in the assignment
    //Solution

    /**
     The Walk navigation model
     */
    glm::vec3 ux = glm::vec3(glm::rotate(glm::mat4(1), alpha, glm::vec3(0, 1, 0)) * glm::vec4(1, 0, 0, 1));
    glm::vec3 uy = glm::vec3(0, 1, 0);
    glm::vec3 uz = glm::vec3(glm::rotate(glm::mat4(1), alpha, glm::vec3(0, 1, 0)) * glm::vec4(0, 0, -1, 1));
    alpha += ROT_SPEED * r.x * deltaT;
    beta += ROT_SPEED * -r.y * deltaT;
    rho += ROT_SPEED * r.z * deltaT;
    pos += ux * MOVE_SPEED * m.x * deltaT;
    pos += uy * MOVE_SPEED * m.y * deltaT;
    pos += uz * MOVE_SPEED * m.z * deltaT;
    
    /**
     World = Transform · Rotation · Scaling, no Scaling here
     */
    glm::mat4 T = glm::translate(glm::mat4(1.0), pos);
    
    if (alpha <= minPitch) alpha = minPitch;
    else if (alpha >= maxPitch) alpha = maxPitch;
    glm::mat4 Rx = glm::rotate(glm::mat4(1.0), alpha, glm::vec3(1, 0, 0));
    glm::mat4 Ry = glm::rotate(glm::mat4(1.0), beta, glm::vec3(0, 1, 0));
    glm::mat4 Rz = glm::rotate(glm::mat4(1.0), rho, glm::vec3(0, 0, 1));
    World = T * Ry * Rx * Rz;
    
    /**
     Look-at view
     ViewPrj: determine the direction of its axis in World coordinates, and then using the coresponding info to build the Camera Matrix
     */

    glm::vec3 c = glm::vec3(T * Ry * glm::vec4(0, camHeight + (camDist * sin(alpha)), camDist * cos(alpha), 1));
    glm::vec3 a = glm::vec3(T * Ry * glm::vec4(0, 0, 0, 1.0f)) + glm::vec3(0, camHeight, 0);

    glm::mat4 Mv = glm::lookAt(c, a, glm::vec3(0, 1, 0));
    glm::mat4 Mp = glm::perspective(FOVy, Ar, nearPlane, farPlane);
    Mp[1][1] *= -1;
    ViewPrj = Mp * Mv;

    /**
     Damping
     */
    static glm::mat4 ViewPrjOld = glm::mat4(1);
    float lambda = 10;
    if (ViewPrjOld == glm::mat4(1))
        ViewPrjOld = ViewPrj;
    ViewPrj = ViewPrjOld * exp(-lambda * deltaT) + ViewPrj * (1 - exp(-lambda * deltaT));
    ViewPrjOld = ViewPrj;
}
