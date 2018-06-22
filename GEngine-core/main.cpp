#include <iostream>
#include <GLFW\glfw3.h>


void foo(void) {
	std::cout << "hello world" << std::endl;
	return;
}

int main(){
	int a = 5;
	if (!glfwInit())
		std::cout << "error" << std::endl;
	else
		std::cout << "yeet nigga" << std::endl;
	foo();
	return 0;
}