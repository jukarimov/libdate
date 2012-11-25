
OBJ = main.o date.o

date: ${OBJ}
	cc ${OBJ} -o $@

clean:
	rm -f date *.o

