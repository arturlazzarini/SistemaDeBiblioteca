#include "Funcionario.hpp"

Funcionario :: Funcionario(){}

Funcionario :: Funcionario(string nome, string senha, int id) : Pessoa(nome,senha,id){}

void Funcionario::adicionarLivros(Acervo *acervo,string titulo, string autor, string prod){
	
	Livro novo(titulo,autor,prod,true);
	acervo->adicionarLivro(novo);
}

void Funcionario::removerLivros(Acervo *acervo,string titulo, string autor, string prod){
	
	Livro livro(titulo,autor, prod,true);
	acervo->removerLivro(livro);
}

void Funcionario::adicionarMultimidias(Acervo *acervo,string titulo, string autor, string produtora, string tipo){
	
	Multimidia nova(titulo,autor,produtora,tipo,true);
	acervo->adicionarMultimidia(nova);
}


void Funcionario::removerMultimidias(Acervo *acervo,string titulo, string autor,string produtora, string tipo){
	
	Multimidia retirada(titulo,autor,produtora,tipo,true);
	acervo->adicionarMultimidia(retirada);
}

Usuario Funcionario::cadastrarUsuario( string nome, string senha, int id){
	
	Usuario novo(nome, senha, id);
	return novo;
}

Funcionario Funcionario::cadastrarFuncionario( string nome, string senha, int id){
	
	Funcionario novo(nome, senha, id);
	return novo;
}
