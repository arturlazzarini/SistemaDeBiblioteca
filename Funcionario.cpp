#include "Funcionario.hpp"
#include "Gerencia.hpp"

//Adiciona novos itens ao acervo da biblioteca
void Funcionario::adicionarItem(string titulo, string autor, string prod){
	
}

//Remove novos itens ao acervo da biblioteca
void Funcionario::removerItem(string item){
	
}

//Cadastra novos usuários e os adiciona à gerencia
void Funcionario::cadastrarUsuario(Gerencia adm, string nome, string senha, string id){
	Pessoa novo(nome, senha, id);
	adm.setUsuariosCadastrados(novo);
}
