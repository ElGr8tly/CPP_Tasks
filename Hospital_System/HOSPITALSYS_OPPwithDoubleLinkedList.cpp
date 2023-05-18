#include <iostream>
#include <string>
using namespace std;

class  person
{
private :

    string Name = "Empty";
    string Date_Of_Birth = "Empty";
public :
    person(string n ,string d )
    :Name(n),Date_Of_Birth(d){}
    person (){}
    void set_Person_Name(string n);
    void set_Person_Date_Of_Birth(string d);
    string get_Person_Name();
    string get_Person_Date_Of_Birth();
};

class Patient: public person
{
private :

    int16_t Hospital_Id  = 0;
    string  Phone_Number = "Empty";
    string  Diagnosis    ="Empty";
public :
    Patient(string n ,string d   ,string PN ,int16_t HID,string D )
    :person(n ,d),Hospital_Id(HID),Phone_Number(PN),Diagnosis(D){}
    Patient(){}
    void set_Patient_Name(string N);
    void set_Patient_Date_Of_Birth(string DOFB);
    void set_Patient_Hospital_Id(int16_t HID);
    void set_Patient_Phone_Number(string PN);
    void set_Patient_Diagnosis(string D);
    int16_t get_Patient_Hospital_Id();
    string get_Patient_Phone_Number();
    string get_Patient_Diagnosis();
    void   show_Patient_Data();
};

class Hospital
{
private :
      string   H_Name = "Empty";
      string   H_Address = "Empty";
      int16_t  H_Number_Of_Doctors = 0;
      int16_t  H_Number_Of_Staff = 0;
      struct H_Patient
      {
          Patient H_patient;
          H_Patient *Forward ;
          H_Patient *Backward;
      };
      H_Patient *H_First_Patient = NULL;
      int16_t get_Patient_ID (int ADD_or_RELEASE  )
      {
          static int16_t H_Patient_ID=0;

          if (ADD_or_RELEASE == 1)
             return (++H_Patient_ID);
          else if ( (ADD_or_RELEASE == 0) && (H_Patient_ID != 0))
             return (--H_Patient_ID);
          else
            return H_Patient_ID ;
      }
public :

    Hospital (string H_N,string   H_A,int16_t  H_ND,int16_t  H_NS)
    :H_Name(H_N),H_Address(H_A),H_Number_Of_Doctors(H_ND),H_Number_Of_Staff(H_NS){}
    Hospital(){}

    void set_Hospital_Name(string H_N);
    void set_Hospital_Address(string H_A);
    void set_Hospital_Number_Of_Doctors(int16_t  H_ND);
    void set_Hospital_Number_Of_Staff(int16_t  H_NS);
    void set_Hospital_Patient_Diagnosis(int16_t H_P_ID , string Diagnosis);
    int16_t add_int16_t_Patient_To_Hospital(string name ,string DateOfBirth ,string PhoneN );
    void release_Patient_From_Hospital(int16_t H_P_ID );
    void show_Hospital_Data();
    void show_H_Patient_Data( int16_t H_P_ID );
};
/****************************************************************************************************/
/****************************************************************************************************/
int main()
{
    Hospital El_Hyah("El Hyah","Feryal Street",50,80);
    El_Hyah.show_Hospital_Data();
    int16_t I = 0;
    while(1)
    {
        I = 0;
        cout<<endl<<"Welcome to Our Hospital System : "<<endl;
        cout<<"To Add New Patient       press 1 : "<<endl;
        cout<<"To Release Patient       press 2 : "<<endl;
        cout<<"To Set Patient Diagnosis press 3 : "<<endl;
        cout<<"To Show Data of Patient  press 4 : "<<endl<<endl;cin>>I;

        if(I== 1 )
           {

            string Name ;
            string DateofBirth ;
            string Phone ;
            cout<<endl<<"To Add New Patient  Give His Name : ";getline(cin>>ws,Name);
            cout<<endl<<"Also  Give His Date of Birth      : ";getline(cin>>ws,DateofBirth);
            cout<<endl<<"Also  Give His Phone Number       : ";getline(cin>>ws,Phone);
            cout<<endl<<"The Hospital Patient ID   is      : "
            <<El_Hyah.add_int16_t_Patient_To_Hospital(Name,DateofBirth,Phone);

           }
           else if (I == 2)
           {
            int16_t H_ID;
            cout<<endl<<"To Release Patient Enter His Hospital ID : ";cin>>H_ID;
            El_Hyah.release_Patient_From_Hospital(H_ID);
           }
           else if (I == 3)
           {
            int16_t H_ID;
            string Diagnosis ;
            cout<<endl<<"To Set Patient Diagnosis Enter  H_ID      : ";cin>>H_ID;
            cout<<endl<<"Enter The Patient Diagnosis               : ";getline(cin>>ws,Diagnosis);
            El_Hyah.set_Hospital_Patient_Diagnosis(H_ID,Diagnosis);
           }
           else if (I == 4)
           {
            int16_t H_ID;
            cout<<endl<<"To Show Data of Patient Enter His Hospital ID :";cin>>H_ID;
            cout<<endl;
            El_Hyah.show_H_Patient_Data(H_ID);
           }
           else
            {cout<<endl<<"Again ,,, "<<endl;
            }
    }

    return 0;
}
/****************************************************************************************************/
/***************************************Person*******************************************************/
    void person::set_Person_Name(string n)
    {
        Name = n ;
    }
    void person::set_Person_Date_Of_Birth(string d)
    {
        Date_Of_Birth = d ;
    }
    string person::get_Person_Name()
    {
        return Name ;
    }
    string person::get_Person_Date_Of_Birth()
    {
        return Date_Of_Birth;
    }
