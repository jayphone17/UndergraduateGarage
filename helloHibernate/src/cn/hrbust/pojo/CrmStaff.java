package cn.hrbust.pojo;

import java.util.Date;

public class CrmStaff {
  private int staffId;
  private CrmPost crmPost;
  private String staffCode;
  private String loginName;
  private String loginPwd;
  private String staffName;
  private String gender;
  private Date birthday;
  private Date onDutyDate;

  public CrmStaff(int staffId, CrmPost crmPost, String staffCode,
                  String loginName, String loginPwd, String staffName, String gender,
                  Date birthday, Date onDutyDate) {
    super();
    this.staffId = staffId;
    this.crmPost = crmPost;
    this.staffCode = staffCode;
    this.loginName = loginName;
    this.loginPwd = loginPwd;
    this.staffName = staffName;
    this.gender = gender;
    this.birthday = birthday;
    this.onDutyDate = onDutyDate;
  }
  public CrmStaff() {
    super();
  }

  public int getStaffId() {
    return staffId;
  }

  public void setStaffId(int staffId) {
    this.staffId = staffId;
  }

  public CrmPost getCrmPost() {
    return crmPost;
  }

  public void setCrmPost(CrmPost crmPost) {
    this.crmPost = crmPost;
  }

  public String getStaffCode() {
    return staffCode;
  }

  public void setStaffCode(String staffCode) {
    this.staffCode = staffCode;
  }

  public String getLoginName() {
    return loginName;
  }

  public void setLoginName(String loginName) {
    this.loginName = loginName;
  }

  public String getLoginPwd() {
    return loginPwd;
  }

  public void setLoginPwd(String loginPwd) {
    this.loginPwd = loginPwd;
  }

  public String getStaffName() {
    return staffName;
  }

  public void setStaffName(String staffName) {
    this.staffName = staffName;
  }

  public String getGender() {
    return gender;
  }

  public void setGender(String gender) {
    this.gender = gender;
  }

  public Date getBirthday() {
    return birthday;
  }

  public void setBirthday(Date birthday) {
    this.birthday = birthday;
  }

  public Date getOnDutyDate() {
    return onDutyDate;
  }

  public void setOnDutyDate(Date onDutyDate) {
    this.onDutyDate = onDutyDate;
  }

  public String toString(){
    return "Crmstaff [staffID=" + staffId + ",staffCode=" + staffCode + ",loginName=" + loginName + ",loginPwd=" + loginPwd + ",staffName=" + staffName + ",gender" + gender + ",birthday" + birthday + ",onDutyDate" + onDutyDate ;
  }
}
