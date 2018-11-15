CC=g++
CFLAGS=-std=c++11 -Wall
BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
all: ${BUILD_DIR}/main
${BUILD_DIR}/Pessoa.o: ${INCLUDE_DIR}/TRABALHOFINAL/Pessoa.hpp ${SRC_DIR}/TRABALHOFINAL/Pessoa.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/TRABALHOFINAL/Pessoa.cpp -o ${BUILD_DIR}/Pessoa.o
${BUILD_DIR}/Acervo.o: ${INCLUDE_DIR}/TRABALHOFINAL/Acervo.hpp ${SRC_DIR}/TRABALHOFINAL/Acervo.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/TRABALHOFINAL/Acervo.cpp -o ${BUILD_DIR}/Acervo.o
${BUILD_DIR}/Biblioteca.o: ${INCLUDE_DIR}/TRABALHOFINAL/Biblioteca.hpp ${SRC_DIR}/TRABALHOFINAL/Biblioteca.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/TRABALHOFINAL/Biblioteca.cpp -o ${BUILD_DIR}/Biblioteca.o
${BUILD_DIR}/Funcionario.o: ${INCLUDE_DIR}/TRABALHOFINAL/Funcionario.hpp ${SRC_DIR}/TRABALHOFINAL/Funcionario.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/TRABALHOFINAL/Funcionario.cpp -o ${BUILD_DIR}/Funcionario.o
${BUILD_DIR}/Gerencia.o: ${INCLUDE_DIR}/TRABALHOFINAL/Gerencia.hpp ${SRC_DIR}/TRABALHOFINAL/Gerencia.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/TRABALHOFINAL/Gerencia.cpp -o ${BUILD_DIR}/Gerencia.o
${BUILD_DIR}/Item.o: ${INCLUDE_DIR}/TRABALHOFINAL/Item.hpp ${SRC_DIR}/TRABALHOFINAL/Item.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/TRABALHOFINAL/Item.cpp -o ${BUILD_DIR}/Item.o
${BUILD_DIR}/Livro.o: ${INCLUDE_DIR}/TRABALHOFINAL/Livro.hpp ${SRC_DIR}/TRABALHOFINAL/Livro.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/TRABALHOFINAL/Livro.cpp -o ${BUILD_DIR}/Livro.o
${BUILD_DIR}/Multimidia.o: ${INCLUDE_DIR}/TRABALHOFINAL/Multimidia.hpp ${SRC_DIR}/TRABALHOFINAL/Multimidia.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/TRABALHOFINAL/Multimidia.cpp -o ${BUILD_DIR}/Multimidia.o
${BUILD_DIR}/Usuario.o: ${INCLUDE_DIR}/TRABALHOFINAL/Usuario.hpp ${SRC_DIR}/TRABALHOFINAL/Usuario.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/TRABALHOFINAL/Usuario.cpp -o ${BUILD_DIR}/Usuario.o
${BUILD_DIR}/main.o: ${INCLUDE_DIR}/TRABALHOFINAL/Pessoa.hpp ${INCLUDE_DIR}/TRABALHOFINAL/Acervo.hpp ${INCLUDE_DIR}/TRABALHOFINAL/Biblioteca.hpp ${INCLUDE_DIR}/TRABALHOFINAL/Funcionario.hpp ${INCLUDE_DIR}/TRABALHOFINAL/Gerencia.hpp ${INCLUDE_DIR}/TRABALHOFINAL/Item.hpp ${INCLUDE_DIR}/TRABALHOFINAL/Livro.hpp ${INCLUDE_DIR}/TRABALHOFINAL/Multimidia.hpp ${INCLUDE_DIR}/TRABALHOFINAL/Usuario.hpp ${SRC_DIR}/main.cpp
${CC} ${CFLAGS} -I ${INCLUDE_DIR}/TRABALHOFINAL/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o
${BUILD_DIR}/main: ${BUILD_DIR}/Pessoa.o ${BUILD_DIR}/Acervo.o ${BUILD_DIR}/Biblioteca.o ${BUILD_DIR}/Funcionario.o ${BUILD_DIR}/Gerencia.o ${BUILD_DIR}/Item.o ${BUILD_DIR}/Livro.o ${BUILD_DIR}/Usuario.o ${BUILD_DIR}/main.o
${CC} ${CFLAGS} -o ${BUILD_DIR}/main ${BUILD_DIR}/*.o
# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean:
rm -f ${BUILD_DIR}/* 
