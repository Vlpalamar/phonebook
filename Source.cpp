#include<D:\visual studio\Spravochnick iz faila\Header.h>
int main()
{
setlocale(0,"");


phonebook t("phoneBook.txt");

t.print_All();

t.serch_name();
cout << endl;
}