#ifndef ACERVO_HPP
#define ACERVO_HPP


/**
*@file Acervo.hpp
*@brief Classe Acervo
*@author x
*@version 1.0
*@date 17/11/2018
*/

#include "Livro.hpp"
#include "Multimidia.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using std::vector;
using std::string;
using std::cout;

class Acervo{
	
	private:
		int _acervoTotalLivro;
		int _acervoTotalMultimidia;
		vector <Livro> _acervoLivro;
		vector <Multimidia> _acervoMultimidia;

	public:
		
	
		/**
		*@brief construtor de Acervo
		*@return Acervo
		*/
		Acervo();
	
		/**
		*@brief inicializarAcervo
		*/
		void inicializarAcervo();
	
		/**
		*@brief adicionarMultimidia
		*@param multimidia
		*/
		void adicionarMultimidia(Multimidia);
	
	
		/**
		*@brief adicionarLivro
		*@param livro
		*/
		void adicionarLivro(Livro);
	
		/**
		*@brief removerLivro
		*@param livro
		*/
		void removerLivro(Livro);
	
		/**
		*@brief removerMultimidia
		*@param multimidia
		*/
		void removerMultimidia(Multimidia);
	
		/**
		*@brief setAcervoTotal
		*@param totalLivro
		*@param totalMultimidia
		*/
		void setAcervoTotal(int,int);
	
		/**
		*@brief setAcervoTotal
		*@param totalLivro
		*/
		void setAcervoTotalLivro(int);
	
		/**
		*@brief setAcervoTotalMultimidia
		*@param totalMultimidia
		*/
		void setAcervoTotalMultimidia(int);
	
		/**
		*@brief getAcervoTotal
		*@return _acervoTotalLivro
		*@return _acervoTotalMultimidia
		*/
		int getAcervoTotal();
	
		/**
		*@brief getAcervoTotalLivro
		*@return _acervoTotalLivro
		*/
		int getAcervoTotalLivro();
	
		/**
		*@brief getAcervoTotalMultimidia
		*@return _acervoTotalMultimidia
		*/
		int getAcervoTotalMultimidia();
	
		/**
		*@brief listarLivros
		*/
		void listarLivros();
	
		/**
		*@brief listarMultimidia
		*/
		void listarMultimidia();
	
		/**
		*@brief procurarLivro
		*@param livro
		*@param campo
		*/
		void procurarLivro(string,int);
	
		/**
		*@brief procurarMultimidia
		*@param multimidia
		*@param campo
		*/
		void procurarMultimidia(string,int);
	
		/**
		*@brief mudarDisponibilidadeLivro
		*@param livro
		*/
		void mudarDisponibilidadeLivro(Livro);
	
		/**
		*@brief mudarDisponibilidadeMultimidia
		*@param multimidia
		*/
		void mudarDisponibilidadeMultimidia(Multimidia);
}

#endif
