#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

/**
*@file Biblioteca.hpp
*@brief Classe Biblioteca
*@author x
*@version 1.0
*@date 17/11/2018
*/

#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>
#include "Funcionario.hpp"
#include "Gerencia.hpp"
#include "Usuario.hpp"
#include "Acervo.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Biblioteca{

private:

	Usuario *usuario;
	Funcionario *funcionario;
	Gerencia *administrador;
	Acervo *acervo;	

public:
	
	
	/**
	*@brief construtor de Biblioteca
	*@return Biblioteca
	*/
	Biblioteca();
	
	/**
	*@brief Destrutor de Biblioteca
	*/
	~Biblioteca();
	
	/**
	*@brief interfacePrincipal
	*/
	void interfacePrincipal();
	
	/**
	*@brief interfaceUsuario
	*@param interfaceTipo
	*/
	void interfaceUsuario(int interfaceTipo);
	
	/**
	*@brief telaInicial
	*@param tipoUsuario
	*@return inteiro
	*/
	int telaInicial(int tipoUsuario);
	
	/**
	*@brief menuUsuario
	*@param acesso
	*/
	void menuUsuario(int &acesso);
	
	/**
	*@brief menuFuncionario
	*@param acesso
	*/
	void menuFuncionario(int &acesso);
	
	/**
	*@brief login
	*@param tipoUsuario
	@return inteiro
	*/
	int login(int tipoUsuario);
	
	/**
	*@brief interfaceFuncionario
	*/
	void interfaceFuncionario();
	
	/**
	*@brief desalocaDados
	*/
	void desalocaDados();

};
class LoginInvalido: public std::exception{

        virtual const char* what()const throw(){

            return "LoginInvalido";
        }
};

#endif

