/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package process;

import DATA.CONNECT;
import java.awt.Color;
import java.awt.Component;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.text.ParseException;
import java.util.Calendar;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Son
 */
public class Ngay extends javax.swing.JFrame {

  
    public static PreparedStatement ps = null;
    public static ResultSet rs;
    public Ngay() throws ParseException {
        initComponents(); 
        Date current= new Date(Calendar.getInstance().getTime().getTime());
        jDateChooser1.setDate(current);
        
        loadDataNgay(current, "sang");   
        loadDataNgay(current, "trua");
        loadDataNgay(current, "chieu");
        loadDataNgay(current, "toi");
        
        loadDataNgayMucDo(current, "thấp");
        loadDataNgayMucDo(current, "bình thường");
        loadDataNgayMucDo(current, "cao");
        
        jTable2.getColumnModel().getColumn(0).setCellRenderer(new MyRenderer0());       
        jTable2.getColumnModel().getColumn(1).setCellRenderer(new MyRenderer());
        jTable2.getColumnModel().getColumn(2).setCellRenderer(new MyRenderer2());
         this.jLabel4.setIcon(Home.iconBG);
    }
    
    public void deleteDataTable(){
        DefaultTableModel model = (DefaultTableModel)jTable1.getModel();
        for (int col=0; col<=3; col++)
            for (int row=0; row<=3; row++)
                model.setValueAt(null, row, col);
        
        model = (DefaultTableModel)jTable2.getModel();
        for (int col=0; col<=2; col++)
            for (int row=0; row<=3; row++)
                model.setValueAt(null, row, col);
    }
    //hiển thị lên table
    public void loadDataNgay(Date date, String thoidiem){
        
        String noidung[] = new String[4];
        DefaultTableModel model = (DefaultTableModel)jTable1.getModel();
        
        ganNoidungDate(date, noidung, thoidiem);
        int k = 0;

        while(noidung[k]!=null){
            if (thoidiem.equals("sang"))
                model.setValueAt(noidung[k], k, 0);
            if (thoidiem.equals("trua"))
                model.setValueAt(noidung[k], k, 1);
            if (thoidiem.equals("chieu"))
                model.setValueAt(noidung[k], k, 2);
            if (thoidiem.equals("toi"))
                model.setValueAt(noidung[k], k, 3);
            k++;
        }

        for (int j = 0; j <= k; j++) 
            noidung[j]=null;
        
    }
    
    public void loadDataNgayMucDo(Date date, String mucDo){
        
        String noidung[] = new String[4];
        DefaultTableModel model = (DefaultTableModel)jTable2.getModel();
        
        ganNoidungDateMucDo(date, noidung, mucDo);
        int k = 0;

        while(noidung[k]!=null){
            if (mucDo.equals("thấp"))
                model.setValueAt(noidung[k], k, 0);
            if (mucDo.equals("bình thường"))
                model.setValueAt(noidung[k], k, 1);
            if (mucDo.equals("cao"))
                model.setValueAt(noidung[k], k, 2);
            
            k++;
        }

        for (int j = 0; j <= k; j++) 
            noidung[j]=null;
        
    }
    
    //cộng trừ ngày
    public java.sql.Date addDate(java.sql.Date date, int i){
        java.util.Date utilDate = new Date(date.getTime());
        
        Calendar cal = Calendar.getInstance();
        cal.setTime(utilDate);
        cal.add(Calendar.DATE, +i);
        utilDate = cal.getTime();
        
        java.sql.Date date2 = new Date(utilDate.getTime());
        return date2;
    }
    
    // gán công việc từng ngày vào mảng noidung[10]
    public void ganNoidungDate(java.sql.Date date, String[] noidung, String thoidiem){  
        
        int count=0;
        String sql = null;
        if (thoidiem.equals("sang")) 
            sql = "select congviec,timeStart from CONGVIEC where dateStart ='"+date+"' and '0:00:00' <= timeStart and timeStart <= '10:59:59' order by timeStart";
        if (thoidiem.equals("trua")) 
            sql = "select congviec,timeStart from CONGVIEC where dateStart ='"+date+"' and '11:00:00' <= timeStart and timeStart <= '13:59:59' order by timeStart";
        if (thoidiem.equals("chieu")) 
            sql = "select congviec,timeStart from CONGVIEC where dateStart ='"+date+"' and '14:00:00' <= timeStart and timeStart <= '17:59:59' order by timeStart";
        if (thoidiem.equals("toi")) 
            sql = "select congviec,timeStart from CONGVIEC where dateStart ='"+date+"' and '18:00:00' <= timeStart and timeStart <= '23:59:59' order by timeStart";
        
        try{
            ps = CONNECT.getConnect().prepareStatement(sql);
            rs=ps.executeQuery();
            while(rs.next()){
                count++;
                noidung[count-1] = rs.getString(1) + "  " + rs.getTime(2);
            }
        }catch(Exception e){
            JOptionPane.showMessageDialog(null, e, e.getMessage(), 0);
        }
    }
    
