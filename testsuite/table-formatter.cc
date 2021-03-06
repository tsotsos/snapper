
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE snapper

#include <boost/test/unit_test.hpp>

#include "../client/utils/TableFormatter.h"


using namespace std;


BOOST_AUTO_TEST_CASE(test1)
{
    locale::global(locale("en_GB.UTF-8"));

    vector<pair<string, TableAlign>> header = {
	{ "Number", TableAlign::RIGHT },
	{ "Name EN", TableAlign::LEFT },
	{ "Name DE", TableAlign::LEFT },
	{ "Square", TableAlign::RIGHT }
    };

    vector<vector<string>> rows = {
	{ "0", "zero", "Null", "0" },
	{ "1", "one", "Eins", "1"} ,
	{ "5", "five", "Fünf", "25" },
	{ "12", "twelve", "Zwölf", "144" }
    };

    snapper::cli::TableFormatter formatter(header, rows, Ascii);

    string result = {
	"Number | Name EN | Name DE | Square\n"
	"-------+---------+---------+-------\n"
	"     0 | zero    | Null    |      0\n"
	"     1 | one     | Eins    |      1\n"
	"     5 | five    | Fünf    |     25\n"
	"    12 | twelve  | Zwölf   |    144\n"
    };

    BOOST_CHECK_EQUAL(formatter.str(), result);
}
