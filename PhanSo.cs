using System;

namespace PhanSo
{
    // Khai báo lớp phân số
    class PhanSo
    {
        private int _tuSo; // Tử số là dữ liệu riêng (field), từ bên ngoài không thể truy cập
        private int _mauSo; 

        public int TuSo     // TuSo là thuộc tính (property), có thể truy xuất từ bên ngoài
        {
            get{return _tuSo;}
            set{_tuSo = value;}
        }
        public int MauSo
        {
            get{return _mauSo;}
            //set{_mauSo = value;}
        }

        // Phương thức thiết lập (constructor)
        public PhanSo(int t=0, int m=1)
        {
            _tuSo = t;
            if(m != 0) _mauSo = m;
        }

        // Phương thức nhập phân số
        public void Nhap()
        {
            Console.Write("Tu so = ");
            _tuSo = int.Parse(Console.ReadLine());
            do{
                Console.Write("Mau so = ");
                _mauSo = int.Parse(Console.ReadLine());               
            }while(_mauSo == 0);
        }

        // Phương thức xuất phân số
        public void Xuat()
        {   
            Console.WriteLine("{0}/{1}\n", _tuSo, _mauSo);
        }

        // Phương thức tối giản phân số
        public void ToiGian()
        {
            int ucln = UCLN(_mauSo, _tuSo);
            _tuSo /= ucln;
            _mauSo /= ucln;
        }

        public static int UCLN(int a, int b) // a,b >0
        {
            while(a != b)  if(a > b) a -= b; else b -= a;
            return a;  
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            //Tạo đối tượng thuộc lớp phân số
            PhanSo p = new PhanSo(8,28); 
            Console.WriteLine("Phan so vua tao:\n");
            p.Xuat();

            Console.WriteLine("Phan so toi gian:\n");
            p.ToiGian();
            p.Xuat();
        }
    }
}