#include "Funcionario.hpp"

Funcionario :: Funcionario(){}

Funcionario :: Funcionario(string nome, string senha, int id) : Pessoa(nome,senha,id){}

//Adiciona novos livros ao acervo da biblioteca
void Funcionario::adicionarlivros(Acervo *acervo,string titulo, string autor, string editora){
	
	Livro novo(titulo,autor,editora,true);
	acervo->adicionarlivro(novo);
}

//Remove novos livros do acervo da biblioteca
void Funcionario::removerLivros(Acervo *acervo,string titulo, string autor, string editora){
	
	Livro livro(titulo,autor, editora,true);
	acervo->removerLivro(livro);
}
//Adiciona novas multimidias ao acervo da biblioteca
void Funcionario::adicionarMultimidias(Acervo *acervo,string titulo, string autor, string editora, string tipo){
	
	Multimidia nova(titulo,autor,editora,tipo,true);
	acervo->adicionarMultimidia(nova);
}

//Remove multimidia do acervo da biblioteca
void Funcionario::removerMultimidias(Acervo *acervo,string titulo, string autor,string editora, string tipo){
	
	Multimidia retirada(titulo,autor,editora,tipo,true);
	acervo->adicionarMultimidia(retirada);
}

//Cadastra novos usuários e os adiciona à gerencia
void Funcionario::cadastrarUsuario(Gerencia *adm, string nome, string senha, int id){
	
	Usuario novo(nome, senha, id);
	adm->setUsuarioCadastrado(novo);
}

//Cadastra novos usuários e os adiciona à gerencia
void Funcionario::cadastrarFuncionario(Gerencia *adm, string nome, string senha, int id){
	
	Funcionario novo(nome, senha, id);
	adm->setFuncionarioCadastrado(novo);
}
