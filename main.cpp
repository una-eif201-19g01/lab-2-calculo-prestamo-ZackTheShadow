//
// Created by Isaac Esquivel  on 2019-08-12.
//


#include <iostream>
#include "CalculoPrestamo.h"

int main() {

	CalculoPrestamo Obj1(30000);

	std::string reporte;

	reporte = Obj1.reporteCalculoPrestamo("1A", "8.40%");

		std::cout << "Calcular Prestamo: " << std::endl;
		std::cout << reporte << std::endl;
        
    return 0;
}
