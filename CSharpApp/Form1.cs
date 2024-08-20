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
            MyLegacyClassWrapper c3 = new(30, 40); // default constructor
            label1.Text = c1.Calc().ToString() + ", " + c2.Calc().ToString() + ", " + c3.Calc().ToString();

            c3 = c1.Set(c2); //
            c2.Set(70, 80);
            label2.Text = c1.Calc().ToString() + ", " + c2.Calc().ToString() + ", " + c3.Calc().ToString();
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
        }
    }
}
