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

System::Void Coursework6::MyForm::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//������� CLI ������ � ������� ������������, ������������ �� ���� ��� �����
		//� ���������� � ������� gcnew ��������� (^) �� CLI ������
		// baseImage - ����������, � ������� �������� �������� �����������
		baseImage = gcnew Bitmap(openFileDialog1->FileName);
		imageUploaded = true;

		//������� CLI ������ � ������� ������������, ������������ �� ���� ������ //��������
		//� ���������� � ������� gcnew ��������� (^) �� CLI ������ 
		//� ������� �� ����������� ������������, ������ ����������� ������� ������ //��������� ������� (������ ��������)
		//������� ����������� ������ �� ���������!
		img1 = gcnew Bitmap(baseImage);

		// �������� ������ �������� baseImage � �������� img1 �����������
		for (int i = 0; i < baseImage->Width; i++)
			for (int j = 0; j < baseImage->Height; j++)
			{
				Color cl = baseImage->GetPixel(i, j);
				img1->SetPixel(i, j, cl);
			}

		//Bitmap^ img2 = gcnew Bitmap(img1->Width, img1->Height);
		pictureBox1->Image = baseImage;
		pictureBox1->Size = baseImage->Size;

		// ������ � ��������(���������� � ����� 1)
		label1->Text = baseImage->Width + "x" + baseImage->Height;
		label12->Text = "";
		label12->Text = (ScaleCounter).ToString() + "%";
	}
}

System::Void Coursework6::MyForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

System::Void Coursework6::MyForm::������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

System::Void Coursework6::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Close();
}

System::Void Coursework6::MyForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

		//���������� � ����� 12 ���������� ��������� �� ���������������
		label12->Text = "";
		label12->Text = (ScaleCounter).ToString() + "%";

		//���������� � ����� 1 ������ ������������ �����������
		label1->Text = img1->Width + "x" + img1->Height;

		scale = 1;
	}
}

System::Void Coursework6::MyForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

		//���������� � ����� 12 ���������� ��������� �� ���������������
		label12->Text = "";
		label12->Text = (ScaleCounter).ToString() + "%";

		//���������� � ����� 1 ������ ������������ �����������
		label1->Text = img1->Width + "x" + img1->Height;
		// ��������� ����� ����������� � img1

		scale = 1;
	}
}

System::Void Coursework6::MyForm::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm1^ f2 = gcnew MyForm1();
	f2->Show();
}

System::Void Coursework6::MyForm::������1ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		// ���������, ���������� �� �������
		if (checkedFlag)
		{
			halfOfThePicture = (img1->Width) / 2;
			//��������� ������ ��������� img1 �� �������� img2
			for (int i = halfOfThePicture; i < img1->Width; i++)
			{
				for (int j = 0; j < img1->Height; j++)
				{
					//� ����� ���� Color ��������� �������� ����� ������� �� ������� �����������
					Color cl1 = img1->GetPixel(i, j);
					img2->SetPixel(i, j, cl1);
				}
			}
		}

		//�������� �� ������� ������� �����������
		for (int i = 0; i < halfOfThePicture; i++)
		{
			for (int j = 0; j < img2->Height; j++)
			{
				//� ����� ���� Color ��������� �������� ����� ������� �� ������� �����������
				Color cl1 = img2->GetPixel(i, j);
				//�������������� ������ ������ ���� Color ����� ���������� 
				// (R, G, B)
				float new_red = 255 - cl1.R;
				float new_green = 255 - cl1.G;
				float new_blue = 255 - cl1.B;
				Color cl2 = Color::FromArgb(new_red, new_green, new_blue);
				//���������� � ��������������� ������� ������� �����������      
				//����� ����
				img2->SetPixel(i, j, cl2);
			}
		}
		pictureBox1->Image = img2;
	}
}

