//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.pojo;

import java.io.Serializable;

public class Useradmin implements Serializable {
  private Integer aid;
  private User user;
  private String aname;
  private String deptname;

  public Useradmin() {
  }

  public Useradmin(String aname) {
    this.aname = aname;
  }

  public Useradmin(User user, String aname, String deptname) {
    this.user = user;
    this.aname = aname;
    this.deptname = deptname;
  }

  public Integer getAid() {
    return this.aid;
  }

  public void setAid(Integer aid) {
    this.aid = aid;
  }

  public User getUser() {
    return this.user;
  }

  public void setUser(User user) {
    this.user = user;
  }

  public String getAname() {
    return this.aname;
  }

  public void setAname(String aname) {
    this.aname = aname;
  }

  public String getDeptname() {
    return this.deptname;
  }

  public void setDeptname(String deptname) {
    this.deptname = deptname;
  }
}
