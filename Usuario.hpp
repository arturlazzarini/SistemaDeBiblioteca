#ifndef USUARIO_HPP
#define USUARIO_HPP


/**
*@file Usuario.hpp
*@brief Usuario
*@author x
*@version 1.0
*@date 18/11/2018
*/


#include "Pessoa.hpp"
#include "Item.hpp"
#include <vector>

class Usuario : public Pessoa{

	private:

		vector<Livros> _livrosAlugados;
		vector<Multimidia> _multimidiaAlugados;
		vector<Livros> _livrosReservados;
		vector<Multimidia> _multimidiaReservados;

	public:
		/**
		*@brief construtor de Usuario
		*@param nome
		*@param senha
		*@param id
		*@return objeto
		*/	
		Usuario();
		Usuario(string,string,id);
	
		/**
		*@brief alugarLivro
		*@param item
		*/
		void alugarLivro(Livro);
	
		/**
		*@brief reservarLivro
		*@param item
		*/
		void reservarLivro(Livro);
	
		/**
		*@brief devolverLivro
		*@param item
		*/
		void devolverLivro(string);
	
		/**
		*@brief alugarMultimidia
		*@param item
		*/
		void alugarMultimidia(Multimidia);
	
		/**
		*@brief reservarMultimidia
		*@param item
		*/
		void reservarMultimidia(Multimidia);
	
		/**
		*@brief devolverMultimidia
		*@param item
		*/
		void devolverMultimidia(string);
	
		/**
		*@brief imprimeLivrosAlugados
		*@return livros alugados
		*/
		void imprimeLivrosAlugados();
	
		/**
		*@brief imprimeLivrosReservados
		*@return livros reservados
		*/
		void imprimeLivrosReservados();
	
		/**
		*@brief imprimeMultimidiaAlugados
		*@return multimidias alugadas
		*/
		void imprimeMultimidiaAlugados();
	
		/**
		*@brief imprimeMultimidiaReservados
		*@return multimidias reservadas
		*/
		void imprimeMultimidiaReservados();
}

#endif
