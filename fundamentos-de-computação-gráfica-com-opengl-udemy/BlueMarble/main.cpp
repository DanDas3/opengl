#include <cassert>
#include <iostream>
#include <array>
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

	//Define um triângulo em coordenadas normalizadas

	array<glm::vec3, 3> triangle = {
		glm::vec3 {-1.0f, -1.0f, 0.0f},
		glm::vec3 {1.0f, -1.0f, 0.0f},
		glm::vec3 {0.0f,1.0f,0.0f}
	};

	// Passar os vértices para a GPU
	GLuint vertexBuffer;

	// Criar o identificador do vertexBuffer
	glGenBuffers(1, &vertexBuffer);

	// Ativa o vertexBuffer 
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	// Copia os dados para a memória de vídeo
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle.data(), GL_STATIC_DRAW);
	
	// Define a cor padrão ao limpar o buffer de cor
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		// Limpa o buffer de cor com a cor de fundo predefinida
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		// Desenha o triangulo
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();

		glfwSwapBuffers(window);
	}
	glDeleteBuffers(1,&vertexBuffer);
	// Encerra o GLFW
	glfwTerminate();
	return 0;
}