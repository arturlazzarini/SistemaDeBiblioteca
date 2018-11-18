#ifndef PESSOA_HPP
#define PESSOA_HPP


/**
*@file Pessoa.hpp
*@brief Classe Pessoa
*@author x
*@version 1.0
*@date 17/11/2018
*/

#include <iostream>
#include <string.h>

using namespace std;

class Pessoa{
	
	private:
		string _nome;
		string _senha;
		int _id = 0;
	
	public:
	
	
		/**
		*@brief construtor de Pessoa
		*@param nome
		*@param senha
		*@param id
		*@return objeto
		*/
		Pessoa(string, string, int){

		
		/**
		*@brief setNome
		*@param nome
		*/
		void setNome(string nome);

		/**
		*@brief setSenha
		*@param senha
		*/
		void setSenha(string senha);

		/**
		*@brief setId
		*@param id
		*/
		void setId(int id);

		/**
		*@brief  getNome 
		*@return _nome
		*/
		string getNome();

		/**
		*@brief  getSenha
		*@return _senha
		*/
		string getSenha();

		/**
		*@brief  getId
		*@return _id
		*/
		string getId();

};
	
#endif
