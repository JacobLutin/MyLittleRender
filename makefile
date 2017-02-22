OBJ = vectormath.o color.o image.o raytracer.o

main: $(OBJ)
	g++ $^ -g3 -gdwarf -o $@

%.o: %.cpp
	g++ -std=c++11 -g3 -gdwarf $^ -c

clean:
	rm -rf main *.o
