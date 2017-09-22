#include <print.hpp>
void print(const std::string& text, std::ostrea& out) {
out << text;
}
void print(const std::string& text, std::ofstream& out)
{
out << text;
}
