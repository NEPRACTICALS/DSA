#include <iostream>
#include <string>
#include <limits>
using namespace std;
// This is a linked list for Patient records with patient_id, name, dob, gender
class Patient
{
public:
    int patient_id;
    string name;
    string dob;
    string gender;
    Patient *next;
    Patient(int id, string name, string dob, string gender)
    {
        this->patient_id = id;
        this->name = name;
        this->dob = dob;
        this->gender = gender;
        this->next = NULL;
    }
};
// This is a linked list for Doctor with doctor_id, name, specialization
class Doctor
{
public:
    int doctor_id;
    string name;
    string specialization;
    Doctor *next;
    Doctor(int id, string name, string specialization)
    {
        this->doctor_id = id;
        this->name = name;
        this->specialization = specialization;
        this->next = NULL;
    }
};
// This is linked list for Appointment with appointment_id, patient_id, doctor_id, appointment_date
class Appointment
{
public:
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointment *next;
    Appointment(int id, int patient_id, int doctor_id, string appointment_date)
    {
        this->appointment_id = id;
        this->patient_id = patient_id;
        this->doctor_id = doctor_id;
        this->appointment_date = appointment_date;
        this->next = NULL;
    }
};
// first check if the patientID is not already present in the list
bool checkPatientId(Patient *&head, int id)
{
    Patient *temp = head;
    while (temp != NULL)
    {
        if (temp->patient_id == id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// first check if the doctor_id is not already present in the list
bool checkDoctorId(Doctor *&head, int id)
{
    Doctor *temp = head;
    while (temp != NULL)
    {
        if (temp->doctor_id == id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// first check if the appointment id is not already present in the list
bool checkAppointmentId(Appointment *&head, int id)
{
    Appointment *temp = head;
    while (temp != NULL)
    {
        if (temp->appointment_id == id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// function to add patient it takes, patientId, name, dob,gender
void addPatient(Patient *&head, int id, string name, string dob, string gender)
{
    // check if the patient_id is already present in the list
    if (checkPatientId(head, id))
    {
        std::cout << " !!!!!!!!!!!!!!!!!!!!  patient_id already exist. !!!!!!!!!!!!" << endl;
        std::cout << " !!!!!!!!!!!!!!!!!!!! use a different patientId !!!!!!!!!!!!" << endl;
        return;
    }
    Patient *newNode = new Patient(id, name, dob, gender);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Patient *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// function to add doctor it takes, doctorId, name, specialization
void addDoctor(Doctor *&head, int id, string name, string specialization)
{
    // check if the doctor_id is already present in the list
    if (checkDoctorId(head, id))
    {
        std::cout << " !!!!!!!!!!!!!!!!!!!!  doctor_id already exist. !!!!!!!!!!!!" << endl;
        std::cout << " !!!!!!!!!!!!!!!!!!!! use a different doctorId !!!!!!!!!!!!" << endl;
        return;
    }
    Doctor *newNode = new Doctor(id, name, specialization);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Doctor *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// function to find doctorByID
Doctor *findDoctorById(Doctor *&head, int id)
{
    Doctor *temp = head;
    while (temp != NULL)
    {
        if (temp->doctor_id == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
// function to find PatientByID
Patient *findPatientById(Patient *&head, int id)
{
    Patient *temp = head;
    while (temp != NULL)
    {
        if (temp->patient_id == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// function to add appointment it takes, appointmentId, doctorId, patientId,appointmentDate
void addAppointment(Appointment *&appHead, Patient *&head, Doctor *&dhead, int id, int patient_id, int doctor_id, string appointment_date)
{
    if (findPatientById(head, patient_id) == NULL || findDoctorById(dhead, doctor_id) == NULL)
    {
        std::cout << " !!!!!!!!!!!!!!!!!!!!  patient_id or doctor_id does not exist. !!!!!!!!!!!!" << endl;
        std::cout << " !!!!!!!!!!!!!!!!!!!! use a valid patientId or doctorId !!!!!!!!!!!!" << endl;
        return;
    }

    // check if the appointment_id is already present in the list
    if (checkAppointmentId(appHead, id))
    {
        std::cout << " !!!!!!!!!!!!!!!!!!!!  appointment_id already exist. !!!!!!!!!!!!" << endl;
        std::cout << " !!!!!!!!!!!!!!!!!!!! use a different appointmentId !!!!!!!!!!!!" << endl;
        return;
    }

    Appointment *newNode = new Appointment(id, patient_id, doctor_id, appointment_date);
    if (appHead == NULL)
    {
        appHead = newNode;
        return;
    }
    Appointment *temp = appHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// function to display the list of appointments booked in Ruhengeri hospital
void displayAppointments(Appointment *&head)
{
    Appointment *temp = head;
    std::cout << "Appointments:" << endl;
    while (temp != NULL)
    {
        std::cout << "Appointment_id: " << temp->appointment_id << ", Patient_id: " << temp->patient_id << ", Doctor_id: " << temp->doctor_id << ", Appointment Date: " << temp->appointment_date << endl;
        temp = temp->next;
    }
}
// function to display the list of patients in Ruhengeri hospital
void displayPatients(Patient *&head)
{
    Patient *temp = head;
    std::cout << " ====== Patients:=========== " << endl;
    while (temp != NULL)
    {
        std::cout << "Patient_id: " << temp->patient_id << ", Name: " << temp->name << ", DOB: " << temp->dob << ", Gender: " << temp->gender << endl;
        temp = temp->next;
    }
}
// function to display the list of doctors in Ruhengeri hospital
void displayDoctors(Doctor *&head)
{
    Doctor *temp = head;
    std::cout << " ========= Doctors:============= " << endl;
    while (temp != NULL)
    {
        std::cout << "Doctor_id: " << temp->doctor_id << ", Name: " << temp->name << ", Specialization: " << temp->specialization << endl;
        temp = temp->next;
    }
}
// check number
void check_number_input(int &num){
    while(true)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr<<"input must be a number: "<<endl;
            cin>>num;
        }
        if(!cin.fail())
            break;
    }
}
int main()
{
    // The Main function will run according to the following Menu :
    // 1. Add a new patient
    // 2. Add a new doctor
    // 3. Add a new appointment
    // 4. Display all patients
    // 5. Display all doctors
    // 6. Display all appointments
    // 7. Exit the program
    int choice;
    Patient *patientHead = NULL;
    Doctor *doctorHead = NULL;
    Appointment *appHead = NULL;
    // WELCOME PAGE  OF RUHENGERI HOSPITAL MANAGEMENT SYSYTEM
    std::cout << "============================= WELCOME RUHENGERI HOSPITAL MANAGEMENT SYSYTEM !================" << endl;
    std::cout << "   ============================= ============================= ============================= " << endl;
    std::cout << "   ============================= DEVELOPED ============================= BY ============================= MIREILLE" << endl;
    std::cout << "   ============================= MENU ============================= " << endl;
    while (true)
    {
        std::cout << "1. Add a new patient" << endl;
        std::cout << "2. Add a new doctor" << endl;
        std::cout << "3. Add a new appointment" << endl;
        std::cout << "4. Display all patients" << endl;
        std::cout << "5. Display all doctors" << endl;
        std::cout << "6. Display all appointments" << endl;
        std::cout << "7. Exit" << endl;
        std::cout << "Enter your choice: ";
        cin >> choice;
        check_number_input(choice);

        switch (choice)
        {
        case 1:
        {
            int id;
            string name, dob, gender;
            std::cout << "========================= PATIENT REGISTRATION ======================= " << endl;
            std::cout << "------------------------" << endl;
            std::cout << "Enter patient_id: ";
            cin >> id;
            std::cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            std::cout << "Enter DOB (YYYY-MM-DD): ";
            cin >> dob;
            std::cout << "Enter Gender: ";
            cin >> gender;
            addPatient(patientHead, id, name, dob, gender);
            break;
        }
        case 2:
        {
            int id;
            string name, specialization;
            std::cout << " ====================== DOCTOR REGISTRATION =================== " << endl;
            std::cout << "------------------------" << endl;
            std::cout << "Enter doctor_id: ";
            cin >> id;
            std::cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            std::cout << "Enter Specialization: ";
            cin >> specialization;
            addDoctor(doctorHead, id, name, specialization);
            break;
        }
        case 3:
        {
            int id, patient_id, doctor_id;
            string appointment_date;
            std::cout << "========================== APPOINTMENT REGISTRATION ======================= " << endl;
            std::cout << "------------------------" << endl;
            std::cout << "Enter appointment_id: ";
            cin >> id;
            std::cout << "Enter patient_id: ";
            cin >> patient_id;
            std::cout << "Enter doctor_id: ";
            cin >> doctor_id;
            std::cout << "Enter appointment date (YYYY-MM-DD): ";
            cin >> appointment_date;
            addAppointment(appHead, patientHead, doctorHead, id, patient_id, doctor_id, appointment_date);
            break;
        }
        case 4:
        {
            displayPatients(patientHead);
            break;
        }
        case 5:
        {
            displayDoctors(doctorHead);
            break;
        }
        case 6:
        {
            displayAppointments(appHead);
            break;
        }
        case 7:
        {
            std::cout << "Exiting..." << std::endl;
            return 0;
        }
        }
    }
    return 0;
}
