#include <iostream>
using namespace std;

void Assignment08::createMazeMesh(int row, int col, char **maze) {
	// The procedure gets in input the number of rows <row> of the maze, and the number of columns <col>
	// Element <maze[r][c]>, with 0 <= r <= row-1 and 0 <= c <= col-1 contains:
	//		Symbol ' ' if there is an empty space
	//		Symbol '#' if there is a wall
	//
	// Example: The following piece of code executes the instruction in the ... section
	//          if there is a wall in position r=5, c=7
	//
	// int r, c;
	// r = 5; c = 7;
	// if(maze[r][c] == '#') {
	//		...
	// }
	//
	// The example below creates a square, with four vertices and two triangles.
	// It must be deleted and replaced with your code creating the mesh of the maze.
    
    /**
    Building the maze
     */
    cout << maze << endl;
    
    int vertexNum = 0;
    
    // draw the floor
    vPos.push_back(0); vPos.push_back(0.0); vPos.push_back(0); vertexNum++;
    vPos.push_back(row); vPos.push_back(0); vPos.push_back(0); vertexNum++;
    vPos.push_back(0); vPos.push_back(0.0); vPos.push_back(col); vertexNum++;
    vPos.push_back(row); vPos.push_back(0); vPos.push_back(col); vertexNum++;
    vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);
    vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            if(maze[i][j] == '#'){
                vPos.push_back(i); vPos.push_back(0.0); vPos.push_back(j);    // vertex 0
                vPos.push_back(i); vPos.push_back(0.0); vPos.push_back(j+1);    // vertex 1
                vPos.push_back(i+1); vPos.push_back(0.0); vPos.push_back(j);    // vertex 2
                vPos.push_back(i+1); vPos.push_back(0.0); vPos.push_back(j+1);    // vertex 3
                
                vPos.push_back(i); vPos.push_back(1.0); vPos.push_back(j);    // vertex 0
                vPos.push_back(i); vPos.push_back(1.0); vPos.push_back(j+1);    // vertex 1
                vPos.push_back(i+1); vPos.push_back(1.0); vPos.push_back(j);    // vertex 2
                vPos.push_back(i+1); vPos.push_back(1.0); vPos.push_back(j+1);    // vertex 3
                
                vIdx.push_back(vertexNum); vIdx.push_back(vertexNum+1); vIdx.push_back(vertexNum+2);    // First triangle
                vIdx.push_back(vertexNum+1); vIdx.push_back(vertexNum+2); vIdx.push_back(vertexNum+3);    // Second triangle
                
                vIdx.push_back(vertexNum+4); vIdx.push_back(vertexNum+5); vIdx.push_back(vertexNum);
                vIdx.push_back(vertexNum+1); vIdx.push_back(vertexNum+0); vIdx.push_back(vertexNum+5);
                
                vIdx.push_back(vertexNum+1); vIdx.push_back(vertexNum+7); vIdx.push_back(vertexNum+5);
                vIdx.push_back(vertexNum+1); vIdx.push_back(vertexNum+3); vIdx.push_back(vertexNum+7);
                
                vIdx.push_back(vertexNum+0); vIdx.push_back(vertexNum+2); vIdx.push_back(vertexNum+4);
                vIdx.push_back(vertexNum+2); vIdx.push_back(vertexNum+6); vIdx.push_back(vertexNum+4);
                
                vIdx.push_back(vertexNum+2); vIdx.push_back(vertexNum+3); vIdx.push_back(vertexNum+6);
                vIdx.push_back(vertexNum+3); vIdx.push_back(vertexNum+7); vIdx.push_back(vertexNum+6);
                
                vIdx.push_back(vertexNum+4); vIdx.push_back(vertexNum+5); vIdx.push_back(vertexNum+7);
                vIdx.push_back(vertexNum+4); vIdx.push_back(vertexNum+7); vIdx.push_back(vertexNum+6);
                
                vertexNum += 8;
            }
        }
    }
	
}
