#ifndef ITEM_HPP
#define ITEM_HPP




class Item{
	private:
		string _titulo;
		string _autor;
		string _editora;
		int _codigo = 0;
		int _quantidadeItens = 0;
		
	public:
		Item(string titulo, string autor, string editora, int codigo, int quantidade){
			setTitulo(titulo);
			setAutor(autor);
			setEditora(editora);
			setCodigo(codigo);
			setQuantidadeItens(quantidade);
		}

		void setTitulo(string titulo);

		
		void setAutor(string autor);

		
		void setEditora(string editora);

		
		void setCodigo(codigo);

		
		void setQuantidadeItens(int quantidade);

		
		string getTitulo();

		
		string getAutor();

		
		string getEditora();

		
		int getCodigo();

		
		int getQuantidadeItens();


}



#endif

