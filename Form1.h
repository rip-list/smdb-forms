#pragma once
#include <sqlite3.h>
#include <string>
#include <msclr/marshal_cppstd.h> 





namespace CppCLRWinFormsProject {

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System;

	sqlite3* db = nullptr;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//sqlite3* db = nullptr;
			if (sqlite3_open("database.db", &db) != SQLITE_OK) {
				MessageBox::Show("Ошибка открытия базы данных", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			
			const char* createTableSQL =
				"CREATE TABLE IF NOT EXISTS Records ("
				"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
				"Text TEXT NOT NULL);";
			char* errMsg;
			if (sqlite3_exec(db, createTableSQL, 0, 0, &errMsg) != SQLITE_OK) {
				MessageBox::Show(gcnew String(errMsg), "Ошибка SQL", MessageBoxButtons::OK, MessageBoxIcon::Error);
				sqlite3_free(errMsg);
			}

			// Привязка событий кнопок идет в разделах самих кнопок

			
			
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;

			}
			if (db) {
				sqlite3_close(db); // Закрываем соединение
			}
		}

	
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ insertTable;

	private: System::Windows::Forms::TextBox^ insertOneTable;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ reinsertTable;
	private: System::Windows::Forms::Button^ deliteTable;


	private: System::Windows::Forms::Button^ writeTable;
	private: System::Windows::Forms::Button^ clearTable;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ textColumn;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->insertTable = (gcnew System::Windows::Forms::Button());
			this->insertOneTable = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->reinsertTable = (gcnew System::Windows::Forms::Button());
			this->deliteTable = (gcnew System::Windows::Forms::Button());
			this->writeTable = (gcnew System::Windows::Forms::Button());
			this->clearTable = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->textColumn });
			this->dataGridView1->Location = System::Drawing::Point(13, 13);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(560, 189);
			this->dataGridView1->TabIndex = 0;
			// 
			// textColumn
			// 
			this->textColumn->HeaderText = L"Text";
			this->textColumn->Name = L"textColumn";
			this->textColumn->ToolTipText = L"сюда текст";
			// 
			// insertTable
			// 
			this->insertTable->Location = System::Drawing::Point(31, 314);
			this->insertTable->Name = L"insertTable";
			this->insertTable->Size = System::Drawing::Size(75, 23);
			this->insertTable->TabIndex = 1;
			this->insertTable->Text = L"Внести данные ";
			this->insertTable->UseVisualStyleBackColor = true;
			this->insertTable->Click += gcnew System::EventHandler(this, &Form1::InsertData);
			// 
			// insertOneTable
			// 
			this->insertOneTable->AllowDrop = true;
			this->insertOneTable->Location = System::Drawing::Point(31, 250);
			this->insertOneTable->Multiline = true;
			this->insertOneTable->Name = L"insertOneTable";
			this->insertOneTable->Size = System::Drawing::Size(128, 42);
			this->insertOneTable->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 234);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Внести данные ";
			// 
			// reinsertTable
			// 
			this->reinsertTable->Location = System::Drawing::Point(173, 314);
			this->reinsertTable->Name = L"reinsertTable";
			this->reinsertTable->Size = System::Drawing::Size(96, 23);
			this->reinsertTable->TabIndex = 4;
			this->reinsertTable->Text = L"Редактировать";
			this->reinsertTable->UseVisualStyleBackColor = true;
			this->reinsertTable->Click += gcnew System::EventHandler(this, &Form1::UpdateData);
			// 
			// deliteTable
			// 
			this->deliteTable->Location = System::Drawing::Point(460, 314);
			this->deliteTable->Name = L"deliteTable";
			this->deliteTable->Size = System::Drawing::Size(75, 23);
			this->deliteTable->TabIndex = 5;
			this->deliteTable->Text = L"Удалить";
			this->deliteTable->UseVisualStyleBackColor = true;
			this->deliteTable->Click += gcnew System::EventHandler(this, &Form1::DeleteData);
			// 
			// writeTable
			// 
			this->writeTable->Location = System::Drawing::Point(332, 314);
			this->writeTable->Name = L"writeTable";
			this->writeTable->Size = System::Drawing::Size(75, 23);
			this->writeTable->TabIndex = 6;
			this->writeTable->Text = L"Читать ";
			this->writeTable->UseVisualStyleBackColor = true;
			this->writeTable->Click += gcnew System::EventHandler(this, &Form1::ReadData);
			// 
			// clearTable
			// 
			this->clearTable->Location = System::Drawing::Point(435, 399);
			this->clearTable->Name = L"clearTable";
			this->clearTable->Size = System::Drawing::Size(124, 25);
			this->clearTable->TabIndex = 7;
			this->clearTable->Text = L"Очистить таблицу";
			this->clearTable->UseVisualStyleBackColor = true;
			this->clearTable->Click += gcnew System::EventHandler(this, &Form1::ClearTable);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(585, 442);
			this->Controls->Add(this->clearTable);
			this->Controls->Add(this->writeTable);
			this->Controls->Add(this->deliteTable);
			this->Controls->Add(this->reinsertTable);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->insertOneTable);
			this->Controls->Add(this->insertTable);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form1";
			this->Text = L"crud-engine";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		// Вставка данных
		void InsertData(Object^ sender, EventArgs^ e) {
			// Получаем текст из TextBox и удаляем лишние пробелы
			String^ text = insertOneTable->Text->Trim();

			// Проверяем, что текст не пустой
			if (String::IsNullOrEmpty(text)) {
				MessageBox::Show("Введите текст", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// Преобразуем managed String в std::string
			std::string sql = "INSERT INTO Records (Text) VALUES ('" + msclr::interop::marshal_as<std::string>(text) + "');";

			// Переменная для сообщения об ошибке от SQLite
			char* errMsg;

			// Выполняем SQL запрос
			if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
				// Если произошла ошибка, выводим сообщение
				MessageBox::Show(gcnew String(errMsg), "Ошибка SQL", MessageBoxButtons::OK, MessageBoxIcon::Error);
				sqlite3_free(errMsg);  // Освобождаем память для errMsg
			}
			else {
				// Если запрос выполнен успешно
				MessageBox::Show("Данные добавлены!", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

				// Очищаем TextBox
				insertOneTable->Clear();

				// Обновляем таблицу (вызываем функцию для чтения данных)
				ReadData(nullptr, nullptr); // Обновить таблицу
			}
		}


		// Чтение данных
		void ReadData(Object^ sender, EventArgs^ e) {
			dataGridView1->Rows->Clear();

			const char* sql = "SELECT * FROM Records;";
			sqlite3_stmt* stmt;
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
				MessageBox::Show("Ошибка чтения данных", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int id = sqlite3_column_int(stmt, 0);
				const char* text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
				dataGridView1->Rows->Add(gcnew String(text));
			}
			sqlite3_finalize(stmt);
		}

		// Обновление данных
		void UpdateData(Object^ sender, EventArgs^ e) {
			if (dataGridView1->SelectedRows->Count == 0) {
				MessageBox::Show("Выберите строку для редактирования", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int rowIndex = dataGridView1->SelectedRows[0]->Index;
			String^ newText = insertOneTable->Text->Trim();
			if (String::IsNullOrEmpty(newText)) {
				MessageBox::Show("Введите новый текст", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			std::string sql = "UPDATE Records SET Text = '" + msclr::interop::marshal_as<std::string>(newText) +
				"' WHERE ID = " + std::to_string(rowIndex + 1) + ";";
			char* errMsg;
			if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
				MessageBox::Show(gcnew String(errMsg), "Ошибка SQL", MessageBoxButtons::OK, MessageBoxIcon::Error);
				sqlite3_free(errMsg);
			}
			else {
				MessageBox::Show("Данные обновлены!", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
				ReadData(nullptr, nullptr); // Обновить таблицу
			}
		}

		// Удаление данных
		void DeleteData(Object^ sender, EventArgs^ e) {
			if (dataGridView1->SelectedRows->Count == 0) {
				MessageBox::Show("Выберите строку для удаления", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int rowIndex = dataGridView1->SelectedRows[0]->Index;
			std::string sql = "DELETE FROM Records WHERE ID = " + std::to_string(rowIndex + 1) + ";";
			char* errMsg;
			if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
				MessageBox::Show(gcnew String(errMsg), "Ошибка SQL", MessageBoxButtons::OK, MessageBoxIcon::Error);
				sqlite3_free(errMsg);
			}
			else {
				MessageBox::Show("Данные удалены!", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
				ReadData(nullptr, nullptr); // Обновить таблицу
			}
		}

		// Очистка таблицы
		void ClearTable(Object^ sender, EventArgs^ e) {
			dataGridView1->Rows->Clear();
		}


};
}

