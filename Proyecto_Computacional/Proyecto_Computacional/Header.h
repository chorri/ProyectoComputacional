#pragma once

#include "Lista.h"

using namespace System;//Rectangle
using namespace System::ComponentModel;
using namespace System::Drawing;//Bitmap
using namespace System::Drawing::Drawing2D;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::Design;


ref class ImagenTrabajo
{
public:

	Bitmap^ img;
	Rectangle area;


	ImagenTrabajo(System::String^ ruta, Rectangle _area) {
		img = gcnew Bitmap(ruta);
		area = _area;
	}
	~ImagenTrabajo() {

	}

	void FiltroDeMedia() {
		int a = 0;
		int red = 0;
		int green = 0;
		int blue = 0;

		for (int x = 1; x < img->Width - 1; x++)
		{

			for (int y = 1; y < img->Height - 1; y++)
			{
				//A
				a = img->GetPixel(x - 1, y - 1).A + img->GetPixel(x, y - 1).A + img->GetPixel(x + 1, y - 1).A +
					img->GetPixel(x - 1, y).A + img->GetPixel(x, y).A + img->GetPixel(x + 1, y).A +
					img->GetPixel(x - 1, y + 1).A + img->GetPixel(x, y + 1).A + img->GetPixel(x + 1, y + 1).A;

				a = a / 9;
				
				//Red
				red = img->GetPixel(x - 1, y - 1).R + img->GetPixel(x, y - 1).R + img->GetPixel(x + 1, y - 1).R +
					img->GetPixel(x - 1, y).R + img->GetPixel(x, y).R + img->GetPixel(x + 1, y).R +
					img->GetPixel(x - 1, y + 1).R + img->GetPixel(x, y + 1).R + img->GetPixel(x + 1, y + 1).R;

				red = red / 9;

				//Green
				green = img->GetPixel(x - 1, y - 1).G + img->GetPixel(x, y - 1).G + img->GetPixel(x + 1, y - 1).G +
					img->GetPixel(x - 1, y).G + img->GetPixel(x, y).G + img->GetPixel(x + 1, y).G +
					img->GetPixel(x - 1, y + 1).G + img->GetPixel(x, y + 1).G + img->GetPixel(x + 1, y + 1).G;

				green = green / 9;

				//Blue
				blue = img->GetPixel(x - 1, y - 1).B + img->GetPixel(x, y - 1).B + img->GetPixel(x + 1, y - 1).B +
					img->GetPixel(x - 1, y).B + img->GetPixel(x, y).B + img->GetPixel(x + 1, y).B +
					img->GetPixel(x - 1, y + 1).B + img->GetPixel(x, y + 1).B + img->GetPixel(x + 1, y + 1).B;

				blue = blue / 9;

				//SetPixel

				Color color = color.FromArgb(a,green, red, blue);
				
				
				img->SetPixel(x, y, color);
			}
		}
		//MessageBox::Show("temp1");
	}

	void FiltroDeLaMediana() {
		int a = 0;
		int red = 0;
		int green = 0;
		int blue = 0;
		Lista<int>^ lista = gcnew Lista<int>();

		for (int x = 1; x < img->Width-1; x++)
		{
			for (int y = 1; y < img->Height - 1; y++)
			{

				//Red
				lista->AgregarFinal(img->GetPixel(x - 1, y - 1).R); lista->AgregarFinal(img->GetPixel(x, y - 1).R); lista->AgregarFinal(img->GetPixel(x + 1, y - 1).R);
				lista->AgregarFinal(img->GetPixel(x - 1, y).R); lista->AgregarFinal(img->GetPixel(x, y).R); lista->AgregarFinal(img->GetPixel(x + 1, y).R);
				lista->AgregarFinal(img->GetPixel(x - 1, y + 1).R); lista->AgregarFinal(img->GetPixel(x, y + 1).R); lista->AgregarFinal(img->GetPixel(x + 1, y + 1).R);
			
				red = ObtenerMediana(lista);
				lista->BorrarTodo();
				
				//Green
				lista->AgregarFinal(img->GetPixel(x - 1, y - 1).G); lista->AgregarFinal(img->GetPixel(x, y - 1).G); lista->AgregarFinal(img->GetPixel(x + 1, y - 1).G);
				lista->AgregarFinal(img->GetPixel(x - 1, y).G); lista->AgregarFinal(img->GetPixel(x, y).G); lista->AgregarFinal(img->GetPixel(x + 1, y).G);
				lista->AgregarFinal(img->GetPixel(x - 1, y + 1).G); lista->AgregarFinal(img->GetPixel(x, y + 1).G); lista->AgregarFinal(img->GetPixel(x + 1, y + 1).G);

				green = ObtenerMediana(lista);
				lista->BorrarTodo();
				
				//Blue
				lista->AgregarFinal(img->GetPixel(x - 1, y - 1).B); lista->AgregarFinal(img->GetPixel(x, y - 1).B); lista->AgregarFinal(img->GetPixel(x + 1, y - 1).B);
				lista->AgregarFinal(img->GetPixel(x - 1, y).B); lista->AgregarFinal(img->GetPixel(x, y).B); lista->AgregarFinal(img->GetPixel(x + 1, y).B);
				lista->AgregarFinal(img->GetPixel(x - 1, y + 1).B); lista->AgregarFinal(img->GetPixel(x, y + 1).B); lista->AgregarFinal(img->GetPixel(x + 1, y + 1).B);

				blue = ObtenerMediana(lista);
				lista->BorrarTodo();

				//Set PIxel
				//MessageBox::Show(red.ToString() + " | " + green.ToString() + " | " + blue.ToString());
				Color color = color.FromArgb(red, green, blue);

				//MessageBox::Show(img->GetPixel(x, y).R.ToString());

				img->SetPixel(x, y, color);

				//MessageBox::Show(img->GetPixel(x,y).R.ToString());
			}
		}

		//MessageBox::Show("Temp");

		delete lista;
	}
	/*
	void FiltroLaplaciano() {
		int a = 0;
		int red = 0;
		int green = 0;
		int blue = 0;

		for (int x = 1; x < img->Width - 1; x++)
		{

			for (int y = 1; y < img->Height - 1; y++)
			{
				//A
				a = img->GetPixel(x - 1, y - 1).A + img->GetPixel(x, y - 1).A + img->GetPixel(x + 1, y - 1).A +
					img->GetPixel(x - 1, y).A + img->GetPixel(x, y).A + img->GetPixel(x + 1, y).A +
					img->GetPixel(x - 1, y + 1).A + img->GetPixel(x, y + 1).A + img->GetPixel(x + 1, y + 1).A;

				a = a / 9;

				//Red
				red = img->GetPixel(x - 1, y - 1).R + img->GetPixel(x, y - 1).R + img->GetPixel(x + 1, y - 1).R +
					img->GetPixel(x - 1, y).R + img->GetPixel(x, y).R + img->GetPixel(x + 1, y).R +
					img->GetPixel(x - 1, y + 1).R + img->GetPixel(x, y + 1).R + img->GetPixel(x + 1, y + 1).R;

				red = red / 9;

				//Green
				green = img->GetPixel(x - 1, y - 1).G + img->GetPixel(x, y - 1).G + img->GetPixel(x + 1, y - 1).G +
					img->GetPixel(x - 1, y).G + img->GetPixel(x, y).G + img->GetPixel(x + 1, y).G +
					img->GetPixel(x - 1, y + 1).G + img->GetPixel(x, y + 1).G + img->GetPixel(x + 1, y + 1).G;

				green = green / 9;

				//Blue
				blue = img->GetPixel(x - 1, y - 1).B + img->GetPixel(x, y - 1).B + img->GetPixel(x + 1, y - 1).B +
					img->GetPixel(x - 1, y).B + img->GetPixel(x, y).B + img->GetPixel(x + 1, y).B +
					img->GetPixel(x - 1, y + 1).B + img->GetPixel(x, y + 1).B + img->GetPixel(x + 1, y + 1).B;

				blue = blue / 9;

				//SetPixel

				Color color = color.FromArgb(a, green, red, blue);


				img->SetPixel(x, y, color);
			}
		}
		MessageBox::Show("Laplaciano");
	}
	*/
	

	virtual void DibujarImagen(Graphics^ graficador) {
		graficador->DrawImage(img, area);
	}

private:
	
	int ObtenerMediana(Lista<int>^ _lista) {
		BubbleSort(_lista, 9);
		return _lista->ElementoAt(4);
	}

	void BubbleSort(Lista<int>^ arr, int n)
	{
		int i, j;
		bool swapped;
		for (i = 0; i < n - 1; i++)
		{
			swapped = false;
			for (j = 0; j < n - i - 1; j++)
			{
				if (arr->ElementoAt(j) > arr->ElementoAt(j + 1))
				{
					int aux = arr->ElementoAt(j);
					arr->At(j)->elem = arr->At(j + 1)->elem;
					arr->At(j + 1)->elem = aux;
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break 
			if (swapped == false)
				break;
		}
	}

};
