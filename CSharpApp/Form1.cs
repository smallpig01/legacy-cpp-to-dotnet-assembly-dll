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
            MyLegacyClassWrapper a = new MyLegacyClassWrapper();
            label1.Text =  a.Calc().ToString();

            a.Set(12, 34);
            label2.Text = a.Calc().ToString();
        }
    }
}