System::Void Coursework6::MyForm::������2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
			// ���������, ���������� �� �������
			if (checkedFlag)
			{
				halfOfThePicture = (img1->Width) / 2;
				//��������� ������ ��������� imageToCompare �� �������� img3
				for (int i = halfOfThePicture; i < img1->Width; i++)
				{
					for (int j = 0; j < img1->Height; j++)
					{
						//� ����� ���� Color ��������� �������� ����� ������� �� ������� �����������
						Color cl1 = img1->GetPixel(i, j);
						img2->SetPixel(i, j, cl1);
					}
				}
			}
			//�������� �� ������� ������� �����������
			for (int i = 0; i < halfOfThePicture; i++)
			{
				for (int j = 0; j < img1->Height; j++)
				{
					//�������������� ������ ������ ���� Color ����� ���������� 
					// (R, G, B)
					float newRed;
					float newGreen;
					float newBlue;
					//� ����� ���� Color ��������� �������� ����� ������� �� ������� �����������
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
					//���������� � ��������������� ������� ������� �����������      
					//����� ����
					img2->SetPixel(i, j, cl2);
				}
				pictureBox1->Image = img2;
			}
		}
	}
	catch (...)
	{
		MessageBox::Show("��� ����� ������ ���� ������ � ��������������", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void Coursework6::MyForm::������3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	groupBox1->Hide();
	groupBox2->Hide();
	groupBox3->Hide();
	filterThreeActivated = true;
	Bitmap^ img2 = gcnew Bitmap(pictureBox1->Image);

	////�������� �� ������� ������� �����������
	//for (int i = 0; i < img2->Width; i++)
	//{
	//	for (int j = 0; j < img2->Height / 2; j++)
	//	{
	//		//� ����� ���� Color ��������� �������� ����� ������� �� �������� �����������
	//		Color pixel = img2->GetPixel(i, j);
	//		//� ����� ���� Color ��������� �������� ����� ���������������� ������� �� ������� �����������
	//		Color oppositePixel = img2->GetPixel(img2->Width - i - 1, img2->Height - j - 1);

	//		//���������� � ��������������� ������� �����������      
	//		img2->SetPixel(img2->Width - i - 1, img2->Height - j - 1, pixel);
	//		img2->SetPixel(i, j, oppositePixel);
	//	}
	//	pictureBox1->Image = img2;
	//}
}

System::Void Coursework6::MyForm::������4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	groupBox1->Hide();
	groupBox2->Hide();
	groupBox3->Show();
	Bitmap^ img = gcnew Bitmap(pictureBox1->Image);
	Bitmap^ newBmp = gcnew Bitmap(img);
	filterFourActivated = true;
	filterThreeActivated = false;
	// ����� ���������� �������� ��������
	int total = img->Width * img->Height;

	// ������� ��� ������� �������� ����� ����������
	chart1->Series["1"]->Points->Clear();
	chart2->Series["2"]->Points->Clear();
	Gist.Clear();
	stretchedGist.Clear();
	pdata.Clear();

	// ��������� Gist ��������
	for (int i = 0; i < 256; i++)
	{
		Gist.Add(0);
	}

	// ���������� � ������ ��� ������� ��������� �����������
	for (int j = 0; j < img->Height; j++)
		for (int i = 0; i < img->Width; i++)
		{
			// �������� (i, j) �������
			Color currentPixel = img->GetPixel(i, j);

			// �������� ���������� ������ �������
			int Red = currentPixel.R;
			int Green = currentPixel.G;
			int Blue = currentPixel.B;

			// ������ ���� �����-����� (������� ������) - ������� ������� ��������������
			Red = Green = Blue = (Red + Green + Blue) / 3;

			// �������� ����� ������� �� ������ (�� �������)
			Color newPixel = Color::FromArgb(Red, Green, Blue);

			//���������� �������� newPixel � ��������������� ������� newBmp
			newBmp->SetPixel(i, j, newPixel);

			// ������� ���������� �������� �� ������� ������ �������
			Gist[Red] ++;

			// ��� ������� ������� ����������� ��������� ������� �������
			pdata.Add(Red);

			stretchedPdata.Add(Red);
		}

	// ������ ������ �����������
	for (int i = 0; i < 256; i++)
	{
		chart1->Series["1"]->Points->AddXY(i, Gist[i]);
	}
	pictureBox1->Image = newBmp;


	//������� ����������� � ������������ �������� ������� �������� ��������
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

	// ���������stretchedGistGist ��������
	for (int i = 0; i < 256; i++)
	{
		stretchedGist.Add(0);
	}

	// ��������� ������� stretchHistogram
	stretchHistogram(stretchedPdata, img->Width, img->Height, 255);
	// ��������� ������ ����������� ���������� � ������� �����
	// ��������, ��������������� ��������������� �����������
	for (int j = 0; j < img->Height; j++)
		for (int i = 0; i < img->Width; i++)
		{

			newBmp->SetPixel(i, j, Color::FromArgb(stretchedPdata[j * img->Width + i], stretchedPdata[j * img->Width + i], stretchedPdata[j * img->Width + i]));
			stretchedGist[stretchedPdata[j * img->Width + i]] ++;
		}

	// ������ ������ �����������
	for (int i = 0; i < 256; i++)
	{
		chart2->Series["2"]->Points->AddXY(i, stretchedGist[i]);
	}

	// ���������� ����� ��������
	pictureBox1->Image = newBmp;
}
System::Void Coursework6::MyForm::������5ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

		//	//���������� � ����� 12 ���������� ��������� �� ���������������
		//	ScaleCounter /= scaleFilter5;
		//	label12->Text = "";
		//	label12->Text = (ScaleCounter).ToString() + "%";

		//	//���������� � ����� 1 ������ ������������ �����������
		//	label1->Text = img3->Width + "x" + img3->Height;
		//}
		//catch (...)
		//{
		//	MessageBox::Show("������� ����� ������������� �����", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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

		//������� �����, ������������ �������
		label12->Text = "";

		//���������� � ����� 1 ������ ������������ �����������
		label1->Text = img3->Width + "x" + img3->Height;
	}
	catch (...)
	{
		MessageBox::Show("������� ����� ������������� �����", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
System::Void Coursework6::MyForm::pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	// ��������, ��� �������� ���������
	if (imageUploaded)
	{
		Bitmap^ img2 = gcnew Bitmap(pictureBox1->Image);
		// ��������, ��� �� �� ������� �� ������� �����������
		if ((e->X > 0) && (e->X < img2->Width) &&
			(e->Y > 0) && (e->Y < img2->Height))
		{
			// ���������� x (���������� � ����� 2)
			label3->Text = Convert::ToString(e->X);
			// ���������� y (���������� � ����� 3)
			label5->Text = Convert::ToString(e->Y);

			Color current_p = img2->GetPixel(e->X, e->Y);
			// ���������� �������� ������ � ��������������� ������
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
					// ��������, ��� �� �� ������� �� ������� �����������
					if ((e->X + i > 0) && (e->X + i < img1->Width) &&
						(e->Y + j > 0) && (e->Y + j < img1->Height))
					{
						// ���� ������ ����� ������
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
	// ���������, ��� �������� ���������
	if (imageUploaded)
	{
		Bitmap^ img2 = gcnew Bitmap(pictureBox1->Image);
		//��������� �������� img1 �� �������� img2 �����������
		for (int i = 0; i < img1->Width; i++)
		{
			for (int j = 0; j < img1->Height; j++)
			{
				//� ����� ���� Color ��������� �������� ����� ������� �� ������� �����������
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
			//�������� �� ������� ������� �����������
			for (int i = 0; i < halfOfThePicture; i++)
			{
				for (int j = 0; j < img1->Height; j++)
				{
					//� ����� ���� Color ��������� �������� ����� ������� �� ������� �����������
					Color cl1 = img2->GetPixel(i, j);
					//�������������� ������ ������ ���� Color ����� ���������� 
					// (R, G, B)
					float new_red = 255 - cl1.R;
					float new_green = 255 - cl1.G;
					float new_blue = 255 - cl1.B;
					Color cl2 = Color::FromArgb(new_red, new_green, new_blue);
					//���������� � ��������������� ������� ������� �����������      
					//����� ����
					img2->SetPixel(i, j, cl2);
				}
			}
			break;
		case 2:
			double koef = q1 / q2;
			//�������� �� ������� ������� �����������
			for (int i = 0; i < halfOfThePicture; i++)
			{
				for (int j = 0; j < img1->Height; j++)
				{
					//�������������� ������ ������ ���� Color ����� ���������� 
					// (R, G, B)
					float newRed;
					float newGreen;
					float newBlue;
					//� ����� ���� Color ��������� �������� ����� ������� �� ������� �����������
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
					//���������� � ��������������� ������� ������� �����������      
					//����� ����
					img2->SetPixel(i, j, cl2);
				}
			}
			break;
		}
		pictureBox1->Image = img2;
	}
}

