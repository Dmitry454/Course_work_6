#include "MyForm.h"
#include "MyForm1.h"
#include <math.h>
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Coursework6::MyForm form;
	Application::Run(% form);

}

System::Void Coursework6::MyForm::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//создаем CLI объект с помощью конструктора, принимающего на вход имя файла
		//и возвращаем с помощью gcnew указатель (^) на CLI объект
		// baseImage - переменная, в которой хранится исходное изображение
		baseImage = gcnew Bitmap(openFileDialog1->FileName);
		imageUploaded = true;

		//создаем CLI объект с помощью конструктора, принимающего на вход размер //картинки
		//и возвращаем с помощью gcnew указатель (^) на CLI объект 
		//в отличие от предыдущего конструктора, данный конструктор создает только //заголовок объекта (размер картинки)
		//никакие графические данные не создаются!
		img1 = gcnew Bitmap(baseImage);

		// Копируем данные картинки baseImage в картинку img1 попиксельно
		for (int i = 0; i < baseImage->Width; i++)
			for (int j = 0; j < baseImage->Height; j++)
			{
				Color cl = baseImage->GetPixel(i, j);
				img1->SetPixel(i, j, cl);
			}

		//Bitmap^ img2 = gcnew Bitmap(img1->Width, img1->Height);
		pictureBox1->Image = baseImage;
		pictureBox1->Size = baseImage->Size;

		// Размер в пикселях(записываем в лейбл 1)
		label1->Text = baseImage->Width + "x" + baseImage->Height;
		label12->Text = "";
		label12->Text = (ScaleCounter).ToString() + "%";
	}
}

System::Void Coursework6::MyForm::сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	saveFileDialog1->Filter = "BitMap files (*.bmp)|*.bmp|JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png";
	saveFileDialog1->FilterIndex = 2;
	saveFileDialog1->RestoreDirectory = true;
	if (System::Windows::Forms::DialogResult::OK == saveFileDialog1->ShowDialog())
	{
		Bitmap^ bmp = gcnew Bitmap(pictureBox1->Image);
		bmp->Save(saveFileDialog1->FileName);
	}
}

System::Void Coursework6::MyForm::восстановитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	groupBox1->Hide();
	groupBox2->Hide();
	groupBox3->Hide();
	img1 = baseImage;
	pictureBox1->Image = baseImage;
	pictureBox1->Size = img1->Size;
	label1->Text = img1->Width + "x" + img1->Height;
	ScaleCounter = 100;
	label12->Text = "";
	label12->Text = (ScaleCounter).ToString() + "%";
	operationNum = 0;
}

System::Void Coursework6::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Close();
}

System::Void Coursework6::MyForm::увеличитьМасштабToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (ScaleCounter < 400 && imageUploaded)
	{
		ScaleCounter += 10;
		scale += 0.1;
		Bitmap^ bitmap1 = gcnew Bitmap(pictureBox1->Image);
		Graphics^ Gr1 = Graphics::FromImage(bitmap1);
		img1 = gcnew Bitmap(bitmap1->Width * scale, bitmap1->Height * scale, Gr1);
		Graphics^ Gr2 = Graphics::FromImage(img1);
		Rectangle compressionRectangle = Rectangle(0, 0, bitmap1->Width * scale, bitmap1->Height * scale);
		Gr2->DrawImage(bitmap1, compressionRectangle);
		pictureBox1->Image = img1;
		pictureBox1->Size = img1->Size;

		//Записываем в лейбл 12 количество процентов от первоначального
		label12->Text = "";
		label12->Text = (ScaleCounter).ToString() + "%";

		//Записываем в лейбл 1 размер обновленного изображения
		label1->Text = img1->Width + "x" + img1->Height;

		scale = 1;
	}
}

