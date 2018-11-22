#define CATCH_CONFIG_ALL_PARTS
#include "catch.hpp"

#include "Item.hpp"

TEST_CASE("Testa Gets, Sets e Construtor"){

	Item novo("Guerra e Paz", "Liev Tolstoi", "Globo");
	novo.setTitulo("Guerra e Paz");
	novo.setAutor("Liev Tolstoi");
	novo.setEditora("Globo");

	if(novo.getTitulo() == "Guerra e Paz" && novo.getAutor() == "Liev Tolstoi"){
		CHECK(novo.getEditora() == "Globo");
	}

}
