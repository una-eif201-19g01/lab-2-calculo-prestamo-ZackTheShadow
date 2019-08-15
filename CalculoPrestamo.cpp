//
// Created by Isaac Esquivel  on 2019-08-12.
//

#include <iostream>
#include <string>
#include <sstream>
#include "CalculoPrestamo.h"

CalculoPrestamo::CalculoPrestamo() {}


CalculoPrestamo::CalculoPrestamo(int64_t monto) : monto(monto) {}


float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT)
{
	float porcentaje=0;
	int encuentraPorcentaje=0;
	
	encuentraPorcentaje= porcentajeTXT.find("%");
	
	if(encuentraPorcentaje > 0)
	{
		porcentaje= std::stof(porcentajeTXT.substr(0,encuentraPorcentaje));
	}
		porcentaje = porcentaje/100;
	return porcentaje;
}



int CalculoPrestamo::calcularTiempoenMeses(std::string tiempoTxT)
{
	int meses=0;
	int encuentraLetra=0;
	
	encuentraLetra= tiempoTxT.find("A");
	
	if(encuentraLetra > 0)
	{
		meses= std::stof(tiempoTxT.substr(0, encuentraLetra));
		meses=meses*12;
	}
	
	else
	   {
		encuentraLetra = tiempoTxT.find("M");
			if(encuentraLetra > 0)
		{
			meses=std::stof(tiempoTxT.substr(0, encuentraLetra));
		}
	}
	
	return meses;
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual)
{
	float tasaMes;
	float interes;

	tasaMes = tasaAnual / 12;
	interes = tasaMes * balance;

	return interes;
}


std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTxT, std::string porcentajeTxT)
{
	std::string reporte = "";
	int meses;
	float porcentaje;
	float balance;
	float balanceCalculado;

	meses = calcularTiempoenMeses(tiempoTxT);
	porcentaje = obtenerPorcentaje(porcentajeTxT);
	balance = getMonto();
	balanceCalculado = getMonto();

	for (int mes = 1; mes <= meses; mes++) {

		float interesMes;

		interesMes = calcularInteresMensual(balance, porcentaje);
		balance = balanceCalculado;
		balanceCalculado = balance + interesMes;

		reporte = reporte + "Tasa [" + porcentajeTxT + "], Mes [" + std::to_string(mes) + "], balance ["
			+ std::to_string(balance) + "], interes [" + std::to_string(interesMes) + "], balance nuevo [" +
			std::to_string(balanceCalculado) + "] \n";
	}

	return reporte;
}


float CalculoPrestamo::getMonto()
{
	return monto;
}

void CalculoPrestamo::setMonto(float monto)
{
}




    