/*******************************Patient******************************************/
    void    Patient::set_Patient_Name(string N)
    {
            set_Person_Name(N);
    }
    void    Patient::set_Patient_Date_Of_Birth(string DOFB)
    {
            set_Person_Date_Of_Birth(DOFB);
    }
    void    Patient::set_Patient_Hospital_Id(int16_t HID)
    {
        Hospital_Id = HID ;
    }
    void    Patient::set_Patient_Phone_Number(string PN)
    {
        Phone_Number =  PN ;
    }
    void    Patient::set_Patient_Diagnosis(string D)
    {
        Diagnosis = D ;
    }
    int16_t Patient::get_Patient_Hospital_Id()
    {
        return Hospital_Id;
    }
    string  Patient::get_Patient_Phone_Number()
    {
        return Phone_Number ;
    }
    string  Patient::get_Patient_Diagnosis()
    {
        return Diagnosis ;
    }
    void    Patient::show_Patient_Data()
    {
        cout<<endl<<"Name of Patient      : "<<get_Person_Name()<<endl;
        cout<<"Patient Date Of Birth: "<<get_Person_Date_Of_Birth()<<endl;
        cout<<"Name of Phone Number : "<<Phone_Number<<endl;
        cout<<"Name of Hospital Id  : "<<Hospital_Id<<endl;
        cout<<"Name of Diagnosis    : "<<Diagnosis<<endl<<endl;
    }

/*******************************Hospital************************************/

    void Hospital::set_Hospital_Name(string H_N)
    {
        H_Name =H_N;
    }
    void Hospital::set_Hospital_Address(string H_A)
    {
        H_Address = H_A;
    }
    void Hospital::set_Hospital_Number_Of_Doctors(int16_t  H_ND)
    {
        H_Number_Of_Doctors = H_ND ;
    }
    void Hospital::set_Hospital_Number_Of_Staff(int16_t  H_NS)
    {
        H_Number_Of_Staff = H_NS ;
    }
    void Hospital::set_Hospital_Patient_Diagnosis(int16_t H_P_ID , string Diagnosis)
    {
        H_Patient * Temp=H_First_Patient;
        while (Temp != NULL)
        {
            if( Temp->H_patient.get_Patient_Hospital_Id() == H_P_ID )
            {
                Temp->H_patient.set_Patient_Diagnosis(Diagnosis);
                break;
            }
            Temp = Temp->Forward ;
        }
    }
    int16_t Hospital::add_int16_t_Patient_To_Hospital(string name ,string DateOfBirth ,string PhoneN )
    {
        if(H_First_Patient == NULL )
        {
            H_First_Patient = new H_Patient ;
            H_First_Patient->Forward =NULL;
            H_First_Patient->Backward=NULL;
            H_First_Patient->H_patient.set_Patient_Name(name) ;
            H_First_Patient->H_patient.set_Patient_Date_Of_Birth(DateOfBirth) ;
            H_First_Patient->H_patient.set_Patient_Phone_Number(PhoneN) ;
            H_First_Patient->H_patient.set_Patient_Hospital_Id(get_Patient_ID(1));

        }
        else
        {
            H_Patient * Temp=H_First_Patient;
            while (Temp->Forward != NULL) {Temp = Temp->Forward ;}
            Temp->Forward = new H_Patient ;
            Temp->Forward->Forward =NULL;
            Temp->Forward->Backward=Temp;
            Temp = Temp->Forward;
            Temp->H_patient.set_Patient_Name(name) ;
            Temp->H_patient.set_Patient_Date_Of_Birth(DateOfBirth) ;
            Temp->H_patient.set_Patient_Phone_Number(PhoneN) ;
            Temp->H_patient.set_Patient_Hospital_Id(get_Patient_ID(1));
        }
        return  get_Patient_ID (2);
    }
    void Hospital::release_Patient_From_Hospital(int16_t H_P_ID )
    {
        H_Patient * Temp=H_First_Patient;
        while (Temp != NULL)
        {
            if( Temp->H_patient.get_Patient_Hospital_Id() == H_P_ID )
            {
                if(Temp->Backward != NULL)
                     {Temp->Backward->Forward=Temp->Forward;}
                else {H_First_Patient = Temp->Forward;}
                if(Temp->Forward != NULL)
                     {Temp->Forward->Backward=Temp->Backward;}

                delete (Temp);
                get_Patient_ID(0);
                break;
            }
            Temp = Temp->Forward ;
        }
    }
    void Hospital::show_Hospital_Data()
    {
        cout<<endl<<"Name of Hospital      : "<<H_Name<<endl;
        cout<<"Address of Hospital  : "<<H_Address<<endl;
        cout<<"Nunmber of Doctors   : "<<H_Number_Of_Doctors<<endl;
        cout<<"Nunmber of Staff     : "<<H_Number_Of_Staff<<endl<<endl;

    }
    void Hospital::show_H_Patient_Data( int16_t H_P_ID )
    {
        H_Patient * Temp=H_First_Patient;
        while (Temp != NULL)
        {
            if( Temp->H_patient.get_Patient_Hospital_Id() == H_P_ID )
            {
                Temp->H_patient.show_Patient_Data();
                break;
            }
            Temp = Temp->Forward ;
        }
    }
/*********************************************************************/
