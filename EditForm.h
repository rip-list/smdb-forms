#pragma once

namespace crud_engine {
	using namespace System;
	using namespace System::Windows::Forms;

public ref class EditForm : public System::Windows::Forms::Form
{
    
public:
    // ����������� ��������� ������� ����� ��� ��������������
    EditForm(String^ currentText)
    {
		InitializeComponent(); // ������������� �����������
        if (currentText != nullptr && currentText->Length > 0)
        {
            textBox1->Text = currentText; // ������������� ����� � textBox1
        }
    }

    // ����� ��� ��������� ������ �� textBox1
    String^ GetText() {
        return textBox1->Text->Trim(); // ���������� ����� ��� ��������
    }

protected:
    ~EditForm()
    {
        if (components)
        {
            delete components;
        }
    }

private:
    TextBox^ textBox1; // ���������� textBox1
    Button^ button1;   // ���������� button1
    System::ComponentModel::Container^ components;

#pragma region 
    void InitializeComponent(void)
    {
        this->textBox1 = gcnew System::Windows::Forms::TextBox();  
        this->button1 = gcnew System::Windows::Forms::Button();
        this->SuspendLayout();

        // 
        // textBox1
        // 
        this->textBox1->Location = System::Drawing::Point(12, 2);
        this->textBox1->Multiline = true;
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(276, 137);
        this->textBox1->TabIndex = 0;

        // 
        // button1
        // 
        this->button1->Location = System::Drawing::Point(12, 145);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(276, 43);
        this->button1->TabIndex = 1;
        this->button1->Text = L"��";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->Click += gcnew EventHandler(this, &EditForm::button1_Click);

        // 
        // EditForm
        // 
        this->ClientSize = System::Drawing::Size(300, 200);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->textBox1);
        this->Name = L"EditForm";
        this->Text = L"������������� ������";
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion

    // ���������� ������ "��"
    void button1_Click(Object^ sender, EventArgs^ e)
    {
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Close();
    }
};
};