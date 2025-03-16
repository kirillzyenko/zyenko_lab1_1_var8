#define GLEW_DLL
#define GLFW_DLL
#include <cstdio>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <math.h>
#include "shader_loader.h"

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: couldn't start GLFW3\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Help", nullptr, nullptr);
    if (!window) {
        fprintf(stderr, "sob");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "ERROR: %s\n", glewGetErrorString(ret));
        return 1;
    }

    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);


    GLfloat points[] = {
    -0.25f, 0.0f,0.0f,//0
    0.0f, 1.0f,0.0f,//1
    0.25f, 0.0f,0.0f,//2
    -1.0f, 0.0f,0.0f,//3
    -0.25f, -0.40f,0.0f,//4
    1.0f, 0.0f,0.0f,//5
    0.25f, -0.40f,0.0f,//6
    -0.75f, -1.0f,0.0f,//7
    0.25f, -0.40f,0.0f,//8
    0.75f, -1.0f,0.0f,//9
    -0.25f, -0.40f,0.0f//10
    };

    GLuint elements[] = {
    0,1,2,
    3,4,0,
    2,5,6,
    4,7,8,
    6,9,10,
    0,4,6,
    0,2,6
    };

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STREAM_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STREAM_DRAW);

    
    Shader_loader shadering;
    GLuint shader_program = shadering.oneLinkProgram();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0); 
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shader_program);
        float timeValue = glfwGetTime();

        points[0] = points[0] + cos(timeValue) / 20000;
        points[1] = points[1] + cos(timeValue) / 20000;
        points[3] = points[3] + cos(timeValue) / 20000;
        points[4] = points[4] + cos(timeValue) / 20000;
        points[6] = points[6] + cos(timeValue) / 20000;
        points[7] = points[7] + cos(timeValue) / 20000;
        points[9] = points[9] + cos(timeValue) / 20000;
        points[10] = points[10] + cos(timeValue) / 20000;
        points[12] = points[12] + cos(timeValue) / 20000;
        points[13] = points[13] + cos(timeValue) / 20000;
        points[15] = points[15] + cos(timeValue) / 20000;
        points[16] = points[16] + cos(timeValue) / 20000;
        points[18] = points[18] + cos(timeValue) / 20000;
        points[19] = points[19] + cos(timeValue) / 20000;
        points[21] = points[21] + cos(timeValue) / 20000;
        points[22] = points[22] + cos(timeValue) / 20000;
        points[24] = points[24] + cos(timeValue) / 20000;
        points[25] = points[25] + cos(timeValue) / 20000;
        points[27] = points[27] + cos(timeValue) / 20000;
        points[28] = points[28] + cos(timeValue) / 20000;
        points[30] = points[30] + cos(timeValue) / 20000;
        points[31] = points[31] + cos(timeValue) / 20000;

        glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

        shadering.uniform_set_vec(shader_program, "in_color", 1 - sin(timeValue), cos(timeValue), sin(timeValue), 1.0f);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 21, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
