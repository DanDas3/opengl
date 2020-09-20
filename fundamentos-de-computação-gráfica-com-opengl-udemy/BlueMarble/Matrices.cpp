#include <iostream>
#include <iomanip>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

using namespace std;

void PrintMatrix(const glm::mat4 &M)
{
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < 4; ++i)
		{
			cout << setw(10) << setprecision(4) << fixed << M[i][j] << " ";
		}
		cout << endl;
	}
}

void Translate()
{
	cout << "*---------------------*" << endl;
	cout << "*---- Translation ----*" << endl;
	cout << "*---------------------*" << endl;

	glm::mat4 I = glm::identity<glm::mat4>();
	glm::vec3 T{ 10, 0, 10 }; // Deslocamento
	glm::mat4 Translation = glm::translate(I, T);
	PrintMatrix(Translation);

	glm::vec4 Position{ 10,10,10,1 };
	glm::vec4 Direction{ 10,10,10,0 };

	cout << endl;
	cout << "Posicao inicial: " << to_string(Position) << endl;
	Position = Translation * Position;
	Direction = Translation * Direction;

	cout << "Posicao deslocada: " << to_string(Position) << endl;
	cout << "Direcao: " << glm::to_string(Direction) << endl;

	cout << endl;
}

void Scale(int x=0)
{
	cout << "*---------------------*" << endl;
	cout << "*------- Scale -------*" << endl;
	cout << "*---------------------*" << endl;

	glm::mat4 I = glm::identity<glm::mat4>();
	glm::vec3 ScaleAmount{ 2, 2, 2 }; // Deslocamento
	glm::mat4 Scale = glm::scale(I, ScaleAmount); // Matriz de escala
	
	PrintMatrix(Scale);

	glm::vec4 Position{ 10,10,5,1 };
	glm::vec4 Direction{ 10,10,5,0 };

	cout << endl;
	cout << "Posicao inicial: " << to_string(Position) << endl;
	cout << "Direcao inicial: " << to_string(Direction) << endl;

	Position = Scale * Position;
	Direction = Scale * Direction;

	cout << "Posicao escalonada: " << to_string(Position) << endl;
	cout << "Direcao escalonada: " << glm::to_string(Direction) << endl;

	cout << endl;
}
/// <summary>
/// Função de teste para demonstrar uma aplicação de rotacão
/// </summary>
void Rotate()
{
	cout << "*---------------------*" << endl;
	cout << "*------- Rotate ------*" << endl;
	cout << "*---------------------*" << endl;

	glm::mat4 I = glm::identity<glm::mat4>();
	constexpr float Angle = glm::radians((float)90);
	glm::vec3 Axis{ 0, 0, 1 }; // Indica em torno de qual eixo a rotação será aplicada
	glm::mat4 Rotation = glm::rotate(I, Angle, Axis); // Matriz de rotação

	PrintMatrix(Rotation);

	glm::vec4 Position{ 100,0,0,1 };
	glm::vec4 Direction{ 100,0,0,0 };

	cout << endl;
	cout << "Posicao inicial: " << to_string(Position) << endl;
	cout << "Direcao inicial: " << to_string(Direction) << endl;

	Position = Rotation * Position;
	Direction = Rotation * Direction;

	cout << "Posicao rotacionada: " << to_string(Position) << endl;
	cout << "Direcao rotacionada: " << glm::to_string(Direction) << endl;

	cout << endl;
}

int main()
{
	Translate();

	Scale();

	Rotate();
	return 0;
}