#include<iostream>
#include<iomanip>// can cinh do rong
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
using namespace std;
class  NgaySinh{// diem lay cua nguoi
	protected:
		 int Ngay , Thang , Nam;
   public:
   	     NgaySinh();
   	     NgaySinh( int ngay, int thang , int nam);
   	    ~NgaySinh();
   	     void Nhap1();
   	     void Xuat1();
   	     bool KiemTra();
};
NgaySinh::NgaySinh(){
	this->Ngay=0;
	this->Thang=0;
	this->Nam=0;
	
}
NgaySinh::NgaySinh(int ngay ,int thang, int nam){
  	this->Ngay=0;
	this->Thang=0;
	this->Nam=0;
}
NgaySinh::~NgaySinh(){

}
void NgaySinh::Nhap1()
{ //Nhap ngay thang nam
    cout<<"\n Nhap Ngay sinh( 23/02/2002)"<<endl;
    do{
        cout<<"\nNgay: ";
        cin>>Ngay;
        cout<<"Thang: ";
        cin>>Thang;
        if(KiemTra()==false){
            cout<<endl<<"Nhap lai ngay thang!!"<<endl;
            cout<<"\nNgay: ";
            cin>>Ngay;
            cout<<"Thang: ";
            cin>>Thang;
        }
    }while(KiemTra()==false);
    do{
    cout<<"Nam: ";
    cin>>Nam;
    if(Nam > 2021 || Nam <= 0){
        cout<<"Nhap lai nam sinh!!";
        cout<<endl<<"Nam: ";
        cin>>Nam;
    }
    }while(Nam > 2021 || Nam <= 0);
}
bool NgaySinh::KiemTra(){
{
    //ki?m tra ngày tháng
    bool KiemTra = true;
    if (Thang < 0 || Thang > 12)
    {
        KiemTra = false;
    }
    else
    {
        switch (Thang)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (Ngay < 1 || Ngay > 31)
            {
                KiemTra = false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (Ngay < 1 || Ngay > 30)
            {
                KiemTra = false;
            }
            break;
        case 2:
            if (Nam % 4 == 0 && Ngay < 1 || Ngay > 29)
            {
                KiemTra = false;
            }
            break;
        }
    }
    return KiemTra;
}
}
void NgaySinh::Xuat1(){
	cout<<Ngay<<"/"<<Thang<<"/"<<Nam;
}
class Nguoi: public NgaySinh{// hoc sinh lay cua nguoi
	protected:
		string Ten, DiaChi;
	public:
		Nguoi();
     	Nguoi(string Ten,string DiaChi);
    	~Nguoi();
    	void Nhap2();
    	void Xuat2();
};
Nguoi::	Nguoi():NgaySinh(){
	this->DiaChi="";
	this->Ten="";
}
Nguoi::Nguoi(string Ten,string DiaChi):NgaySinh(Ngay,Thang,Nam){
	this->DiaChi=DiaChi;
	this->Ten=Ten;
}
Nguoi::~Nguoi(){

}
void Nguoi:: Nhap2(){
	fflush(stdin);
	cout<<"\n Nhap ten :";
	getline(cin,Ten);
	cout<<"\n Nhap dia chi :";
    fflush(stdin);
    getline(cin,DiaChi);
    NgaySinh::Nhap1();
   NgaySinh::KiemTra();
} 
void Nguoi::Xuat2(){
	cout<<"\tTen     \t\t Dia CHi \t \t  Sinh"<<endl;
	cout<<"\t\t "<<Ten<<"     \t "<<DiaChi;
	NgaySinh::Xuat1();
}
class Diem: public Nguoi {
	protected:
		float Toan;
		float Ly;
		float Hoa;
		float Van;
		float Su;
		float Dia;
	public:
		Diem();
		Diem(float Toan,float Ly,float Hoa ,float Van ,float Su,float Dia);
		~Diem();
	 	void Nhap3();
		void Xuat3();
};

