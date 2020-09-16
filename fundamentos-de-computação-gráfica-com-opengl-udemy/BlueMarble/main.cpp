#include <cassert>
#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <GLFW/glfw3.h>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
	// Inicializa o GLFW
	assert(glfwInit() == GL_TRUE);

	// Criar a janela
	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Blue Marble", nullptr, nullptr);

	// Define o contexto ativo do OpenGL
	glfwMakeContextCurrent(window);

	// Inicializa a GLEW
	assert(glewInit() == GLEW_OK);

	GLint GLMajorVersion = 0;
	GLint GLMinorVersion = 0;

	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);

	//cout << "OpenGL version: " << GLMajorVersion << "." << GLMinorVersion << "." << endl;

	// Obtendo informações
	cout << "OpenGL Vendor	:" << glGetString(GL_VENDOR) << endl;
	cout << "OpenGL Renderer:" << glGetString(GL_RENDERER) << endl;
	cout << "OpenGL Version	:" << glGetString(GL_VERSION) << endl;
	cout << "GLSL Version	:" << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

	// Define a cor padrão ao limpar o buffer de cor
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		// Limpa o buffer de cor com a cor de fundo predefinida
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();

		glfwSwapBuffers(window);
	}

	// Encerra o GLFW
	glfwTerminate();
	return 0;
}