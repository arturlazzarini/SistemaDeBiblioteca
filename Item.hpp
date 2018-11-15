#ifndef ITEM_HPP
#define ITEM_HPP

#include <stdbool.h>
#include <string>
#include <iostrem>

using std::cout
using std::cin
using std::string

class Item{

	private:
	
		string _titulo;
		string _autor;
		string _editora;
		bool _disponibilidade;
		
	public:
	
		Item(string,string,string,int,int);
		void setTitulo(string);
		void setAutor(string autor);	
		void setEditora(string);				
		string getTitulo();		
		string getAutor();		
		string getEditora();			
		virtual void imprimeCampos();
		virtual bool isDisponivel();


};

#endif
