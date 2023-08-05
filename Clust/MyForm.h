namespace Clust {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();


            this->numRow->TextChanged += gcnew System::EventHandler(this, &MyForm::EnableCreateButton);
            this->numCol->TextChanged += gcnew System::EventHandler(this, &MyForm::EnableCreateButton);
            toolTip1 = gcnew System::Windows::Forms::ToolTip();
            toolTip1->SetToolTip(button1, "Creator");
            numRowT = gcnew System::Windows::Forms::ToolTip();
            numRowT->SetToolTip(numRow, "Number of Rows");
            numColT = gcnew System::Windows::Forms::ToolTip();
            numColT->SetToolTip(numCol, "Number of Columns");
            ArrRowT = gcnew System::Windows::Forms::ToolTip();
            ArrRowT->SetToolTip(ArrangeRowAfterSum, "arrange the rows");
            ArrColT = gcnew System::Windows::Forms::ToolTip();
            ArrColT->SetToolTip(ArrangeColumnAfterSum, "arrange the columns");
            createT = gcnew System::Windows::Forms::ToolTip();
            createT->SetToolTip(createButton, "create the table");
            Aor1T = gcnew System::Windows::Forms::ToolTip();
            Aor1T->SetToolTip(comboBox1, "rows labels format");
            Aorr1T = gcnew System::Windows::Forms::ToolTip();
            Aorr1T->SetToolTip(comboBox2, "columns labels format");

            // Create a panel to hold the buttons
            Panel^ buttonPanel = gcnew Panel();
            buttonPanel->Width = 20  * 35;
            buttonPanel->Height = 20 * 35;
            buttonPanel->Location = Point(120, 60);
            // Add labels for each column sum
            for (int col = 1; col <= 20; col++) {
                Label^ label2 = gcnew Label();
                label2->Name = String::Format("ColSumLabel{0}", col);
                label2->Text = "0";
                label2->Width = 35;
                label2->Height = 20;
                label2->Visible = false;
                label2->TextAlign = System::Drawing::ContentAlignment::TopLeft;

                label2->Location = Point(121 + ((col - 1) * 35), 70 + 35 * 20);
                this->Controls->Add(label2);
            }

            // Add labels for each row sum
            for (int row = 1; row <= 20; row++) {
                Label^ label3 = gcnew Label();
                label3->Name = String::Format("RowSumLabel{0}", row);
                label3->Text = "0";
                label3->Width = 50;
                label3->Height = 20;
                label3->Visible = false;
                label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
                label3->Location = Point(127 + (35 * 20), 60 + ((row - 1) * 35));
                this->Controls->Add(label3);
            }
            // Add labels for each column
            for (int col = 1; col <= 20; col++) {
                Label^ label = gcnew Label();
                label->Name = String::Format("ColLabel{0}", col);
                label->Width = 35;
                label->Height = 20;
                label->Visible = false;
                label->Location = Point(130 + ((col - 1) * 35), 40);
                this->Controls->Add(label);
            }


            // Add labels for each row
            for (int row = 1; row <= 20; row++) {
                Label^ label1 = gcnew Label();
                label1->Name = String::Format("RowLabel{0}", row);
                label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
                label1->Width = 20;
                label1->Height = 20;
                label1->Visible = false;
                label1->Location = Point(95, 66.5 + ((row - 1) * 35));
                this->Controls->Add(label1);
            }

            // Add buttons to the panel, with default value of 0 and size 40;40
            for (int row = 1; row <= 20; row++) {
                for (int col = 1; col <= 20; col++) {
                    Button^ button = gcnew Button();
                    button->Name = String::Format("R{0}C{1}", row, col);
                    button->Width = 35;
                    button->Height = 35;
                    button->Visible = false;
                    button->Enabled = true;
                    button->Location = Point(((col - 1) * 35), ((row - 1) * 35));
                    button->Click += gcnew System::EventHandler(this, &MyForm::OnButtonClick);
                    buttonPanel->Controls->Add(button);
                }
            }

            // Add the panel to the form
            this->Controls->Add(buttonPanel);
        }

        void OnButtonClick(System::Object^ sender, System::EventArgs^ e)
        {
            Button^ button = dynamic_cast<Button^>(sender);
            if (button->BackColor == Color::Green) {
                button->BackColor = button->Parent->BackColor;
            }
            else {
                button->BackColor = Color::Green;
            }
        }

        void EnableCreateButton(System::Object^ sender, System::EventArgs^ e)
        {
            // Enable the Create button if both textboxes have a length greater than 0
            if (numRow->Text->Length > 0 && numCol->Text->Length > 0 && comboBox1->SelectedIndex != -1 && comboBox2->SelectedIndex != -1)
            {
               
                createButton->Enabled = true;
            }
            else
            {
                createButton->Enabled = false;
            }
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
        System::Windows::Forms::Button^ createButton;
        System::Windows::Forms::TextBox^ numRow;
        System::Windows::Forms::TextBox^ numCol;
        System::Windows::Forms::Button^ ArrangeRowAfterSum;
        System::Windows::Forms::Button^ ArrangeColumnAfterSum;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::ComboBox^ comboBox2;
    private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;

private: System::Windows::Forms::Label^ label4;

private: System::Windows::Forms::ToolTip^ toolTip1;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::ToolTip^ numRowT;
private: System::Windows::Forms::ToolTip^ Aor1T;
private: System::Windows::Forms::ToolTip^ numColT;
private: System::Windows::Forms::ToolTip^ Aorr1T;
private: System::Windows::Forms::ToolTip^ createT;
private: System::Windows::Forms::ToolTip^ ArrRowT;
private: System::Windows::Forms::ToolTip^ ArrColT;
private: System::ComponentModel::IContainer^ components;


















           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
               this->createButton = (gcnew System::Windows::Forms::Button());
               this->numRow = (gcnew System::Windows::Forms::TextBox());
               this->numCol = (gcnew System::Windows::Forms::TextBox());
               this->ArrangeRowAfterSum = (gcnew System::Windows::Forms::Button());
               this->ArrangeColumnAfterSum = (gcnew System::Windows::Forms::Button());
               this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
               this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->numRowT = (gcnew System::Windows::Forms::ToolTip(this->components));
               this->Aor1T = (gcnew System::Windows::Forms::ToolTip(this->components));
               this->numColT = (gcnew System::Windows::Forms::ToolTip(this->components));
               this->Aorr1T = (gcnew System::Windows::Forms::ToolTip(this->components));
               this->createT = (gcnew System::Windows::Forms::ToolTip(this->components));
               this->ArrRowT = (gcnew System::Windows::Forms::ToolTip(this->components));
               this->ArrColT = (gcnew System::Windows::Forms::ToolTip(this->components));
               this->SuspendLayout();
               // 
               // createButton
               // 
               this->createButton->Enabled = false;
               this->createButton->Location = System::Drawing::Point(12, 128);
               this->createButton->Name = L"createButton";
               this->createButton->Size = System::Drawing::Size(100, 23);
               this->createButton->TabIndex = 4;
               this->createButton->Text = L"Create";
               this->createButton->UseVisualStyleBackColor = true;
               this->createButton->Click += gcnew System::EventHandler(this, &MyForm::createButton_Click);
               // 
               // numRow
               // 
               this->numRow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->numRow->Location = System::Drawing::Point(12, 12);
               this->numRow->MaxLength = 2;
               this->numRow->Name = L"numRow";
               this->numRow->Size = System::Drawing::Size(100, 22);
               this->numRow->TabIndex = 0;
               this->numRow->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::numRow_KeyPress);
               // 
               // numCol
               // 
               this->numCol->Location = System::Drawing::Point(12, 70);
               this->numCol->MaxLength = 2;
               this->numCol->Name = L"numCol";
               this->numCol->Size = System::Drawing::Size(100, 22);
               this->numCol->TabIndex = 2;
               this->numCol->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::numCol_KeyPress);
               // 
               // ArrangeRowAfterSum
               // 
               this->ArrangeRowAfterSum->Enabled = false;
               this->ArrangeRowAfterSum->Location = System::Drawing::Point(12, 157);
               this->ArrangeRowAfterSum->Name = L"ArrangeRowAfterSum";
               this->ArrangeRowAfterSum->Size = System::Drawing::Size(100, 23);
               this->ArrangeRowAfterSum->TabIndex = 5;
               this->ArrangeRowAfterSum->Text = L"Step 1";
               this->ArrangeRowAfterSum->UseVisualStyleBackColor = true;
               this->ArrangeRowAfterSum->Click += gcnew System::EventHandler(this, &MyForm::ArrangeRowAfterSum_Click);
               // 
               // ArrangeColumnAfterSum
               // 
               this->ArrangeColumnAfterSum->Enabled = false;
               this->ArrangeColumnAfterSum->Location = System::Drawing::Point(12, 186);
               this->ArrangeColumnAfterSum->Name = L"ArrangeColumnAfterSum";
               this->ArrangeColumnAfterSum->Size = System::Drawing::Size(100, 23);
               this->ArrangeColumnAfterSum->TabIndex = 6;
               this->ArrangeColumnAfterSum->Text = L"Step 2";
               this->ArrangeColumnAfterSum->UseVisualStyleBackColor = true;
               this->ArrangeColumnAfterSum->Click += gcnew System::EventHandler(this, &MyForm::ArrangeColumnAfterSum_Click);
               // 
               // comboBox1
               // 
               this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
               this->comboBox1->FormattingEnabled = true;
               this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"123", L"ABC" });
               this->comboBox1->Location = System::Drawing::Point(12, 40);
               this->comboBox1->MaxDropDownItems = 2;
               this->comboBox1->Name = L"comboBox1";
               this->comboBox1->Size = System::Drawing::Size(100, 24);
               this->comboBox1->TabIndex = 1;
               this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::EnableCreateButton);
               // 
               // comboBox2
               // 
               this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
               this->comboBox2->FormattingEnabled = true;
               this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"123", L"ABC" });
               this->comboBox2->Location = System::Drawing::Point(12, 98);
               this->comboBox2->MaxDropDownItems = 2;
               this->comboBox2->Name = L"comboBox2";
               this->comboBox2->Size = System::Drawing::Size(100, 24);
               this->comboBox2->TabIndex = 3;
               this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::EnableCreateButton);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label1->Location = System::Drawing::Point(666, 3);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(536, 22);
               this->label1->TabIndex = 7;
               this->label1->Text = L"Rank Order Clustering Alghorithm Program as CAM Project";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Location = System::Drawing::Point(9, 234);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(110, 32);
               this->label2->TabIndex = 8;
               this->label2->Text = L"Sumbitted to\r\nDr. Ragab Kamal\r\n";
               this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label4->Location = System::Drawing::Point(1071, 27);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(234, 15);
               this->label4->TabIndex = 10;
               this->label4->Text = L"By RoboSapiens O6U Mechatronics team";
               this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
               // 
               // toolTip1
               // 
               this->toolTip1->ShowAlways = true;
               this->toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
               this->toolTip1->ToolTipTitle = L"Test";
               // 
               // button1
               // 
               this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
               this->button1->Location = System::Drawing::Point(12, 925);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(50, 50);
               this->button1->TabIndex = 11;
               this->button1->UseVisualStyleBackColor = true;
               this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
               // 
               // MyForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(1340, 988);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->label4);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->comboBox2);
               this->Controls->Add(this->comboBox1);
               this->Controls->Add(this->ArrangeColumnAfterSum);
               this->Controls->Add(this->ArrangeRowAfterSum);
               this->Controls->Add(this->numCol);
               this->Controls->Add(this->numRow);
               this->Controls->Add(this->createButton);
               this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
               this->Name = L"MyForm";
               this->Text = L"Rank Order Clustering - RoboSapiens";
               this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
               this->ResumeLayout(false);
               this->PerformLayout();

           }


    private: System::Void createButton_Click(System::Object^ sender, System::EventArgs^ e) {
        int numRows = Int32::Parse(numRow->Text);
        int numCols = Int32::Parse(numCol->Text);

        // Add labels for each column sum
        for (int col = 1; col <= numCols; col++) {
            String^ labelName = String::Format("ColSumLabel{0}", col);
            Label^ label = dynamic_cast<Label^>(this->Controls->Find(labelName, true)[0]);
            label->Visible = true;
            label->TextAlign = System::Drawing::ContentAlignment::TopLeft;

            label->Location = Point(130 + ((col - 1) * 35), 70 + 35 * numRows);
        }


        // Add labels for each row sum
        for (int row = 1; row <= numRows; row++) {
            String^ labelName = String::Format("RowSumLabel{0}", row);
            Label^ label = dynamic_cast<Label^>(this->Controls->Find(labelName, true)[0]);
            label->Visible = true;
            label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;

            label->Location = Point(125 + (35 * numCols), 66.5 + ((row - 1) * 35));

        }


        // Make buttons visible based on user input
        for (int row = 1; row <= numRows; row++) {
            for (int col = 1; col <= numCols; col++) {
                String^ buttonName = String::Format("R{0}C{1}", row, col);
                Button^ button = dynamic_cast<Button^>(this->Controls->Find(buttonName, true)[0]);
                button->Visible = true;
            }
        }

        for (int col = 1; col <= numCols; col++) {
            String^ labelName = String::Format("ColLabel{0}", col);
            Label^ label = dynamic_cast<Label^>(this->Controls->Find(labelName, true)[0]);
            label->Visible = true;
            if (comboBox2->Text == "ABC") {
                label->Text = Char::ConvertFromUtf32('A' + col - 1);
            }
            else if (comboBox2->Text == "123") {
                label->Text = col.ToString();
            }

        }


        for (int row = 1; row <= numRows; row++) {
            String^ labelName = String::Format("RowLabel{0}", row);
            Label^ label = dynamic_cast<Label^>(this->Controls->Find(labelName, true)[0]);
            label->Visible = true;
            if (comboBox1->Text == "ABC") {

                label->Text = Char::ConvertFromUtf32('A' + row - 1);
            }
            else if (comboBox1->Text == "123") {
                label->Text =row.ToString() ;
            }
        }


        //Disable Textboxes and Create Button
        numRow->Enabled = false;
        numCol->Enabled = false;
        createButton->Enabled = false;
        comboBox1->Enabled = false;
        comboBox2->Enabled = false;
        //Enable step 1 button
        ArrangeRowAfterSum->Enabled = true;




    }



    private: System::Void ArrangeRowAfterSum_Click(System::Object^ sender, System::EventArgs^ e) {
        int numRows = Int32::Parse(numRow->Text);
        int numCols = Int32::Parse(numCol->Text);

        // Create arrays to store the sums and their corresponding row indices
        array<int>^ sums = gcnew array<int>(numRows);
        array<int>^ rowIndices = gcnew array<int>(numRows);

        // Calculate the sum of each row and store in arrays
        for (int row = 1; row <= numRows; row++) {
            int sum = 0;
            for (int col = 1; col <= numCols; col++) {
                String^ buttonName = String::Format("R{0}C{1}", row, col);
                Button^ button = dynamic_cast<Button^>(this->Controls->Find(buttonName, true)[0]);
                if (button->BackColor == Color::Green) {
                    sum += (int)Math::Pow(2, numCols - col);
                }

            }
            sums[row - 1] = sum;
            rowIndices[row - 1] = row;

        }

        // Sort the sums and row indices in descending order using bubble sort
        for (int i = 0; i < numRows; i++) {
            for (int j = i + 1; j < numRows; j++) {
                if (sums[i] < sums[j]) {
                    int tempSum = sums[i];
                    sums[i] = sums[j];
                    sums[j] = tempSum;
                    int tempRow = rowIndices[i];
                    rowIndices[i] = rowIndices[j];
                    rowIndices[j] = tempRow;
                }
            }

        }


        // Rearrange the buttons in the grid according to the sorted order
        int rowIndex = 1;
        for (int i = 0; i < numRows; i++) {
            int row = rowIndices[i];
            for (int col = numCols; col >= 1; col--) {
                String^ buttonName = String::Format("R{0}C{1}", row, col);
                Button^ button = dynamic_cast<Button^>(this->Controls->Find(buttonName, true)[0]);
                button->Location = Point(((col - 1) * 35), ((rowIndex - 1) * 35));

            }
            rowIndex++;
        }



        for (int row = 1; row <= numRows; row++) {
            for (int col = numCols; col >= 1; col--) {
                String^ buttonName = String::Format("R{0}C{1}", row, col);
                Button^ button = dynamic_cast<Button^>(this->Controls->Find(buttonName, true)[0]);
                button->Enabled = false;

            }

        }


        int rowLabel = 1;
        for (int i = 0; i < numRows; i++) {
            int row = rowIndices[i];
            for (int col = numCols; col >= 1; col--) {

                String^ labelName = String::Format("RowLabel{0}", row);
                Label^ label = dynamic_cast<Label^>(this->Controls->Find(labelName, true)[0]);
                label->Location = Point(95, 66.5 + ((rowLabel - 1) * 35));

            }
            rowLabel++;
        }

        int rowSumLabel = 1;
        for (int i = 0; i < numRows; i++) {
            int row = rowIndices[i];
            int sum = sums[i];
            for (int col = numCols; col >= 1; col--) {

                String^ labelName = String::Format("RowSumLabel{0}", row);
                Label^ label = dynamic_cast<Label^>(this->Controls->Find(labelName, true)[0]);
                label->Location = Point(125 + (35 * numCols), 66.5 + ((rowSumLabel - 1) * 35));

                label->Text = sum.ToString();


            }
            rowSumLabel++;
        }

        //Disable this button and Enable Step 2
        ArrangeRowAfterSum->Enabled = false;
        ArrangeColumnAfterSum->Enabled = true;


        int y = 1;
        for (int i = 0; i < numRows; i++) {
            int x = rowIndices[i];
            for (int col = 1; col <= numCols; col++) {
                String^ oldButtonName = String::Format("R{0}C{1}", x, col);
                Button^ button = dynamic_cast<Button^>(this->Controls->Find(oldButtonName, true)[0]);
                String^ newButtonName = String::Format("R{0}C{1}", y, col);
                button->Name = newButtonName;


            }
            y++;
        }


    }


    private: System::Void ArrangeColumnAfterSum_Click(System::Object^ sender, System::EventArgs^ e) {
        int numRows = Int32::Parse(numRow->Text);
        int numCols = Int32::Parse(numCol->Text);

        // Create arrays to store the sums and their corresponding column indices
        array<int>^ sums = gcnew array<int>(numCols);
        array<int>^ colIndices = gcnew array<int>(numCols);

        // Calculate the sum of each column and store in arrays
        for (int col = 1; col <= numCols; col++) {
            int sum = 0;
            for (int row = 1; row <= numRows; row++) {
                String^ buttonName = String::Format("R{0}C{1}", row, col);
                Button^ button = dynamic_cast<Button^>(this->Controls->Find(buttonName, true)[0]);
                if (button->BackColor == Color::Green) {
                    sum += (int)Math::Pow(2, numRows - row);
                }
            }
            // String^ message = String::Format("Sum of col {0}: {1}", col, sum);
            // MessageBox::Show(message);
            sums[col - 1] = sum;
            colIndices[col - 1] = col;
        }

        // Sort the sums and column indices in descending order using bubble sort
        for (int i = 0; i < numCols; i++) {
            for (int j = i + 1; j < numCols; j++) {
                if (sums[i] < sums[j]) {
                    int tempSum = sums[i];
                    sums[i] = sums[j];
                    sums[j] = tempSum;
                    int tempCol = colIndices[i];
                    colIndices[i] = colIndices[j];
                    colIndices[j] = tempCol;
                }
            }
        }

        // Rearrange the buttons in the grid according to the sorted order
        int colIndex = 1;
        for (int i = 0; i < numCols; i++) {
            int col = colIndices[i];
            for (int row = 1; row <= numRows; row++) {
                String^ buttonName = String::Format("R{0}C{1}", row, col);
                Button^ button = dynamic_cast<Button^>(this->Controls->Find(buttonName, true)[0]);
                button->Location = Point(((colIndex - 1) * 35), ((row - 1) * 35));
            }
            colIndex++;
        }


        int colLabel = 1;
        for (int i = 0; i < numCols; i++) {
            int col = colIndices[i];
            for (int row = 1; row <= numRows; row++) {
                String^ labelName = String::Format("ColLabel{0}", col);
                Label^ label = dynamic_cast<Label^>(this->Controls->Find(labelName, true)[0]);
                label->Location = Point(130 + ((colLabel - 1) * 35), 40);

            }
            colLabel++;
        }
        int colSumLabel = 1;
        for (int i = 0; i < numCols; i++) {
            int col = colIndices[i];
            int sum = sums[i];
            for (int row = 1; row <= numRows; row++) {
                String^ labelName = String::Format("ColSumLabel{0}", col);
                Label^ label = dynamic_cast<Label^>(this->Controls->Find(labelName, true)[0]);
                label->Location = Point(130 + ((colSumLabel - 1) * 35), 70 + 35 * numRows);

                label->Text = sum.ToString();


            }
            colSumLabel++;
        }

        //Disable the button
        ArrangeColumnAfterSum->Enabled = false;




    }
    
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("  Amr Mohamed Abdulzaher \n ","Creator", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
}


};
}

