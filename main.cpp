#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int main() {
    // Create an SFML window that supports OpenGL
    sf::Window window(sf::VideoMode(800, 600), "SFML + OpenGL", sf::Style::Default, sf::ContextSettings(24));
    window.setVerticalSyncEnabled(true);

    // Initialize GLEW
    // glewExperimental = GL_TRUE;
    // if (glewInit() != GLEW_OK) {
    //     return -1;
    // }

    // Set the color and depth clear values
    glClearDepth(1.f);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection using GLM
    glm::mat4 projection = glm::perspective(glm::radians(90.0f), 800.0f / 600.0f, 1.0f, 500.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(&projection[0][0]);

    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw a triangle
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -1.5f);
            glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -1.5f);
            glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 0.0f,  0.5f, -1.5f);
        glEnd();    // glewExperimental = GL_TRUE;
    // if (glewInit() != GLEW_OK) {
    //     return -1;
    // }

        // Finally, display the rendered frame on screen
        window.display();
    }

    return 0;
}
