#ifndef LIVRO_HPP
#define LIVRO_HPP

#include "Item.hpp"

class Livro : public Item{
	private:

		bool _disponibilidade = true;

	public:

		Livro();
		Livro(string,string,string,bool);
		void setDisponibilidade(bool);
		bool isDisponivel();
		void mudarDisponibilidade();
		void imprimeCampos();
};

#endif
