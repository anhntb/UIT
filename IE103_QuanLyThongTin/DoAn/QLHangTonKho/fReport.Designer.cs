namespace QLHangTonKho
{
    partial class fReport
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
            this.tcBaoCao = new System.Windows.Forms.TabControl();
            this.tpPhieuNhapKho = new System.Windows.Forms.TabPage();
            this.tpPhieuXuatKho = new System.Windows.Forms.TabPage();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.crystalReportViewer1 = new CrystalDecisions.Windows.Forms.CrystalReportViewer();
            this.tcBaoCao.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tcBaoCao
            // 
            this.tcBaoCao.Controls.Add(this.tpPhieuNhapKho);
            this.tcBaoCao.Controls.Add(this.tpPhieuXuatKho);
            this.tcBaoCao.Controls.Add(this.tabPage1);
            this.tcBaoCao.Location = new System.Drawing.Point(12, 3);
            this.tcBaoCao.Name = "tcBaoCao";
            this.tcBaoCao.SelectedIndex = 0;
            this.tcBaoCao.Size = new System.Drawing.Size(1067, 555);
            this.tcBaoCao.TabIndex = 0;
            // 
            // tpPhieuNhapKho
            // 
            this.tpPhieuNhapKho.Location = new System.Drawing.Point(4, 25);
            this.tpPhieuNhapKho.Name = "tpPhieuNhapKho";
            this.tpPhieuNhapKho.Padding = new System.Windows.Forms.Padding(3);
            this.tpPhieuNhapKho.Size = new System.Drawing.Size(1059, 526);
            this.tpPhieuNhapKho.TabIndex = 0;
            this.tpPhieuNhapKho.Text = "Phiếu nhập kho";
            this.tpPhieuNhapKho.UseVisualStyleBackColor = true;
            // 
            // tpPhieuXuatKho
            // 
            this.tpPhieuXuatKho.Location = new System.Drawing.Point(4, 25);
            this.tpPhieuXuatKho.Name = "tpPhieuXuatKho";
            this.tpPhieuXuatKho.Padding = new System.Windows.Forms.Padding(3);
            this.tpPhieuXuatKho.Size = new System.Drawing.Size(1059, 526);
            this.tpPhieuXuatKho.TabIndex = 1;
            this.tpPhieuXuatKho.Text = "Phiếu xuất kho";
            this.tpPhieuXuatKho.UseVisualStyleBackColor = true;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.crystalReportViewer1);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(1059, 526);
            this.tabPage1.TabIndex = 2;
            this.tabPage1.Text = "tabPage1";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // crystalReportViewer1
            // 
            this.crystalReportViewer1.ActiveViewIndex = 0;
            this.crystalReportViewer1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.crystalReportViewer1.Cursor = System.Windows.Forms.Cursors.Default;
            this.crystalReportViewer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.crystalReportViewer1.Location = new System.Drawing.Point(3, 3);
            this.crystalReportViewer1.Name = "crystalReportViewer1";
            this.crystalReportViewer1.ReportSource = "C:\\Users\\TRAM\\OneDrive - Trường ĐH CNTT - University of Information Technology\\Co" +
    "urses\\QuanLyThongTin\\ThucHanh\\Tuan4\\Lab4\\1D.rpt";
            this.crystalReportViewer1.Size = new System.Drawing.Size(1053, 520);
            this.crystalReportViewer1.TabIndex = 0;
            // 
            // fReport
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1091, 570);
            this.Controls.Add(this.tcBaoCao);
            this.Name = "fReport";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Báo cáo thống kê";
            this.tcBaoCao.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tcBaoCao;
        private System.Windows.Forms.TabPage tpPhieuNhapKho;
        private System.Windows.Forms.TabPage tpPhieuXuatKho;
        private System.Windows.Forms.TabPage tabPage1;
        private CrystalDecisions.Windows.Forms.CrystalReportViewer crystalReportViewer1;
    }
}