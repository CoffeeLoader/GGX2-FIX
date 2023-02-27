namespace Background
{
    partial class Background
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.TextDebug = new System.Windows.Forms.Label();
            this.PictureBox = new System.Windows.Forms.PictureBox();
            this.Close = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // TextDebug
            // 
            this.TextDebug.AutoSize = true;
            this.TextDebug.BackColor = System.Drawing.Color.Transparent;
            this.TextDebug.Font = new System.Drawing.Font("Microsoft Sans Serif", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextDebug.ForeColor = System.Drawing.Color.Black;
            this.TextDebug.Location = new System.Drawing.Point(12, 12);
            this.TextDebug.Name = "TextDebug";
            this.TextDebug.Size = new System.Drawing.Size(0, 42);
            this.TextDebug.TabIndex = 0;
            // 
            // PictureBox
            // 
            this.PictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.PictureBox.BackColor = System.Drawing.Color.Black;
            this.PictureBox.Location = new System.Drawing.Point(12, 12);
            this.PictureBox.Name = "PictureBox";
            this.PictureBox.Size = new System.Drawing.Size(776, 576);
            this.PictureBox.TabIndex = 1;
            this.PictureBox.TabStop = false;
            // 
            // Close
            // 
            this.Close.AutoSize = true;
            this.Close.BackColor = System.Drawing.Color.Black;
            this.Close.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Close.ForeColor = System.Drawing.Color.White;
            this.Close.Location = new System.Drawing.Point(12, 551);
            this.Close.Name = "Close";
            this.Close.Size = new System.Drawing.Size(39, 37);
            this.Close.TabIndex = 2;
            this.Close.Text = "X";
            this.Close.Visible = false;
            // 
            // Background
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DimGray;
            this.ClientSize = new System.Drawing.Size(800, 600);
            this.Controls.Add(this.Close);
            this.Controls.Add(this.PictureBox);
            this.Controls.Add(this.TextDebug);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Background";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Background";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Background_FormClosed);
            this.Load += new System.EventHandler(this.Background_Load);
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label TextDebug;
        private System.Windows.Forms.PictureBox PictureBox;
        private System.Windows.Forms.Label Close;
    }
}

