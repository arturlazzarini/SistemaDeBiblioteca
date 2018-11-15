#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "Pessoa.hpp"
#include "Item.hpp"

class Funcionario : public Pessoa{

    public:
		void adicionarItem(Item x);
		void removerItem(Item x);
		void cadastrarUsuario(Gerencia adm, string nome, string senha, string id){
			Pessoa novo(nome, senha, id);
			adm.setUsuariosCadastrados(novo);
		};

}


#endif
