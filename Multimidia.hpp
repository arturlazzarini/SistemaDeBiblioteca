#ifndef MULTIMIDIA_HPP
#define MULTIMIDIA_HPP

#include "Item.hpp"

class Multimidia : public Item{
	private:

		bool _disponibilidade = true;
		
	public:

		Multimidia();
		Multimidia(string,string,string,bool);
		void setItensDisponiveis(int);
		bool isDisponivel();
		void mudarDisponibilidade();
		void imprimeCampos();
		void reservar();
}

#endif
