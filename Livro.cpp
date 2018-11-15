#include "Livro.hpp"

void Livro::setItensDisponiveis(int quantidade){
	_itensDisponiveis = quantidade;
}

bool Livro::isDisponivel(){
	return this->_disponivel;
}
