#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <iostream>
#include <cstdlib>
#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Gerencia.hpp"
#include "Usuario.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Biblioteca{

private:

	Usuario *usuario;
	Funcionario *funcionario;
	Gerencia *administrador; 

public:
	
	Biblioteca();
	~Biblioteca();
	void interfacePrincipal();
	void determinaInterface();
	void interfaceUsuario();
	int login(Pessoa *p);
	void interfaceFuncionario();
	void desalocaDados();

};

class LoginInvalidoError: public std::exception{

        virtual const char* what()const throw(){

            return "LoginInvalidoError";

        }

};

#endif



