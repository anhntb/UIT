namespace QLHangTonKho
{
    partial class fSanPham
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tcSanPham = new System.Windows.Forms.TabControl();
            this.tpSanPham = new System.Windows.Forms.TabPage();
            this.tpLoaiSP = new System.Windows.Forms.TabPage();
            this.tcSanPham.SuspendLayout();
            this.SuspendLayout();
            // 
            // tcSanPham
            // 
            this.tcSanPham.Controls.Add(this.tpSanPham);
            this.tcSanPham.Controls.Add(this.tpLoaiSP);
            this.tcSanPham.Location = new System.Drawing.Point(12, 12);
            this.tcSanPham.Name = "tcSanPham";
            this.tcSanPham.SelectedIndex = 0;
            this.tcSanPham.Size = new System.Drawing.Size(776, 426);
            this.tcSanPham.TabIndex = 0;
            // 
            // tpSanPham
            // 
            this.tpSanPham.Location = new System.Drawing.Point(4, 25);
            this.tpSanPham.Name = "tpSanPham";
            this.tpSanPham.Padding = new System.Windows.Forms.Padding(3);
            this.tpSanPham.Size = new System.Drawing.Size(768, 397);
            this.tpSanPham.TabIndex = 0;
            this.tpSanPham.Text = "Sản phẩm";
            this.tpSanPham.UseVisualStyleBackColor = true;
            // 
            // tpLoaiSP
            // 
            this.tpLoaiSP.Location = new System.Drawing.Point(4, 25);
            this.tpLoaiSP.Name = "tpLoaiSP";
            this.tpLoaiSP.Padding = new System.Windows.Forms.Padding(3);
            this.tpLoaiSP.Size = new System.Drawing.Size(768, 397);
            this.tpLoaiSP.TabIndex = 1;
            this.tpLoaiSP.Text = "Danh mục sản phẩm";
            this.tpLoaiSP.UseVisualStyleBackColor = true;
            // 
            // fSanPham
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tcSanPham);
            this.Name = "fSanPham";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Thông tin sản phẩm";
            this.tcSanPham.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tcSanPham;
        private System.Windows.Forms.TabPage tpSanPham;
        private System.Windows.Forms.TabPage tpLoaiSP;
    }
}