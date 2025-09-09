#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QList>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
      ui->lbl_Image_Display->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"file:///C:/Users/abdul/OneDrive/Desktop/Abdul Moqeet Butt/hms/build/Desktop_Qt_6_9_0_llvm_mingw_64_bit-Debug/debug/1.jpg.jpg"));
    // table view appointments
    ui->tableWidget_appointments->setColumnCount(4);
    QStringList headers = {"Doctor ID", "Doctor Name", "Patient Name", "Date/Time"};
    ui->tableWidget_appointments->setHorizontalHeaderLabels(headers);
    ui->tableWidget_appointments->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // table view patients
    ui->tableWidget_patients->setColumnCount(6);
    ui->tableWidget_patients->setHorizontalHeaderLabels(QStringList() << "Patient ID" << "Name" <<"CNIC" << "Age" <<"Blood Group"<< "Diagnosis");

    // Setup doctor table
    ui->tableWidget_doctor->setColumnCount(6);
    ui->tableWidget_doctor->setHorizontalHeaderLabels(QStringList() << "Doctor ID" << "Name" << "CNIC" <<"Age" <<"Gender"<<"Specialization");


}

MainWindow::~MainWindow()
{
    delete ui;
}

//login page
void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->usernameline->text();
    QString password = ui->passwordline->text();

    if (username == "admin" && password == "1234") {
        ui->stackedWidget->setCurrentIndex(1); // Show medical dashboard
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }

}


void MainWindow::on_pushButton_cancel_clicked()
{
    close();  // Close the app
}


// Medical Panel Page

void MainWindow::on_pushButton_registerpatient_clicked()
{
     ui->stackedWidget->setCurrentIndex(2); // Switch to Register Patient page
}


void MainWindow::on_pushButton_registerdoctor_clicked()
{
   ui->stackedWidget->setCurrentIndex(3); // Switch to Register Doctor page
}


void MainWindow::on_pushButton_removepatient_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); // Switch to View Patient page
}


void MainWindow::on_pushButton_removedoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(5); // Switch to View Doctor page
}


void MainWindow::on_pushButton_bookappointment_clicked()
{
    ui->stackedWidget->setCurrentIndex(6); // Switch to Register Appointment page
}


void MainWindow::on_pushButton_viewappointment_clicked()
{
    ui->stackedWidget->setCurrentIndex(7); // Switch to View Appointment page
}


void MainWindow::on_pushButton_bookaroom_clicked()
{
    ui->stackedWidget->setCurrentIndex(8); // Switch to Book a room page
}



void MainWindow::on_pushbutton_logout_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // Switch to login page as it is logout
}

// register patient page

void MainWindow::on_pushButton_clicked()  // register button
{
    QString name = ui->lineEdit_name->text();
    QString age = ui->lineEdit_age->text();
    QString patientId = ui->lineEdit_patientid->text();
    QString cnic = ui->lineEdit_cnic->text();
    QString bloodGroup = ui->lineEdit_bloodgroup->text();
    QString diagnosis = ui->lineEdit_dignosis->text();


    if (patientId.isEmpty() || name.isEmpty() || age.isEmpty() || cnic.isEmpty() || bloodGroup.isEmpty() || diagnosis.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields.");
        return;
    }


    addPatientRecord(patientId, name, cnic, age, bloodGroup, diagnosis);

    // Show success message
    QMessageBox::information(this, "Success", "Patient record added.");

    // Clear all input fields
    ui->lineEdit_name->clear();
    ui->lineEdit_age->clear();
    ui->lineEdit_patientid->clear();
    ui->lineEdit_cnic->clear();
    ui->lineEdit_bloodgroup->clear();
    ui->lineEdit_dignosis->clear();

    // Switch to the view Patient page (index 4)
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_2_clicked() // cancel button
{
    ui->stackedWidget->setCurrentIndex(1); // Switch to dashboard
}


// panel

void MainWindow::on_pushButton_registerpatient_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Go to Register Patient page
}


void MainWindow::on_pushButton_registerdoctor_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(3); // Go to Register Doctor page
}


void MainWindow::on_pushButton_removepatient_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(4); // Go to View Patient page
}


void MainWindow::on_pushButton_removedoctor_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(5); // Go to View Doctor page
}


void MainWindow::on_pushButton_bookappointment_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6); // Go to Register Appointment page
}


void MainWindow::on_pushButton_viewappointment_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(7); // Go to View Appointment page
}


void MainWindow::on_pushButton_bookaroom_4_clicked() //book a room
{
    ui->stackedWidget->setCurrentIndex(8); // Go to Book a Room page
}


void MainWindow::on_pushbutton_logout_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // Go to login page
}


