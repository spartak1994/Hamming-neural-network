#include<iostream>
#include<vector>

using namespace std;

class Neuron
{

public:

/*Аксон - выходная часть нейрона, которая передает состояние
 нейрона дальше, обработанное функцией активации*/
    class Akson{
    public:
        float getSignal();//Функция активации
        Neuron *ownerNeuron;
    };

/*Дендрит - одна из входных линий нейрона. Содержит весовой коэффициент.
В данной архитектуре каждый дендрит содержит указатель на предшествующий ему
аксон, с которого он и получает сигнал.*/
    class Dendrit{
    public:
        float weight;
        Akson *inputAkson;
    };


    Neuron();
/*Вектор, содержащий входные дендриты, т.к. их может быть разное количество*/
    std::vector<Dendrit> dendrits;
    Akson akson;
/*Суммирующая функция, которая суммирует(В самом простом случае)
входные сигналы*/
    virtual float kernelFunction();
/*Состояние нейрона*/
    float value;
};


float Neuron::Akson::getSignal()
{
    return (1 / (1 + exp(-(ownerNeuron->kernelFunction())))) ;
}

/*Конструктор устанавливает для в качестве нейрона-владельца
аксона свой объект*/
Neuron::Neuron()
{
    akson.ownerNeuron = this;
}

/*Нейрон запрашивает сигнал у каждого своего дендрита,
тем самым обращаясь к аксонам нейронов предыдущего слоя,
которые в свою очередь обращаются к своим нейронам и.т.д,
то есть сбор сигналов идет цепочкой от самого первого слоя*/
float Neuron::kernelFunction()
{
    float result(0.);
    for(Dendrit d : dendrits){
        result += d.inputAkson->getSignal() * d.weight;
    }
    return result;
}

class KohonenNet
{
public:

/*Создание подвида нейрона: входной нейрон, который только
передает входной сигнал дальше*/
    class InputNeuron : public Neuron{
    public:

        float kernelFunction(){
            return value;
        }

    };

    KohonenNet();
    vector<Neuron*> inNeurons;
    vector<Neuron> outNeurons;
    int handle(QImage);

private:
/*Функция обучения нейрона*/
    void study(Neuron &n, QImage pic);

/*Картинки с цифрами для обучения*/
    QString names[9] = {"0.bmp", "1.bmp", "2.bmp", "3.bmp","4.bmp","5.bmp","6.bmp","7.bmp", "8.bmp"};
    const uint numNumbers = 9;
};

int main()
{
    return 0;
}
