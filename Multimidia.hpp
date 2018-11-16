#ifndef MULTIMIDIA_HPP
#define MULTIMIDIA_HPP

#include "Item.hpp"
#include <string>

using std::string;
using std::cout;

class Multimidia : public Item{
	
	private:
		string _tipoMultimidia;
	
	public:

		Multimidia();
		Multimidia(string,string,string,string,bool);
		bool isDisponivel();
		void mudarDisponibilidade();
		void imprimeCampos();
}

#endif
