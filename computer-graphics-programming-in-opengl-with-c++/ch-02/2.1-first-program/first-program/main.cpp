#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];


float x = 0.0f;     // Location of triangle on x axis
float inc = 0.01f;  // offset for moving the triangle

/**
  Reading shaders from a file
*/
string readShaderSource(const char* filePath)
{
    string content;
    ifstream fileStream(filePath, ios::in);
    string line = "";

    while (!fileStream.eof())
    {
        getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

/**
  Checking errors
*/
void printShaderLog(GLuint shader)
{
    int len = 0;
    int chWrittn = 0;
    char* log;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);

    if (len > 0)
    {
        log = (char*)malloc(len);
        glGetShaderInfoLog(shader, len, &chWrittn, log);
        cout << "Shader Info Log: " << log << endl;
        free(log);
    }
}

void printProgramLog(int prog)
{
    int len = 0;
    int chrWrittn = 0;
    char* log;

    glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
    if (len > 0)
    {
        log = (char*)malloc(len);
        glGetProgramInfoLog(prog, len, &chrWrittn, log);
        cout << "Program Info Log: " << log << endl;
        free(log);
    }
}

bool checkOpenGLError()
{
    bool foundError = false;
    int glErr = glGetError();

    while (glErr != GL_NO_ERROR)
    {
        cout << "glError: " << glErr << endl;
        foundError = true;
        glErr = glGetError();
    }
    return foundError;
}
GLuint createShaderProgram()
{
    GLint vertCompiled;
    GLint fragCompiled;
    GLint linked;
    string vertShaderStr = readShaderSource("shaders/triangleVertShader.vert");
    string fragShaderStr = readShaderSource("shaders/fragShader.frag");
    const char* vertShaderSrc = vertShaderStr.c_str();
    const char* fragShaderSrc = fragShaderSrc = fragShaderStr.c_str();

    //    const char *vshaderSource =
    //            "void main(void)\n"
    //            "gl_Position = vec4(0.0,0.0,0.0,1.0);";

    //    const char *fshaderSource =
    //            "out vec4 color;\n"
    //            "void main(void)\n"
    //            "{if(gl_FragCoord.x < 200) color = vec4(1.0,0.0,0.0,1.0)); else color = vec4(0.0,0.0,1.0,1.0);}";

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    //    glShaderSource(vShader, 1, &vshaderSource, NULL);
    //    glShaderSource(fShader, 1 , &fshaderSource, NULL);
    glShaderSource(vShader, 1, &vertShaderSrc, NULL);
    glShaderSource(fShader, 1, &fragShaderSrc, NULL);
    glCompileShader(vShader);
    // Catch errors
    checkOpenGLError();
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
    if (vertCompiled != 1)
    {
        cout << "Vertex compilation failed!" << endl;
        printShaderLog(vShader);
    }
    glCompileShader(fShader);
    // Catch errors
    checkOpenGLError();
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
    if (fragCompiled != 1)
    {
        cout << "Fragment shader compilation failed!" << endl;
        printShaderLog(fShader);
    }

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    glLinkProgram(vfProgram);

    // Catch errors while linking shader
    checkOpenGLError();
    glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
    if (linked != 1)
    {
        cout << "Linking failed!" << endl;
        printProgramLog(vfProgram);
    }
    return vfProgram;
}
void init(GLFWwindow* window)
{
    renderingProgram = createShaderProgram();
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
}

void display(GLFWwindow* window, double currentTime)
{
    glClear(GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(renderingProgram);
    x += inc;
    if (x > 1.0f)
    {
        inc = -0.1f;
    }
    if (x < -1.0f)
    {
        inc = 1.0f;
    }
    GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset");
    glProgramUniform1f(renderingProgram, offsetLoc, x);
    glPointSize(30.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main()
{
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    //    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    //    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter2 - program-1", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        cout << "Initializing error" << endl;
        exit(EXIT_FAILURE);
    }

    glfwSwapInterval(1);
    init(window);

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
