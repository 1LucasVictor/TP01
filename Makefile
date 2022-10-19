SRC:= src
ICL:= include
OBJ:= obj
BIN:= bin
EXE:= ${BIN}/tp

all: libs ${BIN}/tp 
libs: ${OBJ}/mail.o ${OBJ}/priority_queue.o ${OBJ}/account_list.o ${OBJ}/user.o 

${OBJ}/mail.o: ${ICL}/mail.hpp ${SRC}/mail.cpp
	c++ -c ${SRC}/mail.cpp -I ${ICL} -o ${OBJ}/mail.o
${OBJ}/priority_queue.o: ${ICL}/priority_queue.hpp ${SRC}/priority_queue.cpp
	c++ -c ${SRC}/priority_queue.cpp -I ${ICL} -o ${OBJ}/priority_queue.o
${OBJ}/account_list.o: ${SRC}/account_list.cpp
	c++ -c ${SRC}/account_list.cpp -I ${ICL} -o ${OBJ}/account_list.o
${OBJ}/user.o: ${SRC}/user.cpp
	c++ -c ${SRC}/user.cpp -I ${ICL} -o ${OBJ}/user.o
${BIN}/tp: ${OBJ}/main.o
	c++ -pg -Wall ${OBJ}/*.o -o bin/tp
${OBJ}/main.o: ${SRC}/main.cpp
	c++ -c ${SRC}/main.cpp -I ${ICL} -o ${OBJ}/main.o


clean: 
	rm ${OBJ}/*.o ${BIN}/tp