#define GLEW_DLL
#define GLFW_DLL

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>


int main() {
	
	if (!glfwInit()) {

		fprintf(stderr, "ERROR: could not start GLFW3. \n");
		return 1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(512, 512, "MainWindow", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	GLenum ret = glewInit();
	if (GLEW_OK != ret) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(ret));
		return 1;
	}
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.4, 0.5, 1.0, 0.0);

		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_LINE_LOOP);
		float PI = 3.1415926;
		float R = 1.0;
		GLfloat xA = R * cos(90 * PI / 180);
		GLfloat yA = R * sin(90 * PI / 180);
		GLfloat xB = R * cos(306 * PI / 180);
		GLfloat yB = R * sin(306 * PI / 180);
		GLfloat xC = R * cos(162 * PI / 180);
		GLfloat yC = R * sin(162 * PI / 180);
		GLfloat xD = R * cos(18 * PI / 180);
		GLfloat yD = R * sin(18 * PI / 180);
		GLfloat xE = R * cos(234 * PI / 180);
		GLfloat yE = R * sin(234 * PI / 180);
		glVertex2f(xA, yA);
		glVertex2f(xB, yB);
		glVertex2f(xC, yC);
		glVertex2f(xD, yD);
		glVertex2f(xE, yE);
		glColor3f(1.0, 1.0, 0.2);
		glEnd();

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;

}