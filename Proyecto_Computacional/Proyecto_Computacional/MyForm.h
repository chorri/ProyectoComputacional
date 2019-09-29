#pragma once

#include "Header.h"

namespace Proyecto_Computacional {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Graphics^ mainGraphics;

		ImagenTrabajo^ img;




		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			img = gcnew ImagenTrabajo("Test.png", this->ClientRectangle);
			mainGraphics = this->CreateGraphics();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

			delete img;
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::TimerUpdate);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::GetKeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TimerUpdate(System::Object^  sender, System::EventArgs^  e) {
		img->DibujarImagen(this->mainGraphics);
	}
	private: System::Void GetKeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		switch (e->KeyCode)
		{
		case Keys::Q:
			img->FiltroDeMedia();
			break;
		case Keys::W:
			img->FiltroDeLaMediana();
			break;
		default:
			break;
		}
	}
	};
}
