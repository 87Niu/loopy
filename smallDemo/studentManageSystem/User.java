package smallDemo.studentManageSystem;

public class User {
    private String username;
    private String password;
    private String personID;
    private String phoneNum;

    public User() {
    }

    public User(String username, String password, String personID, String phoneNum) {
        this.username = username;
        this.password = password;
        this.personID = personID;
        this.phoneNum = phoneNum;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getPersonID() {
        return personID;
    }

    public void setPersonID(String personID) {
        this.personID = personID;
    }

    public String getPhoneNum() {
        return phoneNum;
    }

    public void setPhoneNum(String phoneNum) {
        this.phoneNum = phoneNum;
    }
}
