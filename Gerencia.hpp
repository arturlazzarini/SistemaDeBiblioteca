#ifndef GERENCIA_HPP
#define GERENCIA_HPP

/**
*@file Gerencia.hpp
*@brief Classe Gerencia
*@author x
*@version 1.0
*@date 17/11/2018
*/

#include "Pessoa.hpp"
#include "Usuario.hpp"
#include "funcionario.hpp"
#include "Acervo.hpp"
#include <vector>

using std::vector;
using std::cout;
using std::cin;

class Gerencia{
	
	private:
		vector <Usuarios> _usuariosCadastrados;
		vector <Funcionarios> _funcionariosCadastrados;
		
	public:
	
		/**
		*@brief construtor de Gerencia
		*@return Gerencia
		*/
		Gerencia();
	
		/**
		*@brief setUsuariosCadastrado
		*@param novo
		*/
		void setUsuarioCadastrado(Usuario);
	
		/**
		*@brief setFuncionarioCadastrado
		*@param novo
		*/
		void setFuncionarioCadastrado(Funcionario);
	
		/**
		*@brief pesquisaFuncionario
		*@param idCadastro
		*@param senhaCadastro
		*@return inteiro
		*/
		int pesquisaFuncionario(int,string);
	
		/**
		*@brief pesquisaUsuario
		*@param idCadastro
		*@param senhaCadastro
		*@return inteiro
		*/
		int pesquisaUsuario(int,string);

};

#endif
