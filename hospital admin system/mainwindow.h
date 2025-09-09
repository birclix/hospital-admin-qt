#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow //cunstructor
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    // Add data to table view appointment
    void addAppointmentRecord(const QString doctorID, const QString doctorName, const QString patientName, const QString dateTime);

    // View Patient
    void addPatientRecord(const QString &id, const QString &name, const QString &cnic, const QString &age, const QString &bloodGroup, const QString &diagnosis);

    //View Doctor
    void addDoctorRecord(const QString &id, const QString &name, const QString &cnic,const QString &age, const QString &gender, const QString &specialization);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_registerpatient_clicked();


    void on_pushButton_registerdoctor_clicked();

    void on_pushButton_removepatient_clicked();

    void on_pushButton_removedoctor_clicked();

    void on_pushButton_bookappointment_clicked();

    void on_pushButton_viewappointment_clicked();

    void on_pushButton_bookaroom_clicked();

    void on_pushbutton_logout_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_registerpatient_8_clicked();

    void on_pushButton_registerdoctor_8_clicked();

    void on_pushButton_removepatient_8_clicked();

    void on_pushButton_removedoctor_8_clicked();

    void on_pushButton_bookappointment_8_clicked();

    void on_pushButton_viewappointment_4_clicked();

    void on_pushButton_bookaroom_4_clicked();

    void on_pushbutton_logout_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_registerpatient_11_clicked();

    void on_pushButton_registerdoctor_11_clicked();

    void on_pushButton_removepatient_11_clicked();

    void on_pushButton_removedoctor_11_clicked();

    void on_pushButton_bookappointment_11_clicked();

    void on_pushButton_viewappointment_7_clicked();

    void on_pushButton_bookaroom_7_clicked();

    void on_pushbutton_logout_9_clicked();

    void on_pushButton_confirm_appointment_clicked();

    void on_pushButton_cencel_appointment_clicked();

    void on_pushButton_registerpatient_23_clicked();

    void on_pushButton_registerdoctor_23_clicked();

    void on_pushbutton_logout_21_clicked();

    void on_pushButton_removepatient_23_clicked();

    void on_pushButton_removedoctor_23_clicked();

    void on_pushButton_bookappointment_23_clicked();

    void on_pushButton_viewappointment_19_clicked();

    void on_pushButton_bookaroom_19_clicked();

    void on_pushButton_confirm_bookaroom_clicked();

    void on_pushButton_registerpatient_32_clicked();

    void on_pushButton_registerdoctor_32_clicked();

    void on_pushButton_removepatient_32_clicked();

    void on_pushButton_removedoctor_32_clicked();

    void on_pushButton_bookappointment_32_clicked();

    void on_pushButton_viewappointment_28_clicked();

    void on_pushButton_bookaroom_28_clicked();

    void on_pushbutton_logout_30_clicked();



    void on_pushButton_search_viewappointment_clicked();

    void on_pushButton_remove_viewappointment_clicked();

    void on_pushButton_clear_viewappointment_clicked();

    void on_pushButton_registerpatient_24_clicked();

    void on_pushButton_registerdoctor_24_clicked();

    void on_pushButton_removepatient_24_clicked();

    void on_pushButton_removedoctor_24_clicked();

    void on_pushButton_bookappointment_24_clicked();

    void on_pushButton_viewappointment_20_clicked();

    void on_pushButton_bookaroom_20_clicked();

    void on_pushbutton_logout_22_clicked();

    void on_pushButton_cancel_viewappointment_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_remove_viewpatients_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_registerpatient_12_clicked();

    void on_pushButton_registerdoctor_12_clicked();

    void on_pushButton_removepatient_12_clicked();

    void on_pushButton_removedoctor_12_clicked();

    void on_pushButton_bookappointment_12_clicked();

    void on_pushButton_viewappointment_8_clicked();

    void on_pushButton_bookaroom_8_clicked();

    void on_pushbutton_logout_10_clicked();

    void on_pushButton_cancel_viewpatients_clicked();

    void on_pushButton_search_viewdoctor_clicked();

    void on_pushButton_remove_viewdoctor_clicked();

    void on_pushButton_cleaar_viewdoctor_clicked();

    void on_pushButton_registerpatient_17_clicked();

    void on_pushButton_registerdoctor_17_clicked();

    void on_pushButton_removepatient_17_clicked();

    void on_pushButton_removedoctor_17_clicked();

    void on_pushButton_bookappointment_17_clicked();

    void on_pushButton_viewappointment_13_clicked();

    void on_pushButton_bookaroom_13_clicked();

    void on_pushbutton_logout_15_clicked();

    void on_pushButton_cancel_viewdoctor_clicked();

    void on_pushButton_cencel_bookaroom_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
