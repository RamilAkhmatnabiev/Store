
#include <iostream>
#include <string>
using namespace std;
class Product;
class User
{
public:
	User(string name, string adress, double balanse, double sent)
	{
		this->name = name;
		this->adress = adress;
		this->balanse = balanse;
		this->sent = sent;
	}
	void ReduceBalance(double price)
	{
		this->balanse -= price;
		this->sent += price;
	}
	double GetSent()
	{
		return sent;
	}
	string GetName()
	{
		return name;
	}
	double GetBalance()
	{
		return balanse;
	}
	int GetMyDiscInPercent()
	{
		int yourDiscount = 0;
		if (sent < 10000)
		{
			return yourDiscount = 0;
		}
		if (sent < 30000)
		{
			return yourDiscount = 10;
		}
		if (sent < 50000)
		{
			return  yourDiscount = 20;
		}
		return  yourDiscount = 30;
	}

private:
	string name;
	string adress;
	double balanse;
	double sent;
};
class Product
{
protected:
	string name;
	double price;
	static int id;
public:
	virtual double GetDiscountPrice(User user)
	{
		if (user.GetSent()<10000)
		{
			return price;
		}
		if (user.GetSent()<30000)
		{
			return price * 0.9;
		}
		if (user.GetSent()<50000)
		{
			return price * 0.8;
		}
		return price * 0.7;
	}
	
	string GetName()
	{
		return name;
	}
	double GetPrice()
	{
		return price;
	}
	int GetId()
	{
		return id;
	}

	virtual void Print()
	{
		cout << "id " << id << endl;
		cout << "Наименование " << name << endl;
		cout << "Цена " << price << endl;
	}


private:
	
};
int Product :: id = 0;

class Phone : public Product
{
public:
	Phone(string name, int memoryRam, double price)
	{
		this->name = name;
		this->price = price;
		this->memory = memoryRam;
		this->id++;
		Print();
	}
	void Print() override
	{
		cout << "id\t" << id << endl;
		cout << "Наименование\t" << name << endl;
		cout << "Память\t" << memory << endl;
		cout << "Цена\t" << price << endl;
		cout << "------------------------------" << endl;
	}

private:
	int memory;
};
class Tv : public Product
{
public:
	Tv(string name, int diagonal, double price)
	{
		this->name = name;
		this->price = price;
		this->diagonal = diagonal;
		this->id++;
		Print();
	}
	void Print() override
	{
		cout << "id\t" << id << endl;
		cout << "Наименование\t" << name << endl;
		cout << "Диагональ\t" << diagonal << endl;
		cout << "Цена\t" << price << endl;
		cout << "------------------------------" << endl;
	}
private:
	int diagonal;

};
class Stereo : public Product
{
public:
	Stereo(string name, int powerWatt, double price)
	{
		this->name = name;
		this->price = price;
		this->powerWatt = powerWatt;
		this->id++;
		Print();
	}
	void Print() override
	{
		cout << "id\t" << id << endl;
		cout << "Наименование\t" << name << endl;
		cout << "Мощность\t" << powerWatt << endl;
		cout << "Цена\t" << price << endl;
		cout << "------------------------------" << endl;
	}

private:
	int powerWatt;
};
class Informer
{
public:
	static void Buy(User& user, Product* product)
	{
		double price = product->GetDiscountPrice(user);
		user.ReduceBalance(price);
		cout << user.GetName() << "\tкупил\t"<<product->GetName() <<" за "<<price << "рублей, со скидкой"<<user.GetMyDiscInPercent()<<"%. Tовар отпрален на обработку" << endl;//"Заглушка" реализовать систему обработки заказа
	}
private:

};
void Line()
{
	cout << "--------------------------" << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	User user("Иван Иванов Иванович", "Улица Пушкина, Дом Колотушкина", 900000, 900);
	Phone Iphone1("iphone 10", 256, 70000);
	Phone Iphone2("iphone 11", 128, 90000);
	Phone Samsung("Samsung s7", 32, 40000);
	Phone ChinaBest("China Phone", 512, 10000);
	Tv lg1("Lg 1\t", 55, 55000);
	Tv lg2("Lg 2\t", 60, 60000);
	Tv Sony("Lg 1\t", 45, 150000);
	Stereo Sony1("Sony xnvb", 500, 5000);
	Stereo JBL("Sony xnvb", 125, 7500);
	const int length = Iphone1.GetId();
	Product*  product = new Product [length]{ Iphone1, Iphone2,Samsung, ChinaBest,lg1,lg2,Sony,Sony1,JBL };
	while (true)
	{
		cout << endl << endl;
		cout << "Здравствуйте\t" << user.GetName() << "\tваш баланс\t" << user.GetBalance() << endl;
		Line();
		cout << "Ваша скидка :" << user.GetMyDiscInPercent() << endl << endl;
		cout << "В нашем магазине Вы уже накупили на : " << user.GetSent() << "руб." << endl << endl;
		for (int i = 0; i < length; i++)
		{
			cout << "Товар № " << i <<"\t"<< product[i].GetName() << "\tцена " << product[i].GetPrice()<<"\tсо скидкой\t"<<user.GetMyDiscInPercent()<<"%\t"<<product[i].GetDiscountPrice(user)<< endl;
		}
		

		cout <<endl<< "введите номер товара" << endl;
		int num;
		cin >> num;
		Line();
		if (num >= 0 && num < length)
		{
			if (product[num].GetDiscountPrice(user) < user.GetBalance())
			{
				cout << "your price " << product[num].GetDiscountPrice(user) << endl;
				Informer::Buy(user, &product[num]);
			}
			else
			{
				cout << "недостаточно средств" << endl;
			}

		}
		else
		{
			cout << "таких товаров нет" << endl;
		}
	}

	delete[] product;

}
