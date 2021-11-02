#include <conio.h>

#include <stdio.h>

#include <ctype.h>

#include <string>

#include <iostream>

#include <fstream>

#include <stdlib.h>

#include <iomanip>
#include <cstring>

using namespace std;



class SinhVien{

    private:

    char hoTen[50];

    int maSV;

    char ngaySinh[20];

    char lop[20];

    float diemTB;

    float diemRenLuyen;

    float diemTK;

    int hocBong;

    SinhVien *sv;

    static const char *dataFile;

    int sl;



    public:

    void nhapSV();

    void hienThiSinhVien();

    void sapXepTheoDTB();

    void sapXepTheoHocBong();

    void timTheoTen();

    void timTheoDTK();

    void ghiFile();

    void docFile();

    void khoiTaoFile();

    SinhVien(){

        sl= 0;

        sv= NULL;

        }

    ~SinhVien(){

        delete sv;

        }



    };

         const char *SinhVien::dataFile="QuanLySinhVien.txt";

//Nhap sinh vien

    void SinhVien::nhapSV(){

        int i= sl+1;

            cout<<endl<<" Nhap ho va ten: ";

            cin.getline(sv[i].hoTen,sizeof(sv[i].hoTen));

            //Nhap ma sinh vien co kiem tra

                    int check;

                    do{

                    check= 1;

                    cout<<endl<<" Nhap ma sinh vien: ";

                    cin>>sv[i].maSV;

                           for(int j=1;j<i;j++){

                            if(sv[j].maSV== sv[i].maSV){

                                cout<<endl<<"Ban da nhap sai! Nhap lai";

                                check= 0;

                                }

                            }

                        }while(check== 0);

            //Nhap ngay thang nam sinh

            cout<<endl<<" Nhap ngay sinh sinh vien (dd-mm-yy): ";

            cin.ignore();

            cin.getline(sv[i].ngaySinh,sizeof(sv[i].ngaySinh));

            cout<<endl<<" Nhap lop: ";

            cin.getline(sv[i].lop,sizeof(sv[i].lop));

            cout<<endl<<" Nhap diem trung binh hoc tap (0->10): ";

            cin>>sv[i].diemTB;

            cout<<endl<<" Nhap diem ren luyen (0->100): ";

            cin>>sv[i].diemRenLuyen;

        //Tinh diem tong ket

            if((sv[i].diemRenLuyen>=70)&&(sv[i].diemRenLuyen<80)){

                sv[i].diemTK= sv[i].diemTB+ 0.2;

                }



            else if((sv[i].diemRenLuyen>=80)&&(sv[i].diemRenLuyen<90)){

                sv[i].diemTK= sv[i].diemTB+ 0.5;

                }



            else if((sv[i].diemRenLuyen>=90)&&(sv[i].diemRenLuyen<=100)){

                sv[i].diemTK= sv[i].diemTB+ 0.8;

                }

        /*Học bổng: Nếu ĐTK >=7.0,Học bổng = 120000,

        ĐTK>=80, Học bổng = 180000, nếu ĐTK >=90, Học bổng = 240000*/

            if((sv[i].diemTK>=7)&&(sv[i].diemTK<8)){

                sv[i].hocBong= 120000;

                }



            else if((sv[i].diemTK>=8)&&(sv[i].diemTK<9)){

                sv[i].hocBong= 180000;

                }

            else if((sv[i].diemTK>=9)&&(sv[i].diemTK<=10)){

                sv[i].hocBong= 240000;

                }

        }

    //Ham khoi tao file

     void SinhVien::khoiTaoFile(){

        fstream f(dataFile,ios::out|ios::app);

        f.close();

        }



    //Ham ghi file

    void SinhVien::ghiFile(){

        fstream os(dataFile,ios::out|ios::app);

        int i= sl+1;

        os<<sv[i].hoTen<<endl;

        os<<sv[i].maSV<<endl;

        os<<sv[i].ngaySinh<<endl;

        os<<sv[i].lop<<endl;

        os<<setw(5)<<sv[i].diemTB

        <<setw(5)<<sv[i].diemRenLuyen

        <<setw(5)<<sv[i].diemTK

        <<setw(10)<<sv[i].hocBong<<endl;

        os.close();

        }

    //Ham doc file

        void SinhVien::docFile(){

            fstream s(dataFile,ios::in);

            int dem=1;

            string buffer;

            while(1){

                getline(s,buffer);

                if(!s.eof()){

                    dem++;

                    }

                else

                break;

                }

            sl= dem/5;

            s.close();

            fstream f(dataFile,ios::in);

                sv= new SinhVien[100];

                for(int i=1;i<=sl;i++){

                    f.getline(sv[i].hoTen,sizeof(sv[i].hoTen));

                    f>>sv[i].maSV;

                    f.ignore(1);

                    f.getline(sv[i].ngaySinh,sizeof(sv[i].ngaySinh));

                    f.getline(sv[i].lop,sizeof(sv[i].lop));

                    f>>sv[i].diemTB>>sv[i].diemRenLuyen>>sv[i].diemTK>>sv[i].hocBong;

                    f.ignore();



                }

                f.close();

        }



    //Hien thi sinh vien

    void SinhVien::hienThiSinhVien(){

    cout<<endl;

    cout<<endl<<"Ho va ten sinh vien: "<<hoTen;

    cout<<endl<<"Ma sinh vien:        "<<maSV;

    cout<<endl<<"Ngay thang nam sinh: "<<ngaySinh;

    cout<<endl<<"Lop:                 "<<lop;

    cout<<endl<<"Diem trung binh:     "<<diemTB;

    cout<<endl<<"Diem ren luyen:      "<<diemRenLuyen;

    cout<<endl<<"Diem tong ket:       "<<diemTK;

    cout<<endl<<"Xep loai hoc bong:   "<<hocBong;

    }



    //Sap xep SV theo diem trung binh

   void SinhVien::sapXepTheoDTB(){

    SinhVien s;

    for(int i=1;i<=sl;i++){

        for(int j=1;j<i;j++){

            if(sv[j].diemTB>sv[i].diemTB){

                    s= sv[i];

                    sv[i]= sv[j];

                    sv[j]= s;

                }

            }

        }

         for(int i=1;i<=sl;i++){

            sv[i].hienThiSinhVien();

            }

    }



    //Sap xep SV theo hoc bong

   void SinhVien::sapXepTheoHocBong(){

    SinhVien s;

    for(int i=1;i<=sl;i++){

        for(int j=1;j<i;j++){

            if(sv[j].hocBong>sv[i].hocBong){

                    s= sv[i];

                    sv[i]= sv[j];

                    sv[j]= s;

                }

            }

        }

         for(int i=1;i<=sl;i++){

            sv[i].hienThiSinhVien();

            }

    }



    //Tim kiem theo ten sinh vien

