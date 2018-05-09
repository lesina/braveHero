#include "GraphicStartup.h"
#include "../../logging.h"

GLFWwindow *GraphicStartup::window;
unsigned int GraphicStartup::SCR_WIDTH;
unsigned int GraphicStartup::SCR_HEIGHT;
glm::vec3 GraphicStartup::cameraPos;
glm::vec3 GraphicStartup::cameraFront;
glm::vec3 GraphicStartup::cameraUp;
bool GraphicStartup::firstMouse;
float GraphicStartup::fov;
float GraphicStartup::deltaTime;
float GraphicStartup::lastFrame;
Shader GraphicStartup::ourShader;
float GraphicStartup::vertices[] = {
        -0.1f, -0.1f, 0.0f, 0.0f, 0.0f,
        0.1f, -0.1f, 0.0f, 1.0f, 0.0f,
        0.1f, 0.1f, 0.0f, 1.0f, 1.0f,
        0.1f, 0.1f, 0.0f, 1.0f, 1.0f,
        -0.1f, 0.1f, 0.0f, 0.0f, 1.0f,
        -0.1f, -0.1f, 0.0f, 0.0f, 0.0f
};
float GraphicStartup::vertices2[] = {
        -0.1f, -0.1f, 0.0f, 0.0f, 0.0f,
        0.1f, -0.1f, 0.0f, 1.0f, 0.0f,
        0.1f, 0.1f, 0.0f, 1.0f, 1.0f,
        0.1f, 0.1f, 0.0f, 1.0f, 1.0f,
        -0.1f, 0.1f, 0.0f, 0.0f, 1.0f,
        -0.1f, -0.1f, 0.0f, 0.0f, 0.0f
};
glm::vec3 GraphicStartup::cubePositions[] = {
        glm::vec3(0.0f, -1.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f)
};
unsigned int GraphicStartup::VBO, GraphicStartup::VAO;
unsigned int GraphicStartup::textureHero, GraphicStartup::textureBullet, GraphicStartup::textureEnemy;
int GraphicStartup::width, GraphicStartup::height, GraphicStartup::nrChannels;
unsigned char *GraphicStartup::data;

void GraphicStartup::init() {
    braveLog::braveLogAlways("%s: Init graphics", __PRETTY_FUNCTION__);

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    SCR_WIDTH = Settings::GetScrWidth();
    SCR_HEIGHT = Settings::GetScrHeight();

    cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    firstMouse = true;
    fov = 45.0f;

    deltaTime = 0.0f;
    lastFrame = 0.0f;

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    braveAssertMsg(window, "%s", "Failed to create GLFW window");

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    braveAssertMsg(gladLoadGLLoader((GLADloadproc) glfwGetProcAddress), "%s", "Failed to initialize GLAD");

    glEnable(GL_DEPTH_TEST);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    initTexture(textureHero, "GameSDK/textures/hero.png");
    initTexture(textureBullet, "GameSDK/textures/bullet.png");
    initTexture(textureEnemy, "GameSDK/textures/awesomeface.png");

    ourShader = Shader("Code/SDK/FX/Shaders/Common.vs", "Code/SDK/FX/Shaders/Common.fs");
    ourShader.use();
    ourShader.setInt("textureHero", 0);
    ourShader.setInt("textureBullet", 1);
    ourShader.setInt("textureEnemy", 2);

    glm::mat4 projection = glm::perspective(glm::radians(fov), (float) SCR_WIDTH / (float) SCR_HEIGHT, 0.1f, 100.0f);
    ourShader.setMat4("projection", projection);

    glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    ourShader.setMat4("view", view);
}

void GraphicStartup::update() {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    processInput(window);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    BindTexture();

    ourShader.use();

    glBindVertexArray(VAO);
    for (unsigned int i = 0; i < 1; i++) {
        glm::mat4 model;
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        ourShader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void GraphicStartup::stop() {
    braveLog::braveLogAlways("%s: Stop graphics", __PRETTY_FUNCTION__);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
}

bool GraphicStartup::WindowShouldNotClose() {
    return !glfwWindowShouldClose(window);
}

void GraphicStartup::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        std::cout << "up" << std::endl;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        std::cout << "down" << std::endl;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        cubePositions[0].x -= cameraSpeed;
        std::cout << cameraSpeed << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        cubePositions[0].x += cameraSpeed;
        std::cout << cameraSpeed << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        std::cout << "shoot" << std::endl;
}

void GraphicStartup::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void GraphicStartup::mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    if (firstMouse) {
    }
}

void GraphicStartup::initTexture(unsigned int &p_texture, const char *n_texture) {
    glGenTextures(1, &p_texture);
    glBindTexture(GL_TEXTURE_2D, p_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(true);
    data = stbi_load(n_texture, &width, &height, &nrChannels, 0);

    braveEnsureMsg(data, "%s", "Failed to load texture") else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);
}

void GraphicStartup::BindTexture() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureHero);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, textureBullet);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, textureEnemy);
}