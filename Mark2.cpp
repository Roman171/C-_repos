#include"pch.h"
#include <string>
#include<cstdlib>
using namespace std;
#include "glut.h"
#include<math.h>
float winwid = 500;
float winhie = 500;
float angle = 0, Scale = 0.5 , X_=0 , Y_=0;
void* font = GLUT_BITMAP_TIMES_ROMAN_24;
//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glut32.lib")
#define PI 3.14
//#include<cmath>
//
void RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glBegin;
	// Начало нашего кода. Весь код - ниже!
	float angle = 0;
	int circle_points = 20;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circle_points; i++) {
		angle = 2 * PI*i / circle_points;
		glVertex2f(400 * cos(angle), 400 * sin(angle));


	}
	glEnd();
	Scale = 1 - abs(sin(3.14*angle / 90) / sqrt(3.0) / 2);
	glScalef(Scale, Scale, 1);
	glBegin(GL_LINES);
	for (float i = -winwid / 2; i <= winwid / 2; i += 20) {
		glVertex2f(i, -winhie / 2);
		glVertex2f(i, winhie / 2);

	}
	for (float i = -winhie / 2; i <= winhie / 2; i += 20) {
		glVertex2f(-winwid / 2, i);
		glVertex2f(winwid / 2, i);

	}
	glEnd();

	float theta, phi, x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glBegin(GL_LINES);
	for (phi = 0; phi <= 2 * PI; phi += PI / 50)
	{
		for (theta = -PI / 2; theta <= PI / 2; theta += PI / 50)
		{
			x = 300 * cos(theta)*cos(phi);
			y = 300 * cos(theta)*sin(phi);
			glVertex2f(x, y);
		}
	}

	glEnd();

	glPopMatrix();
	// Конец нашего кода. Весь код - выше!
	glutSwapBuffers();
	glutPostRedisplay();
}
//
void Initialize() {
	glClearColor(0.2, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-winwid / 2, winwid / 2, -winhie / 2, winhie / 2, -1500, 1500);

	glMatrixMode(GL_MODELVIEW);

}
//
void MouseScale(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		Scale = 0.90;
		glScalef(Scale, Scale, Scale);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

		Scale = 1.1;
		glScalef(Scale, Scale, Scale);
	}
	glutPostRedisplay();

}
//
//
//
//void Timer(int value) {
//
//
////	angle++;
//	//glRotatef(0.3, 1, 1 ,1);
//	glutPostRedisplay();
//	glutTimerFunc(30, Timer, rand() % 100);
//}
//void MouseRot(int x, int y) {
//	if (X_ < X_) {
//		X_ = -(X_ - X_);
//	}
//	else if (X_ > X_) {
//		X_ = X_ - X_;
//	}
//	else
//		X_ = X_;
//	
//	X_ += x;
//	glRotatef(0.3, 0, X_, 0);
//	//glutBitmapCharacter(font ,X_);
//}
//
//int main(int argc, char *argv[]) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA);
//	glutInitWindowPosition(300, 300);
//	glutInitWindowSize(winwid, winhie);
//	glutCreateWindow("Пример вывода 2D графики");
//	glutDisplayFunc(RenderScene);
//	glutTimerFunc(30, Timer, rand() % 100);
//	glutMouseFunc(MouseScale);
//	glutPassiveMotionFunc(PassiceMouse);
//	glutMotionFunc(MouseRot);
//
//		Initialize();
//	gluOrtho2D(-1, 1, -1, 1);
//
//
//	glutMainLoop();
//	return 0;
//}

float x1_ = -20.;
float y1_ = 0.;
float x2_ = 20.;
float y2_ = 0.;
string str;
string to_string(int val) {
	char buff[32];
	printf(buff, "%d", val);
	return string(buff);
}
void PassiceMouse(int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT);
		//glColor3f(1, 1, 1);
		X_ = x;
		Y_ = y;
		
	
	}
string sText()
{
	
	std::string sx1, sx2, sy1, sy2;
	sx1 = to_string(X_);
	sx2 = to_string(X_);
	sy1 = to_string(Y_);
	sy2 = to_string(Y_);
	str = str.empty();
	str += sx1;
	str += ",";
	str += sx2;
	str += ",";
	str += sy1;
	str += ",";
	str += sy2;
	str += ";";
	return str;
}
void drawText(const char* text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double* matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 400, 0, 400, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);

}

void display()
{
	str = sText();
	drawText(str.data(), str.size(), 10, 10);
	glutSwapBuffers();

}

void timer(int = 0)
{
	display();
	glutTimerFunc(1, timer, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA);
	glutInitWindowSize(winwid, winhie);
	glutInitWindowPosition(300, 300);
	
	
	glutCreateWindow("Points");
	glutMouseFunc(MouseScale);
	glMatrixMode(GL_PROJECTION);
	
	glutPassiveMotionFunc(PassiceMouse);	
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA);
		glutDisplayFunc(RenderScene);
	Initialize();
	glOrtho(-400, 400, -400, 400, -400, 400);
	timer();
	glLoadIdentity();
	glutMainLoop();	
	return 0;
}