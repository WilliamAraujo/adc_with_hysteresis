INCLUDE = ./include
LIB	    = ./lib
SRC     = ./src

FLAGS = -o3 -Wall
LIBS  = -led -L $(LIB)

all: libed myapps

libed: \
	adc_hysteresis.o \
	tests.o \
	log.o
	ar -rcs $(LIB)/libed.a *.o

myapps: clean_apps \
	main

%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

%: %.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

run:
	./main

clean:
	rm -rf $(LIB)/* *.o \
	main

clean_apps:
	rm -rf main
