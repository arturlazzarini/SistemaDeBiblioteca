#include "Acervo.hpp"

Acervo::Acervo(){}

void Acervo::setAcervoTotal(int totalLivro,int totalMultimidia){
	
	_acervoTotalLivro = totalLivro;
	_acervoTotalMultimidia = totalMultimidia;
}

void Acervo::setAcervoTotalMultimidia(int totalMultimidia){
	
	_acervoTotalMultimidia = totalMultimidia;
}

void Acervo::setAcervoTotalLivro(int totalLivro){
	
	_acervoTotalLivro = totalLivro;
}

int Acervo::getAcervoTotal(){

	return _acervoTotalLivro + _acervoTotalMultimidia;
}

int Acervo::getAcervoTotalLivro(){

	return _acervoTotalLivro ;
}

int Acervo::getAcervoTotalMultimidia(){

	return  _acervoTotalMultimidia;
}

void Acervo::listarLivros(){

	for(int i=0;i<_acervoTotalLivro;i++){

			acervoLivro[i].imprimirCampos();
	}

}

void Acervo::listarMultimidia(){

	for(int i=0;i<_acervoTotalMultimidia;i++){

			acervoMultimidia[i].imprimirCampos();

	}
}

void Acervo::procuraLivros(string livro,int campo){
	
		if(campo==1){
			
			for(i=0;i < _acervoTotalLivro;i++){
			
				if(_acervoLivro[i].getTitulo() == livro)
					_acervoLivro[i].imprimirCampos();
			}
		}
		if(campo==2){
			
			for(i=0;i < _acervoTotalLivro;i++){
			
				if(acervoLivro[i].getAutor()== livro)
					acervoLivro[i].imprimirCampos();
			}
		}
		if(campo==3){
			
			for(i=0;i < _acervoTotalLivro;i++){
			
				if(acervoLivro[i].getEditora() == livro)
					acervoLivro[i].imprimirCampos();
			}
		}			
}

void Acervo::procuraMultimidia(string multimidia, int campo){
	
		if(campo==1){
			
			for(i=0;i < _acervoTotalMultimidia;i++){
			
				if(acervoMultimidia[i].getTitulo() == multimidia)
					acervoMultimidia[i].imprimirCampos();
			}
		}
		
		if(campo==2){
			
			for(i=0; i < _acervoTotalMultimidia; i++){
			
				if(acervoMultimidia[i].getAutor() == multimidia)
					acervoMultimidia[i].imprimirCampos();
			}
			
}

void Acervo::removeLivro(Livro livro){
	
	for(i=0;i < _acervoTotalLivro;i++){
		
		if(acervoLivro[i].nome == livro.nome){
			
			acervoLivro.erase(acervoLivro.begin()+i);
			setAcervoTotalLivro(acervoLivro.size());
			std::cout<<"Livro removido com sucesso"<<std::endl;
			break;
		}
	}
}

void Acervo::removeMultimidia(Multimidia multimidia){
	
		for(i=0;i < acervoLivro.size();i++){
		
			if(acervoMultimidia[i].nome == multimidia.nome){
				
				acervoLivro.erase(acervoLivro.begin()+i);
				setAcervoTotalMultimidia(acervoLivro.size());
				std::cout<<"Multimidia removida com sucesso"<<std::endl;
				break;
		}
			
	}
}
void Acervo::adicionarMultimidia(Multimidia multimidia){
	
	acervoMultimidia.push_back(multimidia);
	std::cout<<"Livro adicionado com sucesso"<<std::endl;
}

void Acervo::adicionarLivro(Livro livro){
	
	acervoLivro.push_back(livro);
	std::cout<<"Livro adicionado com sucesso"<<std::endl;
}

void Acervo::mudarDisponibilidadeLivro(Livro livro){

	int naoexiste=0;
	
	for(i=0;i < _acervoTotalLivro;i++){
			
			if(_acervoLivro[i].getTitulo() == livro.getTitulo() && _acervoLivro[i].getAutor() == livro.getAutor()){
				_acervoLivro[i].mudarDisponibilidade();
				break;
			}
			naoExiste++;
		}

		if(naoExiste == _acervoMultimidia){
			cout<<"Este livro nao esta disponivel"<<endl;
		}
		
}
void Acervo::mudarDisponibilidadeMultimidia(Multimidia multimidia){
	
	int naoexiste=0;
	
	for(i=0;i < _acervoTotalMultimidia;i++){
			
			if(_acervoMultimidia[i].getTitulo() == multimidia.getTitulo() && _acervoMultimidia[i].getAutor() == multimidia.getAutor()){
				
				_acervoMultimidia[i].mudarDisponibilidade();
				break;
			}
			naoExiste++;
		}
		
		if(naoExiste == _acervoMultimidia){
			cout<<"Esta multimidia nao esta disponivel"<<endl;
		}
}
