#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <GLFW/glfw3.h>

using namespace std;

int main()
{
	glm::vec3 v(1, 2, 3);
	cout << "Vector: " << glm::to_string(v) << endl;

	if (glfwInit())
	{
		cout << "GLFW Initialized with success!" << endl;
	}
	else
	{
		cout << "GLFW Initialized failed!" << endl;
	}

	if (glewInit() == GLEW_OK)
	{
		cout << "GLEW Initialized with success!" << endl;
	}
	else
	{
		cout << "GLEW Initialized failed!" << endl;
	}
	return 0;
}