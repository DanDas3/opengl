#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
using namespace std;

void init(GLFWwindow *window){}

void display(GLFWwindow *window, double currentTime)
{
    glClearColor(1.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main()
{
    if(!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    GLFWwindow *window = glfwCreateWindow(600,800, "Chapter2 - program-1", NULL, NULL);
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
