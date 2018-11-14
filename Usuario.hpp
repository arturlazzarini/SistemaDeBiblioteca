#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Pessoa.hpp"
#include "item.hpp"




class Usuario : public Pessoa{

	public:
		//void buscaItem(string Autor,string Nome, string );
		void alugarItem(string item){}
		void reservarItem(string item){}
		void devolverItem(string item){}

}

#endif

