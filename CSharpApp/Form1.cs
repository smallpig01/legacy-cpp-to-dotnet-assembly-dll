using LegacyCpp2DotNetAssemblyDll;

namespace CSharpApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MyLegacyClassWrapper c1 = new();       // default constructor
            MyLegacyClassWrapper c2 = new(10, 20); // constructor with parameters
            label1.Text = c1.Calc().ToString() + ", " + c2.Calc().ToString();

            c1.Set(30, 40); // set values
            c2.Set(50, 60); // set values
            label2.Text = c1.Calc().ToString() + ", " + c2.Calc().ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MyLegacyClassWrapper c1 = new();       // default constructor
            MyLegacyClassWrapper c2 = new(10, 20); // constructor with parameters
            MyLegacyClassWrapper c3 = new(30, 40); // constructor with parameters
            label1.Text = c1.Calc().ToString() + ", " + c2.Calc().ToString() + ", " + c3.Calc().ToString();

            c3 = c1.Set(c2); // parse c2 object to c1 object, and return c1 object
            c1.Set(50, 60);  // change c1 object value, but no effect on c3 object
            c2.Set(70, 80);  // change c2 object value, but no effect on c3 object
            label2.Text = c1.Calc().ToString() + ", " + c2.Calc().ToString() + ", " + c3.Calc().ToString();

            c3.Set(1, 1); // try to use c3 object to check c3 object is alive or not
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // create a,b1,b2 object, and set their values;
            ClsAWrapper a = new();
            a.SetValue(11);
            ClsBWrapper b1 = new();
            b1.SetValue(22);
            ClsBWrapper b2 = new();
            b2.SetValue(33);
            label1.Text = a.GetValue().ToString() + ", " + b1.GetValue().ToString() + ", " + b2.GetValue().ToString();

            // push a b1 object into a::foo to set a value into b object, and return the b2 object, but no effect on b1 object;
            b2 = a.Foo(b1);
            a.SetValue(44);
            b1.SetValue(55);
            label2.Text = a.GetValue().ToString() + ", " + b1.GetValue().ToString() + ", " + b2.GetValue().ToString();

            b2.SetValue(66); // try to use b2 object to check b2 object is alive or not
        }

        private void button4_Click(object sender, EventArgs e)
        {
            // create 3 object and set separated values
            LegacyCpp2DotNetAssemblyDll.MyLegacyClassWrapper c1 = new(10, 10);
            LegacyCpp2DotNetAssemblyDll.MyLegacyClassWrapper c2 = new(20, 20);
            LegacyCpp2DotNetAssemblyDll.MyLegacyClassWrapper c3 = new(30, 30);
            label1.Text = c1.Calc().ToString() + ", " + c2.Calc().ToString() + ", " + c3.Calc().ToString();

            // send c2 to get c1 value, and revieve the c2 into c3
            c3 = c1.Get(c2);
            label2.Text = c1.Calc().ToString() + ", " + c2.Calc().ToString() + ", " + c3.Calc().ToString();

            // test whether C1, C2, C3 are separate objects
            c1.Set(40, 40);
            c2.Set(50, 50);
            c3.Set(60, 60);
            label3.Text = c1.Calc().ToString() + ", " + c2.Calc().ToString() + ", " + c3.Calc().ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            // create a array set values
            float[] array = new float[] { 1.1f, 2.2f, 9.9f, 4.4f, 5.5f };
            // use CArrayToolsWrapper static function to get the max value of array
            float max = LegacyCpp2DotNetAssemblyDll.CArrayToolsWrapper.Max(array);
            label1.Text = max.ToString();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            // ptrint MyEnum.B int/hex/bin value
            int int_b = (int)MyEnum.B;
            string hex_b = "0x" + Convert.ToString((int)MyEnum.B, 16).PadLeft(4, '0');
            string bin_b = "0b" + Convert.ToString((int)MyEnum.B, 2).PadLeft(4, '0');
            label1.Text = "MyEnum.B =           " + int_b.ToString() + ", " + hex_b.ToString() + ", " + bin_b.ToString();

            // ptrint MyEnum.D int/hex/bin value
            int int_d = (int)MyEnum.D;
            string hex_d = "0x" + Convert.ToString((int)MyEnum.D, 16).PadLeft(4, '0');
            string bin_d = "0b" + Convert.ToString((int)MyEnum.D, 2).PadLeft(4, '0');
            label2.Text = "MyEnum.D =          " + int_d.ToString() + ", " + hex_d.ToString() + ", " + bin_d.ToString();

            // bit operation of B and D, and print int/hex/bin value
            MyEnum EnumBitOperation = (MyEnum.B | MyEnum.D);
            string hex_bd = "0x" + Convert.ToString((long)EnumBitOperation, 16).PadLeft(4, '0');
            string bin_bd = "0b" + Convert.ToString((long)EnumBitOperation, 2).PadLeft(4, '0');
            label3.Text = "MyEnum .B | .D = " + EnumBitOperation.ToString() + ", " + hex_bd.ToString() + ", " + bin_bd.ToString();

            #region 不應被清除的程式碼
            // use c++ legacy enum (in class enum) 
            InClassMyEnum.MyEnum in_class_enum_A = InClassMyEnum.MyEnum.A;
            InClassMyEnum.MyEnum in_class_enum_B = InClassMyEnum.MyEnum.B;
            InClassMyEnum.MyEnum in_class_enum_C = InClassMyEnum.MyEnum.C;
            InClassMyEnum.MyEnum in_class_enum_D = InClassMyEnum.MyEnum.D;
            InClassMyEnum.MyEnum in_class_enum_ALL = in_class_enum_ALL = in_class_enum_A | in_class_enum_B | in_class_enum_C | in_class_enum_D;
            #endregion
        }

        private void button7_Click(object sender, EventArgs e)
        {
            MyStringCharWrapper myStringCharWrapper = new();
            string intput_str, optput_str;

            // System::String and std::string interconverting
            intput_str = "System::String and std::string interconverting!!";
            myStringCharWrapper.SetDataString(intput_str);
            optput_str = myStringCharWrapper.GetDataString();
            label1.Text = optput_str;

            // System::String and char* interconverting
            intput_str = "System::String and char* interconverting!!";
            myStringCharWrapper.SetDataChar(intput_str);
            optput_str = myStringCharWrapper.GetDataChar();
            label2.Text = optput_str;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            // create a int {1,2,3,4,5} array
            int[] src_array = new int[] { 1, 2, 3, 4, 5 };
            label1.Text = "src_arr = " + string.Join(", ", src_array);

            // use MyStdVectorWrapper.RevertVector to get the reverted array
            int[] dst_array = MyStdVectorWrapper.RevertVector(src_array);
            label2.Text = "src_arr = " + string.Join(", ", src_array) + "; dst_arr = " + string.Join(", ", dst_array);

            // change the src_array to {10} and dst_array to {20}
            src_array[0] = 1; src_array[1] = 1; src_array[2] = 1; src_array[3] = 1; src_array[4] = 1;
            dst_array[0] = 2; dst_array[1] = 2; dst_array[2] = 2; dst_array[3] = 2; dst_array[4] = 2;
            label3.Text = "src_arr = " + string.Join(", ", src_array) + "; dst_arr = " + string.Join(", ", dst_array);
        }
    }
}