System::Void Coursework6::MyForm::уменьшитьМасштабToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (ScaleCounter > 10 && imageUploaded)
	{
		ScaleCounter -= 10;
		scale -= 0.1;
		Bitmap^ bitmap1 = gcnew Bitmap(pictureBox1->Image);
		Graphics^ Gr1 = Graphics::FromImage(bitmap1);
		img1 = gcnew Bitmap(bitmap1->Width * scale, bitmap1->Height * scale, Gr1);
		Graphics^ Gr2 = Graphics::FromImage(img1);
		Rectangle compressionRectangle = Rectangle(0, 0, bitmap1->Width * scale, bitmap1->Height * scale);
		Gr2->DrawImage(bitmap1, compressionRectangle);
		pictureBox1->Image = img1;
		pictureBox1->Size = img1->Size;

		//Записываем в лейбл 12 количество процентов от первоначального
		label12->Text = "";
		label12->Text = (ScaleCounter).ToString() + "%";

		//Записываем в лейбл 1 размер обновленного изображения
		label1->Text = img1->Width + "x" + img1->Height;
		// Сохраняем новое изображение в img1

		scale = 1;
	}
}

System::Void Coursework6::MyForm::справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm1^ f2 = gcnew MyForm1();
	f2->Show();
}

System::Void Coursework6::MyForm::фильтр1ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	operationNum = 1;
	groupBox1->Hide();
	groupBox2->Hide();
	groupBox3->Hide();
	filterThreeActivated = false;

	if (imageUploaded)
	{
		Bitmap^ img2 = gcnew Bitmap(pictureBox1->Image);
		halfOfThePicture = img1->Width;
		// Проверяем, поставлена ли галочка
		if (checkedFlag)
		{
			halfOfThePicture = (img1->Width) / 2;
			//Переносим правую половинку img1 на картинку img2
			for (int i = halfOfThePicture; i < img1->Width; i++)
			{
				for (int j = 0; j < img1->Height; j++)
				{
					//в обект типа Color сохраняем значение цвета пикселя из первого изображения
					Color cl1 = img1->GetPixel(i, j);
					img2->SetPixel(i, j, cl1);
				}
			}
		}

		//проходим по каждому пикселю изображения
		for (int i = 0; i < halfOfThePicture; i++)
		{
			for (int j = 0; j < img2->Height; j++)
			{
				//в обект типа Color сохраняем значение цвета пикселя из первого изображения
				Color cl1 = img2->GetPixel(i, j);
				//инициализируем второй объект типа Color тремя значениями 
				// (R, G, B)
				float new_red = 255 - cl1.R;
				float new_green = 255 - cl1.G;
				float new_blue = 255 - cl1.B;
				Color cl2 = Color::FromArgb(new_red, new_green, new_blue);
				//записываем в соответствующий пиксель второго изображения      
				//новый цвет
				img2->SetPixel(i, j, cl2);
			}
		}
		pictureBox1->Image = img2;
	}
}

System::Void Coursework6::MyForm::фильтр2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	operationNum = 2;
	groupBox1->Show();
	groupBox2->Hide();
	groupBox3->Hide();
	filterFourActivated = false;
	filterThreeActivated = false;
}

