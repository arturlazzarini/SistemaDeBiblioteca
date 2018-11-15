#ifndef MULTIMIDIA_HPP
#define MULTIMIDIA_HPP

#include "Item.hpp"

class Multimidia : public Item{
	private:
		bool _disponibilidade;
		
	public:
		void setItensDisponiveis(int);
		bool isDisponivel();
		void imprimeCampos();
}

#endif
