#include <string>
#include <fstream>
#include <iostream>
/*!
Печатает строку text в стандартный поток
\param text, out - строка для вывода, стандартный поток 
\return Ничего не возвращает
*/
void print(const std::string& text, std::ostream& out = std::cout);
/*!
Печатает строку text в поток out
\param text, out - строка для вывода, поток для вывода
\return Ничего не возвращает
*/
void print(const std::string& text, std::ofstream& out);