// Register Doctor
void MainWindow::on_pushButton_3_clicked() // register button
{
    QString name = ui->lineEdit_doctorname->text();
    QString age = ui->lineEdit_doctorage->text();
    QString gender = ui->lineEdit_doctorgender->text();
    QString cnic = ui->lineEdit_doctorcnic->text();
    QString doctorId = ui->lineEdit_doctorid->text();
    QString specialization = ui->lineEdit_specialization->text();

    if (doctorId.isEmpty() || name.isEmpty() || cnic.isEmpty() || specialization.isEmpty() || gender.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all doctor fields.");
        return;
    }

    addDoctorRecord(doctorId, name, age, cnic, gender, specialization);


    QMessageBox::information(this, "Success", "Doctor record added.");

    ui->lineEdit_doctorname->clear();
    ui->lineEdit_doctorage->clear();
    ui->lineEdit_doctorgender->clear();
    ui->lineEdit_doctorcnic->clear();
    ui->lineEdit_doctorid->clear();
    ui->lineEdit_specialization->clear();

    // Switch to the dashboard page (index 5)
    ui->stackedWidget->setCurrentIndex(5);
}






void MainWindow::on_pushButton_4_clicked() // cancel button
{
    ui->stackedWidget->setCurrentIndex(1); // Switch to dashboard
}



// panel

void MainWindow::on_pushButton_registerpatient_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Go to Register Patient page
}


void MainWindow::on_pushButton_registerdoctor_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(3); // Go to Register Doctor page
}


void MainWindow::on_pushButton_removepatient_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(4); // Go to View Patient page
}


void MainWindow::on_pushButton_removedoctor_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(5); // Go to View Doctor page
}


void MainWindow::on_pushButton_bookappointment_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(6); // Go to Register Appointment page
}


void MainWindow::on_pushButton_viewappointment_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(7); // Go to View Appointment page
}


void MainWindow::on_pushButton_bookaroom_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(8); // Go to Book a Room page
}


void MainWindow::on_pushbutton_logout_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // Go to Login page
}


//Register Appointment Page


void MainWindow::on_pushButton_confirm_appointment_clicked()
{
    QString name = ui->lineEdit_enteryourname->text();
    QString age = ui->lineEditage->text();
    QString appointmentType = ui->lineEdit_doctor_id->text();
    QString doctor = ui->lineEdit_2->text();
    QDateTime dateTime = ui->dateTimeEdit->dateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd HH:mm:ss");

    // Check if any of the fields are empty
    if (name.isEmpty() || age.isEmpty() || appointmentType.isEmpty()|| appointmentType.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields.");
        return;  // Exit the function if any field is empty
    }

    // Add the appointment record
    addAppointmentRecord(appointmentType, name, doctor, dateTimeString);

    // Show a success message
    QMessageBox::information(this, "Appointment Confirmed", "Your appointment is confirmed.");

    // Clear all input fields
    ui->lineEdit_enteryourname->clear();
    ui->lineEdit_2->clear();
    ui->lineEditage->clear();
    ui->lineEdit_doctor_id->clear();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());  // Reset date-time field

    // Switch to the View Appointment page (index 7)
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_cencel_appointment_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

//Panel




void MainWindow::on_pushButton_registerpatient_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Go to Register Patient page
}


void MainWindow::on_pushButton_registerdoctor_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // Go to Register Doctor page
}




void MainWindow::on_pushButton_removepatient_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); // Go to View Patient page
}


void MainWindow::on_pushButton_removedoctor_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(5); // Go to View Doctor page
}


void MainWindow::on_pushButton_bookappointment_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(6); // Go to Register Appointment page
}


void MainWindow::on_pushButton_viewappointment_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(7); // Go to View Appointment page
}


void MainWindow::on_pushButton_bookaroom_19_clicked()
{

}


void MainWindow::on_pushbutton_logout_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // Go to Login Page
}


// Book a room
void MainWindow::on_pushButton_confirm_bookaroom_clicked()
{
    QString name = ui->lineEdit_enteryourname_3->text();
    QString age = ui->lineEditage_2->text();
    QString appointmentType = ui->lineEdit_3->text();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter your name.");
        return;
    }

    if (age.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter your age.");
        return;
    }

    if (appointmentType.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter the appointment type.");
        return;
    }

    QMessageBox::information(this, "Appointment Registered", "Appointment successfully registered.");
    ui->stackedWidget->setCurrentIndex(1); // dashboard
}


//Panel



void MainWindow::on_pushButton_registerpatient_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Go to Register Patient page
}


void MainWindow::on_pushButton_registerdoctor_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // Go to Register Doctor page
}


void MainWindow::on_pushButton_removepatient_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); // Go to View Patient page
}


void MainWindow::on_pushButton_removedoctor_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(5); // Go to View Doctor page
}


