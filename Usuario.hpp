#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Pessoa.hpp"
#include "Item.hpp"
#include <vector>

class Usuario : public Pessoa{

	private:
		vector<Livros> _livrosAlugados;
		vector<Multimidia> _multimidiaAlugados;
		vector<Livros> _livrosReservados;
		vector<Multimidia> _multimidiaReservados;

	public:
		Usuario(string,string,id);
		void alugarLivro(string);
		void devolverLivro(string);
		void alugarMultimidia(string);
		void devolverMultimidia(string);
		void imprimeLivrosAlugados();
		void imprimeLivrosReservados();
		void imprimeMultimidiaAlugados();
		void imprimeMultimidiaReservados();
}

#endif
