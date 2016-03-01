#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Scene.h"
#include "RotateObject.h"

#include "BasicTexMat.h"
#include "BasicMat.h"
#include "AdDiffuseMat.h"
#include "AnimatedMat.h"
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

void main()
{
	Screen screen(WIDTH , HEIGHT , "OpenGL Test");
	screen.CreateWindow();
	
	Scene scene(&screen);
	
	Camera camera;
	Object cameraObj(&camera);
	scene.AddCamera(&camera);
	cameraObj.transform.Position = vec3(0, -2, -5);
	
	Object* nanosuit = scene.LoadFile<AnimatedMat>("./models/Ely_by_K._Atienza.fbx");
	nanosuit->AddComponent(new RotateObject());
	nanosuit->transform.Position -= vec3(1, 0, 0);
	nanosuit->transform.Scale = vec3(0.02);
	nanosuit = scene.LoadFile<BasicTexMat>("./models/nanosuit2/Nanosuit.obj");
	nanosuit->AddComponent(new RotateObject());
	nanosuit = scene.LoadFile<AdDiffuseMat>("./models/nanosuit2/Nanosuit.obj");
	nanosuit->AddComponent(new RotateObject());
	nanosuit->transform.Position -= vec3(-1, 0, 0);
	scene.UpdateLoop();
	
	glfwTerminate();
}