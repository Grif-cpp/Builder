// Trains.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <string>
struct carriage
{
	std::string color, type;
};
class Builder {
public:
	double x, y;
	carriage carriage_now;
	virtual ~Builder() {}
	virtual void ProduceCoords() {
		
	}
	virtual void ProduceGroup() {
		
	}
};
class Coords :public Builder {
	 void ProduceCoords() override{
		 std::cin >> x >> y;							//get coords
	}
};
class  Group :public Builder {
	 void ProduceGroup() override {
		std:: cin >> carriage_now.type >> carriage_now.color;					//get type and color
	}
};
class Train {
public :
	double x, y;
	int siz;
	std::vector<carriage>carriages;
	void make_train(Builder& builder1, Builder& builder2)
	{
		std::cin >> siz;
		carriages.resize(siz);
		builder1.ProduceCoords();
		x = builder1.x;
		y = builder1.y;
		for (int i = 0; i < siz; i++)
		{
			builder2.ProduceGroup();
			carriages[i] = builder2.carriage_now;
		}
	}
};
int main()
{
	Builder* q = new Coords();
	Builder* q1 = new Group();
	Train tr;
	tr.make_train(*q, *q1);
	return 0;
}