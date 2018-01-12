
package Object;
public class DanhBa {

  
    int MACT;
    String name;
    String phonenumber;
    String email;
    String address;

    public DanhBa() {
    }

    public DanhBa(int MACT,String name, String phonenumber, String email, String address) {
        this.name = name;
        this.phonenumber = phonenumber;
        this.email = email;
        this.address = address;
        this.MACT=MACT;
    }
      public int getMACT() {
        return MACT;
    }

    public void setMACT(int MACT) {
        this.MACT = MACT;
    }
    

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhonenumber() {
        return phonenumber;
    }

    public void setPhonenumber(String phonenumber) {
        this.phonenumber = phonenumber;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }
    
    
}