Diem::Diem():Nguoi(){
	  Toan=0;
	  Ly=0;
	  Hoa=0;
	  Van=0;
	  Su=0;
	  Dia=0;
}
Diem::Diem(float Toan, float Ly, float Hoa, float Van,float Su, float Dia):Nguoi(Ten,DiaChi){
	  this->Toan=Toan;
      this->Ly=Ly;
      this->Hoa=Hoa;
	  this->Van=Van;
	  this->Su=Su;
	  this->Dia=Dia;
}
Diem::~Diem(){
	 this->Toan=0;
	 this->Ly=0;
	 this->Hoa=0;
	 this->Van=0;
	 this->Su=0;
     this->Dia=0;
}
void Diem::Nhap3() {
	Nguoi::Nhap2();
    fflush(stdin);
     fflush(stdin);
     cout<<" Nhap Diem  Cua Hoc Sinh : ";
    do {
        cout<<"Nhap Diem Toan: ";
	    cin >> Toan;
        if (Toan < 0.0 || Toan >10.0){
            cout <<"Nhap Lai Diem Toan: ";
            cin >> Toan;
        }
    }while( Toan < 0.0 ||  Toan >10.0);
    do {
        cout<<"Nhap Diem Ly: ";
	     cin >>  Ly;
        if ( Toan < 0.0 ||  Ly >10.0){
            cout <<"Nhap Lai Diem Ly: ";
             cin >>  Ly;
        }
    }while( Ly < 0.0 ||  Ly >10.0);
    do {
        cout<<"Nhap Diem Hoa: ";
	     cin >>  Hoa;
        if ( Hoa < 0.0 ||  Hoa >10.0){
            cout <<"Nhap Lai Diem Hoa: ";
             cin >>  Hoa;
        }
    }while( Hoa < 0.0 ||  Hoa >10.0);
    do {
        cout<<"Nhap Diem Van: ";
	     cin >>  Van;
        if ( Van < 0.0 ||  Van >10.0){
            cout <<"Nhap Lai Diem Van: ";
             cin >>  Van;
        }
    }while( Van < 0.0 ||  Van >10.0);
    do {
        cout<<"Nhap Diem Su: ";
	     cin >>  Su;
        if ( Su < 0.0 ||  Su >10.0){
            cout <<"Nhap Lai Diem Su: ";
             cin >>  Su;
        }
    }while( Su < 0.0 ||  Su >10.0);
    do {
        cout<<"Nhap Diem Dia: ";
	     cin >>  Dia;
        if ( Dia < 0.0 ||  Dia >10.0){
            cout <<"Nhap Lai Diem Dia: ";
             cin >>  Dia;
        }
    }while( Dia < 0.0 ||  Dia >10.0);
   
   
}
void Diem:: Xuat3(){
    cout<<"\n\t\t\t  DIEM CUA HOC SINH: "<<endl;
	cout<<setw(10)<<" Toan"<<setw(10)<<"Ly "<<setw(10)<<"Hoa "<<setw(10)<<"Van "<<setw(10)<<" Su "<<setw(10)<<"Dia "<<endl;
	cout<<setfill('-');
    cout<<setw(60)<<"-"<<endl;
    cout<<setfill(' ');
	cout<<setw(10)<<Toan<<setw(10)<<Ly<<setw(10)<<Hoa<<setw(10)<<Van<<setw(10)<<Su <<setw(10)<<Dia ;
}
class HocSinh: public Diem{
	private:
	  string   Lop , MSHS;
	  static int STT;
    public:
    	HocSinh();
    	HocSinh( string Lop, string MSHS);
    	~HocSinh();
	    void Nhap4();
	    void Xuat4();
};
int HocSinh::STT=1;
HocSinh::HocSinh():Diem(){
	Lop ="";
	MSHS="";
}
HocSinh::HocSinh( string Lop,  string  MSHS):Diem(Toan,Ly,Hoa,Van,Su,Dia){
	this->Lop=Lop;
	this->MSHS=MSHS;
}
HocSinh::~HocSinh(){
	this->Lop="";
	this->MSHS="";
}
 void HocSinh::Nhap4(){
 	Diem::Nhap3();
    cout<<"\n Nhap lop :";
    fflush(stdin);
    getline(cin,Lop);
    cout<<"\n Nhap ma so hoc sinh : "<<endl;
    fflush(stdin);
    getline(cin,MSHS);
}
void HocSinh::Xuat4(){
	HocSinh A;
	// stt bang thuoc tinh tinh
	// ham setw no tu can do dong tu trai sang phai ghi ki tu tu phai sang trai
	cout<<setw(45)<<" THONG TIN HOC SINH \n"<<endl;
   	cout<<setw(8)<<left<<"STT "<<setw(25)<<left<<"Ten"<<setw(15)<<left<<"Dia Chi"<<setw(10)<<left<<"MSHS"<<setw(25)<<left<<"Ngay Sinh"<<endl;
   	cout<<setfill('-');
    cout<<setw(85)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<setw(8)<<left<<A.STT<<setw(25)<<left<<Ten<<setw(15)<<left<<DiaChi<<setw(10)<<left<<MSHS<<left<<Ngay<<"/"<<Thang<<"/"<<Nam<<endl;
	Diem::Xuat3();
}
void input(HocSinh s[], int n){
    for(int i=0; i<n; i++){
        cout<<"Nhap Thong Tin Cua Hoc Sinh Thu   "<<i+1<<endl;
         s[i].Nhap4();
    }
}
void print(HocSinh s[], int n){
    for(int i=0; i<n; i++){
        cout<<" ThongTin hoc sinh thu   "<<i+1<<endl;
        s[i].Xuat4();
    }
}
// sap xep theo ten
/*void sapXepTen(HocSinh s[], int n){
    HocSinh temp;
    for (int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (strcmp(s[i].Ten,s[j].Ten) > 0){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
// sap xep theo diem
void sapXepDiemTB(HocSinh s[], int n){
    HocSinh temp ;
    for (int i = 0; i < n -1; i++){
        for(int j = i+1; j < n; j++){
            if (s[i].DiemTB() > s[i].DiemTB()){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
// xep loai
void xeploai (float a){
    if (a >= 8.0){
        cout <<"Gioi" << endl;
    }
    else if (a >=7.0 && a < 8.0){
        cout <<"Kha"<< endl;
    }
    else if (a >= 5.0 && a < 7.0){
        cout <<"Trung Binh"<< endl;
    }
    else {
        cout <<"Yeu"<< endl;
    }
}*/
void menu(){
  
    int n;
    do{
		cout<<" Nhap So Luong Hoc Sinh : ";
		cin>>n;
	}while(n<=0);
		HocSinh a[n+1];
	//char fileName[] = "employee.txt";
	int chon,b, flat = 1;
	bool daNhap = false ;
	while(flat){
	    system("cls");
        cout  <<"\t\t\t"<< "       CHUONG TRINH QUAN LY HOC SINH C/C++\n             ";
        cout  <<"\t\t"<< "*************************MENU**************************\n";
        cout  <<"\t\t\t"<< "**      1. Nhap Thong tin hoc sinh                       **\n";
        cout  <<"\t\t\t"<< "**      2. Xuat thong tin hoc sinh.                      **\n";
        cout  <<"\t\t\t"<< "**      3. Xoa sinh vien boi ID.                         **\n";
        cout  <<"\t\t\t"<< "**      4. Tim kiem sinh vien theo ID.                   **\n";
        cout  <<"\t\t\t"<< "**      5. Them 1 hoc sinh .                             **\n";  
        cout  <<"\t\t\t"<< "**      6. Sap xep sinh vien theo diem trung binh .      **\n";
        cout  <<"\t\t\t"<< "**      7. Xep loai hoc sinh .                           **\n";  
        cout  <<"\t\t\t"<< "**      8. Sap xep sinh vien theo ten.                   **\n";
        cout  <<"\t\t\t"<< "**      9. Thong ke sinh vien theo tinh                  **\n";
        cout  <<"\t\t\t"<< "**      10. Ghi danh sach hoc sinh vao file.             **\n";
        cout  <<"\t\t\t"<< "**      0. Thoat                                         **\n";
        cout  <<"\t\t\t"<< "*******************************************************\n";
        cout  << "Nhap tuy chon: ";
        cin >> chon;
        switch(chon){
            case 1:
            		cout<<"\n Ban da chon nhap Thong Tin  Hoc Sinh !";
			        input(a,n);	
			        cout<<"\n Ban da nhap thanh cong !\n";
			        daNhap=true;
		         	cout<<"\n Vui long nhap phim bat ki de tiep tuc !";
		        	getch();
		        	break;
                
            case 2:
                  print(a,n);
            case 3:
                
            case 4:
               
            case 5:
                
            case 6:
                
            case 7:
                
                   
            case 8:
    
               
            case 0:
               
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                //pressAnyKey();
                break;
        }
    }
}
int main(){
	menu();
	//int n;
	//cout<<"NHAP SO LUONG HOC SINH: "; 
    // cin>>n;
	//HocSinh a[n+1];
//	input(a,n);
    //print(a,n);
   

}