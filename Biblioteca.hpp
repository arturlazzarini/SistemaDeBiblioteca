#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <iostream>
#include <cstdlib>
#include "Funcionario.hpp"
#include "Gerencia.hpp"
#include "Usuario.hpp"

using std::cout;
using std::endl;
using std::string;

class Biblioteca{

private:

	Usuario usuario;
	Funcionario funcionario;
	Gerencia administrador; 

public:
	
	Biblioteca();
	~Biblioteca();
	void interfacePrincipal();
	void determinaInterface();
	void interfaceUsuario();
	void login();
	void loginfuncionario();
	void desalocaDados();



};

#endif
