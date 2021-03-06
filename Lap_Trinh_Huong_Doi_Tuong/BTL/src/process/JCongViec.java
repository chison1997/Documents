/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package process;

import DATA.UpdateTable;
import DATA.CONGVIECDATA;
import java.sql.ResultSet;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.table.TableColumnModel;
import Object.CongViec;

/**
 *
 * @author Admin
 */
public class JCongViec extends javax.swing.JFrame {

    /**
     * Creates new forNhapCVCuCV
     */
     CONGVIECDATA CONGVIECDATA = new CONGVIECDATA();
    public static String sqlTT="SELECT * FROM CONGVIEC order by MACV";
    public JCongViec() {
        initComponents();
        UpdateTable.LoadData(sqlTT, tbCongViec);
        
        TableColumnModel columnModel = tbCongViec.getColumnModel();
        jLabel14.setIcon(Home.iconBG);
    
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        txtNoidung = new javax.swing.JTextField();
        txtTen = new javax.swing.JTextField();
        gio1 = new javax.swing.JSpinner();
        phut1 = new javax.swing.JSpinner();
        gio2 = new javax.swing.JSpinner();
        phut2 = new javax.swing.JSpinner();
        jRadioButton1 = new javax.swing.JRadioButton();
        jComboBoxUuTien = new javax.swing.JComboBox<>();
        jThem = new javax.swing.JButton();
        jLabel13 = new javax.swing.JLabel();
        jComboBoxTrangThai = new javax.swing.JComboBox<>();
        jSua = new javax.swing.JButton();
        jXoa = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        tbCongViec = new javax.swing.JTable();
        jButton4 = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel11 = new javax.swing.JLabel();
        jLabel16 = new javax.swing.JLabel();
        jLabel17 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel18 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();

        jLabel1.setText("jLabel1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel3.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        jLabel3.setText("Công việc");
        getContentPane().add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 70, -1, 30));

