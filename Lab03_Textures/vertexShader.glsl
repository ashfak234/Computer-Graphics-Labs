#version 330 core

layout(location = 0) in vec3 position;

out vec3 Colour;

void main()
{
    //postion.x postion.y postion.z or just postiion
    // Output vertex position
    gl_Position = vec4(position, 1.0);
}
