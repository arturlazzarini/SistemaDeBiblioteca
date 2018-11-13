#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

class Biblioteca{

private:

	Usuario usuario;
	Funcionario funcionario;

public:

	Sistema();
	~Sistema();
	void loginUsuario();
	void loginfuncionario();
	void interfacePrincipal();
	void determinaInterface();
	void interfaceUsuario();
	void interfaceFuncionario();
	void desalocaDados();

};

#endif