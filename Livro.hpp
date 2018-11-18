#ifndef LIVRO_HPP
#define LIVRO_HPP

/**
*@file Livro.hpp
*@brief Classe Livro
*@author x
*@version 1.0
*@date 17/11/2018
*/


#include "Item.hpp"

class Livro : public Item{
	private:

		bool _disponibilidade = true;

	public:
		
	
		/**
		*@brief construtor de Livro
		*@param titulo
		*@param autor
		*@param editora
		*@param disponibilidade
		*@return Livro
		*/
		Livro();
		Livro(string,string,string,bool);
	
		/**
		*@brief isDisponivel
		*@return _disponivel
		*/
		bool isDisponivel();
	
		/**
		*@brief mudarDisponibilidade
		*/
		void mudarDisponibilidade();
	
		/**
		*@brief imprimeCampos
		*/
		void imprimeCampos();
}

#endif
