#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/shader.hpp>

// Function prototypes
void keyboardInput(GLFWwindow *window);

int main( void )
{
    // =========================================================================
    // Window creation - you shouldn't need to change this code
    // -------------------------------------------------------------------------
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1; 
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Lab02 Basic Shapes", NULL, NULL);
    
    if( window == NULL ){
        fprintf(stderr, "Failed to open GLFW window.\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    // -------------------------------------------------------------------------
    // End of window creation
    // =========================================================================
    
	// Ensure we can capture keyboard inputs
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    ////Define vertices
    //const float vertices[] = {
    //    // x     y      z
    //      -0.5f, -0.5f, 0.0f,
    //       0.5f, -0.5f, 0.0f,
    //       0.0f,  0.5f, 0.0f

    //};

    //// Define vertex colours
    //const float colours[] = {
    //    // R     G      B
    //       1.0f,  0.0f, 0.0f,
    //       0.0f,  1.0f, 0.0f,
    //       0.0f,  0.0f, 1.0f

    //};


    // Define vertices
    static const float vertices[] = {
        -0.9f, -0.5f, 0.0f,   // triangle 1
        -0.1f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.1f, -0.5f, 0.0f,   // triangle 2
         0.9f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f
    };

    // Define vertex colours
    static const float colours[] = {
        1.0f, 0.0f, 0.0f,    // triangle 1 (red)
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,    // triangle 2 (blue)
        0.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
    };

    // Create the Vertex Array Object (VAO)
    unsigned int VAO;
    glGenVertexArrays(1, &VAO); // generates a VAO with the name VAO
    glBindVertexArray(VAO); // binds the VAO (so that OpenGL knows that we are working with this current VAO)

    // Create Vertex Buffer Object (VBO)
    unsigned int VBO;
    glGenBuffers(1, &VBO); //generates a buffer object with the name VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//binds the VBO to GL_ARRAY_BUFFER which tells OpenGL that the VBO contains vertex attributes
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //creates a new data store for the VBO, tells OpenGL where to find the data that is to be stored in the VBO and what it is to be used for (GL_STATIC_DRAW means the data is not going to be modified)

    // Create colour buffer
    unsigned int colourBuffer;
    glGenBuffers(1, &colourBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);


    // Compile shader program
    unsigned int shaderID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");
    // Use the shader program
    glUseProgram(shaderID);

    // Render loop
	while (!glfwWindowShouldClose(window))
    {
        // Get inputs
        keyboardInput(window);
        
        // Clear the window
        glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Send the VBO to the shaders
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0,        // attribute
                              3,        // size
                              GL_FLOAT, // type
                              GL_FALSE, // normalise?
                              0,        // stride
                              (void*)0);// offset

        // Send the colour buffer to the shaders
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        // Draw the triangle

        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / (3 * sizeof(float)));
        glDisableVertexAttribArray(0);


		// Swap buffers
		glfwSwapBuffers(window); 
		glfwPollEvents();
	}
    
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return 0;
}

void keyboardInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
