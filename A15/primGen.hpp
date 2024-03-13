#define LEN 1024.0
#define WIDTH 512.0
void Assignment15::createBoxMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
    // The primitive built here is a box centered in the origin, with proportions respecting the texture.
    int counter = 0;
    // The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
    // box的长宽高
    float scale = 1.2;
    float length = 1*scale;
    float width = 0.3*scale;
    float height = 1*scale;
    // front
    vDef.push_back({{0,0,0}, {0,0,1}, {0.085,0.82}});    // vertex 0 - Position, Normal and uv
    vDef.push_back({{length,0,0}, {0,0,1}, {0.438,0.82}});    // vertex 1 - Position and Normal
    vDef.push_back({{0,height,0}, {0,0,1}, {0.085,0.180}});    // vertex 2 - Position and Normal
    vDef.push_back({{length,height,0}, {0,0,1}, {0.438,0.180}});// vertex 3 - Position and Normal

    // The procedures also fill the array vIdx with the indices of the vertices of the triangles
    vIdx.push_back(counter); vIdx.push_back(counter + 1); vIdx.push_back(counter + 2);    // First triangle
    vIdx.push_back(counter + 1); vIdx.push_back(counter + 2); vIdx.push_back(counter + 3);    // Second triangle
    
    counter += 4;
    
    // back
    vDef.push_back({{0,0,-width}, {0,0,-1}, {0.438*2,0.82}});    // vertex 0 - Position, Normal and uv
    vDef.push_back({{length,0,-width}, {0,0,-1}, {0.438+0.085,0.82}});    // vertex 1 - Position and Normal
    vDef.push_back({{0,height,-width}, {0,0,-1}, {0.438*2,0.180}});    // vertex 2 - Position and Normal
    vDef.push_back({{length,height,-width}, {0,0,-1}, {0.438+0.085,0.180}});// vertex 3 - Position and Normal

    // The procedures also fill the array vIdx with the indices of the vertices of the triangles
    vIdx.push_back(counter); vIdx.push_back(counter + 1); vIdx.push_back(counter + 2);    // First triangle
    vIdx.push_back(counter + 1); vIdx.push_back(counter + 2); vIdx.push_back(counter + 3);    // Second triangle
    
    counter += 4;
    
    //top
    vDef.push_back({{0,height,0}, {0,1,0}, {0.085,0.180}});    // vertex 2 - Position and Normal
    vDef.push_back({{length,height,0}, {0,1,0}, {0.438,0.180}});// vertex 3 - Position and Normal
    vDef.push_back({{0,height,-width}, {0,1,0}, {0.085,0.0}});    // vertex 2 - Position and Normal
    vDef.push_back({{length,height,-width}, {0,1,0}, {0.438,0.0}});// vertex 3 - Position and Normal
    
    // The procedures also fill the array vIdx with the indices of the vertices of the triangles
    vIdx.push_back(counter); vIdx.push_back(counter + 1); vIdx.push_back(counter + 2);    // First triangle
    vIdx.push_back(counter + 1); vIdx.push_back(counter + 2); vIdx.push_back(counter + 3);    // Second triangle
    
    counter += 4;
    
    //bottom
    vDef.push_back({{0,0,0}, {0,-1,0}, {0.085,0.820}});    // vertex 2 - Position and Normal
    vDef.push_back({{length,0,0}, {0,-1,0}, {0.438,0.820}});// vertex 3 - Position and Normal
    vDef.push_back({{0,0,-width}, {0,-1,0}, {0.085,1.0}});    // vertex 2 - Position and Normal
    vDef.push_back({{length,0,-width}, {0,-1,0}, {0.438,1.0}});// vertex 3 - Position and Normal
    
    // The procedures also fill the array vIdx with the indices of the vertices of the triangles
    vIdx.push_back(counter); vIdx.push_back(counter + 1); vIdx.push_back(counter + 2);    // First triangle
    vIdx.push_back(counter + 1); vIdx.push_back(counter + 2); vIdx.push_back(counter + 3);    // Second triangle
    
    counter += 4;
    
    //right
    vDef.push_back({{length,0,0}, {1,0,0}, {0.438,0.82}});    // vertex 1 - Position and Normal
    vDef.push_back({{length,height,0}, {1,0,0}, {0.438,0.180}});// vertex 3 - Position and Normal
    vDef.push_back({{length,0,-width}, {1,0,0}, {0.438+0.085,0.82}});    // vertex 0 - Position, Normal and uv
    vDef.push_back({{length,height,-width}, {1,0,0}, {0.438+0.085,0.180}});// vertex 3 - Position and Normal
    
    // The procedures also fill the array vIdx with the indices of the vertices of the triangles
    vIdx.push_back(counter); vIdx.push_back(counter + 1); vIdx.push_back(counter + 2);    // First triangle
    vIdx.push_back(counter + 1); vIdx.push_back(counter + 2); vIdx.push_back(counter + 3);    // Second triangle
    
    counter += 4;
    
    //left
    vDef.push_back({{0,0,0}, {-1,0,0}, {0.085,0.82}});    // vertex 1 - Position and Normal
    vDef.push_back({{0,height,0}, {-1,0,0}, {0.085,0.180}});// vertex 3 - Position and Normal
    vDef.push_back({{0,0,-width}, {-1,0,0}, {0.0,0.82}});    // vertex 0 - Position, Normal and uv
    vDef.push_back({{0,height,-width}, {-1,0,0}, {0.0,0.180}});// vertex 3 - Position and Normal
    
    // The procedures also fill the array vIdx with the indices of the vertices of the triangles
    vIdx.push_back(counter); vIdx.push_back(counter + 1); vIdx.push_back(counter + 2);    // First triangle
    vIdx.push_back(counter + 1); vIdx.push_back(counter + 2); vIdx.push_back(counter + 3);    // Second triangle
    
    counter += 4;
    
}

