/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package process;

import DATA.UpdateTable;
import DATA.DANHBADATA;
import java.sql.ResultSet;
import javax.swing.JOptionPane;
import javax.swing.JTable;
import Object.DanhBa;


public class JDanhBa extends javax.swing.JFrame {

    DANHBADATA DANHBADATA = new DANHBADATA();
    /**
     * Creates new form JDanhBa
     */
    public static String sqlCT = "SELECT * FROM CONTACT order by MACT asc";
   

    public JDanhBa() {
        initComponents();
        UpdateTable.LoadData((sqlCT), tbCT);
     //   this.getContentPane().setBackground(Home.mau);
        jLabel6.setIcon(Home.iconBG);
    }

    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        name = new javax.swing.JTextField();
        phone = new javax.swing.JTextField();
        email = new javax.swing.JTextField();
        address = new javax.swing.JTextField();
        sua = new javax.swing.JButton();
        xoa = new javax.swing.JButton();
        them = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        tbCT = new javax.swing.JTable();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jButton4 = new javax.swing.JButton();
        jLabel6 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        name.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        getContentPane().add(name, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 100, 194, 30));

        phone.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        getContentPane().add(phone, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 140, 194, 32));

        email.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        getContentPane().add(email, new org.netbeans.lib.awtextra.AbsoluteConstraints(548, 93, 194, 30));

        address.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        getContentPane().add(address, new org.netbeans.lib.awtextra.AbsoluteConstraints(548, 134, 194, 30));

        sua.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        sua.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/Pencil-icon.png"))); // NOI18N
        sua.setText("SỬA");
        sua.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                suaActionPerformed(evt);
            }
        });
        getContentPane().add(sua, new org.netbeans.lib.awtextra.AbsoluteConstraints(345, 199, 140, 40));

        xoa.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        xoa.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/delete-icon.png"))); // NOI18N
        xoa.setText("XOÁ");
        xoa.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                xoaActionPerformed(evt);
            }
        });
        getContentPane().add(xoa, new org.netbeans.lib.awtextra.AbsoluteConstraints(485, 199, 140, 40));

        them.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        them.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/Add-icon.png"))); // NOI18N
        them.setText("THÊM");
        them.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                themActionPerformed(evt);
            }
        });
        getContentPane().add(them, new org.netbeans.lib.awtextra.AbsoluteConstraints(193, 199, 150, 40));

        jLabel1.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        jLabel1.setText("DANH BẠ");
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(379, 36, -1, -1));

        tbCT.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Title 1", "Title 2", "Title 3", "Title 4"
            }
        ));
        tbCT.setRowHeight(23);
        tbCT.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tbCTMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(tbCT);

        getContentPane().add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(86, 269, 657, 172));

        jLabel2.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_hire-me_59572.png"))); // NOI18N
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(86, 93, -1, -1));

        jLabel3.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_Phone_408400.png"))); // NOI18N
        getContentPane().add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(86, 138, -1, -1));

        jLabel4.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_email-px-png_63463.png"))); // NOI18N
        getContentPane().add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(506, 93, -1, -1));

        jLabel5.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel5.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_go-home_118770.png"))); // NOI18N
        getContentPane().add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(506, 134, -1, -1));

        jButton4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_back-alt_134226.png"))); // NOI18N
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton4, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        jLabel6.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/hoacuc.jpg"))); // NOI18N
        jLabel6.setText("jLabel6");
        getContentPane().add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, -6, 830, 520));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void suaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_suaActionPerformed
        DanhBa con = new DanhBa();
        
        int index = this.tbCT.getSelectedRow();
        int id = Integer.parseInt(this.tbCT.getValueAt(index, 0).toString());
        
        con.setMACT(id);
        con.setName(this.name.getText());
        con.setPhonenumber(this.phone.getText());
        con.setEmail(this.email.getText());
        con.setAddress(this.address.getText());
        DANHBADATA.UpdateContact(con);
        UpdateTable.LoadData("SELECT * FROM CONTACT", tbCT);
    }//GEN-LAST:event_suaActionPerformed

    private void themActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_themActionPerformed
         DanhBa con = new DanhBa();
        con.setName(this.name.getText());
        con.setPhonenumber(this.phone.getText());
        con.setEmail(this.email.getText());
        con.setAddress(this.address.getText());
        DANHBADATA.InsertContact(con);
        UpdateTable.LoadData("SELECT * FROM CONTACT", tbCT);
    }//GEN-LAST:event_themActionPerformed
 
    private void xoaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_xoaActionPerformed
        int click = JOptionPane.showConfirmDialog(null,"Bạn có chắc chắn xoá không?","Thông báo",JOptionPane.YES_NO_OPTION);
        if (click == JOptionPane.YES_OPTION){
            int index = this.tbCT.getSelectedRow();
            int mact = (int) this.tbCT.getValueAt(index, 0);
            if(DANHBADATA.DeleteContact(mact)) {
                JOptionPane.showMessageDialog(null, "Bạn đã xóa thành công", "Thông báo", 1);
            }
            else JOptionPane.showMessageDialog(null, "Có lỗi xảy ra", "Thông báo", 2);
            UpdateTable.LoadData("SELECT * FROM CONTACT", tbCT);
        }
        
    }//GEN-LAST:event_xoaActionPerformed

    private void tbCTMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tbCTMouseClicked
        try{
            int row = this.tbCT.getSelectedRow();
            String IDrow = (this.tbCT.getModel().getValueAt(row, 0)).toString();
            String sql1 = "SELECT * FROM CONTACT WHERE MACT='"+IDrow+"'";
            ResultSet rs = UpdateTable.ShowTextField(sql1);

            if(rs.next()) {
                
                this.name.setText(rs.getString("name"));
                this.phone.setText(rs.getString("phone"));
                this.email.setText(rs.getString("email"));
                this.address.setText(rs.getString("address"));
            }
        }catch(Exception e) {
        }
    
        
    }//GEN-LAST:event_tbCTMouseClicked

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
         // TODO add your handling code here:
        Home h = new Home();
        h.setVisible(true);
        dispose();
    }//GEN-LAST:event_jButton4ActionPerformed
 
    /**
         * @param args the command line arguments
         */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(DanhBa.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(DanhBa.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(DanhBa.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(DanhBa.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new JDanhBa().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField address;
    private javax.swing.JTextField email;
    private javax.swing.JButton jButton4;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextField name;
    private javax.swing.JTextField phone;
    private javax.swing.JButton sua;
    private javax.swing.JTable tbCT;
    private javax.swing.JButton them;
    private javax.swing.JButton xoa;
    // End of variables declaration//GEN-END:variables
}

