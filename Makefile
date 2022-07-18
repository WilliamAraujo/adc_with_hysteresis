SRC = src/adc_hysteresis.c \
	  src/tests.c \
	  unity/unity.c \
	  main.c

FLAGS = -o3 -Wall

INC = -Iunity \
	  -Iinclude

PROJECT_NAME = adc_hysteresis.out

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(FLAGS) $(INC) -o $(PROJECT_NAME)

run: $(PROJECT_NAME)
	./${PROJECT_NAME}

clean:
	rm -rf $(PROJECT_NAME)
