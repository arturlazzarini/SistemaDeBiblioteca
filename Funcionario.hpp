#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "Gerencia.hpp"
#include "Pessoa.hpp"
#include "Acervo.hpp"

class Funcionario : public Pessoa{

    public:
		Funcionario();
		Funcionario(string,string,id);
		void adicionarItem(Acervo *acervo,string titulo, string autor, string prod);
		void removerItem(Acervo *acervo,string item);
		void cadastrarUsuario(Gerencia *adm, string nome, string senha, string id);
		void cadastrarFuncionario(Gerencia *adm, string nome, string senha, string id);
};

#endif
