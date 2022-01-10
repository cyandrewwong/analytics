#pragma once
#include "table.h"



const std::string RateTypetoString(RateType ratetype) {

	switch (ratetype) {

	case RateType::OIS: { return "OIS"; }
	case RateType::LIBOR: { return "LIBOR"; }

	default:
		throw std::exception("Unable to convert RateType Enum to string!");
	}
}

Row::Row(tm i_tenor, RateType i_ratetype, double i_rate) {
	tenor = i_tenor;
	ratetype = i_ratetype;
	rate = i_rate;
	return;
}


Table::Table(std::vector<Row> all_rows) {
	rows = all_rows;
	return;
}


std::vector<std::vector<std::string>> Table::display()
{
	std::vector<std::vector<std::string>> res;

	for (auto& row : rows)
	{
		// Tenor			
		char buffer[50];
		strftime(buffer, 50, "%d/%m/%Y", &row.tenor);
		std::string tenor(buffer);

		// RateType
		std::string ratetype = RateTypetoString(row.ratetype);

		// Rate
		std::string rate = std::to_string(row.rate);

		std::vector<std::string> display_row{ tenor, ratetype, rate };
		res.push_back(display_row);
	}

	return res;
}