    public void ganNoidungDateMucDo(java.sql.Date date, String[] noidung, String mucDo){  
        
        int count=0;
        String sql = "select congviec, timeStart from CONGVIEC where uutien = N'"+ mucDo + "' and dateStart = '"+date+"'";
       
        try{
            ps = CONNECT.getConnect().prepareStatement(sql);
            rs=ps.executeQuery();
            while(rs.next()){
                count++;
                noidung[count-1] = rs.getString(1) + "  " + rs.getTime(2);
            }
        }catch(Exception e){
            JOptionPane.showMessageDialog(null, e, e.getMessage(), 0);
        }
    }
    
    
    public class MyRenderer extends DefaultTableCellRenderer {

    // This is a overridden function which gets executed for each action to
    /// your Jtable
        @Override
        public Component getTableCellRendererComponent (JTable table, 
            Object obj, boolean isSelected, boolean hasFocus, int row, int column) {
            Component d =  super.getTableCellRendererComponent(table, obj, isSelected, hasFocus, row, column);
            Color c = new Color(255, 232, 191);
              d.setBackground(c);
            /*
            String strval = table.getValueAt(0, 1).toString();
            int intval = Integer.parseInt(strval);
            if (intval == 6) {
                d.setBackground(Color.ORANGE);
            }
            else {
                d.setBackground(Color.WHITE);
            }*/
            return d;
        }
    
    }
    public class MyRenderer2 extends DefaultTableCellRenderer {

   
        @Override
        public Component getTableCellRendererComponent (JTable table, 
            Object obj, boolean isSelected, boolean hasFocus, int row, int column) {
            Component d =  super.getTableCellRendererComponent(table, obj, isSelected, hasFocus, row, column);
            Color c = new Color(252, 215, 148);
              d.setBackground(c);
            
            return d;
        }
    
    }

    public class MyRenderer0 extends DefaultTableCellRenderer {

   
        @Override
        public Component getTableCellRendererComponent (JTable table, 
            Object obj, boolean isSelected, boolean hasFocus, int row, int column) {
            Component d =  super.getTableCellRendererComponent(table, obj, isSelected, hasFocus, row, column);
            Color vangnhat = new Color(255, 247, 234);
              d.setBackground(vangnhat);
            
            return d;
        }
    
    }
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jDateChooser1 = new com.toedter.calendar.JDateChooser();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jScrollPane3 = new javax.swing.JScrollPane();
        jTable2 = new javax.swing.JTable();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jButton4 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        jButton6 = new javax.swing.JButton();
        jLabel4 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jDateChooser1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N

