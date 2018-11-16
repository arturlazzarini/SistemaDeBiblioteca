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
		void adicionarMultimidias(Acervo*,string,string,string,string,bool);
		void removerMultimidias(Acervo*,string,string,string,string,bool);
		void cadastrarUsuario(Gerencia *adm, string nome, string senha, string id);
		void cadastrarFuncionario(Gerencia *adm, string nome, string senha, string id);
};

#endif
