#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <iostream>
#include <cstdlib>
#include <exception>
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
	void interfaceUsuario(int interfaceTipo);
	int telaInicial(int tipoUsuario);
	void menuUsuario(int &acesso);
	void menuFuncionario(int &acesso);
	int login(Pessoa *p,Gerencia *adm,int tipoUsuario);
	void interfaceFuncionario();
	void desalocaDados();

};
class LoginInvalido: public std::exception{

        virtual const char* what()const throw(){

            return "LoginInvalido";
        }
};

#endif
