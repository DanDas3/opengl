#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

GLuint createShaderProgram()
{
    const char *vshaderSource =
            "void main(void)\n"
            "gl_Position = vec4(0.0,0.0,0.0,1.0);";

    const char *fshaderSource =
            "out vec4 color;\n"
            "void main(void)\n"
            "{if(gl_FragCoord.x < 200) color = vec4(1.0,0.0,0.0,1.0)); else color = vec4(0.0,0.0,1.0,1.0);}";

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vShader, 1, &vshaderSource, NULL);
    glShaderSource(fShader, 1 , &fshaderSource, NULL);
    glCompileShader(vShader);
    glCompileShader(fShader);

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    glLinkProgram(vfProgram);

    return vfProgram;
}
void init(GLFWwindow *window)
{
    renderingProgram = createShaderProgram();
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
}

void display(GLFWwindow *window, double currentTime)
{
//    glClearColor(1.0,0.0,0.0,1.0);
//    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(renderingProgram);
    glPointSize(30.0f);
    glDrawArrays(GL_POINTS, 0, 1);
}

int main()
{
    if(!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    GLFWwindow *window = glfwCreateWindow(600,600, "Chapter2 - program-1", NULL, NULL);
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK)
    {
        cout << "Initializing error" << endl;
        exit(EXIT_FAILURE);
    }

    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window))
    {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
