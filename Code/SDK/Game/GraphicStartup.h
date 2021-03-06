#ifndef BRAVEHERO_GRAPHICSTARTUP_H
#define BRAVEHERO_GRAPHICSTARTUP_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Settings.h"
#include "../FX/Shader.h"
#include "../../stb_image.h"


class GraphicStartup {
public:
    static void init();

    static void update();

    static void stop();

    static bool WindowShouldNotClose();

private:
    GraphicStartup() {};

    GraphicStartup(GraphicStartup const &);

    GraphicStartup &operator=(GraphicStartup const &);

    static GLFWwindow *window;
    static unsigned int SCR_WIDTH;
    static unsigned int SCR_HEIGHT;

    static glm::vec3 cameraPos;
    static glm::vec3 cameraFront;
    static glm::vec3 cameraUp;

    static bool firstMouse;
    static float fov;

    static float deltaTime;
    static float lastFrame;

    static Shader ourShader;

    static float vertices[];
    static float vertices2[];
    static glm::vec3 cubePositions[];

    static unsigned int VBO, VAO;
    static unsigned int textureHero, textureBullet, textureEnemy;

    static int width, height, nrChannels;
    static unsigned char *data;

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    static void mouse_callback(GLFWwindow *window, double xpos, double ypos);

    static void processInput(GLFWwindow *window);

    static void initTexture(unsigned int &, const char *);

    static void BindTexture();
};


#endif //BRAVEHERO_GRAPHICSTARTUP_H
