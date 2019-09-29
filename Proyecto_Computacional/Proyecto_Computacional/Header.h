#pragma once

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
		int red = 0;
		int green = 0;
		int blue = 0;

		for (int x = 1; x < img->Width - 1; x++)
		{

			for (int y = 1; y < img->Height - 1; y++)
			{
				
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

				Color color = color.FromArgb(green, red, blue);
				
				
				img->SetPixel(x, y, color);
			}
		}
	}

	void FiltroDeLaMediana() {
		
	}

	virtual void DibujarImagen(Graphics^ graficador) {
		graficador->DrawImage(img, area);
	}

private:

};
