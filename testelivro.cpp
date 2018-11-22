#define CATCH_CONFIG_ALL_PARTS
#include "catch.hpp"

#include "Item.hpp"
#include "Livro.hpp"

TEST_CASE("Testa Construtor e disponibilidade"){

	Livro novo("Guerra e Paz", "Liev Tolstoi", "Globo", true);
	novo.setDisponibilidade(true);

	if(novo.isDisponivel() == true){
		novo.mudarDisponibilidade();
		CHECK(novo.isDisponivel() == false);
	}

}
