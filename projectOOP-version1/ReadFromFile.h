
//chete faila i vrysha broq na redovete
int readFile(char* fileName);


//vrysha broq na kolonite za daden red
int countColumns(char* row);


//printira masiv ot kolonite za vseki red
void arrayOfCountColumns(char* fileName);


//proverqva dali string e int
bool isInt(char* data);

//proverqva dali string e double
bool isDouble(char* data);

//proverqva dali string e date
bool isDate(char* data);

//proverqva dali daden string e string ;d
bool isString(char* data);

//preobrazuva string kym chislo (int or double)
//int
int castStringToInt(char* data);
//double
double castStringToDouble(char* data);
