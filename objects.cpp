
class Pessoa{
	private:
		string _nome;
		string senha;
		int id;

}

class Usuario : public Pessoa{

	public:
		void alugarItem(string item){};
		void reservarItem(string item){};
		void devolverItem(string item){};

}

class Funcionario : public Pessoa{

	public:
		void adicionarItem(string titulo, string autor, string prod){};
		void removerItem(string item){};
		void cadastrarUsuario(string nome, string senha, string id){};

}



class Item{
	private:
		string _titulo;
		string _autor;
		string _prod;
		int _codigo;
		int _quantidadeItens;

}

class Livro : public Item{
	private:
		int _itensDisponiveis;

}

class Multimidia : public Item{
	private:
		int _itensDisponiveis;

}



class Gerencia{

}

class Acervo{
	private:
		int _acervoTotal;

	public:
		void listaItens(){};
		void procuraItens(){};
}


