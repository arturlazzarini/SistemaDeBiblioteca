class Pessoa{
	private:
		string _nome;
		string _senha;
		int _id = 0;
	
	public:
		Pessoa(string nome, string senha, string id){
			setNome(nome);
			setSenha(senha);
			setId();
			
		}
	
		void setNome(string nome){
			_nome = nome;
		}
		
		void setSenha(string senha){
			_senha = senha;
		}
		
		void setId(){
			
		}
		
		string getNome(){
			return _nome;
		}
		
		string getSenha(){
			return _senha;
		}
		
		string getId(){
		
		}
	
}

class Usuario : public Pessoa{

	public:
		void alugarItem(string item){}
		void reservarItem(string item){}
		void devolverItem(string item){}

}

class Funcionario : public Pessoa{

	public:
		void adicionarItem(string titulo, string autor, string prod){};
		void removerItem(string item){};
		void cadastrarUsuario(Gerencia adm, string nome, string senha, string id){
			Pessoa novo(nome, senha, id);
			adm.setUsuariosCadastrados(novo);
		};

}



class Item{
	private:
		string _titulo;
		string _autor;
		string _prod;
		int _codigo = 0;
		int _quantidadeItens = 0;
		
	public:
		Item(string titulo, string autor, string prod, int codigo, int quantidade){
			setTitulo(titulo);
			setAutor(autor);
			setProd(prod);
			setCodigo(codigo);
			setQuantidadeItens(quantidade);
		}

		void setTitulo(string titulo){
			_titulo = titulo;
		}
		
		void setAutor(string autor){
			_autor = autor;
		}
		
		void setProd(string produtora){
			_prod = produtora;
		}
		
		void setCodigo(){
		
		}
		
		void setQuantidadeItens(int quantidade){
			_quantidadeItens += quantidade;
		}
		
		string getTitulo(){
			return _titulo;
		}
		
		string getAutor(){
			return _autor;
		}
		
		string getProd(){
			return _prod;
		}
		
		int getCodigo(){
			return _codigo;
		}
		
		int getQuantidadeItens(){
			return _quantidadeItens;
		}

}

class Livro : public Item{
	private:
		int _itensDisponiveis = 0;

	public:
		void setItensDisponiveis(int quantidade){
			_itensDisponiveis = quantidade;
		}

}

class Multimidia : public Item{
	private:
		int _itensDisponiveis;

}



class Gerencia{
	private:
		std::vector <Pessoa> _usuariosCadastrados;
		
	public:
		void setUsuariosCadastrados(Pessoa novoUsuario){
			_usuariosCadastrados.push_back(novoUsuario);
		}


}

class Acervo{
	private:
		int _acervoTotal;

	public:
		void listaItens(){};
		void procuraItens(){};
}

