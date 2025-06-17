package qlkb;

import javax.swing.SwingUtilities;

public class QLKB {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new ThanhToanForm().setVisible(true);
        });
    }
}
