#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <iostream>

namespace tabloidnoye_chudo2 {

    struct Product {
        std::string article;
        std::string name;
        int price;
        int sales;
        int reviews;
        double rating;
        std::string seasonality;
        std::string gender;
    };

    void readData(const std::string& filename, std::vector<Product>& products);
    void displayData(System::Windows::Forms::DataGridView^ dataGridView, const std::vector<Product>& products);

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm()
        {
            InitializeComponent();
            InitializeDataGridView();
            LoadDataFromFile();
            DisplayDataInDataGridView();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::DataGridView^ dataGridView;


        void InitializeComponent()
        {
            this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView
            // 
            this->dataGridView->ColumnHeadersHeight = 46;
            this->dataGridView->Location = System::Drawing::Point(0, 0);
            this->dataGridView->Name = L"dataGridView";
            this->dataGridView->RowHeadersWidth = 82;
            this->dataGridView->Size = System::Drawing::Size(240, 150);
            this->dataGridView->TabIndex = 0;
            // 
            // MyForm
            // 
            this->ClientSize = System::Drawing::Size(1214, 847);
            this->Name = L"MyForm";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
            this->ResumeLayout(false);

        }

        void InitializeDataGridView()
        {
            dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Controls->Add(dataGridView);

            dataGridView->Columns->Add("Article", "Article");
            dataGridView->Columns->Add("Name", "Name");
            dataGridView->Columns->Add("Price", "Price");
            dataGridView->Columns->Add("Sales", "Sales");
            dataGridView->Columns->Add("Reviews", "Reviews");
            dataGridView->Columns->Add("Rating", "Rating");
            dataGridView->Columns->Add("Seasonality", "Seasonality");
            dataGridView->Columns->Add("Gender", "Gender");
        }

        void LoadDataFromFile()
        {
            std::vector<Product> products;
            readData("data.txt", products);
            displayData(dataGridView, products);
        }

        void DisplayDataInDataGridView()
        {
            dataGridView->RowsDefaultCellStyle = gcnew System::Windows::Forms::DataGridViewCellStyle();
            dataGridView->DefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 10);
            dataGridView->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridView->RowHeadersVisible = false;
            dataGridView->AllowUserToAddRows = false;
            dataGridView->AllowUserToDeleteRows = false;
            dataGridView->ReadOnly = true;

            // Устанавливаем правильный формат для отображения русских символов
            dataGridView->DefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204));
        }
    };
}
