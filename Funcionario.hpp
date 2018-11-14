#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

class Funcionario : public Pessoa{

    public:
		void adicionarItem(string titulo, string autor, string prod){};
		void removerItem(string item){};
		void cadastrarUsuario(Gerencia adm, string nome, string senha, string id){
			Pessoa novo(nome, senha, id);
			adm.setUsuariosCadastrados(novo);
		};

}


#endif
