package toolbar;

import javax.swing.*;
import java.awt.*;

public class Toolbar extends JFrame {
    
    public Toolbar() {
        setTitle("Toolbar");
        setSize(560, 100);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Tạo thanh công cụ
        JToolBar toolBar = new JToolBar();

        // Các nút chức năng
        ImageIcon openFolder = new ImageIcon(getClass().getResource("/icons/open-folder.png"));
        Image scaled_OF = openFolder.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnOpen = new JButton(new ImageIcon(scaled_OF));
        btnOpen.setToolTipText("Open");
        btnOpen.addActionListener(e -> showMessage("Open"));

        ImageIcon save = new ImageIcon(getClass().getResource("/icons/save.png"));
        Image scaled_S = save.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnSave = new JButton(new ImageIcon(scaled_S));
        btnSave.setToolTipText("Save");
        btnSave.addActionListener(e -> showMessage("Save"));

        ImageIcon saveAll = new ImageIcon(getClass().getResource("/icons/data-storage.png"));
        Image scaled_SA = saveAll.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnSaveAll = new JButton(new ImageIcon(scaled_SA));
        btnSaveAll.setToolTipText("Save All");
        btnSaveAll.addActionListener(e -> showMessage("Save All"));        

        ImageIcon print = new ImageIcon(getClass().getResource("/icons/printer.png"));
        Image scaled_P = print.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnPrint = new JButton(new ImageIcon(scaled_P));
        btnPrint.setToolTipText("Print");
        btnPrint.addActionListener(e -> showMessage("Print")); 
        
        ImageIcon printPreview = new ImageIcon(getClass().getResource("/icons/preview.png"));
        Image scaled_PP = printPreview.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnPrintPreview = new JButton(new ImageIcon(scaled_PP));
        btnPrintPreview.setToolTipText("Print Preview");
        btnPrintPreview.addActionListener(e -> showMessage("Print Preview")); 
        
        ImageIcon shareFb = new ImageIcon(getClass().getResource("/icons/facebook.png"));
        Image scaled_SF = shareFb.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnShareFb = new JButton(new ImageIcon(scaled_SF));
        btnShareFb.setToolTipText("Facebook Share");
        btnShareFb.addActionListener(e -> showMessage("Facebook Share")); 
        
        ImageIcon display = new ImageIcon(getClass().getResource("/icons/monitor.png"));
        Image scaled_D = display.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnDisplay = new JButton(new ImageIcon(scaled_D));
        btnDisplay.setToolTipText("Display");
        btnDisplay.addActionListener(e -> showMessage("Display")); 
        
        ImageIcon panTool = new ImageIcon(getClass().getResource("/icons/tap.png"));
        Image scaled_PT = panTool.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnPanTool = new JButton(new ImageIcon(scaled_PT));
        btnPanTool.setToolTipText("Pan Tool");
        btnPanTool.addActionListener(e -> showMessage("Pan Tool")); 
        
        ImageIcon zoom = new ImageIcon(getClass().getResource("/icons/glasses.png"));
        Image scaled_Z = zoom.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnZoom = new JButton(new ImageIcon(scaled_Z));
        btnZoom.setToolTipText("Zoom");
        btnZoom.addActionListener(e -> showMessage("Zoom")); 
        
        ImageIcon click = new ImageIcon(getClass().getResource("/icons/mouse-click-icon.png"));
        Image scaled_C = click.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnClick = new JButton(new ImageIcon(scaled_C));
        btnClick.setToolTipText("Mouse Click");
        btnClick.addActionListener(e -> showMessage("Mouse Click")); 
        
        ImageIcon addDocument = new ImageIcon(getClass().getResource("/icons/text-document-add-icon.png"));
        Image scaled_AD = addDocument.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnAddDocument = new JButton(new ImageIcon(scaled_AD));
        btnAddDocument.setToolTipText("Add Document");
        btnAddDocument.addActionListener(e -> showMessage("Add Document")); 
        
        ImageIcon screenShot = new ImageIcon(getClass().getResource("/icons/screenshot.png"));
        Image scaled_SS = screenShot.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnScreenShot = new JButton(new ImageIcon(scaled_SS));
        btnScreenShot.setToolTipText("ScreenShot");
        btnScreenShot.addActionListener(e -> showMessage("ScreenShot")); 
        
        ImageIcon security = new ImageIcon(getClass().getResource("/icons/lock.png"));
        Image scaled_Se = security.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnSecurity = new JButton(new ImageIcon(scaled_Se));
        btnSecurity.setToolTipText("Security");
        btnSecurity.addActionListener(e -> showMessage("Security")); 
        
        ImageIcon edit = new ImageIcon(getClass().getResource("/icons/edit.png"));
        Image scaled_E = edit.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        JButton btnEdit = new JButton(new ImageIcon(scaled_E));
        btnEdit.setToolTipText("Edit");
        btnEdit.addActionListener(e -> showMessage("Edit")); 
        
        // Thêm nút vào toolbar
        toolBar.add(btnOpen);
        toolBar.add(btnSave);
        toolBar.add(btnSaveAll);
        toolBar.add(btnPrint);  
        toolBar.add(btnPrintPreview);
        toolBar.add(btnShareFb);
        toolBar.add(btnDisplay);
        toolBar.add(btnPanTool);
        toolBar.add(btnZoom);
        toolBar.add(btnClick);
        toolBar.add(btnAddDocument);
        toolBar.add(btnScreenShot);
        toolBar.add(btnSecurity);
        toolBar.add(btnEdit);

        // Thêm toolbar vào frame
        add(toolBar);

        setVisible(true);
    }

    private void showMessage(String message) {
        JOptionPane.showMessageDialog(this, "Bạn đã chọn chức năng: " + message);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new Toolbar());
    }
}

