#ifndef MULTIMIDIA_HPP
#define MULTIMIDIA_HPP

#include "Item.hpp"

class Multimidia : public Item{
	private:
		int _itensDisponiveis = 0;
		string _tipoMultimidia;
		
	public:
		void setItensDisponiveis(int quantidade){}
		void setTipoMultimidia(string tipo){}

}


#endif
