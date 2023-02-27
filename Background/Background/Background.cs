using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection.Emit;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace Background {
    public partial class Background : Form {

        int[] Res = { Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height };
        Process Proc;

        public Background() {
            InitializeComponent();
        }

        private void Background_Load(object sender, EventArgs e) {

            try {
                Proc = Process.GetProcessesByName("ggx2")[0];
            }
            catch {
                MessageBox.Show("What your doing?");
                Application.Exit();
            }

            Cursor.Hide();

            this.StartPosition = FormStartPosition.Manual;
            this.Location = new System.Drawing.Point(0, 0);
            this.Size = new System.Drawing.Size(Res[0], Res[1]);
            this.TopMost = false;

            PictureBox.Location = new System.Drawing.Point(0, 0);
            PictureBox.Size = new System.Drawing.Size(Res[0], Res[1]);
            PictureBox.BackColor = Color.FromArgb(0,0,0);

            if (File.Exists(@"Background.png")) {
                FileStream ImageFile = new System.IO.FileStream(@"Background.png", FileMode.Open, FileAccess.Read);
                PictureBox.Image = Image.FromStream(ImageFile);
            }

            Close.Parent = PictureBox;
            Close.BackColor = Color.Transparent;
            Close.Location = new System.Drawing.Point(Res[0]-40, 10);

            TextDebug.Parent = PictureBox;
            TextDebug.Text = "";

        }

        private void Background_FormClosed(object sender, FormClosedEventArgs e) {
            try { Proc.Kill(); } catch { }
        }
    }
}
