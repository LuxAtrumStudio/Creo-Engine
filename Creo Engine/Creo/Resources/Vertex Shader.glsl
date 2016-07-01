#version 330
layout(location = 0) in vec3 vertexPosition_ModelSpace;
void main(){
	gl_Position.xyz = vertexPosition_ModelSpace;
	gl_Position.w = 1.0;
}