void MainWindow::on_pushButton_bookappointment_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(6); // Go to Register Appointment page
}


void MainWindow::on_pushButton_viewappointment_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(7); // Go to View Appointment page
}


void MainWindow::on_pushButton_bookaroom_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(8); // Go to Book a room page
}


void MainWindow::on_pushbutton_logout_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // Go to  logout page
}


// View Appointment page

// Add data to table
void MainWindow::addAppointmentRecord(const QString doctorID, const QString doctorName, const QString patientName, const QString dateTime) {
    int rowCount = ui->tableWidget_appointments->rowCount();
    ui->tableWidget_appointments->insertRow(rowCount);

    ui->tableWidget_appointments->setItem(rowCount, 0, new QTableWidgetItem(doctorID));
    ui->tableWidget_appointments->setItem(rowCount, 1, new QTableWidgetItem(doctorName));
    ui->tableWidget_appointments->setItem(rowCount, 2, new QTableWidgetItem(patientName));
    ui->tableWidget_appointments->setItem(rowCount, 3, new QTableWidgetItem(dateTime));
}




// Search button

void MainWindow::on_pushButton_search_viewappointment_clicked()
{
    QString searchDoctorID = ui->lineEdit_enterdoctorid_viewappointment->text();
    bool found = false;
    for (int row = 0; row < ui->tableWidget_appointments->rowCount(); ++row) {
        if (ui->tableWidget_appointments->item(row, 0)->text() == searchDoctorID) {
            ui->tableWidget_appointments->selectRow(row);
            found = true;
        } else {
            ui->tableWidget_appointments->setRowHidden(row, true);
        }
    }

    if (!found) {
        QMessageBox::information(this, "Not Found", "No appointment found with given Doctor ID.");
    }

}



// remove button
void MainWindow::on_pushButton_remove_viewappointment_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget_appointments->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        ui->tableWidget_appointments->removeRow(row);
        QMessageBox::information(this, "Removed", "Appointment removed successfully.");
    } else {
        QMessageBox::warning(this, "No Selection", "Please select a row to remove.");
    }

}


// clear button
void MainWindow::on_pushButton_clear_viewappointment_clicked()
{
    ui->lineEdit_enterdoctorid_viewappointment->clear();
    for (int i = 0; i < ui->tableWidget_appointments->rowCount(); ++i) {
        ui->tableWidget_appointments->setRowHidden(i, false);
    }
}


//Cancel Button
void MainWindow::on_pushButton_cancel_viewappointment_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Go to Dashboard page
}


//Panel

void MainWindow::on_pushButton_registerpatient_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Go to Register Patient page
}


void MainWindow::on_pushButton_registerdoctor_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // Go to Register Doctor page
}


void MainWindow::on_pushButton_removepatient_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); // Go to View Patient page
}


void MainWindow::on_pushButton_removedoctor_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(5); // Go to View Doctor page
}


void MainWindow::on_pushButton_bookappointment_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(6); // Go to Register Appointment page
}


void MainWindow::on_pushButton_viewappointment_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(7); // Go to View Appointment page
}


void MainWindow::on_pushButton_bookaroom_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(8); // Go to book a room page
}


void MainWindow::on_pushbutton_logout_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // Go to  login page
}


// View Patient Record
//adding patient table
void MainWindow::addPatientRecord(const QString &id, const QString &name,const QString &cnic, const QString &age,const QString &bloodGroup, const QString &diagnosis)
{
    int row = ui->tableWidget_patients->rowCount();
    ui->tableWidget_patients->insertRow(row);
    ui->tableWidget_patients->setItem(row, 0, new QTableWidgetItem(id));
    ui->tableWidget_patients->setItem(row, 1, new QTableWidgetItem(name));
    ui->tableWidget_patients->setItem(row, 2, new QTableWidgetItem(cnic));
    ui->tableWidget_patients->setItem(row, 3, new QTableWidgetItem(age));
    ui->tableWidget_patients->setItem(row, 4, new QTableWidgetItem(bloodGroup));
    ui->tableWidget_patients->setItem(row, 5, new QTableWidgetItem(diagnosis));
}

// Search Button

void MainWindow::on_pushButton_search_clicked()
{
    QString searchId = ui->lineEdit_enterpatientid_viewpatient->text();
    if (searchId.isEmpty()) {
        QMessageBox::warning(this, "Search Error", "Enter a Patient ID to search.");
        return;
    }

    for (int i = 0; i < ui->tableWidget_patients->rowCount(); ++i) {
        if (ui->tableWidget_patients->item(i, 0)->text() == searchId) {
            ui->tableWidget_patients->selectRow(i);
            return;
        }
    }

    QMessageBox::information(this, "Not Found", "Patient ID not found.");

}

