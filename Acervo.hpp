#ifndef ACERVO_HPP
#define ACERVO_HPP

#include "Livro.hpp"
#include "Multimidia.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Acervo{
	
	private:
		int _acervoTotalLivro;
		int _acervoTotalMultimidia;
		vector <Livro> _acervoLivro;
		vector <Multimidia> _acervoMultimidia;

	public:

		Acervo();
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
		void procurarLivro(Livro);
		void procurarMultimidia(Multimidia);
		void reservarLivro(Livro)
}

#endif