void SinhVien::timTheoTen(){

    char tenSV[20];

    char *strKiemTra;

    char ten[20];



    int count=0;

    cout<<endl<<"Nhap ten sinh vien ma ban muon tim kiem: ";

    cin.ignore();

    cin.getline(tenSV,sizeof(tenSV));

    char *token;

    char str[20];

        for(int i=1;i<=sl;i++){

            strKiemTra= NULL;

            //Tach ten sinh vien

            //Gan ho ten vao bien str -> cat bien str ko cat ho ten

            strcpy(str,sv[i].hoTen);

            //su dung phan tich tu to tokenizing de cat xau str

            token= strtok(str," ");

            while(token!=NULL){

                strcpy(ten,token);

                token= strtok(NULL," ");

                }

            strKiemTra= strstr(ten, tenSV);

            if(strKiemTra!= NULL){

                cout<<endl<<"Sinh vien ma ban can tim la";

                sv[i].hienThiSinhVien();

                count++;

                }

            }

            cout<<endl<<endl<<"So ket qua phu hop la: "<<count;

    }



    //Tim kiem theo tong diem

    void SinhVien::timTheoDTK(){

        int diemTimKiem;

        int count=0;

        cout<<endl<<"Nhap diem tong ket muon tim kiem (0->10): ";

        cin>>diemTimKiem;

        cout<<endl<<"Cac sinh vien co diem tong ket >= "<<diemTimKiem<<" la: ";

        for(int i=1;i<=sl;i++){

            if(sv[i].diemTK>= diemTimKiem){

                sv[i].hienThiSinhVien();

                count++;

                }

            }

        if(count> 0){

            cout<<endl<<"So ket qua phu hop la: "<<count;

            }

        else

        cout<<endl<<"Khong co ket qua nao phu hop"<<endl;

        }



    //Ham hien thi menu

    void menu(){

    cout<<endl<<"******Quan Ly Sinh Vien******"<<endl;

    cout<<endl<<"1. Nhap sinh vien"<<endl;

    cout<<endl<<"2. Sap xep SV theo diem TB "<<endl;

    cout<<endl<<"3. Sap xep SV theo hoc bong"<<endl;

    cout<<endl<<"4. Tim kiem theo ten sinh vien"<<endl;

    cout<<endl<<"5. Tim kiem theo diem TK"<<endl;

    cout<<endl<<"6. Thoat"<<endl;

    }



   main(){

    system("cls");

    SinhVien SV;

    SV.khoiTaoFile();

    do{

        system("cls");

        SV.docFile();

        menu();

        int input= getch();

    //nhap vao so 6 thoat

        if(input=='6'){

            cout<<"Ban da chon thoat khoi chuong trinh! ";

            break;

            }

        switch(input){

            case ('1'):{

                system("cls");

                cout<<endl<<"Nhap sinh vien"<<endl;

                cin.ignore();

                SV.nhapSV();

                SV.ghiFile();

                getch();

                break;

                }

            case('2'):{

                system("cls");

                cout<<endl<<"Sap xep SV theo diem TB";

                SV.sapXepTheoDTB();

                getch();

                break;

                }

            case('3'):{

                system("cls");

                cout<<endl<<"Sap xep SV theo hoc bong";

                SV.sapXepTheoHocBong();

                getch();

                break;

                }

            case('4'):{

                system("cls");

                cout<<endl<<"Tim kiem theo ten sinh vie";

                SV.timTheoTen();

                getch();

                break;

                }

            case('5'):{

                system("cls");

               cout<<endl<<"Tim kiem theo diem TK";

                SV.timTheoDTK();

                getch();

                break;

                }

          default:{

                cout<<"Hay nhap tu 1-6:";

                getch();

                }

            }



        }while(1);

    getch();

}