        jLabel4.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        jLabel4.setText("Chi tiết");
        getContentPane().add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 70, -1, 30));

        jLabel5.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel5.setText("Ngày");
        getContentPane().add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 120, -1, 25));

        jLabel6.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel6.setText("Ngày");
        getContentPane().add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 170, -1, 20));

        jLabel7.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        getContentPane().add(jLabel7, new org.netbeans.lib.awtextra.AbsoluteConstraints(591, 141, -1, -1));

        jLabel9.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel9.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_bell_2199103 (1).png"))); // NOI18N
        jLabel9.setText("Nhắc nhở");
        getContentPane().add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(750, 220, 92, -1));

        jLabel10.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel10.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/numbered-information.png"))); // NOI18N
        jLabel10.setText("Ưu tiên");
        getContentPane().add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 220, -1, 30));

        txtNoidung.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        txtNoidung.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtNoidungActionPerformed(evt);
            }
        });
        getContentPane().add(txtNoidung, new org.netbeans.lib.awtextra.AbsoluteConstraints(490, 70, 420, 30));

        txtTen.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        txtTen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtTenActionPerformed(evt);
            }
        });
        getContentPane().add(txtTen, new org.netbeans.lib.awtextra.AbsoluteConstraints(160, 70, 200, 30));

        gio1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        gio1.setModel(new javax.swing.SpinnerNumberModel(0, 0, 23, 1));
        getContentPane().add(gio1, new org.netbeans.lib.awtextra.AbsoluteConstraints(490, 120, 50, 35));

        phut1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        phut1.setModel(new javax.swing.SpinnerNumberModel(0, 0, 59, 1));
        getContentPane().add(phut1, new org.netbeans.lib.awtextra.AbsoluteConstraints(610, 120, 50, 35));

        gio2.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        gio2.setModel(new javax.swing.SpinnerNumberModel(0, 0, 23, 1));
        getContentPane().add(gio2, new org.netbeans.lib.awtextra.AbsoluteConstraints(490, 170, 50, 35));

        phut2.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        phut2.setModel(new javax.swing.SpinnerNumberModel(0, 0, 59, 1));
        getContentPane().add(phut2, new org.netbeans.lib.awtextra.AbsoluteConstraints(610, 170, 50, 35));

        jRadioButton1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jRadioButton1.setText("Có");
        jRadioButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jRadioButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jRadioButton1, new org.netbeans.lib.awtextra.AbsoluteConstraints(850, 220, -1, 30));

        jComboBoxUuTien.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jComboBoxUuTien.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "cao", "bình thường", "thấp" }));
        jComboBoxUuTien.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jComboBoxUuTienActionPerformed(evt);
            }
        });
        getContentPane().add(jComboBoxUuTien, new org.netbeans.lib.awtextra.AbsoluteConstraints(490, 220, 122, 30));

        jThem.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jThem.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/Add-icon.png"))); // NOI18N
        jThem.setText("THÊM");
        jThem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jThemActionPerformed(evt);
            }
        });
        getContentPane().add(jThem, new org.netbeans.lib.awtextra.AbsoluteConstraints(210, 270, 180, 43));

        jLabel13.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel13.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/volume.png"))); // NOI18N
        jLabel13.setText("Trạng thái");
        getContentPane().add(jLabel13, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 220, -1, 30));

        jComboBoxTrangThai.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jComboBoxTrangThai.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "chưa hoàn thành", "đang hoàn thành", "đã hoàn thành" }));
        jComboBoxTrangThai.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jComboBoxTrangThaiActionPerformed(evt);
            }
        });
        getContentPane().add(jComboBoxTrangThai, new org.netbeans.lib.awtextra.AbsoluteConstraints(160, 220, 140, 30));

        jSua.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jSua.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/Pencil-icon.png"))); // NOI18N
        jSua.setText("SỬA");
        jSua.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jSuaActionPerformed(evt);
            }
        });
        getContentPane().add(jSua, new org.netbeans.lib.awtextra.AbsoluteConstraints(390, 270, 160, 43));

        jXoa.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jXoa.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/delete-icon.png"))); // NOI18N
        jXoa.setText("XOÁ");
        jXoa.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jXoaActionPerformed(evt);
            }
        });
        getContentPane().add(jXoa, new org.netbeans.lib.awtextra.AbsoluteConstraints(550, 270, 150, 43));

        tbCongViec.setModel(new javax.swing.table.DefaultTableModel(
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
        tbCongViec.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tbCongViecMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(tbCongViec);

        getContentPane().add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 330, 890, 210));

        jButton4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_house_384890.png"))); // NOI18N
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton4, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, 30));

        jLabel2.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel2.setText("Giờ");
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 120, -1, 30));

        jLabel11.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel11.setText("Phút");
        getContentPane().add(jLabel11, new org.netbeans.lib.awtextra.AbsoluteConstraints(570, 120, -1, 30));

        jLabel16.setFont(new java.awt.Font("Tahoma", 0, 16)); // NOI18N
        jLabel16.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_clock_1055090.png"))); // NOI18N
        jLabel16.setText("Bắt đầu:");
        getContentPane().add(jLabel16, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 120, 139, -1));

        jLabel17.setFont(new java.awt.Font("Tahoma", 0, 16)); // NOI18N
        jLabel17.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_clock_1055090.png"))); // NOI18N
        jLabel17.setText("Kết thúc:");
        getContentPane().add(jLabel17, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 170, 143, -1));

        jLabel8.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel8.setText("Giờ");
        getContentPane().add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 170, -1, 30));

        jLabel18.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel18.setText("Phút");
        getContentPane().add(jLabel18, new org.netbeans.lib.awtextra.AbsoluteConstraints(570, 170, -1, 30));
        getContentPane().add(jLabel14, new org.netbeans.lib.awtextra.AbsoluteConstraints(-20, 0, 950, 570));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jThemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jThemActionPerformed
            // TODO add your handling code here:
        
         String strTimeBD = this.gio1.getValue().toString()+":"+ this.phut1.getValue().toString();
         String strTimeKT = this.gio2.getValue().toString()+":"+ this.phut2.getValue().toString();
       
         java.sql.Date dateBD =new java.sql.Date(jDateChooserBD.getDate().getTime());
         java.sql.Date dateKT =new java.sql.Date(jDateChooserKT.getDate().getTime());
        
         DateFormat formatter=new SimpleDateFormat("HH:mm");
         
         java.sql.Time timeBD = null;
        try {
            timeBD = new java.sql.Time(formatter.parse(strTimeBD).getTime());
        } catch (ParseException ex) {
            Logger.getLogger(JCongViec.class.getName()).log(Level.SEVERE, null, ex);
        }
         
        java.sql.Time timeKT = null;
        try {
            timeKT = new java.sql.Time(formatter.parse(strTimeKT).getTime());
        } catch (ParseException ex) {
            Logger.getLogger(JCongViec.class.getName()).log(Level.SEVERE, null, ex);
        }
         
         
         CongViec thongtin = new CongViec();
         
         thongtin.setCongviec(this.txtTen.getText());
         thongtin.setChitiet(this.txtNoidung.getText());
         thongtin.setDateStart(dateBD);
         thongtin.setDateEnd(dateKT);
         thongtin.setTimeEnd(timeKT);
         thongtin.setTimeStart(timeBD);
         thongtin.setUutien(this.jComboBoxUuTien.getSelectedItem().toString());
         thongtin.setTrangthai(this.jComboBoxTrangThai.getSelectedItem().toString());
         if(jRadioButton1.isSelected())
             thongtin.setNhacnho(true);
         else thongtin.setNhacnho(false);
         
         CONGVIECDATA.InsertCONGVIEC(thongtin);
         UpdateTable.LoadData("SELECT * FROM CONGVIEC", tbCongViec);
         
         
    }//GEN-LAST:event_jThemActionPerformed

    private void jComboBoxUuTienActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBoxUuTienActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jComboBoxUuTienActionPerformed

    private void jRadioButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jRadioButton1ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jRadioButton1ActionPerformed

    private void jComboBoxTrangThaiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBoxTrangThaiActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jComboBoxTrangThaiActionPerformed

    private void jSuaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jSuaActionPerformed
            // TODO add your handling code here:
         String strTimeBD = this.gio1.getValue().toString()+":"+ this.phut1.getValue().toString();
         String strTimeKT = this.gio2.getValue().toString()+":"+ this.phut2.getValue().toString();
        
         java.sql.Date dateBD =new java.sql.Date(jDateChooserBD.getDate().getTime());
         java.sql.Date dateKT =new java.sql.Date(jDateChooserKT.getDate().getTime());
         
         DateFormat formatter=new SimpleDateFormat("HH:mm");
         
         java.sql.Time timeBD = null;
        try {
            timeBD = new java.sql.Time(formatter.parse(strTimeBD).getTime());
        } catch (ParseException ex) {
            Logger.getLogger(JCongViec.class.getName()).log(Level.SEVERE, null, ex);
        }
         
        java.sql.Time timeKT = null;
        try {
            timeKT = new java.sql.Time(formatter.parse(strTimeKT).getTime());
        } catch (ParseException ex) {
            Logger.getLogger(JCongViec.class.getName()).log(Level.SEVERE, null, ex);
        }
       
         
         CongViec thongtin = new CongViec();
         
         int index = this.tbCongViec.getSelectedRow();
         int macv = Integer.parseInt(this.tbCongViec.getValueAt(index, 0).toString());
         thongtin.setMaCV(macv);   
         thongtin.setCongviec(this.txtTen.getText());
         thongtin.setChitiet(this.txtNoidung.getText());
         thongtin.setDateStart(dateBD);
         thongtin.setDateEnd(dateKT);
         thongtin.setTimeEnd(timeKT);
         thongtin.setTimeStart(timeBD);
         
         thongtin.setUutien(this.jComboBoxUuTien.getSelectedItem().toString());
         thongtin.setTrangthai(this.jComboBoxTrangThai.getSelectedItem().toString());
         if(jRadioButton1.isSelected())
             thongtin.setNhacnho(true);
         else thongtin.setNhacnho(false);
         
         CONGVIECDATA.UpdateCONGVIEC(thongtin);
         UpdateTable.LoadData("SELECT * FROM CONGVIEC", tbCongViec);
         
    }//GEN-LAST:event_jSuaActionPerformed

    private void jXoaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jXoaActionPerformed
        // TODO add your handling code here:
         int click = JOptionPane.showConfirmDialog(null,"Bạn có chắc chắn xoá không?","Thông báo",JOptionPane.YES_NO_OPTION);
        if (click == JOptionPane.YES_OPTION){
            int index = this.tbCongViec.getSelectedRow();
            String macv = this.tbCongViec.getValueAt(index, 0).toString();
            if(CONGVIECDATA.DeleteCONGVIEC(macv)) {
                JOptionPane.showMessageDialog(null, "Bạn đã xóa thành công", "Thông báo", 1);
            }
            else JOptionPane.showMessageDialog(null, "Có lỗi xảy ra", "Thông báo", 2);
            UpdateTable.LoadData("SELECT * FROM CONGVIEC", tbCongViec);
        }
    }//GEN-LAST:event_jXoaActionPerformed

    private void tbCongViecMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tbCongViecMouseClicked
         // TODO add your handling code here:
          try{
            int row = this.tbCongViec.getSelectedRow();
            String IDrow = (this.tbCongViec.getModel().getValueAt(row, 0)).toString();
            String sql1 = "SELECT * FROM CONGVIEC WHERE MACV='"+IDrow+"'";
            ResultSet rs = UpdateTable.ShowTextField(sql1);

            if(rs.next()) {
               
                this.txtTen.setText(rs.getString("ten"));
                this.txtNoidung.setText(rs.getString("noidung"));
        
                this.jComboBoxUuTien.setSelectedItem(rs.getString("uutien"));
                this.jComboBoxTrangThai.setSelectedItem(rs.getString("trangthai"));
                this.jDateChooserBD.setDate(rs.getDate("dateStart"));
                this.jDateChooserKT.setDate(rs.getDate("dateEnd"));
                if (rs.getBoolean("nhacnho")==true)
                    this.jRadioButton1.setSelected(true);
                else this.jRadioButton1.setSelected(false);
                
                this.gio1.setValue(rs.getTime("timeStart").getHours());
                this.gio2.setValue(rs.getTime("timeEnd").getHours());
                this.phut1.setValue(rs.getTime("timeStart").getMinutes());
                this.phut2.setValue(rs.getTime("timeEnd").getMinutes());
                
     
            }
        }catch(Exception e) {
        }
    }//GEN-LAST:event_tbCongViecMouseClicked

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
         // TODO add your handling code here:
        Home t = new Home();
        t.setVisible(true);
        dispose();
    }//GEN-LAST:event_jButton4ActionPerformed

    private void txtNoidungActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtNoidungActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txtNoidungActionPerformed

    private void txtTenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtTenActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txtTenActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
       
           //</editor-fold>
     //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
         public void run() {
                new JCongViec().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JSpinner gio1;
    private javax.swing.JSpinner gio2;
    private javax.swing.JButton jButton4;
    private javax.swing.JComboBox<String> jComboBoxTrangThai;
    private javax.swing.JComboBox<String> jComboBoxUuTien;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel17;
    private javax.swing.JLabel jLabel18;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JRadioButton jRadioButton1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JButton jSua;
    private javax.swing.JButton jThem;
    private javax.swing.JButton jXoa;
    private javax.swing.JSpinner phut1;
    private javax.swing.JSpinner phut2;
    private javax.swing.JTable tbCongViec;
    private javax.swing.JTextField txtNoidung;
    private javax.swing.JTextField txtTen;
    // End of variables declaration//GEN-END:variables
}
