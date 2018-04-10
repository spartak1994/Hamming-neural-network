//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <vector>
//---------------------------------------------------------------------------
class Neuron
{
	public:
	/*Аксон - выходная часть нейрона, которая передает состояние
 нейрона дальше, обработанное функцией активации*/
//	class Akson{
//	public:
//		float getSignal(float T)
//		{
//			ShowMessage((UnicodeString)"Мы в аксоне, вес первого = " + ownerNeuron->dendrits[0].weight +", а вход "+ ownerNeuron->dendrits[0].input + ", а размер " + ownerNeuron->dendrits.size());
//			if(ownerNeuron->kernelFunction()<=0) return 0.0;
//			if(ownerNeuron->kernelFunction()<T) return ownerNeuron->kernelFunction();
//			if(ownerNeuron->kernelFunction()>=T) return T;
//			return -1;
//		}//Функция активации
//		Neuron *ownerNeuron;
//
//		Akson(Neuron *n)
//		{
//			ownerNeuron = n;
//			//ShowMessage((UnicodeString)"Заебца, мы в конструкторе с параметром аксона");
//		}
//
//		Akson()
//		{
//			//ShowMessage((UnicodeString)"Пизда, мы в конструкторе по умолчанию аксона");
//			ownerNeuron = 0;
//		}
//	};

    /*Дендрит - одна из входных линий нейрона. Содержит весовой коэффициент.
В данной архитектуре каждый дендрит содержит указатель на предшествующий ему
аксон, с которого он и получает сигнал.*/
	class Dendrit{
	public:
        float weight;
		float input;
		Dendrit(){}
		Dendrit(float w)
		{
			weight = w;
		}
	};

	/*Вектор, содержащий входные дендриты, т.к. их может быть разное количество*/
	std::vector<Dendrit> dendrits;
	//Akson *akson;
/*Суммирующая функция, которая суммирует(В самом простом случае)
входные сигналы*/

	float getSignal(float T)
		{
			//ShowMessage((UnicodeString)"Мы в аксоне, вес первого = " + this->dendrits[0].weight +", а вход "+ ownerNeuron->dendrits[0].input + ", а размер " + ownerNeuron->dendrits.size());
			if(this->kernelFunction()<=0)
			{
				value = 0.0;
				return 0.0;
			}
			if(this->kernelFunction()<T){
				value = this->kernelFunction();
				return this->kernelFunction();
			}
			if(this->kernelFunction()>=T)
			{
				value = T;
				return T;
			}
			return -1;
		}//Функция активации


	float kernelFunction()
	{
		  float sum = 0;

		  for(int i=0; i<dendrits.size(); i++)
		  {
			  //ShowMessage((UnicodeString)"Мы в кернел ф-и, input = " + this->dendrits[i].input + " вес = " + this->dendrits[i].weight);
			  sum += (dendrits[i].input * dendrits[i].weight);
		  }
		  //this->value = sum;

		  return sum;
	};
/*Состояние нейрона*/
	float value;
	

	Neuron(int DendritCount)
	{
		 for(int i=0; i<DendritCount; i++)
		 {
			 //Dendrit dendrit = new Dendrit();
			// dendrits.push_back(Dendrit());
		 }
		 dendrits.resize(DendritCount);
		 //this->akson = (new Akson(this));
	}

};

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label4;
	TEdit *Edit4;
	TButton *Button2;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	TBitBtn *BitBtn6;
	TBitBtn *BitBtn7;
	TBitBtn *BitBtn8;
	TBitBtn *BitBtn9;
	TBitBtn *BitBtn10;
	TBitBtn *BitBtn11;
	TBitBtn *BitBtn12;
	TBitBtn *BitBtn13;
	TBitBtn *BitBtn14;
	TBitBtn *BitBtn15;
	TBitBtn *BitBtn16;
	TBitBtn *BitBtn17;
	TBitBtn *BitBtn18;
	TBitBtn *BitBtn19;
	TBitBtn *BitBtn20;
	TBitBtn *BitBtn21;
	TBitBtn *BitBtn22;
	TBitBtn *BitBtn23;
	TBitBtn *BitBtn24;
	TBitBtn *BitBtn25;
	TBitBtn *BitBtn26;
	TBitBtn *BitBtn27;
	TBitBtn *BitBtn28;
	TBitBtn *BitBtn29;
	TBitBtn *BitBtn30;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall BitBtn5Click(TObject *Sender);
	void __fastcall BitBtn6Click(TObject *Sender);
	void __fastcall BitBtn7Click(TObject *Sender);
	void __fastcall BitBtn8Click(TObject *Sender);
	void __fastcall BitBtn9Click(TObject *Sender);
	void __fastcall BitBtn10Click(TObject *Sender);
	void __fastcall BitBtn11Click(TObject *Sender);
	void __fastcall BitBtn12Click(TObject *Sender);
	void __fastcall BitBtn13Click(TObject *Sender);
	void __fastcall BitBtn14Click(TObject *Sender);
	void __fastcall BitBtn15Click(TObject *Sender);
	void __fastcall BitBtn16Click(TObject *Sender);
	void __fastcall BitBtn17Click(TObject *Sender);
	void __fastcall BitBtn18Click(TObject *Sender);
	void __fastcall BitBtn19Click(TObject *Sender);
	void __fastcall BitBtn20Click(TObject *Sender);
	void __fastcall BitBtn21Click(TObject *Sender);
	void __fastcall BitBtn22Click(TObject *Sender);
	void __fastcall BitBtn23Click(TObject *Sender);
	void __fastcall BitBtn24Click(TObject *Sender);
	void __fastcall BitBtn25Click(TObject *Sender);
	void __fastcall BitBtn26Click(TObject *Sender);
	void __fastcall BitBtn27Click(TObject *Sender);
	void __fastcall BitBtn28Click(TObject *Sender);
	void __fastcall BitBtn29Click(TObject *Sender);
	void __fastcall BitBtn30Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	std::vector<Neuron> level1;
	std::vector<Neuron> level2;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
