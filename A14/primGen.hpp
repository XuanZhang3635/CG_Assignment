void Assignment14::createCubeMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
/*	vDef.push_back({{0.0f, 0.0f, 0.1f}, {0.5f, 0.0f, 0.866f}});	// vertex 0 - Position and Normal
	vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{1.0f, 1.0f, 0.1f}, {-0.5f, 0.0f, 0.866f}});// vertex 3 - Position and Normal

	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle
	
	// The primitive built here is a cube centered in the origin, whose edge lenght is 2.
*/	
	// Fill array vPos with the positions of the vertices of the mesh
    // 对于每个顶点，法向量是与该点相邻的所有面的法向量的平均值
    // 正面
	vDef.push_back({{0.0f, 0.0f, 0.1f}, {0.5f, 0.0f, 0.866f}});	// vertex 0 - Position and Normal
	vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{1.0f, 1.0f, 0.1f}, {-0.5f, 0.0f, 0.866f}});// vertex 3 - Position and Normal
    
    // 背面
    vDef.push_back({{0.0f, 0.0f, -0.9f}, {-0.5f, 0.0f, -0.866f}});    // vertex 4 - Position and Normal
    vDef.push_back({{1.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}});    // vertex 5 - Position and Normal
    vDef.push_back({{0.0f, 1.0f, -0.9f}, {0.0f, 0.0f, -1.0f}});    // vertex 6 - Position and Normal
    vDef.push_back({{1.0f, 1.0f, -0.9f}, {0.5f, 0.0f, -0.866f}});// vertex 7 - Position and Normal

    // 左面
    vDef.push_back({{0.0f, 0.0f, 0.1f}, {-1.0f, 0.0f, 0.0f}});    // vertex 8 - Position and Normal
    vDef.push_back({{0.0f, 1.0f, 0.0f}, {-1.0f, 0.0f, 0.0f}});    // vertex 9 - Position and Normal
    vDef.push_back({{0.0f, 0.0f, -0.9f}, {-1.0f, 0.0f, 0.0f}});    // vertex 10 - Position and Normal
    vDef.push_back({{0.0f, 1.0f, -0.9f}, {-1.0f, 0.0f, 0.0f}});// vertex 11 - Position and Normal
    
    // 右面
    vDef.push_back({{1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}});    // vertex 12 - Position and Normal
    vDef.push_back({{1.0f, 1.0f, 0.1f}, {1.0f, 0.0f, 0.0f}});    // vertex 13 - Position and Normal
    vDef.push_back({{1.0f, 0.0f, -1.0f}, {1.0f, 0.0f, 0.0f}});    // vertex 14 - Position and Normal
    vDef.push_back({{1.0f, 1.0f, -0.9f}, {1.0f, 0.0f, 0.0f}});// vertex 15 - Position and Normal
    
    // 上面
    vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}});    // vertex 2 - Position and Normal
    vDef.push_back({{1.0f, 1.0f, 0.1f}, {0.0f, 1.0f, 0.0f}});// vertex 3 - Position and Normal
    vDef.push_back({{0.0f, 1.0f, -0.9f}, {0.0f, 1.0f, 0.0f}});    // vertex 6 - Position and Normal
    vDef.push_back({{1.0f, 1.0f, -0.9f}, {0.0f, 1.0f, 0.0f}});// vertex 7 - Position and Normal
    
    // 底部
    vDef.push_back({{0.0f, 0.0f, 0.1f}, {0.0f, -1.0f, 0.0f}});    // vertex 0 - Position and Normal
    vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, -1.0f, 0.0f}});    // vertex 1 - Position and Normal
    vDef.push_back({{0.0f, 0.0f, -0.9f}, {0.0f, -1.0f, 0.0f}});    // vertex 4 - Position and Normal
    vDef.push_back({{1.0f, 0.0f, -1.0f}, {0.0f, -1.0f, 0.0f}});    // vertex 5 - Position and Normal

    
	// Fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle
    
    vIdx.push_back(4); vIdx.push_back(5); vIdx.push_back(6);
    vIdx.push_back(5); vIdx.push_back(6); vIdx.push_back(7);
    
    vIdx.push_back(8); vIdx.push_back(9); vIdx.push_back(10);
    vIdx.push_back(9); vIdx.push_back(10); vIdx.push_back(11);
    
    vIdx.push_back(12); vIdx.push_back(13); vIdx.push_back(14);
    vIdx.push_back(13); vIdx.push_back(14); vIdx.push_back(15);
    
    vIdx.push_back(16); vIdx.push_back(17); vIdx.push_back(18);
    vIdx.push_back(17); vIdx.push_back(18); vIdx.push_back(19);
    
    vIdx.push_back(20); vIdx.push_back(21); vIdx.push_back(22);
    vIdx.push_back(21); vIdx.push_back(22); vIdx.push_back(23);
    
}

