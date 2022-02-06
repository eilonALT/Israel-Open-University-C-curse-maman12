CREATOR =  gcc -Wall -ansi -pedantic

# Creating the final executable - magic.
magic: magic.o util.o
	$(CREATOR) -g magic.o util.o -o magic


# Creating magic.o file.
magic.o: magic.c util.h
	$(CREATOR) -c magic.c -o magic.o

# Creating magic.o file.
util.o: util.c util.h
	$(CREATOR) -c util.c -o util.o
