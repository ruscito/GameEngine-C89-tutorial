CFLAGS=`pkg-config --cflags glfw3`  -Wno-nullability-completeness -Wno-missing-declarations -Wno-deprecated-declarations
LIBS=`pkg-config --libs glfw3` -framework OpenGL
INC= -I include

game_engine:
	gcc $(CFLAGS) src/graphics.c src/statemanager.c src/engine.c main.c -o test -g  $(INC) $(LIBS)

clean:
	rm test