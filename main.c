#include <stdio.h>
#include <GLFW/glfw3.h>
#include "src/engine.h"

Engine engine = {0};

unsigned int initState1() {
  printf("state 1 created\n");
  return 0;
}

unsigned int updateState1(float deltatime) {
  printf("state 1 update %f\n", deltatime);
  return 0;
}

unsigned int drawState1(float deltatime) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    /* Swap front and back buffers */
    glfwSwapBuffers((&engine.graphics)->window);
    /* Poll for and process events */
    glfwPollEvents();    
    return 0;
}

unsigned int destroyState1() {
  printf("state 1 destroyed\n");
  return 0;
}

int main() {
  struct EngineOptions options = {0};
  options.title = "C engine test";
  options.width = 480;
  options.height = 272;

  ENGINE_init(&engine, &options);

  State state1 = {0};
  state1.init = initState1;
  /* state1.update = updateState1; */
  state1.draw = drawState1;
  state1.destroy = destroyState1;
  STATEMANAGER_push(&engine.statemanager, &state1);

  while (!glfwWindowShouldClose((&engine.graphics)->window)) {
      STATEMANAGER_update(&engine.statemanager, 10.0f);
      STATEMANAGER_draw(&engine.statemanager, 10.0f);
  }

  ENGINE_free(&engine);
}
