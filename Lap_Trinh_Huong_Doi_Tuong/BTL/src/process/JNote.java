/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package process;

import DATA.UpdateTable;
import DATA.NOTEDATA;
import java.sql.ResultSet;
import javax.swing.JOptionPane;
import javax.swing.table.TableColumnModel;
import Object.Note;
/**
 *
 * @author tiep
 */
public class JNote extends javax.swing.JFrame {

    /**
     * Creates new form JNote
     */
    NOTEDATA NOTEDATA =new NOTEDATA();
    public static String sqlN = "SELECT * FROM NOTE order by MAN asc";
    public JNote() {
        initComponents();
        this.setLocation(250,100);
        UpdateTable.LoadData((sqlN), tbNote);
        this.jLabel2.setIcon(Home.iconBG);
         this.getContentPane().setBackground(Home.mau);
         setSizeColumn();
        
    }
    private void setSizeColumn(){
        TableColumnModel columnModel = tbNote.getColumnModel();
        columnModel.getColumn(0).setWidth(2);
        columnModel.getColumn(1).setPreferredWidth(200);
    }
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane2 = new javax.swing.JScrollPane();
        jTextArea2 = new javax.swing.JTextArea();
        jScrollPane1 = new javax.swing.JScrollPane();
        note = new javax.swing.JTextArea();
        jLabel1 = new javax.swing.JLabel();
        them = new javax.swing.JButton();
        sua = new javax.swing.JButton();
        xoa = new javax.swing.JButton();
        jScrollPane3 = new javax.swing.JScrollPane();
        tbNote = new javax.swing.JTable();
        jButton4 = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();

        jTextArea2.setColumns(20);
        jTextArea2.setRows(5);
        jScrollPane2.setViewportView(jTextArea2);

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        note.setBackground(new java.awt.Color(255, 255, 204));
        note.setColumns(20);
        note.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        note.setRows(5);
        jScrollPane1.setViewportView(note);

        getContentPane().add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(51, 77, 286, 220));

        jLabel1.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        jLabel1.setText("GHI CHÚ");
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(154, 37, -1, -1));

        them.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        them.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/Add-icon.png"))); // NOI18N
        them.setText("Thêm");
        them.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                themActionPerformed(evt);
            }
        });
        getContentPane().add(them, new org.netbeans.lib.awtextra.AbsoluteConstraints(51, 308, 100, 40));

        sua.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        sua.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/Pencil-icon.png"))); // NOI18N
        sua.setText("Sửa");
        sua.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                suaActionPerformed(evt);
            }
        });
        getContentPane().add(sua, new org.netbeans.lib.awtextra.AbsoluteConstraints(151, 308, 90, 40));

        xoa.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        xoa.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/delete-icon.png"))); // NOI18N
        xoa.setText("Xóa");
        xoa.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                xoaActionPerformed(evt);
            }
        });
        getContentPane().add(xoa, new org.netbeans.lib.awtextra.AbsoluteConstraints(237, 308, 100, 40));

        tbNote.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        tbNote.setModel(new javax.swing.table.DefaultTableModel(
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
        tbNote.setRowHeight(30);
        tbNote.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tbNoteMouseClicked(evt);
            }
        });
        jScrollPane3.setViewportView(tbNote);

        getContentPane().add(jScrollPane3, new org.netbeans.lib.awtextra.AbsoluteConstraints(369, 77, 427, 271));

        jButton4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_back-alt_134226.png"))); // NOI18N
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton4, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, -6, 850, 420));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void themActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_themActionPerformed
        Note nt= new Note();
        nt.setNoidung(this.note.getText());
        NOTEDATA.InsertNOTE(nt);
        UpdateTable.LoadData("SELECT * FROM NOTE", tbNote);
        setSizeColumn();
    }//GEN-LAST:event_themActionPerformed

    private void suaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_suaActionPerformed
        Note n = new Note();
        
        n.setNoidung(this.note.getText());
        
        int index = this.tbNote.getSelectedRow();
        int id = Integer.parseInt(this.tbNote.getValueAt(index, 0).toString());
        n.setMAN(id);
        
        NOTEDATA.UpdateNOTE(n);
        UpdateTable.LoadData("SELECT * FROM NOTE", tbNote);
        setSizeColumn();
    }//GEN-LAST:event_suaActionPerformed

    private void tbNoteMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tbNoteMouseClicked
        try{
            int row = this.tbNote.getSelectedRow();
            String IDrow = (this.tbNote.getModel().getValueAt(row, 0)).toString();
            String sql1 = "SELECT * FROM NOTE WHERE MAN='"+IDrow+"'";
            ResultSet rs = UpdateTable.ShowTextField(sql1);

            if(rs.next()) {
                this.note.setText(rs.getString("noidung"));
            }
        }catch(Exception e) {
        }
    }//GEN-LAST:event_tbNoteMouseClicked

    private void xoaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_xoaActionPerformed
   
        int click = JOptionPane.showConfirmDialog(null,"Bạn có chắc chắn xoá không?","Thông báo",JOptionPane.YES_NO_OPTION);
        if (click == JOptionPane.YES_OPTION){
            int index = this.tbNote.getSelectedRow();
            int man = (int) this.tbNote.getValueAt(index, 0);
            if(NOTEDATA.DeleteNOTE(man)) {
                JOptionPane.showMessageDialog(null, "Bạn đã xóa thành công", "Thông báo", 1);
            }
            else JOptionPane.showMessageDialog(null, "Có lỗi xảy ra", "Thông báo", 2);
            UpdateTable.LoadData("SELECT * FROM NOTE", tbNote);
            setSizeColumn();
        }
        
        
    }//GEN-LAST:event_xoaActionPerformed

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
            java.util.logging.Logger.getLogger(JNote.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(JNote.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(JNote.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(JNote.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new JNote().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton4;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JTextArea jTextArea2;
    private javax.swing.JTextArea note;
    private javax.swing.JButton sua;
    private javax.swing.JTable tbNote;
    private javax.swing.JButton them;
    private javax.swing.JButton xoa;
    // End of variables declaration//GEN-END:variables
}
