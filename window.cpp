#include "window.h"

int Window::get_width() const
{
	return width;
}

int Window::get_height() const
{
	return height;
}

void Window::setup(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(window_name.c_str());
	glewInit();

	glutDisplayFunc(&display);
	glutIdleFunc(&display);
	glutReshapeFunc(&reshape);
	glutKeyboardFunc(&keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	//glShadeModel(GL_SMOOTH);

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	//glMatrixMode(GL_MODELVIEW);
}

void Window::start()
{
	glutMainLoop();
}

void Window::set_width(const int new_width)
{
	width = new_width;
}

void Window::set_height(const int new_height)
{
	height = new_height;
}

void Window::set_size(const int new_width, const int new_height)
{
	width = new_width;
	height = new_height;
}

void Window::set_name(std::string name)
{
	window_name = name;
}

void Window::reshape(const int new_width, const int new_height)
{
	glViewport(0, 0, new_width, new_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (new_height == 0)
		gluPerspective(80, (float)new_width, 1.0, 5000.0);
	else
		gluPerspective(80, (float)new_width / (float)new_height, 1.0, 5000.0);
	glMatrixMode(GL_MODELVIEW);
}

void Window::keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void Window::mouse(int button, int state, int x, int y)
{

}

// Mouse Interaction
void Window::motion(int x, int y)
{

}

void Window::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	game();
	draw();
	glutPostRedisplay();
	glutSwapBuffers();
}