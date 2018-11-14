#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string.h>

using namespace std;


class Pessoa{
	private:
		string _nome;
		string _senha;
		int _id = 0;
	
	public:
		Pessoa(string, string, int){

	
		void setNome(string nome);

		
		void setSenha(string senha);

		
		void setId(int id);

		
		string getNome();

		
		string getSenha();

		
		string getId();

}


#endif
	
	
	
	
	