        jTable1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {"", null, null, null},
                {"", null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Sáng", "Trưa", "Chiều", "Tối"
            }
        ));
        jTable1.setRowHeight(23);
        jScrollPane1.setViewportView(jTable1);

        jButton1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jButton1.setText("Xem");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_next_1814.png"))); // NOI18N
        jButton2.setPreferredSize(new java.awt.Dimension(55, 33));
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_next_1814 - Copy.png"))); // NOI18N
        jButton3.setPreferredSize(new java.awt.Dimension(55, 33));
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        jLabel1.setText("Ngày:");

        jTable2.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jTable2.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null}
            },
            new String [] {
                "Mức độ thấp", "Mức độ bình thường", "Mức độ cao"
            }
        ));
        jTable2.setRowHeight(23);
        jScrollPane3.setViewportView(jTable2);

        jLabel2.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/numbered-information.png"))); // NOI18N
        jLabel2.setText("Theo độ ưu tiên");

        jLabel3.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_clock_1055090.png"))); // NOI18N
        jLabel3.setText("Theo thời gian");

        jButton4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_back-alt_134226.png"))); // NOI18N
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jButton5.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jButton5.setText("Xem theo tuần");
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });

        jButton6.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jButton6.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/if_edit_383148.png"))); // NOI18N
        jButton6.setText("Cập nhật");
        jButton6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton6ActionPerformed(evt);
            }
        });

        jLabel4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icon/hoacuc.jpg"))); // NOI18N
        jLabel4.setText("jLabel4");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(59, 59, 59)
                .addComponent(jButton5))
            .addGroup(layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addComponent(jLabel1)
                .addGap(10, 10, 10)
                .addComponent(jDateChooser1, javax.swing.GroupLayout.PREFERRED_SIZE, 232, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(10, 10, 10)
                .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(277, 277, 277)
                .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 90, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, 0)
                .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 97, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addGroup(layout.createSequentialGroup()
                .addGap(22, 22, 22)
                .addComponent(jLabel3))
            .addGroup(layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 857, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addGroup(layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addComponent(jLabel2))
            .addGroup(layout.createSequentialGroup()
                .addGap(22, 22, 22)
                .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 857, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addComponent(jButton4)
            .addGroup(layout.createSequentialGroup()
                .addGap(409, 409, 409)
                .addComponent(jButton6, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 900, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(6, 6, 6)
                .addComponent(jButton5, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(31, 31, 31)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(4, 4, 4)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jDateChooser1, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addGap(22, 22, 22)
                .addComponent(jLabel3)
                .addGap(3, 3, 3)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 123, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(17, 17, 17)
                .addComponent(jLabel2)
                .addGap(6, 6, 6)
                .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 124, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addGroup(layout.createSequentialGroup()
                .addGap(6, 6, 6)
                .addComponent(jButton4))
            .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 470, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addGroup(layout.createSequentialGroup()
                .addGap(70, 70, 70)
                .addComponent(jButton6, javax.swing.GroupLayout.PREFERRED_SIZE, 44, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
         java.sql.Date date =new java.sql.Date(jDateChooser1.getDate().getTime());
        
        deleteDataTable();
        loadDataNgay(date, "sang");   
        loadDataNgay(date, "trua");
        loadDataNgay(date, "chieu");
        loadDataNgay(date, "toi");

        loadDataNgayMucDo(date, "thấp");
        loadDataNgayMucDo(date, "bình thường");
        loadDataNgayMucDo(date, "cao");
      
        
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
         // TODO add your handling code here:
        Date date =new java.sql.Date(jDateChooser1.getDate().getTime());
        Date date2 = addDate(date, 1);
        jDateChooser1.setDate(date2);
        
        deleteDataTable();
        loadDataNgay(date2, "sang");   
        loadDataNgay(date2, "trua");
        loadDataNgay(date2, "chieu");
        loadDataNgay(date2, "toi");
        
        loadDataNgayMucDo(date2, "thấp");
        loadDataNgayMucDo(date2, "bình thường");
        loadDataNgayMucDo(date2, "cao");
        
        
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
          // TODO add your handling code here:
        Date date =new java.sql.Date(jDateChooser1.getDate().getTime());
        Date date2 = addDate(date, -1);
        jDateChooser1.setDate(date2);
        
        deleteDataTable();
        loadDataNgay(date2, "sang");   
        loadDataNgay(date2, "trua");
        loadDataNgay(date2, "chieu");
        loadDataNgay(date2, "toi");
        
        loadDataNgayMucDo(date2, "thấp");
        loadDataNgayMucDo(date2, "bình thường");
        loadDataNgayMucDo(date2, "cao");
    }//GEN-LAST:event_jButton3ActionPerformed

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
         // TODO add your handling code here:
         Home t = new Home();
         t.setVisible(true);
         dispose();
    }//GEN-LAST:event_jButton4ActionPerformed

    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton5ActionPerformed
        try {
            Tuan t = new Tuan();
            
            t.setVisible(true);
            dispose();
        } catch (ParseException ex) {
            Logger.getLogger(Ngay.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jButton5ActionPerformed

    private void jButton6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton6ActionPerformed
         // TODO add your handling code here:
         JCongViec t = new JCongViec();
         t.setVisible(true);
         dispose();
    }//GEN-LAST:event_jButton6ActionPerformed

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
            java.util.logging.Logger.getLogger(Tuan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Tuan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Tuan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Tuan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    new Ngay().setVisible(true);
                } catch (ParseException ex) {
                    Logger.getLogger(Ngay.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton5;
    private javax.swing.JButton jButton6;
    private com.toedter.calendar.JDateChooser jDateChooser1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JTable jTable1;
    private javax.swing.JTable jTable2;
    // End of variables declaration//GEN-END:variables
}
