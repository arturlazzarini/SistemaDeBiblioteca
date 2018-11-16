#ifndef ACERVO_HPP
#define ACERVO_HPP

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

		Acervo();
		void inicializarAcervo();
		void adicionarMultimidia(Multimidia);
		void adicionarLivro(Livro);
		void removerLivro(Livro);
		void removerMultimidia(Multimidia);
		void setAcervoTotal(int,int);
		void setAcervoTotalLivro(int);
		void setAcervoTotalMultimidia(int);
		int getAcervoTotal();
		int getAcervoTotalLivro();
		int getAcervoTotalMuktimidia();
		void listarLivros();
		void listarMultimidia();
		void procurarLivro(string,int);
		void procurarMultimidia(string,int);
		void mudarDisponibilidadeLivro(Livro);
		void mudarDisponibilidadeMultimidia(Multimidia);
}

#endif
