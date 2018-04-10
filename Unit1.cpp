//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int inCount;
int neuronCount;
int ObrazecCount;
float eMax = 0.1;

float activationFunction(float s)
{
	float t = inCount/2.0;
	if(s<=0)return 0;
	if(s>0 && s<=t) return s;
	else return t;
}

float NormFunc(float *mas1, float *mas2, int size)
{
	float difference = 0;
	for(int i = 0; i < size; i++)
	{
		difference  = abs(mas1[i] - mas2[i]);
		return difference;
	}
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

	  BitBtn1->Tag = -1;
	  BitBtn2->Tag = -1;
	  BitBtn3->Tag = -1;
	  BitBtn4->Tag = -1;
	  BitBtn5->Tag = -1;
	  BitBtn6->Tag = -1;
	  BitBtn7->Tag = -1;
	  BitBtn8->Tag = -1;
	  BitBtn9->Tag = -1;
	  BitBtn10->Tag = -1;
	  BitBtn11->Tag = -1;
	  BitBtn12->Tag = -1;
	  BitBtn13->Tag = -1;
	  BitBtn14->Tag = -1;
	  BitBtn15->Tag = -1;
	  BitBtn16->Tag = -1;
	  BitBtn17->Tag = -1;
	  BitBtn18->Tag = -1;
	  BitBtn19->Tag = -1;
	  BitBtn20->Tag = -1;
	  BitBtn21->Tag = -1;
	  BitBtn22->Tag = -1;
	  BitBtn23->Tag = -1;
	  BitBtn24->Tag = -1;
	  BitBtn25->Tag = -1;
	  BitBtn26->Tag = -1;
	  BitBtn27->Tag = -1;
	  BitBtn28->Tag = -1;
	  BitBtn29->Tag = -1;
	  BitBtn30->Tag = -1;



	  BitBtn1->Glyph->TransparentColor = clLime;
	  BitBtn2->Glyph->TransparentColor = clLime;
	  BitBtn3->Glyph->TransparentColor = clLime;
	  BitBtn4->Glyph->TransparentColor = clLime;
	  BitBtn5->Glyph->TransparentColor = clLime;
	  BitBtn6->Glyph->TransparentColor = clLime;
	  BitBtn7->Glyph->TransparentColor = clLime;
	  BitBtn8->Glyph->TransparentColor = clLime;
	  BitBtn9->Glyph->TransparentColor = clLime;
	  BitBtn10->Glyph->TransparentColor = clLime;
	  BitBtn11->Glyph->TransparentColor = clLime;
	  BitBtn12->Glyph->TransparentColor = clLime;
	  BitBtn13->Glyph->TransparentColor = clLime;
	  BitBtn14->Glyph->TransparentColor = clLime;
	  BitBtn15->Glyph->TransparentColor = clLime;
	  BitBtn16->Glyph->TransparentColor = clLime;
	  BitBtn17->Glyph->TransparentColor = clLime;
	  BitBtn18->Glyph->TransparentColor = clLime;
	  BitBtn19->Glyph->TransparentColor = clLime;
	  BitBtn20->Glyph->TransparentColor = clLime;
	  BitBtn21->Glyph->TransparentColor = clLime;
	  BitBtn22->Glyph->TransparentColor = clLime;
	  BitBtn23->Glyph->TransparentColor = clLime;
	  BitBtn24->Glyph->TransparentColor = clLime;
	  BitBtn25->Glyph->TransparentColor = clLime;
	  BitBtn26->Glyph->TransparentColor = clLime;
	  BitBtn27->Glyph->TransparentColor = clLime;
	  BitBtn28->Glyph->TransparentColor = clLime;
	  BitBtn29->Glyph->TransparentColor = clLime;
	  BitBtn30->Glyph->TransparentColor = clLime;

	  BitBtn1->Glyph->LoadFromFile("grey.bmp");
	  BitBtn2->Glyph->LoadFromFile("grey.bmp");
	  BitBtn3->Glyph->LoadFromFile("grey.bmp");
	  BitBtn4->Glyph->LoadFromFile("grey.bmp");
	  BitBtn5->Glyph->LoadFromFile("grey.bmp");
	  BitBtn6->Glyph->LoadFromFile("grey.bmp");
	  BitBtn7->Glyph->LoadFromFile("grey.bmp");
	  BitBtn8->Glyph->LoadFromFile("grey.bmp");
	  BitBtn9->Glyph->LoadFromFile("grey.bmp");
	  BitBtn10->Glyph->LoadFromFile("grey.bmp");
	  BitBtn11->Glyph->LoadFromFile("grey.bmp");
	  BitBtn12->Glyph->LoadFromFile("grey.bmp");
	  BitBtn13->Glyph->LoadFromFile("grey.bmp");
	  BitBtn14->Glyph->LoadFromFile("grey.bmp");
	  BitBtn15->Glyph->LoadFromFile("grey.bmp");
	  BitBtn16->Glyph->LoadFromFile("grey.bmp");
	  BitBtn17->Glyph->LoadFromFile("grey.bmp");
	  BitBtn18->Glyph->LoadFromFile("grey.bmp");
	  BitBtn19->Glyph->LoadFromFile("grey.bmp");
	  BitBtn20->Glyph->LoadFromFile("grey.bmp");
	  BitBtn21->Glyph->LoadFromFile("grey.bmp");
	  BitBtn22->Glyph->LoadFromFile("grey.bmp");
	  BitBtn23->Glyph->LoadFromFile("grey.bmp");
	  BitBtn24->Glyph->LoadFromFile("grey.bmp");
	  BitBtn25->Glyph->LoadFromFile("grey.bmp");
	  BitBtn26->Glyph->LoadFromFile("grey.bmp");
	  BitBtn27->Glyph->LoadFromFile("grey.bmp");
	  BitBtn28->Glyph->LoadFromFile("grey.bmp");
	  BitBtn29->Glyph->LoadFromFile("grey.bmp");
	  BitBtn30->Glyph->LoadFromFile("grey.bmp");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 inCount = 30;//StrToInt(Edit1->Text) * StrToInt(Edit2->Text);
	 //ShowMessage(inCount);
	 float eps = StrToFloat(Edit4->Text);
	 float T =  inCount/2.0;
	 //ShowMessage(eps);
	 ///узнали количество входов
	 ObrazecCount = 10;
	 float *mas = new float[inCount]; //сюда будем читать входное изображение
	 //будем считать что есть какая то матрица образцов,
	 float **matrix = new float* [10]; // 10 строк в массиве, это эталонная матрица
	 for (int count = 0; count < 10; count++)
	 {
		matrix[count] = new float[inCount]; //
	 }
	 mas[0] = BitBtn1->Tag;
	 mas[1] = BitBtn2->Tag;
	 mas[2] = BitBtn3->Tag;
	 mas[3] = BitBtn4->Tag;
	 mas[4] = BitBtn5->Tag;
	 mas[5] = BitBtn6->Tag;
	 mas[6] = BitBtn7->Tag;
	 mas[7] = BitBtn8->Tag;
	 mas[8] = BitBtn9->Tag;
	 mas[9] = BitBtn10->Tag;
	 mas[10] = BitBtn11->Tag;
	 mas[11] = BitBtn12->Tag;
	 mas[12] = BitBtn13->Tag;
	 mas[13] = BitBtn14->Tag;
	 mas[14] = BitBtn15->Tag;
	 mas[15] = BitBtn16->Tag;
	 mas[16] = BitBtn17->Tag;
	 mas[17] = BitBtn18->Tag;
	 mas[18] = BitBtn19->Tag;
	 mas[19] = BitBtn20->Tag;
	 mas[20] = BitBtn21->Tag;
	 mas[21] = BitBtn22->Tag;
	 mas[22] = BitBtn23->Tag;
	 mas[23] = BitBtn24->Tag;
	 mas[24] = BitBtn25->Tag;
	 mas[25] = BitBtn26->Tag;
	 mas[26] = BitBtn27->Tag;
	 mas[27] = BitBtn28->Tag;
	 mas[28] = BitBtn29->Tag;
	 mas[29] = BitBtn30->Tag;



	 //A
	 for(int i = 0; i<30; i++)
	 {
		 matrix[0][i]= -1;
	 }
	 matrix[0][2]=1;
	 matrix[0][6]=1;
	 matrix[0][8]=1;
	 matrix[0][10]=1;
	 matrix[0][14]=1;
	 matrix[0][15]=1;
	 matrix[0][16]=1;
	 matrix[0][17]=1;
	 matrix[0][18]=1;
	 matrix[0][19]=1;
	 matrix[0][20]=1;
	 matrix[0][24]=1;
	 matrix[0][25]=1;
	 matrix[0][29]=1;
	 //Б
	  for(int i = 0; i<30; i++)
	 {
		 matrix[1][i]= -1;
	 }
	 matrix[1][0]=1;
	 matrix[1][1]=1;
	 matrix[1][2]=1;
	 matrix[1][3]=1;
	 matrix[1][5]=1;
	 matrix[1][10]=1;
	 matrix[1][11]=1;
	 matrix[1][12]=1;
	 matrix[1][13]=1;
	 matrix[1][15]=1;
	 matrix[1][18]=1;
	 matrix[1][20]=1;
	 matrix[1][23]=1;
	 matrix[1][25]=1;
	 matrix[1][26]=1;
	 matrix[1][27]=1;
	 matrix[1][28]=1;
	 //В
	  for(int i = 0; i<30; i++)
	 {
		 matrix[2][i]= -1;
	 }
	 matrix[2][0]=1;
	 matrix[2][1]=1;
	 matrix[2][2]=1;
	 matrix[2][3]=1;
	 matrix[2][5]=1;
	 matrix[2][9]=1;
	 matrix[2][10]=1;
	 matrix[2][11]=1;
	 matrix[2][12]=1;
	 matrix[2][13]=1;
	 matrix[2][15]=1;
	 matrix[2][19]=1;
	 matrix[2][20]=1;
	 matrix[2][24]=1;
	 matrix[2][25]=1;
	 matrix[2][26]=1;
	 matrix[2][27]=1;
	 matrix[2][28]=1;

	 //Г
	  for(int i = 0; i<30; i++)
	 {
		 matrix[3][i]= -1;
	 }
	 matrix[3][0]=1;
	 matrix[3][1]=1;
	 matrix[3][2]=1;
	 matrix[3][3]=1;
	 matrix[3][5]=1;
	 matrix[3][10]=1;
	 matrix[3][15]=1;
	 matrix[3][20]=1;
	 matrix[3][25]=1;


	 //Д
	  for(int i = 0; i<30; i++)
	 {
		 matrix[4][i]= -1;
	 }
	 matrix[4][1]=1;
	 matrix[4][2]=1;
	 matrix[4][3]=1;
	 matrix[4][6]=1;
	 matrix[4][8]=1;
	 matrix[4][11]=1;
	 matrix[4][13]=1;
	 matrix[4][16]=1;
	 matrix[4][18]=1;
	 matrix[4][20]=1;
	 matrix[4][21]=1;
	 matrix[4][21]=1;
	 matrix[4][23]=1;
	 matrix[4][24]=1;
	 matrix[4][25]=1;
	 matrix[4][29]=1;
	 //Е
	  for(int i = 0; i<30; i++)
	 {
		 matrix[5][i]= -1;
	 }
	 matrix[5][0]=1;
	 matrix[5][1]=1;
	 matrix[5][2]=1;
	 matrix[5][3]=1;
	 matrix[5][5]=1;
	 matrix[5][10]=1;
	 matrix[5][11]=1;
	 matrix[5][12]=1;
	 matrix[5][13]=1;
	 matrix[5][15]=1;
	 matrix[5][20]=1;
	 matrix[5][25]=1;
	 matrix[5][26]=1;
	 matrix[5][27]=1;
	 matrix[5][28]=1;

	 //Ж
	  for(int i = 0; i<30; i++)
	 {
		 matrix[6][i]= -1;
	 }
	 matrix[6][5]=1;
	 matrix[6][7]=1;
	 matrix[6][9]=1;
	 matrix[6][11]=1;
	 matrix[6][12]=1;
	 matrix[6][13]=1;
	 matrix[6][17]=1;
	 matrix[6][21]=1;
	 matrix[6][22]=1;
	 matrix[6][23]=1;
	 matrix[6][25]=1;
	 matrix[6][29]=1;
	 matrix[6][27]=1;

	 //З
	  for(int i = 0; i<30; i++)
	 {
		 matrix[7][i]= -1;
	 }
	 matrix[7][0]=1;
	 matrix[7][1]=1;
	 matrix[7][2]=1;
	 matrix[7][3]=1;
	 matrix[7][8]=1;
	 matrix[7][11]=1;
	 matrix[7][12]=1;
	 matrix[7][13]=1;
	 matrix[7][18]=1;
	 matrix[7][23]=1;
	 matrix[7][25]=1;
	 matrix[7][26]=1;
	 matrix[7][27]=1;
	 matrix[7][28]=1;
	 //И
	  for(int i = 0; i<30; i++)
	 {
		 matrix[8][i]= -1;
	 }
	 matrix[8][0]=1;
	 matrix[8][4]=1;
	 matrix[8][5]=1;
	 matrix[8][8]=1;
	 matrix[8][9]=1;
	 matrix[8][10]=1;
	 matrix[8][12]=1;
	 matrix[8][14]=1;
	 matrix[8][15]=1;
	 matrix[8][16]=1;
	 matrix[8][19]=1;
	 matrix[8][20]=1;
	 matrix[8][24]=1;
	 matrix[8][25]=1;
	 matrix[8][29]=1;
	 //9
	  for(int i = 0; i<30; i++)
	 {
		 matrix[9][i]= -1;
	 }
	 matrix[9][0]=1;
	 matrix[9][3]=1;
	 matrix[9][5]=1;
	 matrix[9][7]=1;
	 matrix[9][10]=1;
	 matrix[9][11]=1;
	 matrix[9][15]=1;
	 matrix[9][17]=1;
	 matrix[9][20]=1;
	 matrix[9][23]=1;
	 matrix[9][25]=1;
	 matrix[9][29]=1;


	 // но по факту ее надо будет еще заполнять.
	 //теперь будем создавать первый слой
	 for(int i = 0; i<ObrazecCount; i++)
	 {
			Neuron* neuron = new Neuron(inCount);
			level1.push_back(*neuron);
	 }
	 //ShowMessage((UnicodeString)"Создали первый слой");
	 //ShowMessage(level1.size());
	 //слой создали, теперь надо рассчитать веса дендритов связывающих нейроны с входами
	 for(int i = 0; i < level1.size(); i++)
	 {
		for(int j = 0; j < level1[i].dendrits.size(); j++)
		{
			level1[i].dendrits[j].weight = matrix[i][j] * 0.5;
			level1[i].dendrits[j].input = mas[j];
			//ShowMessage((UnicodeString)"mas[" + j + "] = " + mas[j]);
		}
	 }
	 //ShowMessage((UnicodeString)"Заполнили дендриты первого лоя весами и входами");
	 //ShowMessage((UnicodeString)"Для проверки");
	 //ShowMessage((UnicodeString)"Вес первого = " + level1[0].dendrits[0].weight + ", a вход = " + level1[0].dendrits[0].input);
	 level1[0].getSignal(T);

	 //теперь создадим матрицу обратных связей синапсов второго слоя
	 float **sinapsMatrix = new float* [10]; // 10 строк в массиве
	 for (int count = 0; count < 10; count++)
	 {
		sinapsMatrix[count] = new float[10]; //
	 }

	 for(int i = 0; i < 10; i++)
	 {
		for(int j = 0; j < 10; j++)
		{
			//ShowMessage((UnicodeString)i + "; " + j);
			if(i==j)sinapsMatrix[i][j] = 1.0;
			else sinapsMatrix[i][j]= -eps;
		}
	 }

	 //теперь добавим второй слой нейронов
	 for(int i = 0; i<level1.size(); i++)
	 {
		  Neuron* neuron = new Neuron(level1.size()+1);
		  level2.push_back(*neuron);
	 }

	 //теперь заполним веса дендритов второго слоя
	 //ShowMessage((UnicodeString)"Начинаем заполнять второй слой");
	 for(int i = 0; i < level2.size(); i++)
	 {
		for(int j = 0; j< level2[i].dendrits.size()-1; j++)
		{
			//ShowMessage((UnicodeString)"Для проверки");
			//ShowMessage((UnicodeString)"Вес = " + level1[i].dendrits[j].weight + ", a вход = " + level1[i].dendrits[j].input);
			level2[i].dendrits[j].weight = sinapsMatrix[i][j];
			level2[i].dendrits[j].input = level1[i].getSignal(T);

		}
		level2[i].dendrits[level2[i].dendrits.size()-1].weight = 1;
		level2[i].dendrits[level2[i].dendrits.size()-1].input = level1[i].getSignal(T);

	 }

	 ///////////////////////////////////////////////////////////////////////////
	 //теперь приступим к работе

	 float norma = eMax+1;
	 float *previous = new float[ObrazecCount];
	 float *current = new float[ObrazecCount];

	 for(int i = 0; i < ObrazecCount; i++)
	 {
		previous[i] =  level1[i].getSignal(T);
		level2[i].value = level1[i].getSignal(T);
		level2[i].dendrits[level2[i].dendrits.size()-1].weight = 0;
	 }

	 //ShowMessage(level2[1].dendrits[1].weight);
		 int l = 0;
		 ShowMessage((UnicodeString)"Состояния нейронов второго слоя после обучения:  \n" + previous[0] + "; " + previous[1] + "; " + previous[2] + "; " + previous[3] + "; " + previous[4] + "; " + previous[5] + "; " + previous[6] + "; " + previous[7] + "; " + previous[8]+ "; " + previous[9] );
	 while(norma > eMax)
	 {
		  ShowMessage((UnicodeString)"Cостояния нейронов на предыдущем шаге:\n" + previous[0] + "; " + previous[1] + "; " + previous[2] + "; " + previous[3] + "; " + previous[4] + "; " + previous[5] + "; " + previous[6] + "; " + previous[7] + "; " + previous[8]+ "; " + previous[9] );
		  l++;
		  //пересчитаем входы дендритов
		  for(int i = 0; i < level2.size(); i++)
		  {
			  for(int j = 0; j < level2[i].dendrits.size()-1; j++)
			  {
					//ShowMessage((UnicodeString)level2[i].dendrits[j].input +  " вход ");

//				   for(int k = 0; k < level2.size(); k++ )
//				   {
					   //ShowMessage((UnicodeString)level2[k].value +  ", вход " );
					   level2[i].dendrits[j].input = level2[j].value;
					   //ShowMessage((UnicodeString)level2[i].dendrits[j].input);
				 //  }
			  }
		  }
		  for(int i = 0; i< level2.size(); i++)
		  {
				//ShowMessage(level2[i].value);
				for(int j=0; j<level2[i].dendrits.size(); j++)
				{
					//ShowMessage((UnicodeString)level2[i].dendrits[j].weight + " - вес, " + level2[i].dendrits[j].input);
				}
				current[i] = level2[i].getSignal(T);
		  }
		  ShowMessage((UnicodeString)"Текущие состояния нейронов: \n" + current[0] + "; " + current[1] + "; " + current[2] + "; " + current[3] + "; " + current[4] + "; " + current[5] + "; " + current[6] + "; " + current[7] + "; " + current[8]+ "; " + current[9] );
		  norma = NormFunc(current, previous, level2.size());
		  ShowMessage((UnicodeString)"Функция проверки расстояния Хэмминга показала " + norma+"\nДля выхода из цикла расстояние должно быть меньше 0.1");

		  for(int i = 0; i<level2.size(); i++)
		  {
			previous[i] = current[i];
		  }

		  //ShowMessage(1488);
	 }
	 ShowMessage("Вышли из цикла");
	 float max = 0;
	 for(int i =0; i< level2.size(); i++)
	 {
		 if(level2[i].value>max) max = level2[i].value;
	 }
	 for(int i =0; i< level2.size(); i++)
	 {
		 if(level2[i].value == max)
		 {
			if(i == 0)ShowMessage((UnicodeString)"Походит на A" );
			if(i == 1)ShowMessage((UnicodeString)"Походит на Б" );
			if(i == 2)ShowMessage((UnicodeString)"Походит на В" );
			if(i == 3)ShowMessage((UnicodeString)"Походит на Г" );
			if(i == 4)ShowMessage((UnicodeString)"Походит на Д" );
			if(i == 5)ShowMessage((UnicodeString)"Походит на Е" );
			if(i == 6)ShowMessage((UnicodeString)"Походит на Ж" );
			if(i == 7)ShowMessage((UnicodeString)"Походит на З" );
			if(i == 8)ShowMessage((UnicodeString)"Походит на И" );
			if(i == 9)ShowMessage((UnicodeString)"Походит на К" );
		 }
	 }
	 exit(0);

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	if(BitBtn1->Tag == -1)
	{
		BitBtn1->Glyph->LoadFromFile("black.bmp");
		BitBtn1->Tag = 1;
		return;
	}
	if(BitBtn1->Tag == 1)
	{
		BitBtn1->Glyph->LoadFromFile("grey.bmp");
		BitBtn1->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
	if(BitBtn2->Tag == -1)
	{
		BitBtn2->Glyph->LoadFromFile("black.bmp");
		BitBtn2->Tag = 1;
		return;
	}
	if(BitBtn2->Tag == 1)
	{
		BitBtn2->Glyph->LoadFromFile("grey.bmp");
		BitBtn2->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
	if(BitBtn3->Tag == -1)
	{
		BitBtn3->Glyph->LoadFromFile("black.bmp");
		BitBtn3->Tag = 1;
		return;
	}
	if(BitBtn3->Tag == 1)
	{
		BitBtn3->Glyph->LoadFromFile("grey.bmp");
		BitBtn3->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
	if(BitBtn4->Tag == -1)
	{
		BitBtn4->Glyph->LoadFromFile("black.bmp");
		BitBtn4->Tag = 1;
		return;
	}
	if(BitBtn4->Tag == 1)
	{
		BitBtn4->Glyph->LoadFromFile("grey.bmp");
		BitBtn4->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
	if(BitBtn5->Tag == -1)
	{
		BitBtn5->Glyph->LoadFromFile("black.bmp");
		BitBtn5->Tag = 1;
		return;
	}
	if(BitBtn5->Tag == 1)
	{
		BitBtn5->Glyph->LoadFromFile("grey.bmp");
		BitBtn5->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
	if(BitBtn6->Tag == -1)
	{
		BitBtn6->Glyph->LoadFromFile("black.bmp");
		BitBtn6->Tag = 1;
		return;
	}
	if(BitBtn6->Tag == 1)
	{
		BitBtn6->Glyph->LoadFromFile("grey.bmp");
		BitBtn6->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
	if(BitBtn7->Tag == -1)
	{
		BitBtn7->Glyph->LoadFromFile("black.bmp");
		BitBtn7->Tag = 1;
		return;
	}
	if(BitBtn7->Tag == 1)
	{
		BitBtn7->Glyph->LoadFromFile("grey.bmp");
		BitBtn7->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
	if(BitBtn8->Tag == -1)
	{
		BitBtn8->Glyph->LoadFromFile("black.bmp");
		BitBtn8->Tag = 1;
		return;
	}
	if(BitBtn8->Tag == 1)
	{
		BitBtn8->Glyph->LoadFromFile("grey.bmp");
		BitBtn8->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{
	if(BitBtn9->Tag == -1)
	{
		BitBtn9->Glyph->LoadFromFile("black.bmp");
		BitBtn9->Tag = 1;
		return;
	}
	if(BitBtn9->Tag == 1)
	{
		BitBtn9->Glyph->LoadFromFile("grey.bmp");
		BitBtn9->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn10Click(TObject *Sender)
{
	if(BitBtn10->Tag == -1)
	{
		BitBtn10->Glyph->LoadFromFile("black.bmp");
		BitBtn10->Tag = 1;
		return;
	}
	if(BitBtn10->Tag == 1)
	{
		BitBtn10->Glyph->LoadFromFile("grey.bmp");
		BitBtn10->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn11Click(TObject *Sender)
{
	if(BitBtn11->Tag == -1)
	{
		BitBtn11->Glyph->LoadFromFile("black.bmp");
		BitBtn11->Tag = 1;
		return;
	}
	if(BitBtn11->Tag == 1)
	{
		BitBtn11->Glyph->LoadFromFile("grey.bmp");
		BitBtn11->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn12Click(TObject *Sender)
{
	if(BitBtn12->Tag == -1)
	{
		BitBtn12->Glyph->LoadFromFile("black.bmp");
		BitBtn12->Tag = 1;
		return;
	}
	if(BitBtn12->Tag == 1)
	{
		BitBtn12->Glyph->LoadFromFile("grey.bmp");
		BitBtn12->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn13Click(TObject *Sender)
{
	if(BitBtn13->Tag == -1)
	{
		BitBtn13->Glyph->LoadFromFile("black.bmp");
		BitBtn13->Tag = 1;
		return;
	}
	if(BitBtn13->Tag == 1)
	{
		BitBtn13->Glyph->LoadFromFile("grey.bmp");
		BitBtn13->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn14Click(TObject *Sender)
{
	if(BitBtn14->Tag == -1)
	{
		BitBtn14->Glyph->LoadFromFile("black.bmp");
		BitBtn14->Tag = 1;
		return;
	}
	if(BitBtn14->Tag == 1)
	{
		BitBtn14->Glyph->LoadFromFile("grey.bmp");
		BitBtn14->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn15Click(TObject *Sender)
{
	if(BitBtn15->Tag == -1)
	{
		BitBtn15->Glyph->LoadFromFile("black.bmp");
		BitBtn15->Tag = 1;
		return;
	}
	if(BitBtn15->Tag == 1)
	{
		BitBtn15->Glyph->LoadFromFile("grey.bmp");
		BitBtn15->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn16Click(TObject *Sender)
{
	if(BitBtn16->Tag == -1)
	{
		BitBtn16->Glyph->LoadFromFile("black.bmp");
		BitBtn16->Tag = 1;
		return;
	}
	if(BitBtn16->Tag == 1)
	{
		BitBtn16->Glyph->LoadFromFile("grey.bmp");
		BitBtn16->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn17Click(TObject *Sender)
{
	if(BitBtn17->Tag == -1)
	{
		BitBtn17->Glyph->LoadFromFile("black.bmp");
		BitBtn17->Tag = 1;
		return;
	}
	if(BitBtn17->Tag == 1)
	{
		BitBtn17->Glyph->LoadFromFile("grey.bmp");
		BitBtn17->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn18Click(TObject *Sender)
{
	if(BitBtn18->Tag == -1)
	{
		BitBtn18->Glyph->LoadFromFile("black.bmp");
		BitBtn18->Tag = 1;
		return;
	}
	if(BitBtn18->Tag == 1)
	{
		BitBtn18->Glyph->LoadFromFile("grey.bmp");
		BitBtn18->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn19Click(TObject *Sender)
{
	if(BitBtn19->Tag == -1)
	{
		BitBtn19->Glyph->LoadFromFile("black.bmp");
		BitBtn19->Tag = 1;
		return;
	}
	if(BitBtn19->Tag == 1)
	{
		BitBtn19->Glyph->LoadFromFile("grey.bmp");
		BitBtn19->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn20Click(TObject *Sender)
{
	if(BitBtn20->Tag == -1)
	{
		BitBtn20->Glyph->LoadFromFile("black.bmp");
		BitBtn20->Tag = 1;
		return;
	}
	if(BitBtn20->Tag == 1)
	{
		BitBtn20->Glyph->LoadFromFile("grey.bmp");
		BitBtn20->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn21Click(TObject *Sender)
{
	if(BitBtn21->Tag == -1)
	{
		BitBtn21->Glyph->LoadFromFile("black.bmp");
		BitBtn21->Tag = 1;
		return;
	}
	if(BitBtn21->Tag == 1)
	{
		BitBtn21->Glyph->LoadFromFile("grey.bmp");
		BitBtn21->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn22Click(TObject *Sender)
{
	if(BitBtn22->Tag == -1)
	{
		BitBtn22->Glyph->LoadFromFile("black.bmp");
		BitBtn22->Tag = 1;
		return;
	}
	if(BitBtn22->Tag == 1)
	{
		BitBtn22->Glyph->LoadFromFile("grey.bmp");
		BitBtn22->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn23Click(TObject *Sender)
{
	if(BitBtn23->Tag == -1)
	{
		BitBtn23->Glyph->LoadFromFile("black.bmp");
		BitBtn23->Tag = 1;
		return;
	}
	if(BitBtn23->Tag == 1)
	{
		BitBtn23->Glyph->LoadFromFile("grey.bmp");
		BitBtn23->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn24Click(TObject *Sender)
{
	if(BitBtn24->Tag == -1)
	{
		BitBtn24->Glyph->LoadFromFile("black.bmp");
		BitBtn24->Tag = 1;
		return;
	}
	if(BitBtn24->Tag == 1)
	{
		BitBtn24->Glyph->LoadFromFile("grey.bmp");
		BitBtn24->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn25Click(TObject *Sender)
{
	if(BitBtn25->Tag == -1)
	{
		BitBtn25->Glyph->LoadFromFile("black.bmp");
		BitBtn25->Tag = 1;
		return;
	}
	if(BitBtn25->Tag == 1)
	{
		BitBtn25->Glyph->LoadFromFile("grey.bmp");
		BitBtn25->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn26Click(TObject *Sender)
{
	if(BitBtn26->Tag == -1)
	{
		BitBtn26->Glyph->LoadFromFile("black.bmp");
		BitBtn26->Tag = 1;
		return;
	}
	if(BitBtn26->Tag == 1)
	{
		BitBtn26->Glyph->LoadFromFile("grey.bmp");
		BitBtn26->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn27Click(TObject *Sender)
{
	if(BitBtn27->Tag == -1)
	{
		BitBtn27->Glyph->LoadFromFile("black.bmp");
		BitBtn27->Tag = 1;
		return;
	}
	if(BitBtn27->Tag == 1)
	{
		BitBtn27->Glyph->LoadFromFile("grey.bmp");
		BitBtn27->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn28Click(TObject *Sender)
{
		if(BitBtn28->Tag == -1)
	{
		BitBtn28->Glyph->LoadFromFile("black.bmp");
		BitBtn28->Tag = 1;
		return;
	}
	if(BitBtn28->Tag == 1)
	{
		BitBtn28->Glyph->LoadFromFile("grey.bmp");
		BitBtn28->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn29Click(TObject *Sender)
{
		if(BitBtn29->Tag == -1)
	{
		BitBtn29->Glyph->LoadFromFile("black.bmp");
		BitBtn29->Tag = 1;
		return;
	}
	if(BitBtn29->Tag == 1)
	{
		BitBtn29->Glyph->LoadFromFile("grey.bmp");
		BitBtn29->Tag = -1;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn30Click(TObject *Sender)
{
	if(BitBtn30->Tag == -1)
	{
		BitBtn30->Glyph->LoadFromFile("black.bmp");
		BitBtn30->Tag = 1;
		return;
	}
	if(BitBtn30->Tag == 1)
	{
		BitBtn30->Glyph->LoadFromFile("grey.bmp");
		BitBtn30->Tag = -1;
		return;
	}

}
//---------------------------------------------------------------------------

