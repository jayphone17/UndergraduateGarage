//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.pojo;

import java.io.Serializable;

public class User implements Serializable {
  private Integer uid;
  private Usergroup usergroup;
  private String username;
  private String password;
  private Useradmin useradmin;
  private Expert expert;
  private Unit unit;

  public User() {
  }

  public User(String username, String password) {
    this.username = username;
    this.password = password;
  }

  public User(Usergroup usergroup, String username, String password, Useradmin useradmin, Expert expert, Unit unit) {
    this.usergroup = usergroup;
    this.username = username;
    this.password = password;
    this.useradmin = useradmin;
    this.expert = expert;
    this.unit = unit;
  }

  public Integer getUid() {
    return this.uid;
  }

  public void setUid(Integer uid) {
    this.uid = uid;
  }

  public Usergroup getUsergroup() {
    return this.usergroup;
  }

  public void setUsergroup(Usergroup usergroup) {
    this.usergroup = usergroup;
  }

  public String getUsername() {
    return this.username;
  }

  public void setUsername(String username) {
    this.username = username;
  }

  public String getPassword() {
    return this.password;
  }

  public void setPassword(String password) {
    this.password = password;
  }

  public Useradmin getUseradmin() {
    return this.useradmin;
  }

  public void setUseradmin(Useradmin useradmin) {
    this.useradmin = useradmin;
  }

  public Expert getExpert() {
    return this.expert;
  }

  public void setExpert(Expert expert) {
    this.expert = expert;
  }

  public Unit getUnit() {
    return this.unit;
  }

  public void setUnit(Unit unit) {
    this.unit = unit;
  }
}
