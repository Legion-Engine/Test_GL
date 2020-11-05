#include <iostream>
#include <common/gl.hpp>
#include <common/utils.hpp>

int main()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	auto monitor = glfwGetPrimaryMonitor();
	auto videoMode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, videoMode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, videoMode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, videoMode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, videoMode->refreshRate);
	glfwWindowHint(GLFW_SAMPLES, 16);

	auto window = glfwCreateWindow(WINDOW_W, WINDOW_H, "OpenGL Test", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		glEnable(GL_DEBUG_OUTPUT);

		glDebugMessageCallback([](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
			{
				cstring s;
				switch (source)
				{
				case GL_DEBUG_SOURCE_API:
					s = "OpenGL";
					break;
				case GL_DEBUG_SOURCE_SHADER_COMPILER:
					s = "Shader compiler";
					break;
				case GL_DEBUG_SOURCE_THIRD_PARTY:
					s = "Third party";
					break;
				case GL_DEBUG_SOURCE_APPLICATION:
					s = "Application";
					break;
				case GL_DEBUG_SOURCE_OTHER:
					s = "Other";
					break;
				default:
					s = "Unknown";
					break;
				}

				cstring t;

				switch (type)
				{
				case GL_DEBUG_TYPE_ERROR:
					t = "Error";
					break;
				case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
					t = "Deprecation";
					break;
				case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
					t = "Undefined behavior";
					break;
				case GL_DEBUG_TYPE_PERFORMANCE:
					t = "Performance";
					break;
				case GL_DEBUG_TYPE_PORTABILITY:
					t = "Portability";
					break;
				case GL_DEBUG_TYPE_MARKER:
					t = "Marker";
					break;
				case GL_DEBUG_TYPE_PUSH_GROUP:
					t = "Push";
					break;
				case GL_DEBUG_TYPE_POP_GROUP:
					t = "Pop";
					break;
				case GL_DEBUG_TYPE_OTHER:
					t = "Misc";
					break;
				default:
					t = "Unknown";
					break;
				}

				switch (severity)
				{
				case GL_DEBUG_SEVERITY_HIGH:
					printf("HIGH: [%s-%s] %s", s, t, message);
					break;
				case GL_DEBUG_SEVERITY_MEDIUM:
					printf("MEDIUM: [%s-%s] %s", s, t, message);
					break;
				case GL_DEBUG_SEVERITY_LOW:
					printf("LOW: [%s-%s] %s", s, t, message);
					break;
				case GL_DEBUG_SEVERITY_NOTIFICATION:
					printf("NOTE: [%s-%s] %s", s, t, message);
					break;
				default:
					printf("UNKNOWN: [%s-%s] %s", s, t, message);
					break;
				}
			}, nullptr);
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	glEnable(GL_MULTISAMPLE);

	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* version = glGetString(GL_VERSION);
	const unsigned char* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);

	printf("Initialized Renderer\n\tCONTEXT INFO\n\t----------------------------------\n\tGPU Vendor:\t%s\n\tGPU:\t\t%s\n\tGL Version:\t%s\n\tGLSL Version:\t%s\n\t----------------------------------\n", vendor, renderer, version, glslVersion);

	std::cout << "Hello GL\n";
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
	glfwTerminate();
	std::cin.ignore();
	return 0;
}
