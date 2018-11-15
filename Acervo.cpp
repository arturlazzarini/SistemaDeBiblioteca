#include "Acervo.hpp"



	

	Acervo(int acervoTotalLivro, int acervoTotalMultimidia, Item acervolivro[],Item acervoMultimidia[]){
	
	
		this->_acervoTotalLivro = acervoTotalLivro;
		this->_acervoTotalMultimidia = acervoTotalMultimidia;
		//como sera a inicializaçao do acervo ?	
	
	
	}


	void Acervo::setAcervoTotal(int acervoLivro,int acervoMultimidia){


		this->_acervoTotalLivro = acervoLivro;
		this->_acervoTotalMultimidia = acevoMultimidia;
	}

	int Acervo::getAcervoTotal(){

		return _acervoTotalLivro + _acervoTotalMultimidia;

	}

	void Acervo::adicionaLivro(Item x){
	
		 this->acervoLivro.push_back (x);
	
	}

	void Acervo::removeLivro(Item x){
	
	int i;	
	for(i=0;i<this->acervoLivro.size();i++){
	
		if(this->acervoLivro[i]._titulo == x._titulo){
		
			this->acervoLivro.erase (this->acervoLivro.begin()+ i);
		
			}	
		
		}
		
	}

	
	void Acervo::adicionaMultimidia(Item x){
	
		this->acervoMultimidia.push_back(x);
	}


	void Acervo::removeMultimidia(Item x){
	
	int i;	
	for(i=0;i<this->acervoMultimidia.size();i++){
	
		if(this->acervoMultimidia[i]._titulo == x._titulo){
		
			this->acervoMultimidia.erase (this->acervoMultimidia.begin()+ i);
		
			}	
		
		}
		
	}

	void Acervo::imprimeItens(){

		cout<<"\nTítulo : "<<getTitulo()<<endl;
		cout<<"Autor : "<<getAutor()<<endl;
		cout<<"Editora : "<<getEditora()<<endl;
		cout<<"Codigo : "<<getCodigo()<<endl;
		//quantidade de itens vem aq ?
		//cout<<"quantidade disponivel : "<<getQuantidadeItens()<<endl;


	}

	void Acervo::listarLivros(){

		int i =0;

		for(i=0;i<acervoLivro.size();i++){

				acervoLivro[i].imprimeItens();

		}


	}

		void Acervo::listarMultimidia(){

		int i =0;

		for(i=0;i<acervoMultimidia.size();i++){

				acervoMultimidia[i].imprimeItens();

		}


	}

	void Acervo::procuraLivros(Item x){

		cout<<"\nDigite 1 para procurar Livro por Titulo \nDigite 2 para procurar Livro por Autor  \nDigite 3 para procurar Livro por Editora 
		\nDigite 4 para procurar Livro por codigo\n "


	}

	void Acervo::procuraMultimidia(Item x){

		cout<<"\nDigite 1 para procurar Multimidia por Titulo \nDigite 2 para procurar Multimidia por Autor  \nDigite 3 para procurar Multimidia por Editora 
		\nDigite 4 para procurar Multimidia por codigo\n "


	}



