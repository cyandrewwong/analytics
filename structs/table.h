#pragma once
#include <string>
#include <chrono>
#include <vector>
#include <ctime>
#include <vector>



enum RateType {
	OIS = 0,
	LIBOR = 1
};

struct Row {
	Row(tm i_tenor, RateType i_ratetype, double i_rate);

	tm tenor;
	RateType ratetype;
	double rate;

};


struct Table {

	Table(std::vector<Row> all_rows);
	std::vector<Row> rows;
	std::vector<std::vector<std::string>> display();

};
