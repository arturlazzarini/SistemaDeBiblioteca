#ifndef MULTIMIDIA_HPP
#define MULTIMIDIA_HPP

/**
*@file Multimidia.hpp
*@brief Classe Multimidia
*@author x
*@version 1.0
*@date 17/11/2018
*/

#include "Item.hpp"
#include <string>

using std::string;
using std::cout;

class Multimidia : public Item{
	
	private:
		string _tipoMultimidia;
	
	public:
	
		
		/**
		*@brief construtor de Multimidia
		*@param titulo
		*@param autor
		*@param editora
		*@param tipo
		*@param disponibilidade
		*@return Multimidia
		*/
		Multimidia();
		Multimidia(string,string,string,string,bool);
	
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