#define M_PI 3.141595f
void Assignment15::createSphereMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
    // The primitive built here is a sphere of radius 1, centered in the origin, on which the Mars texture is applied seamless.
    int sectors = 32;// 经度切分数目
    int stacks = 32;// 纬度切分数目
    float radius = 1;
    // The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
    //vDef.push_back({{0,0,0}, {0,0,1}, {0,0}});    // vertex 0 - Position, Normal and uv
    //vDef.push_back({{1,0,0}, {0,0,1}, {1,0}});    // vertex 1 - Position and Normal
    //vDef.push_back({{0,1,0}, {0,0,1}, {0,1}});    // vertex 2 - Position and Normal
    //vDef.push_back({{1,1,0}, {0,0,1}, {1,1}});// vertex 3 - Position and Normal

    // The procedures also fill the array vIdx with the indices of the vertices of the triangles
    //vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);    // First triangle
    //vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);    // Second triangle
    for (int i = 0; i <= stacks; ++i) {
        for (int j = 0; j <= sectors; ++j) {
            float stackAngle = M_PI * i / stacks;
            float sectorAngle = 2.0f * M_PI * j / sectors;
            // 球坐标
            float z = radius * std::sin(stackAngle) * std::sin(sectorAngle);
            float x = radius * std::sin(stackAngle) * std::cos(sectorAngle);
            float y = radius * std::cos(stackAngle);

            // 法向量计算
            glm::vec3 normal = glm::normalize(glm::vec3(x,y,z));

            // 纹理坐标范围 [0, 1]
            float u = static_cast<float>(j) / sectors;
            float v = static_cast<float>(i) / stacks;
            
            vDef.push_back({{x,y,z},normal,{u,v}});
        }
        
    }
    
    // 生成索引数组
    for (int i = 0; i < stacks; ++i) {
        for (int j = 0; j < sectors; ++j) {
            int index1 = {i * (sectors + 1) + j};
            int index2 = {i * (sectors + 1) + j + 1};
            int index3 = {(i + 1) * (sectors + 1) + j + 1};
            int index4 = {(i + 1) * (sectors + 1) + j};

            vIdx.push_back(index1);
            vIdx.push_back(index2);
            vIdx.push_back(index3);
            vIdx.push_back(index1);
            vIdx.push_back(index3);
            vIdx.push_back(index4);
        }
    }
}

