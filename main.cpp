#include<iostream>
#include<vector>

using namespace std;

class Neuron
{

public:

/*����� - �������� ����� �������, ������� �������� ���������
 ������� ������, ������������ �������� ���������*/
    class Akson{
    public:
        float getSignal();//������� ���������
        Neuron *ownerNeuron;
    };

/*������� - ���� �� ������� ����� �������. �������� ������� �����������.
� ������ ����������� ������ ������� �������� ��������� �� �������������� ���
�����, � �������� �� � �������� ������.*/
    class Dendrit{
    public:
        float weight;
        Akson *inputAkson;
    };


    Neuron();
/*������, ���������� ������� ��������, �.�. �� ����� ���� ������ ����������*/
    std::vector<Dendrit> dendrits;
    Akson akson;
/*����������� �������, ������� ���������(� ����� ������� ������)
������� �������*/
    virtual float kernelFunction();
/*��������� �������*/
    float value;
};


float Neuron::Akson::getSignal()
{
    return (1 / (1 + exp(-(ownerNeuron->kernelFunction())))) ;
}

/*����������� ������������� ��� � �������� �������-���������
������ ���� ������*/
Neuron::Neuron()
{
    akson.ownerNeuron = this;
}

/*������ ����������� ������ � ������� ������ ��������,
��� ����� ��������� � ������� �������� ����������� ����,
������� � ���� ������� ���������� � ����� �������� �.�.�,
�� ���� ���� �������� ���� �������� �� ������ ������� ����*/
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

/*�������� ������� �������: ������� ������, ������� ������
�������� ������� ������ ������*/
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
/*������� �������� �������*/
    void study(Neuron &n, QImage pic);

/*�������� � ������� ��� ��������*/
    QString names[9] = {"0.bmp", "1.bmp", "2.bmp", "3.bmp","4.bmp","5.bmp","6.bmp","7.bmp", "8.bmp"};
    const uint numNumbers = 9;
};

int main()
{
    return 0;
}
