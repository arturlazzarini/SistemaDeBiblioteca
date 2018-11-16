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

		Usuario();
		Usuario(string,string,id);
		void alugarLivro(Livro);
		void reservarLivro(Livro);
		void devolverLivro(string);
		void alugarMultimidia(Multimidia);
		void reservarMultimidia(Multimidia);
		void devolverMultimidia(string);
		void imprimeLivrosAlugados();
		void imprimeLivrosReservados();
		void imprimeMultimidiaAlugados();
		void imprimeMultimidiaReservados();
}

#endif
