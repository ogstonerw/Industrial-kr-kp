#include "MyForm.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;

namespace tabloidnoye_chudo2 {

    void readData(const std::string& filename, std::vector<Product>& products) {
        std::ifstream ifs(filename);
        std::string line;
        while (std::getline(ifs, line)) {
            std::stringstream ss(line);
            std::string field;
            Product product;
            std::getline(ss, field, '/');
            product.article = field;
            std::getline(ss, field, '/');
            product.name = field;
            std::getline(ss, field, '/');
            product.price = std::stoi(field);
            std::getline(ss, field, '/');
            product.sales = std::stoi(field);
            std::getline(ss, field, '/');
            product.reviews = std::stoi(field);
            std::getline(ss, field, '/');
            product.rating = std::stod(field);
            std::getline(ss, field, '/');
            product.seasonality = field;
            std::getline(ss, field, '/');
            product.gender = field;
            products.push_back(product);
        }
        ifs.close();
    }

    void displayData(System::Windows::Forms::DataGridView^ dataGridView, const std::vector<Product>& products) {
        dataGridView->Rows->Clear();
        for (const Product& product : products) {
            array<String^>^ row = { gcnew String(product.article.c_str()), gcnew String(product.name.c_str()),
                                    product.price.ToString(), product.sales.ToString(), product.reviews.ToString(),
                                    product.rating.ToString(), gcnew String(product.seasonality.c_str()), gcnew String(product.gender.c_str()) };
            dataGridView->Rows->Add(row);
        }
    }

} // namespace tabloidnoye_chudo2

[STAThread]
void runForm() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew tabloidnoye_chudo2::MyForm());
}

int main() {
    runForm();
    return 0;
}
