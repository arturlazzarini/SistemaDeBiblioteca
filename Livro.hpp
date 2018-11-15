#ifndef LIVRO_HPP
#define LIVRO_HPP

#include "Item.hpp"

class Livro : public Item{
	private:
		int _itensDisponiveis = 0;
		bool _disponivel;

	public:
		void setItensDisponiveis(int);
		bool isDisponivel();

}

#endif