//Clear Button

void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit_enterpatientid_viewpatient->clear();
}



//Remove Button

void MainWindow::on_pushButton_remove_viewpatients_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget_patients->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        ui->tableWidget_patients->removeRow(row);
        QMessageBox::information(this, "Removed", "Selected patient removed.");
    } else {
        QMessageBox::warning(this, "Selection Error", "Select a row to remove.");
    }
}


void MainWindow::on_pushButton_cancel_viewpatients_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Go to dashboard page
}


//Panel



void MainWindow::on_pushButton_registerpatient_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Go to Register Patient page
}


void MainWindow::on_pushButton_registerdoctor_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // Go to Register Doctor page
}


void MainWindow::on_pushButton_removepatient_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); // Go to View Patient page
}


void MainWindow::on_pushButton_removedoctor_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(5); // Go to Register Doctor page
}


void MainWindow::on_pushButton_bookappointment_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(6); // Go to Register Appointment page
}


void MainWindow::on_pushButton_viewappointment_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(7); // Go to View Appointment page
}


void MainWindow::on_pushButton_bookaroom_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(8); // Go to Book a Room page
}


void MainWindow::on_pushbutton_logout_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // Go to log out page
}


// View Doctor page


// Add doctor record
void MainWindow::addDoctorRecord(const QString &id, const QString &name, const QString &cnic,const QString &age, const QString &gender, const QString &specialization)
{
    int row = ui->tableWidget_doctor->rowCount();
    ui->tableWidget_doctor->insertRow(row);
    ui->tableWidget_doctor->setItem(row, 0, new QTableWidgetItem(id));
    ui->tableWidget_doctor->setItem(row, 1, new QTableWidgetItem(name));
    ui->tableWidget_doctor->setItem(row, 2, new QTableWidgetItem(cnic));
    ui->tableWidget_doctor->setItem(row, 3, new QTableWidgetItem(age));
    ui->tableWidget_doctor->setItem(row, 4, new QTableWidgetItem(gender));
    ui->tableWidget_doctor->setItem(row, 5, new QTableWidgetItem(specialization));
}

// search button
void MainWindow::on_pushButton_search_viewdoctor_clicked()
{
    QString searchId = ui->lineEdit_enterpatientid_viewdoctor->text();
    if (searchId.isEmpty()) {
        QMessageBox::warning(this, "Search Error", "Enter a Doctor ID to search.");
        return;
    }

    for (int i = 0; i < ui->tableWidget_doctor->rowCount(); ++i) {
        if (ui->tableWidget_doctor->item(i, 0)->text() == searchId) {
            ui->tableWidget_doctor->selectRow(i);
            return;
        }
    }

    QMessageBox::information(this, "Not Found", "Doctor ID not found.");

}

// Remove button

void MainWindow::on_pushButton_remove_viewdoctor_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget_doctor->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        ui->tableWidget_doctor->removeRow(row);
        QMessageBox::information(this, "Removed", "Selected doctor removed.");
    } else {
        QMessageBox::warning(this, "Selection Error", "Select a row to remove.");
    }
}


//clear button
void MainWindow::on_pushButton_cleaar_viewdoctor_clicked()
{
        ui->lineEdit_enterpatientid_viewdoctor->clear();
}

// cancel button


void MainWindow::on_pushButton_cancel_viewdoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Go to dashboard page
}




//panel



void MainWindow::on_pushButton_registerpatient_17_clicked()
{
        ui->stackedWidget->setCurrentIndex(2); // Go to Register Patient page
}


void MainWindow::on_pushButton_registerdoctor_17_clicked()
{
        ui->stackedWidget->setCurrentIndex(3); // Go to Register Doctor page
}


void MainWindow::on_pushButton_removepatient_17_clicked()
{
        ui->stackedWidget->setCurrentIndex(4); // Go to View Patient page
}


void MainWindow::on_pushButton_removedoctor_17_clicked()
{
        ui->stackedWidget->setCurrentIndex(5); // Go to view  doctor page
}


void MainWindow::on_pushButton_bookappointment_17_clicked()
{
        ui->stackedWidget->setCurrentIndex(6); // Go to Register Appointment page
}


void MainWindow::on_pushButton_viewappointment_13_clicked()
{
        ui->stackedWidget->setCurrentIndex(7); // Go to View Appointment page
}


void MainWindow::on_pushButton_bookaroom_13_clicked()
{
        ui->stackedWidget->setCurrentIndex(8); // Go to book a room page
}


void MainWindow::on_pushbutton_logout_15_clicked()
{
        ui->stackedWidget->setCurrentIndex(0); // Go to login page
}



void MainWindow::on_pushButton_cencel_bookaroom_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Go to dashboard
}