void Assignment14::createFunctionMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is the surface y = sin(x) * cos(z) with -3 <= x <= 3 and -3 <= z <= 3.
    // 定义平面的范围
    float minX = -3.0f;
    float maxX = 3.0f;
    float minZ = -3.0f;
    float maxZ = 3.0f;

    // 离散采样的步长
    float step = 0.1f;

    // 生成平面上的顶点
    int counter = 0;
    for (float x = minX; x <= maxX; x += step) {
        for (float z = minZ; z <= maxZ; z += step) {
            // 计算 y 值
            float y = sin(x) * cos(z);

            // 计算法向量，如果没有负号就和老师的结果一样
            glm::vec3 normal = glm::normalize(glm::vec3(cos(x) * cos(z), 1.0f, sin(x) * -sin(z)));

            vDef.push_back({glm::vec3(x, y, z), normal});
        }
    }

    // 构建索引
    for (int i = 0; i < (maxX - minX) / step; ++i) {
        for (int j = 0; j < (maxZ - minZ) / step; ++j) {
            int index = i * ((maxZ - minZ) / step + 1) + j;

            vIdx.push_back(index);
            vIdx.push_back(index + 1);
            vIdx.push_back(index + (maxZ - minZ) / step + 1);

            vIdx.push_back(index + 1);
            vIdx.push_back(index + (maxZ - minZ) / step + 2);
            vIdx.push_back(index + (maxZ - minZ) / step + 1);
        }
    }
}

void Assignment14::createCylinderMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is a cylinder, with radius 1, and height 2, centered in the origin.
	
    int segments = 64; // 顶部和底部分割的段数
    int sides = 16;    // 侧面分割的段数
    float radius = 1.0f;
    float height = 2.0f;

    int counter = 0;

    // 顶部圆盘法向量
    glm::vec3 topNormal = glm::vec3(0.0f, 1.0f, 0.0f);
    // 底部圆盘法向量
    glm::vec3 bottomNormal = glm::vec3(0.0f, -1.0f, 0.0f);
    vDef.push_back({ glm::vec3(0,0,0), bottomNormal });
    vDef.push_back({ glm::vec3(0,height,0), topNormal });
    counter += 2;
    // 顶部圆盘和底部圆盘
    for (int i = 0; i < segments; ++i) {
        
        float theta1 = glm::two_pi<float>() * static_cast<float>(i) / static_cast<float>(segments);
        float theta2 = glm::two_pi<float>() * static_cast<float>(i + 1) / static_cast<float>(segments);
        
        // 底部圆盘顶点
        glm::vec3 bottomVertex1 = glm::vec3(sin(theta1) * radius,0,cos(theta1) * radius);
        glm::vec3 bottomVertex2 = glm::vec3(sin(theta2) * radius,0,cos(theta2) * radius);
        
        // 顶部圆盘顶点
        glm::vec3 topVertex1 = glm::vec3(sin(theta1) * radius,height,cos(theta1) * radius);
        glm::vec3 topVertex2 = glm::vec3(sin(theta2) * radius,height,cos(theta2) * radius);

        vDef.push_back({bottomVertex1,bottomNormal});
        vDef.push_back({bottomVertex2,bottomNormal});
        vDef.push_back({topVertex1,topNormal});
        vDef.push_back({topVertex2,topNormal});
        
        vIdx.push_back(0);vIdx.push_back(counter);vIdx.push_back(counter + 1);
        vIdx.push_back(1);vIdx.push_back(counter + 2);vIdx.push_back(counter + 3);
        
        counter += 4;
        
        glm::vec3 sideVertex1 = bottomVertex1;
        glm::vec3 sideVertex2 = bottomVertex2;
        glm::vec3 sideVertex3 = topVertex2;
        
        glm::vec3 sideVertex4 = bottomVertex1;
        glm::vec3 sideVertex5 = topVertex1;
        glm::vec3 sideVertex6 = topVertex2;
        
        
        glm::vec3 sideNormal1 = glm::normalize(glm::cross(glm::vec3(cos(theta1),0,sin(theta1)),glm::vec3(0,1,0)));
        glm::vec3 sideNormal2 = glm::normalize(glm::cross(glm::vec3(cos(theta2),0,sin(theta2)),glm::vec3(0,1,0)));
        glm::vec3 sideNormal3 = glm::normalize(glm::cross(glm::vec3(cos(theta1),height,sin(theta1)),glm::vec3(0,1,0)));
        glm::vec3 sideNormal4 = glm::normalize(glm::cross(glm::vec3(cos(theta2),height,sin(theta2)),glm::vec3(0,1,0)));
        
        vDef.push_back({sideVertex1,sideNormal1});
        vDef.push_back({sideVertex2,sideNormal2});
        vDef.push_back({sideVertex3,sideNormal4});
        
        vDef.push_back({sideVertex4,sideNormal1});
        vDef.push_back({sideVertex5,sideNormal3});
        vDef.push_back({sideVertex6,sideNormal4});
        
        vIdx.push_back(counter);vIdx.push_back(counter + 1);vIdx.push_back(counter + 2);
        vIdx.push_back(counter + 3);vIdx.push_back(counter + 4);vIdx.push_back(counter + 5);
        
        counter += 6;

    }
    
}
