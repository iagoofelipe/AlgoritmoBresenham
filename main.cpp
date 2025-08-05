#include <GL/glut.h>
#include <math.h>

const int INITIAL_X = 200;
const int INITIAL_Y = 200;
const int NUM_COORDINATES = 19;
const int COORDINATES[NUM_COORDINATES][2] = {
	{0, 0},		{0, 25},
	{10, 25},	{10, 45},
	{0, 45},	{0, 60},
	{15, 60},	{30, 45},
	{30, 60},	{40, 60},
	{40, 45},	{55, 45},
	{55, 30},	{65, 30},
	{65, 0},	{50, 0},
	{25, 15},	{25, 0},
	{0, 0},
};

// desenha as linhas utilizando o algoritmo de Bresenham
void bresenhamLine(int x1, int y1, int x2, int y2) {
	int
		dx = abs(x2 - x1),
		dy = abs(y2 - y1),
		sx = x1 < x2 ? 1 : -1,
		sy = y1 < y2 ? 1 : -1,
		err = (dx > dy ? dx : dy) / 2,
		e2;

	while (true) {
		glBegin(GL_POINTS);
		glVertex2i(x1, y1);
		glEnd();

		if (x1 == x2 && y1 == y2) break;

		e2 = err;

		if (dx != 0 && e2 > -dx) {
			err -= dy;
			x1 += sx;
		}

		if (e2 < dy) {
			err += dx;
			y1 += sy;
		}
	}
}

// função de exibição chamada pelo GLUT
void display() {
	if (NUM_COORDINATES < 2) return;

	glClear(GL_COLOR_BUFFER_BIT);

	int
		x1 = COORDINATES[0][0] + INITIAL_X,
		y1 = COORDINATES[0][1] + INITIAL_Y,
		x2, y2;

	// desenhando as linhas (ignora a origem pois já é passado em x1 e x2)
	for (int i = 1; i < NUM_COORDINATES; i++) {
		x2 = COORDINATES[i][0] + INITIAL_X;
		y2 = COORDINATES[i][1] + INITIAL_Y;

		bresenhamLine(x1, y1, x2, y2);

		// armazenando o ponto de destino como origem da próxima coordenada
		x1 = x2;
		y1 = y2;
	}

	glFlush();
}

// inicializa as configurações do OpenGL e exibe a janela
void setup(int* argc, char** argv, const char* title, int width = 1280, int height = 720, int posX = 200, int posY = 200) {

	// configurações de inicialização
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(posX, posY);
	glutCreateWindow(title);

	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);
	gluOrtho2D(0, width, 0, height);

	glutDisplayFunc(display);
}

int main(int argc, char** argv) {
	setup(&argc, argv, "Algoritmo de Bresenham - Atividade Ativa");
	glutMainLoop(); // loop principal da aplicação

	return 0;
}