#ifndef LIVRO_HPP
#define LIVRO_HPP

#include "Item.hpp"

class Livro : public Item{
	private:
		bool _disponibilidade;

	public:
		void setItensDisponiveis(int);
		bool isDisponivel();
		void imprimeCampos();
}

#endif
