#ifndef ITEM_HPP
#define ITEM_HPP

/**
*@file Item.hpp
*@brief Classe Item
*@author x
*@version 1.0
*@date 17/11/2018
*/


#include <stdbool.h>
#include <string>
#include <iostrem>

using std::cout
using std::cin
using std::string

class Item{

	private:
	
		string _titulo;
		string _autor;
		string _editora;
		bool _disponibilidade;
		
	public:
		
		/**
		*@brief construtor de Item
		*@param titulo
		*@param autor
		*@param editora
		*@param disponibilidade
		*@return objeto
		*/
		Item();
		Item(string,string,string,bool);
		
		/**
		*@brief setTitulo 
		*@param titulo
		*/
		void setTitulo(string);
		
		/**
		*@brief setAutor 
		*@param autor
		*/
		void setAutor(string autor);	
		
		/**
		*@brief setEditora
		*@param editora
		*/
		void setEditora(string);			
		
		/**
		*@brief  getTitulo
		*@return titulo
		*/
		string getTitulo();
		
		/**
		*@brief  getAutor
		*@return autor
		*/
		string getAutor();
		
		/**
		*@brief  getEditora
		*@return editora
		*/
		string getEditora();			
		
		/**
		*@brief  imprimeCampos
		*/
		virtual void imprimeCampos();
		
		/**
		*@brief  isDisponivel
		*/
		virtual bool isDisponivel();

};

#endif