System::Void Coursework6::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		q1 = Convert::ToInt16(textBox1->Text);
		q2 = Convert::ToInt16(textBox2->Text);
		double koef = q1 / q2;

		if (imageUploaded)
		{
			Bitmap^ img2 = gcnew Bitmap(img1->Width, img1->Height);
			halfOfThePicture = img1->Width;
			// Проверяем, поставлена ли галочка
			if (checkedFlag)
			{
				halfOfThePicture = (img1->Width) / 2;
				//Переносим правую половинку imageToCompare на картинку img3
				for (int i = halfOfThePicture; i < img1->Width; i++)
				{
					for (int j = 0; j < img1->Height; j++)
					{
						//в обект типа Color сохраняем значение цвета пикселя из первого изображения
						Color cl1 = img1->GetPixel(i, j);
						img2->SetPixel(i, j, cl1);
					}
				}
			}
			//проходим по каждому пикселю изображения
			for (int i = 0; i < halfOfThePicture; i++)
			{
				for (int j = 0; j < img1->Height; j++)
				{
					//инициализируем второй объект типа Color тремя значениями 
					// (R, G, B)
					float newRed;
					float newGreen;
					float newBlue;
					//в обект типа Color сохраняем значение цвета пикселя из первого изображения
					Color cl1 = img1->GetPixel(i, j);
					if (cl1.R < q1) newRed = 0;
					else if (cl1.R > q2) newRed = 255;
					else {
						newRed = cl1.G * koef;
					}
					if (cl1.G < q1) newGreen = 0;
					else if (cl1.G > q2) newGreen = 255;
					else {
						newGreen = cl1.G * koef;
					}
					if (cl1.B < q1) newBlue = 0;
					else if (cl1.B > q2) newBlue = 255;
					else {
						newBlue = cl1.G * koef;
					}

					Color cl2 = Color::FromArgb(newRed, newGreen, newBlue);
					//записываем в соответствующий пиксель второго изображения      
					//новый цвет
					img2->SetPixel(i, j, cl2);
				}
				pictureBox1->Image = img2;
			}
		}
	}
	catch (...)
	{
		MessageBox::Show("Оба числа должны быть целыми и положительными", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void Coursework6::MyForm::фильтр3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	groupBox1->Hide();
	groupBox2->Hide();
	groupBox3->Hide();
	filterThreeActivated = true;
	Bitmap^ img2 = gcnew Bitmap(pictureBox1->Image);

	////проходим по каждому пикселю изображения
	//for (int i = 0; i < img2->Width; i++)
	//{
	//	for (int j = 0; j < img2->Height / 2; j++)
	//	{
	//		//в обект типа Color сохраняем значение цвета пикселя из текущего изображения
	//		Color pixel = img2->GetPixel(i, j);
	//		//в обект типа Color сохраняем значение цвета противоположного пикселя из первого изображения
	//		Color oppositePixel = img2->GetPixel(img2->Width - i - 1, img2->Height - j - 1);

	//		//записываем в соответствующий пиксель изображения      
	//		img2->SetPixel(img2->Width - i - 1, img2->Height - j - 1, pixel);
	//		img2->SetPixel(i, j, oppositePixel);
	//	}
	//	pictureBox1->Image = img2;
	//}
}

System::Void Coursework6::MyForm::фильтр4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	groupBox1->Hide();
	groupBox2->Hide();
	groupBox3->Show();
	Bitmap^ img = gcnew Bitmap(pictureBox1->Image);
	Bitmap^ newBmp = gcnew Bitmap(img);
	filterFourActivated = true;
	filterThreeActivated = false;
	// общее количество пикселей картинки
	int total = img->Width * img->Height;

	// Удаляем все прошлые значения точек гистограмм
	chart1->Series["1"]->Points->Clear();
	chart2->Series["2"]->Points->Clear();
	Gist.Clear();
	stretchedGist.Clear();
	pdata.Clear();

	// заполняем Gist ноликами
	for (int i = 0; i < 256; i++)
	{
		Gist.Add(0);
	}

	// перебираем в циклах все пиксели исходного изображения
	for (int j = 0; j < img->Height; j++)
		for (int i = 0; i < img->Width; i++)
		{
			// получаем (i, j) пиксель
			Color currentPixel = img->GetPixel(i, j);

			// получаем компоненты цветов пикселя
			int Red = currentPixel.R;
			int Green = currentPixel.G;
			int Blue = currentPixel.B;

			// делаем цвет черно-белым (оттенки серого) - находим среднее арифметическое
			Red = Green = Blue = (Red + Green + Blue) / 3;

			// собираем новый пиксель по частям (по каналам)
			Color newPixel = Color::FromArgb(Red, Green, Blue);

			//Записываем значение newPixel в соответствующий пиксель newBmp
			newBmp->SetPixel(i, j, newPixel);

			// считаем количество пикселей по каждому уровню яркости
			Gist[Red] ++;

			// для каждого пикселя изображения фиксируем уровень яркости
			pdata.Add(Red);

			stretchedPdata.Add(Red);
		}

	// строим первую гистограмму
	for (int i = 0; i < 256; i++)
	{
		chart1->Series["1"]->Points->AddXY(i, Gist[i]);
	}
	pictureBox1->Image = newBmp;


	//Находим минимальное и максимальное значения яркости исходной картинки
	int max = 0;
	int min = 255;
	for (int i = 0; i < total; i++)
	{
		if (pdata[i] > max) max = pdata[i];
		if (pdata[i] < min) min = pdata[i];
	}
}
System::Void Coursework6::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	Bitmap^ img = gcnew Bitmap(pictureBox1->Image);
	Bitmap^ newBmp = gcnew Bitmap(img);
	chart2->Series["2"]->Points->Clear();
	stretchedGist.Clear();

	// заполняемstretchedGistGist ноликами
	for (int i = 0; i < 256; i++)
	{
		stretchedGist.Add(0);
	}

	// Применяем функцию stretchHistogram
	stretchHistogram(stretchedPdata, img->Width, img->Height, 255);
	// Заполняем вторую гистограмму значениями и создаем новую
	// картинку, соответствующую нормализованной гистограмме
	for (int j = 0; j < img->Height; j++)
		for (int i = 0; i < img->Width; i++)
		{

			newBmp->SetPixel(i, j, Color::FromArgb(stretchedPdata[j * img->Width + i], stretchedPdata[j * img->Width + i], stretchedPdata[j * img->Width + i]));
			stretchedGist[stretchedPdata[j * img->Width + i]] ++;
		}

	// строим вторую гистограмму
	for (int i = 0; i < 256; i++)
	{
		chart2->Series["2"]->Points->AddXY(i, stretchedGist[i]);
	}

	// Отображаем новую картинку
	pictureBox1->Image = newBmp;
}
System::Void Coursework6::MyForm::фильтр5ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	groupBox1->Hide();
	groupBox2->Show();
	groupBox3->Hide();
	filterFourActivated = false;
	filterThreeActivated = false;
}
System::Void Coursework6::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	int scaleFilter5 = 1;
	try
	{
		scaleFilter5 = Convert::ToInt16(textBox3->Text);

		Bitmap^ img2 = gcnew Bitmap(pictureBox1->Image);
		//int width = (img2->Width) / scaleFilter5;
		//int height = (img2->Height) / scaleFilter5;
		//Bitmap^ img3 = gcnew Bitmap(width, height);
		//for (int i = 0; i < img2->Width - scaleFilter5; i += scaleFilter5)
		//{
		//	for (int j = 0; j < img2->Height - scaleFilter5; j += scaleFilter5)
		//	{
		//		//Color cl1 = img2->GetPixel(i, j);
		//		//Color cl2 = img2->GetPixel(i + 1, j);
		//		//Color cl3 = img2->GetPixel(i, j + 1);
		//		//Color cl4 = img2->GetPixel(i + 1, j + 1);

		//		int sumRed = 0;
		//		int sumBlue = 0;
		//		int sumGreen = 0;
		//		for (int column = 0; column < scaleFilter5; column++)
		//		{
		//			for (int row = 0; row < scaleFilter5; row++)
		//			{
		//				Color cl1 = img2->GetPixel(i + row, j + column);
		//				sumRed += cl1.R;
		//				sumGreen += cl1.G;
		//				sumBlue += cl1.B;
		//			}
		//		}
		//		int numOfPixels = scaleFilter5 * scaleFilter5;
		//		sumRed /= numOfPixels;
		//		sumGreen /= numOfPixels;
		//		sumBlue /= numOfPixels;
		//		img3->SetPixel(i / scaleFilter5, j / scaleFilter5, Color::FromArgb(sumRed, sumGreen, sumBlue));
		//	}
		//}
		//	pictureBox1->Image = img3;

		//	//Записываем в лейбл 12 количество процентов от первоначального
		//	ScaleCounter /= scaleFilter5;
		//	label12->Text = "";
		//	label12->Text = (ScaleCounter).ToString() + "%";

		//	//Записываем в лейбл 1 размер обновленного изображения
		//	label1->Text = img3->Width + "x" + img3->Height;
		//}
		//catch (...)
		//{
		//	MessageBox::Show("Введите целое положительное число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		//}
		int width = (img2->Width) * scaleFilter5;
		Bitmap^ img3 = gcnew Bitmap(width, img2->Width);
		for (int i = 0; i < img2->Width; i ++)
		{
			for (int j = 0; j < img2->Height; j ++)
			{
				Color cl = img2->GetPixel(i, j);
				for (int x = 0; x < scaleFilter5; x++)
				{
					img3->SetPixel(i*scaleFilter5 + x, j, cl);
				}
			}
		}
		pictureBox1->Image = img3;
		pictureBox1->Size = img3->Size;

		//Очищаем лейбл, отображающий масштаб
		label12->Text = "";

		//Записываем в лейбл 1 размер обновленного изображения
		label1->Text = img3->Width + "x" + img3->Height;
	}
	catch (...)
	{
		MessageBox::Show("Введите целое положительное число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
System::Void Coursework6::MyForm::pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	// проверка, что картинка загружена
	if (imageUploaded)
	{
		Bitmap^ img2 = gcnew Bitmap(pictureBox1->Image);
		// проверка, что мы не выходим за пределы изображения
		if ((e->X > 0) && (e->X < img2->Width) &&
			(e->Y > 0) && (e->Y < img2->Height))
		{
			// координата x (записываем в лейбл 2)
			label3->Text = Convert::ToString(e->X);
			// координата y (записываем в лейбл 3)
			label5->Text = Convert::ToString(e->Y);

			Color current_p = img2->GetPixel(e->X, e->Y);
			// Записываем значения цветов в соответствующие лейблы
			label7->Text = Convert::ToString(current_p.R);
			label9->Text = Convert::ToString(current_p.G);
			label11->Text = Convert::ToString(current_p.B);
		}

		if (filterThreeActivated)
		{
			for (int i = -2; i < 2; i++)
			{
				for (int j = -2; j < 2; j++)
				{
					// проверка, что мы не выходим за пределы изображения
					if ((e->X + i > 0) && (e->X + i < img1->Width) &&
						(e->Y + j > 0) && (e->Y + j < img1->Height))
					{
						// если нажата левая кнопка
						if (e->Button == System::Windows::Forms::MouseButtons::Left)
						{
							img2->SetPixel(e->X + i, e->Y + j, Color::White);
						}
					}
				}
				pictureBox1->Image = img2;
			}

		}
	}
}
System::Void Coursework6::MyForm::checkBox1_CheckStateChanged(System::Object^ sender, System::EventArgs^ e)
{
	// Проверяем, что картинка загружена
	if (imageUploaded)
	{
		Bitmap^ img2 = gcnew Bitmap(pictureBox1->Image);
		//Переносим картинку img1 на картинку img2 попиксельно
		for (int i = 0; i < img1->Width; i++)
		{
			for (int j = 0; j < img1->Height; j++)
			{
				//в обект типа Color сохраняем значение цвета пикселя из первого изображения
				Color cl1 = img1->GetPixel(i, j);
				img2->SetPixel(i, j, cl1);
			}
		}

		if (checkedFlag)
		{
			halfOfThePicture = img2->Width;
			//halfOfThePicture *= 2;
			checkedFlag = 0;
		}
		else
		{
			halfOfThePicture = (img2->Width) / 2;
			//halfOfThePicture /= 2;
			checkedFlag = 1;
		}

		switch (operationNum)
		{
		case 1:
			//проходим по каждому пикселю изображения
			for (int i = 0; i < halfOfThePicture; i++)
			{
				for (int j = 0; j < img1->Height; j++)
				{
					//в обект типа Color сохраняем значение цвета пикселя из первого изображения
					Color cl1 = img2->GetPixel(i, j);
					//инициализируем второй объект типа Color тремя значениями 
					// (R, G, B)
					float new_red = 255 - cl1.R;
					float new_green = 255 - cl1.G;
					float new_blue = 255 - cl1.B;
					Color cl2 = Color::FromArgb(new_red, new_green, new_blue);
					//записываем в соответствующий пиксель второго изображения      
					//новый цвет
					img2->SetPixel(i, j, cl2);
				}
			}
			break;
		case 2:
			double koef = q1 / q2;
			//проходим по каждому пикселю изображения
			for (int i = 0; i < halfOfThePicture; i++)
			{
				for (int j = 0; j < img1->Height; j++)
				{
					//инициализируем второй объект типа Color тремя значениями 
					// (R, G, B)
					float newRed;
					float newGreen;
					float newBlue;
					//в обект типа Color сохраняем значение цвета пикселя из первого изображения
					Color cl1 = img1->GetPixel(i, j);
					if (cl1.R < q1) newRed = 0;
					else if (cl1.R > q2) newRed = 255;
					else {
						newRed = cl1.G * koef;
					}
					if (cl1.G < q1) newGreen = 0;
					else if (cl1.G > q2) newGreen = 255;
					else {
						newGreen = cl1.G * koef;
					}
					if (cl1.B < q1) newBlue = 0;
					else if (cl1.B > q2) newBlue = 255;
					else {
						newBlue = cl1.G * koef;
					}

					Color cl2 = Color::FromArgb(newRed, newGreen, newBlue);
					//записываем в соответствующий пиксель второго изображения      
					//новый цвет
					img2->SetPixel(i, j, cl2);
				}
			}
			break;
		}
		pictureBox1->Image = img2;
	}
}

