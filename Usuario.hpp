#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Pessoa.hpp"
#include "item.hpp"
#include <vector>

class Usuario : public Pessoa{

	private:
		Vector<Livros> _livrosAlugados;
		Vector<Multimidia> _multimidiaAlugados;

	public:
		//void buscaItem(string Autor,string Nome, string );
		void alugarLivro(string);
		void devolverLivro(string);
		void alugarMultimidia(string);
		void alugarMultimidia(string);
}

#endif
