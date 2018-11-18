#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

/**
*@file Funcionario.hpp
*@brief Classe Funcionario
*@author x
*@version 1.0
*@date 17/11/2018
*/


#include "Gerencia.hpp"
#include "Pessoa.hpp"
#include "Acervo.hpp"

class Funcionario : public Pessoa{

    public:	
	
		/**
		*@brief construtor de Funcionario
		*@param nome
		*@param senha
		*@param id
		*@return Funcionario
		*/
		Funcionario();
		Funcionario(string,string,id);
	
		/**
		*@brief adicionarLivros
		*@param acervo
		*@param titulo
		*@param autor
		*@param editora
		*/
		void adicionarLivros(Acervo*,string,string,string);
	
		/**
		*@brief removerLivros
		*@param acervo
		*@param titulo
		*@param autor
		*@param editora
		*/
		void removerLivros(Acervo*,string,string,string);
	
		/**
		*@brief adicionarMultimidias
		*@param acervo
		*@param titulo
		*@param autor
		*@param editora
		*/
		void adicionarMultimidias(Acervo*,string,string,string,string,bool);
	
		/**
		*@brief removerMultimidias
		*@param acervo
		*@param titulo
		*@param autor
		*@param editora
		*/
		void removerMultimidias(Acervo*,string,string,string,string,bool);
	
		/**
		*@brief cadastrarUsuario
		*@param adm
		*@param nome
		*@param senha
		*@param id
		*/
		void cadastrarUsuario(Gerencia *adm, string nome, string senha, string id);
	
		/**
		*@brief cadastrarFuncionario
		*@param adm
		*@param nome
		*@param senha
		*@param id
		*/
		void cadastrarFuncionario(Gerencia *adm, string nome, string senha, string id);
};

#endif
