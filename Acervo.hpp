#ifndef ACERVO_HPP
#define ACERVO_HPP


#include "item.hpp"
#include "Pessoa.hpp"
#include <vector>
#include <iostream>

using namespace std;



class Acervo{
	private:
		int _acervoTotalLivro;
		int _acervoTotalMultimidia;
		vector <Item> acervoLivro;
		vector <Item> acervoMultimidia;

	public:

		Acervo(int acervoTotalLivro, int acervoTotalMultimidia, Item acervolivro[],Item acervoMultimidia[]);
		void setAcervoTotal(int acervoLivro,int acervoMultimidia);
		int getAcervoTotal();
		void adicionaLivro(Item x);
		void removeLivro(Item x);
		void adicionaMultimidia(Item x);
		void removeMultimidia(Item x);
		void listarLivros();
		void listarMultimidia();
		void imprimeItens();
		void procurarLivro(Item x);
		void procurarMultimidia(Item x);
}




#endif


