#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 colour;

out vec3 fragmentColour;

void main()
{

	
	// shift to the right by 0.5 - gl_Position = vec4((position + vec3(0.5f, 0.0f, 0.0f)), 1);
	// make the triangle upside down - gl_Position = vec4(position.x, -position.y, position.z, 1);

	//Output vertex position
	gl_Position = vec4(position, 1);
	

	// Output vertex colour
	fragmentColour = colour;
}