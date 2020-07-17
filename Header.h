#pragma once
#include<D:\visual studio\Spravochnick iz faila\list.h>


class phonebook_page
{
protected:
	string name="";
	string owner="";
	long number=0;
	string adress="";
	string description = "";

public:
	phonebook_page():name(""), owner(""), number(0), adress(""), description("") {};
	phonebook_page(string name, string owner, long number, string adress, string descr) :name(name), owner(owner), number(number),adress(adress), description(descr) {};
	
	string get_name() const;
	string get_owner()const;
	int get_numb()const;
	string get_adress()const;
	string get_descr()const;


	void set_name(string n_name);
	void set_owner(string n_owner);
	void set_numb(int n_numb);
	void set_adress(string n_adress);
	void set_descr(string n_descr);



	void print();
	~phonebook_page();
private:

};



inline string phonebook_page::get_name() const
{
	return this->name;
}

inline string phonebook_page::get_owner()const
{
	return this->owner;
}

inline int phonebook_page::get_numb()const
{
	return this->number;
}

inline string phonebook_page::get_adress()const
{
	return this->adress;
}
	
inline string phonebook_page::get_descr()const
{
	return this->description;
}

inline void phonebook_page::set_name(string n_name)
{
	this->name = n_name;
}

inline void phonebook_page::set_owner(string n_owner)
{
	this->owner = n_owner;
}

inline void phonebook_page::set_numb(int n_numb)
{
	this->number = n_numb;
}

inline void phonebook_page::set_adress(string n_adress)
{
	this->adress = n_adress;
}

inline void phonebook_page::set_descr(string n_descr)
{
	this->description = n_descr;
}

inline void phonebook_page::print()
{
	cout << "Name:" << name << "\n" << "Owner:" << owner << "\nNumb:" << number<<"\nAdress:"<<adress<<"\nDescr:"<<description;
}


phonebook_page::~phonebook_page()
{
}

/////////////////////////////////////////////////////


class phonebook
{
protected:
	ForwardList<phonebook_page, 10> pages;
	string namefile;
public:
	phonebook(string namefile):namefile(namefile)
	{
		ifstream fin(namefile);
		if (fin.is_open())
		{
			string b;
			int n;
			do
			{
				phonebook_page a;
				fin >> b;
				a.set_name(b);
				fin >> b;
				a.set_owner(b);
				fin >> n;
				a.set_numb(n);
				fin >> b;
				a.set_adress(b);
				fin >> b;
				a.set_descr(b);
				Add_pages(a);
			} while (fin >> b or fin >> n);
		}
		else
		{
			cout << "error";
		}
		

		
		
	}

	void serch_name();
	void serch_owner();
	void serch_numb();
	void serch_owner();
	void serch_descr();
	void Add_by_hand();
	void Add_to_file();
	void Add_pages(phonebook_page &p);
	void menu();
	void print_All() ;
};



inline void phonebook::serch_name()
{
	string y_name;
	cout << "Enter name u wanna find:";
	cin >> y_name;
	for (size_t i = 0; i < pages.getSize(); i++)
	{
		cout << "!";
		if (y_name==pages[i].get_name())
		{
			
			pages[i].print();
			break;
		}
	}

}

inline void phonebook::serch_owner()
{
	string y_name;
	cout << "Enter owner u wanna find:";
	cin >> y_name;
	for (size_t i = 0; i < pages.getSize(); i++)
	{
		cout << "!";
		if (y_name == pages[i].get_owner())
		{

			pages[i].print();
			break;
		}
	}

}



inline void phonebook::serch_numb()
{
	int y_name;
	cout << "Enter number u wanna find:";
	cin >> y_name;
	for (size_t i = 0; i < pages.getSize(); i++)
	{
		cout << "!";
		if (y_name == pages[i].get_numb())
		{

			pages[i].print();
			break;
		}
	}

}
inline void phonebook::serch_descr()
{
	string y_name;
	cout << "Enter name u description find:";
	cin >> y_name;
	for (size_t i = 0; i < pages.getSize(); i++)
	{
		cout << "!";
		if (y_name == pages[i].get_descr())
		{

			pages[i].print();
			break;
		}
	}
}
inline void phonebook::Add_by_hand()
{
	phonebook_page _new_page;
	string a;
	int b;
	cout << "Enter Name: ";
	cin >> a;
	_new_page.set_name(a);
	cout << "Enter owner: ";
	cin >> a;
	_new_page.set_owner(a);
	cout << "Enter number: ";
	cin >> b;
	_new_page.set_numb(b);
	cout << "Enter Adress: ";
	cin >> a;
	_new_page.set_adress(a);
	cout << "Enter descr: ";
	cin >> a;
	_new_page.set_descr(a);
	Add_pages(_new_page);
	Add_to_file();

}

inline void phonebook::Add_to_file()
{
	ofstream fout(this->namefile, ios::app);
	fout <<"ERRRRRROROOORORORNAYA_STROKA"<< pages[pages.getSize()-1].get_name()<<"\n"<< pages[pages.getSize()-1].get_owner() << "\n" << pages[pages.getSize()-1].get_numb() << "\n" << pages[pages.getSize()-1].get_adress() << "\n" <<pages[pages.getSize()-1].get_descr() << "\n";
}

inline void phonebook::Add_pages(phonebook_page &p)
{
	pages.push_back(p);
}

inline void phonebook::menu()
{
	int ch = 0;
	cout << "\nselect\n1.Serch by name\n2.Serch by owner\n3.Serch by phone number\n4.Serch by description\n5.Show all\n6.Add\n";
	cin >> ch;
	while (true)
	{
		switch (ch)
		{
		case 1:
			serch_name();
			break;
		case 2:
			serch_owner();
			break;
		case 3:
			serch_numb();
			break;
		case 4:
			serch_descr();
			break;
		case 5:
			print_All();
			break;
		case 6:
			Add_by_hand();
			break;
		default:
			exit(0);
			break;
		}
	}
}

inline void phonebook::print_All()  
{
	
	for (size_t i = 0; i < pages.getSize(); i++)
	{
		cout << "\n\tPage number: " << i+1 << "\n\n";
		pages[i].print();
	}
}
