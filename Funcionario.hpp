#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "Gerencia.hpp"
#include "Pessoa.hpp"
#include "Acervo.hpp"

class Funcionario : public Pessoa{

    public:
		Funcionario();
		Funcionario(string,string,id);
		void adicionarLivros(Acervo*,string,string,string);
		void removerLivros(Acervo*,string);
		void adicionarMultimidias(Acervo*,string,string,string);
		void removerMultimidias(Acervo*,string);
		void cadastrarUsuario(Gerencia*, string, string, int id);
		void cadastrarFuncionario(Gerencia*, string, string, int id);
};

#endif
